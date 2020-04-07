#ifndef Dh_DDMRM_Iceray_render_pierce_projector_HPP_
 #define Dh_DDMRM_Iceray_render_pierce_projector_HPP_

 // GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector

 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"

 #include "../../camera/_pure.hpp"

 #include "../4ray/_pure.hpp"
 #include "../3sheaf/_pure.hpp"

 #include "./_pure.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pierce
        {

         class GC_projector
          : public GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure
          {
           public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                    T_scalar;

             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar          T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D        T_coord;

             typedef GS_DDMRM::S_IceRay::S_type::S_ray::S_beam::GT_simple    T_beam;

             typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure         T_sheaf;
             typedef GS_DDMRM::S_IceRay::S_camera::GC__pure                  T_camera;
             typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure           T_ray;

             typedef GC__pure T__pure, T_this;

           public:
                      GC_projector();
             virtual ~GC_projector();

           protected:
             virtual void F1v_render( T_color & P_color, T_coord const& P_coord );

           public:
             virtual void Fv_camera( T_camera* P_camera );
             T_camera*     F_camera(){ return M2_camera; }
           protected:
             T_camera* & F1_camera()
              {
               return M2_camera;
              }
           private:
             T_camera* M2_camera;
           private:
             static T_camera & Fs_camera();

           public:
             virtual void        Fv_sheaf( T_sheaf * P_sheaf );
                     T_sheaf   &  F_sheaf(){ return *M2_sheaf; }
           protected:
             T_sheaf   & F1v_sheaf(){ return *M2_sheaf; }
           private:
             T_sheaf * M2_sheaf;
           private:
             static T_sheaf & Fs_sheaf();

           private:
            T_beam M2_beam;
          };

       }
     }
   }
 }

#endif
