#ifndef Dh_DDMRM_Iceray_render_beam__pure_HPP_
 #define Dh_DDMRM_Iceray_render_beam__pure_HPP_

// GS_DDMRM::S_IceRay::S_render::S_beam::GC__pure

 #include "..\..\type\color.hpp"
 #include "..\..\type\ray\beam.hpp"
 #include "..\4ray\_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_beam
        {

         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar        T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_ray::S_beam::GT_simple  T_beam;
             typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure         T_ray;

           public:
                      GC__pure();
             virtual ~GC__pure();

           public:
             virtual void Fv_do( T_color & P_color, T_beam const& P_beam )=0;

           public:
             virtual void Fv_ray( T_ray * P_ray );
           protected:
             T_ray * &   F1v_ray(){ return M2_ray; }
           private:
             T_ray *      M2_ray;
           private:
             static T_ray & Fs_ray();
          };

       }
     }
   }
 }

#endif
