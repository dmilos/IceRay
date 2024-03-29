#ifndef Dh_DDMRM_Iceray_render_ray__pure_HPP_
 #define Dh_DDMRM_Iceray_render_ray__pure_HPP_

 // GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure

 //#include "../../type/basic/size.hpp"
 //#include "../../type/basic/scalar.hpp"

 #include "../../type/ray/simple.hpp"
 #include "../../type/ray/beam.hpp"

 //#include "../../type/pointer/dumb.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_ray
        {

         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar      T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple        T_ray;

           public:
                      GC__pure();
             virtual ~GC__pure();

           public:
             virtual void Fv_trace( T_color & P_color, T_ray const& P_ray )=0;

          };

       }
     }
   }
 }

#endif
