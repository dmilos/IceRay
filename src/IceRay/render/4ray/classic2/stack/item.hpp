#ifndef Dh_DDMRM_Iceray_render_ray_classic2_beam__item_HPP_
 #define Dh_DDMRM_Iceray_render_ray_classic2_beam__item_HPP_

 #include "../../../../type/ray/trace.hpp"
 #include "../../../../geometry/_type/state.hpp"
 #include "../../../../material/intersect.hpp"





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

             class GC_item
              : public GS_DDMRM::S_IceRay::S_material::GC_intersect
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state    T_state;
                 typedef GS_DDMRM::S_IceRay::S_type::GT_size                  T_size;
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace          T_ray;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar       T_coord;
              };

            }
          }
        }
      }
    }
  }

#endif