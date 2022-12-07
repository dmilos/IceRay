#ifndef Dh_DDMRM_Iceray_material_compute_transmission_correct_direction_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_correct_direction_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::GC_corrector

#include "../instruction.hpp"

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

             class GC_direction  //!< if ray is out of cone bring it back
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                    En_inCoord_Normal = 1
                   ,En_inSize_Leader  = 0
                   ,En_inSize_Count   = 1
                   ,En_inScalar_Angle = 0
                  };

                 enum Ee_output
                  {
                    //En_outCoord_Correct = 2
                  };

               public:
                 GC_direction
                  (
                    T_size const& P_inCoord_Normal // = 1
                   ,T_size const& P_inLeader       // = 0
                   ,T_size const& P_inCount        // = 1
                   ,T_size const& P_inAngle        // = 0
                  )
                  { // TODO
                   F_input<T_coord>(   En_inCoord_Normal,  P_inCoord_Normal );
                   F_input<T_size>(    En_inSize_Leader,   P_inLeader       );
                   F_input<T_size>(    En_inSize_Count,    P_inCount        );
                   F_input<T_scalar>(  En_inScalar_Angle,  P_inAngle        );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord  const& I_normal   = M2_memoryCoord->Fv_load(  F_input<T_coord >( En_inCoord_Normal ) );
                   T_size   const& I_leader   = M2_memorySize->Fv_load(   F_input<T_size  >( En_inSize_Leader  ) );
                   T_size   const& I_count    = M2_memorySize->Fv_load(   F_input<T_size  >( En_inSize_Count   ) );
                   T_scalar const& I_angle    = M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_Angle ) );

                   auto      & I_heading = P_next.Fv_expose( I_leader );

                   T_coord I_y = I_heading.M_direction;
                   T_coord I_x; ::math::linear::vector::cross( I_x, I_y, I_normal ); ::math::linear::vector::length( I_x, T_scalar( 1 ) );
                   T_coord I_z; ::math::linear::vector::cross( I_z, I_x, I_y );      ::math::linear::vector::length( I_z, T_scalar( 1 ) );
                   auto I_bounce = ::math::linear::vector::angle( I_heading.M_direction, I_normal );
                   if( ::math::geometry::deg2rad( 90 ) < I_bounce )
                    {
                     I_bounce = ::math::geometry::deg2rad( 180 ) - I_bounce;
                    }

                   for( T_size I_index=1; I_index < I_count; ++I_index )
                    {
                     auto      & I_current = P_next.Fv_expose( I_leader );
                     auto I_A = ::math::linear::vector::angle( I_y, I_current.M_direction );
                     if( I_A < I_angle )
                      {
                       continue;
                      }
                     // TODO
                    }

                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>     T2_memorySize;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>  T2_memoryScalar;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>    T2_memoryCoord;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize    = P_memory->F_get<T_size>();
                   M2_memoryScalar = P_memory->F_get<T_scalar>();
                   M2_memoryCoord   = P_memory->F_get<T_coord>();
                  }
               private:
                 T2_memorySize      *M2_memorySize;
                 T2_memoryScalar   *M2_memoryScalar;
                 T2_memoryCoord     *M2_memoryCoord;
              };

            }
          }
        }
      }
    }
  }

#endif
