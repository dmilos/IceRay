#ifndef Dh_DDMRM_Iceray_render_ray_classic2_beam__stack_HPP_
 #define Dh_DDMRM_Iceray_render_ray_classic2_beam__stack_HPP_

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

             class GC__stack
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC_item T_accident;
                 typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;

                          GC__stack(){}
                 virtual ~GC__stack(){}

               public:
                 virtual T_accident      &   Fv_topAccident()=0;
                 virtual T_accident const&   Fv_topAccident()const=0;

               //virtual void            Fv_clear() = 0;
                 virtual void            Fv_pop() = 0;
                 virtual T_size const&   Fv_occupancy()const=0;
                 virtual void            Fv_reserve( T_size const& P_capacity )=0;

                 virtual void            Fv_mark()=0;
              };

            }
          }
        }
      }
    }
  }

#endif