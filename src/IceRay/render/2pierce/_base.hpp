#ifndef Dh_DDMRM_Iceray_render_pierce__base_HPP_
 #define Dh_DDMRM_Iceray_render_pierce__base_HPP_
 // GS_DDMRM::S_IceRay::S_render::S_pierce::GC__base

 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"

 #include "../../camera/_pure.hpp"
 #include "../../camera/flat/perspective.hpp"

 #include "../4ray/_pure.hpp"
 #include "../4ray/_base.hpp"

 #include "./_pure.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pierce
        {

         class GC__base
          : public GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure
          {
           public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                    T_scalar;

             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar          T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D        T_coord;

             typedef GS_DDMRM::S_IceRay::S_type::S_ray::S_beam::GT_simple    T_beam;

             typedef GS_DDMRM::S_IceRay::S_camera::GC__pure                  T_camera;
             typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure           T_ray;

             typedef GC__pure T__pure, T_this;

           public:
                      GC__base();
             virtual ~GC__base();

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
             typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective  T2_perspective;
             static T2_perspective M2s_camera;

           public:
             virtual void      Fv_ray( T_ray * P_ray ){ M2_ray = P_ray; }
                     T_ray   *  F_ray(){ return M2_ray; }
           protected:
             typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__base           T1_base;
             T_ray * & F1v_ray(){ return M2_ray; }
           private:
             T_ray * M2_ray;
           //static T1_base M2s_base;

           private:
            T_beam M2_beam;
          };

       }
     }
   }
 }

#endif
