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
           namespace S_correct
            {

             class GC_cone  //!< (re)calculate max angle depend on normal and bump
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                    En_inCoord_Normal = 1
                   ,En_inCoord_Bump   = 0
                   ,En_inScalar_Angle = 0
                  };

                 enum Ee_output
                  {
                    En_outScalar_Angle = 1
                  };

               public:
                 GC_cone
                  (
                    T_size const& P_inCoord_Normal // = 1
                   ,T_size const& P_inCoord_Bump   // = 2
                   ,T_size const& P_inAngle        // = 0
                   ,T_size const& P_outAngle       // = 0
                  )
                  {
                   F_input<T_coord>(   En_inCoord_Normal,  P_inCoord_Normal );
                   F_input<T_coord>(   En_inCoord_Bump,    P_inCoord_Bump   );
                   F_input<T_scalar>(  En_inScalar_Angle,  P_inAngle        );

                   //F_output<T_scalar>( En_outScalar_Angle,     P_outAngle );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord  const& I_normal = M2_memoryCoord->Fv_load(  F_input<T_coord >( En_inCoord_Normal ) );
                   T_coord  const& I_bimp   = M2_memoryCoord->Fv_load(  F_input<T_coord >( En_inCoord_Bump   ) );
                   T_scalar const& I_angle  = M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_Angle ) );

                   M2_memoryScalar->Fv_store( F_output<T_scalar>( En_outScalar_Angle ), 0.0/*TODO*/ );
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
                   M2_memoryScalar = P_memory->F_get<T_scalar>();
                   M2_memoryCoord   = P_memory->F_get<T_coord>();
                  }
               private:
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
