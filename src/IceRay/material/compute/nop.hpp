#ifndef Dh_DDMRM_Iceray_material_compute_NOP_HPP_
 #define Dh_DDMRM_Iceray_material_compute_NOP_HPP_









 #include "./instruction.hpp"


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_material
     {
      namespace S_compute
       {

        class GC_nop
         : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
         {
          public:

            typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

            enum Ee_input
             {
             };
            enum Ee_output
             {
             };

          public:
            GC_nop
             (
             )
             {
             }

          public:
            bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
             {
              return true;
             }

          public:
            void    Fv_memory( T_memory * P_memory  )
             {
              F1_memory() = P_memory;
             }

         };

       }
     }
   }
 }

#endif
