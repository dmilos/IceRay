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
                   ,En_inSize_Begin
                   ,En_inSize_End
                  };

                 enum Ee_output
                  {
                    //En_outCoord_Correct = 2
                  };

               public:
                 GC_corrector
                  (
                    T_size const& P_inCoord_Normal  = 1
                   ,T_size const& P_inCoord_Bump    = 2
                   ,T_size const& P_inBegin = 2   //!< TODO put propery numbers;
                   ,T_size const& P_inEnd = 2     //!< TODO put propery numbers;
                  )
                  { // TODO
                   F_input<T_coord>(    En_inCoord_Normal,   P_inCoord_Normal   );
                   F_input<T_coord>(    En_inCoord_Bump ,    P_inCoord_Bump     );
                   F_input<T_size>(     En_inSize_Begin ,    P_inBegin     );
                   F_input<T_size>(     En_inSize_End ,      P_inEnd     );
                   //F_output<T_coord>(  En_outCoord_Correct, P_inCorrect  );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {

                   T_coord  const& I_normal   = M2_memoryCoord->Fv_load( F_input<T_coord>(  En_inCoord_Normal ) );
                   T_coord  const& I_bump     = M2_memoryCoord->Fv_load( F_input<T_coord>(  En_inCoord_Bump   ) );
                   T_size  const& I_begin     = M2_memorySize->Fv_load( F_input<T_size>(    En_inSize_Begin   ) );
                   T_size  const& I_end       = M2_memorySize->Fv_load( F_input<T_size>(    En_inSize_End     ) );

                   T_coord I_correct = I_bump;

                   T_scalar I_dot = ::math::linear::vector::dot( P_intersect.M_incoming.M_direction, I_bump );

                   if( 0 < I_dot )
                    {
                     // TODO I_correct = f( I_bump );
                    }

                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>     T2_memorySize;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>    T2_memoryCoord;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize    = dynamic_cast<T2_memorySize  *>( P_memory->F_get<T_size>()  );
                   M2_memoryCoord   = dynamic_cast<T2_memoryCoord *>( P_memory->F_get<T_coord>() );
                  }
               private:
                 T2_memorySize      *M2_memorySize;
                 T2_memoryCoord     *M2_memoryCoord;
              };

          }
        }
      }
    }
  }

#endif
