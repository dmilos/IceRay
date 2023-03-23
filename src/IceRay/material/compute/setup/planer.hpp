#ifndef Dh_DDMRM_Iceray_material_compute_Setup_PlaneReflect_HPP_
 #define Dh_DDMRM_Iceray_material_compute_Setup_PlaneReflect_HPP_

 #include <tuple>
 #include <limits>

 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_setup
          {

           class GC_PlaneReflect
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               enum Ee_output
                {
                };
               enum Ee_input
                {
                };

             public:
               GC_PlaneReflect
                (
                )
                {
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_coord const& I_direction  = P_intersect.M_incoming.M_direction;
                 T_coord const& I_normal     = P_intersect.M_intersection.M_normal;

                 using namespace GS_DDMRM::S_IceRay::S_material::S_compute::S_memory;
                 T_coord const& I_reflection = M2_memoryCoord->Fv_direct( En_inCoord3D_Dynamic_Reflected );
                 auto & I_X = M2_memoryCoord->Fv_direct( En_inCoord3D_Dynamic_Reflect_X );
                 ::math::linear::vector::cross( I_X, I_reflection, I_normal );  ::math::linear::vector::length( I_X, T_scalar(1) );
                 auto & I_Y = M2_memoryCoord->Fv_direct( En_inCoord3D_Dynamic_Reflect_Y );
                 ::math::linear::vector::cross( I_Y, I_reflection, I_X );       ::math::linear::vector::length( I_Y, T_scalar(1) );

                 return true;
                }

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>   T2_memoryCoord;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                 F1_memory() = P_memory;
                 M2_memoryCoord  = P_memory->F_get<T_coord>( );
                }

             private:
               T2_memoryCoord    *M2_memoryCoord;
            };

          }
        }
      }
    }
  }

#endif
