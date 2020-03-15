#ifndef Dh_DDMRM_Iceray_material_compute_transmission_corrector_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_corrector_HPP_

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

             class GC_corrector
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                    En_inCoord_Normal = 0
                   ,En_inCoord_Bump   = 1
                  };

                 enum Ee_output
                  {
                    En_outCoord_Correct = 2
                  };

               public:
                 GC_corrector
                  (
                    T_size const& P_inNormal  = 1
                   ,T_size const& P_inBump    = 2
                   ,T_size const& P_inCorrect = 2
                  )
                  {
                   F_input<T_coord>(    En_inCoord_Normal,   P_inNormal   );
                   F_input<T_coord>(    En_inCoord_Bump ,    P_inBump     );
                   F_output<T_coord>(  En_outCoord_Correct, P_inCorrect  );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {

                   T_coord  const& I_normal         = M2_memoryCoord->Fv_load( F_input<T_coord>(  En_inCoord_Normal       ) );
                   T_coord  const& I_bump          = M2_memoryCoord->Fv_load( F_input<T_coord>(  En_inCoord_Bump       ) );

                   T_coord I_correct = I_bump;

                   T_scalar I_dot = ::math::linear::vector::dot( P_intersect.M_incoming.M_direction, I_bump );

                   if( 0 < I_dot )
                    {
                     // TODO I_correct = f( I_bump );
                    }

                   M2_memoryCoord->Fv_store( F_output<T_coord>( En_outCoord_Correct ), I_correct );

                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>    T2_memoryCoord;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memoryCoord   = dynamic_cast<T2_memoryCoord * >( P_memory->F_get<T_coord>() );
                  }
               private:
                 T2_memoryCoord     *M2_memoryCoord;
              };

          }
        }
      }
    }
  }

#endif
