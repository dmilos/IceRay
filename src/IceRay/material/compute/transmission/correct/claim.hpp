#ifndef Dh_DDMRM_Iceray_material_compute_transmission_correct_claim_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_correct_claim_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_correct::GC_claim

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

             class GC_claim  //!< claim everything outside of cone
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                    En_inCoord_Normal = 1
                   ,En_inSize_Count   = 1
                   ,En_inSize_Leader  = 0
                  };

                 enum Ee_output
                  {
                    //En_outCoord_Correct = 2
                  };

               public:
                 GC_claim
                  (
                    T_size const& P_inCoord_Normal // = 1
                   ,T_size const& P_inSizeCount    // = 1
                   ,T_size const& P_inRayLeader    // = 0
                  )
                  {
                   F_input<T_coord>(   En_inCoord_Normal,  P_inCoord_Normal );
                   F_input<T_size>(    En_inSize_Count,    P_inSizeCount    );
                   F_input<T_size>(    En_inSize_Leader,   P_inRayLeader    );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord  const& I_normal   = M2_memoryCoord->Fv_load(  F_input<T_coord >( En_inCoord_Normal ) );
                   T_size   const& I_count    = M2_memorySize->Fv_load(   F_input<T_size  >( En_inSize_Count   ) );
                   T_size   const& I_leader   = M2_memorySize->Fv_load(   F_input<T_size  >( En_inSize_Leader  ) );

                   for( T_size I_index = I_leader; I_index < I_leader+I_count; ++I_index )
                    {
                     auto      & I_current = P_next.Fv_expose( I_index );
                     if( I_current.M_status == T_ray::Ee_status::En_abandoned )
                      {
                       continue;
                      }
                     auto I_A = ::math::linear::vector::angle( I_current.M_direction, I_normal );
                     if( I_A < math::geometry::deg2rad(90) )
                      { // DEBUG I_current.M_coefficient = 0.5;
                       continue;  
                      }
                     ::math::linear::vector::reflect( I_current.M_direction, I_current.M_direction, I_normal );
                     // DEBUG I_current.M_coefficient = 0;
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
