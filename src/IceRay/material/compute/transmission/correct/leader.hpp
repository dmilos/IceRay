#ifndef Dh_DDMRM_Iceray_material_compute_transmission_correct_leader_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_correct_leader_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::GC_corrector

#include "../../instruction.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_transmission
          {
           namespace S_correct
            {

             class GC_leader  //!< correct leader to match cone angle
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                    En_inCoord_Normal = 1
                   ,En_inScalar_Angle = 0
                   ,En_inSize_Leader = 0
                  };

                 enum Ee_output
                  {
                  };

               public:
                 GC_leader
                  (
                    T_size const& P_inCoord_Normal // = 1
                   ,T_size const& P_inAngle        // = 0
                   ,T_size const& P_inLeader       // = 2
                  )
                  {
                   F_input<T_coord>(   En_inCoord_Normal, P_inCoord_Normal );
                   F_input<T_scalar>(  En_inScalar_Angle, P_inAngle        );
                   F_input<T_size>(    En_inSize_Leader,  P_inLeader       );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord  const& I_normal   = M2_memoryCoord->Fv_load(  F_input<T_coord >( En_inCoord_Normal ) );
                   T_scalar const& I_angle    = M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_Angle ) );
                   T_size   const& I_leader   = M2_memorySize->Fv_load(   F_input<T_size >( En_inSize_Leader ) );

                   auto      & I_original = P_next.Fv_expose( I_leader );
                   auto      & I_direction = I_original.M_direction;

                   auto I_decline = ::math::linear::vector::angle( I_direction, I_normal );

                   auto I_delta = I_angle - (::math::geometry::deg2rad( 90 ) - I_decline );
                   if( 0 < I_delta )
                    {
                     T_coord I_y = I_direction;
                     T_coord I_x; ::math::linear::vector::cross( I_x, I_y, I_normal ); ::math::linear::vector::length( I_x, T_scalar( 1 ) );
                     T_coord I_z; ::math::linear::vector::cross( I_z, I_x, I_y );      ::math::linear::vector::length( I_z, T_scalar( 1 ) );

                     ::math::linear::vector::combine( I_direction, cos( I_delta ), I_y, sin( I_delta ), I_z );
                    }

                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>     T2_memorySize;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>   T2_memoryScalar;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>    T2_memoryCoord;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize    = P_memory->F_get<T_size>();
                   M2_memoryScalar  = P_memory->F_get<T_scalar>();
                   M2_memoryCoord   = P_memory->F_get<T_coord>();
                  }
               private:
                 T2_memorySize      *M2_memorySize;
                 T2_memoryScalar    *M2_memoryScalar;
                 T2_memoryCoord     *M2_memoryCoord;
              };

            }
          }
        }
      }
    }
  }

#endif
