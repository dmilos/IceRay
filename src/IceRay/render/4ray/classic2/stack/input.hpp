#ifndef Dh_DDMRM_Iceray_render_ray_classic2_stack__input_HPP_
 #define Dh_DDMRM_Iceray_render_ray_classic2_stack__input_HPP_

// GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__input

 #include "./item.hpp"

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

             class GC__input
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_trace         T_ray;
                 typedef GS_DDMRM::S_IceRay::S_type::GT_size                 T_size;
                 typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state   T_state;

               public:
                          GC__input(){}
                 virtual ~GC__input(){}

               public:
                 virtual T_size const&   Fv_size( )const=0;
                 virtual T_ray  const&   Fv_get( T_size const& P_index )const=0;
                 virtual T_ray       &   Fv_expose( T_size const& P_index )=0;
                 virtual T_ray       &   Fv_top()=0;
                 virtual T_ray  const&   Fv_top()const=0;
              };

            }
          }
        }
      }
    }
  }

#endif