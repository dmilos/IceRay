#ifndef _DDMRM_IceRay_render_ray_classic2_stack_implementation_hpp_
 #define _DDMRM_IceRay_render_ray_classic2_stack_implementation_hpp_

 #include "../../../../type/basic/size.hpp"
 #include "../../../../type/basic/integer.hpp"

 #include "../../../../geometry/_type/manager.hpp"


 #include "./data.hpp"

 #include "./input.hpp"
 #include "./output.hpp"
 #include "./stack.hpp"
 #include "./beam.hpp"

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

             class GC_implementation
              : public GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC_data
              , public GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__beam
              , public GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__stack
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::GT_int8   T_uint8;
                 typedef GS_DDMRM::S_IceRay::S_type::GT_uint64   T_uint64;

                 //typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_state           T_ray;


                 typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC_data T_data;

                 typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state       T_state;
                 typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GT_allocator   T_allocator;

                 typedef  GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__input   T__input;
                 typedef  GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__output  T__output;
                 typedef  GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__beam    T__beam;
                 typedef  GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::S_stack::GC__stack   T__stack;

               public:
                 GC_implementation();
                ~GC_implementation();

               public:  // Stack
                 T__stack::T_accident      & Fv_topAccident( )override;
                 T__stack::T_accident const& Fv_topAccident( )const override;

               public:  // Input
                 T__input::T_ray       & Fv_top( )override;
                 T__input::T_ray  const& Fv_top( )const override;
                 T__input::T_ray  const& Fv_get( T_size const& P_index )const override;
                 T__input::T_ray       & Fv_expose( T_size const& P_index )override;

                 void                    Fv_pop()override;
                 T_size const&           Fv_occupancy( )const override;
                 void                    Fv_reserve( T_size const& P_capacity ) override;

               public: // Input
                 T_size const&           Fv_size( )const override;

               public: // Output
                 void Fv_push()override;

               public:
                 void F_clear();

               public:
                  T_size   const&  F_index()const{ return M2_index; }
                  void             Fv_mark()
                   {
                    M2_index = 0; 
                   }
               private:
                 T_size M2_index=0;

               public:
                 T_uint64 F_total()const{ return M2_total; }
               private:
                 T_uint64 M2_total=0;
              };
            }
          }
        }
      }
    }
  }

#endif
