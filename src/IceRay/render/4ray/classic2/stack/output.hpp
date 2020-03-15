#ifndef Dh_DDMRM_Iceray_render_ray_classic2_stack__output_HPP_
 #define Dh_DDMRM_Iceray_render_ray_classic2_stack__output_HPP_

//  GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__output

 #include "IceRay/type/ray/simple.hpp"
 #include "IceRay/geometry/_type/state.hpp"
 #include "IceRay/geometry/_type/manager.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_ray
        {
         namespace S_classic2
          {
           namespace S_stack
            {

             class GC__output
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_size                     T_size;
                 typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace             T_ray;
                 typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state       T_state;

               public:
                          GC__output(){}
                 virtual ~GC__output(){}

               public:
                 /*! Append ray to this beam*/
                 virtual  void Fv_push()=0;

                 /*! Remove top ray*/
                 virtual  void Fv_pop()=0;
             };

            }
          }
        }
      }
    }
  }

#endif