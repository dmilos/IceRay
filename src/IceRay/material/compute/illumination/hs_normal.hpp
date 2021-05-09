#ifndef Dh_DDMRM_Iceray_material_compute_illumination_HeidrichSeidel_normal_HPP_
 #define Dh_DDMRM_Iceray_material_compute_illumination_HeidrichSeidel_normal_HPP_

 #include <tuple>
 #include <limits>

 #include "../../illumination/HeidrichSeidel/normal.hpp"
 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_illumination
          {
           namespace S_HeidrichSeidel
            {

             class GC_normal
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
                 typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                   En_inCoord_Groove = 2,
                   En_inCoord_Normal = 1
                  };
                 enum Ee_output{ En_outCoord_result=0 };

               public:
                 GC_normal
                  (
                    T_size const& P_result  = 0

                   ,T_size const& P_normal  = 1
                   ,T_size const& P_groove  = 2
                  )
                  {
                   F_output<T_coord>(  En_outCoord_result,  P_result );

                   F_input<T_coord>(    En_inCoord_Normal,  P_normal );
                   F_input<T_coord>(    En_inCoord_Groove,  P_groove );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord const& I_groove    = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord ][ En_inCoord_Groove    ] );
                   T_coord const& I_normal    = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord ][ En_inCoord_Normal    ] );

                   GS_DDMRM::S_IceRay::S_material::S_illumination::S_HeidrichSeidel::GC_normal I_HeidrichSeidel( I_groove );

                   T_coord I_T;
                   I_HeidrichSeidel.F_process( I_T, I_normal );

                   M2_memoryCoord->Fv_store( F_output<T_coord>( En_outCoord_result ), I_T );
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
  }

#endif
