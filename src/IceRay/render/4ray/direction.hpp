#ifndef Dh_DDMRM_Iceray_render_ray_direction_HPP_
 #define Dh_DDMRM_Iceray_render_ray_direction_HPP_

// GS_DDMRM::S_IceRay::S_render::S_ray::GC_direction

 #include "./_pure.hpp"
 #include "../../type/math/interval.hpp"
 #include "../../type/color.hpp"

 #include "../../geometry/_pure/intersect.hpp"
 #include "../../geometry/volumetric/vacuum.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_ray
        {

         class GC_direction
          : public GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar  T_color;


             GC_direction();
             ~GC_direction();

             void Fv_trace( T_color & P_color, T_ray const& );
          };

       }
     }
   }
 }

#endif
