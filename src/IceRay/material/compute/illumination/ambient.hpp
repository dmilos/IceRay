#ifndef Dh_DDMRM_Iceray_material_compute_illumination_ambient_HPP_
 #define Dh_DDMRM_Iceray_material_compute_illumination_ambient_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_ambient

 #include <limits>

 #include "../../illumination/ambient.hpp"
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

             class GC_ambient
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
                   En_inColor_Emission = 0
                  };

                 enum Ee_output
                  {
                   En_outColor_result=0
                  };

               public:
                 GC_ambient
                  (
                    T_size const& P_result   = 0
                   ,T_size const& P_emission = 0
                  )
                  {
                   F_output<T_color>( En_outColor_result,   P_result );
                   F_input<T_color>(  En_inColor_Emission,  P_emission );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_color const& I_emission = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Emission ) );

                   GS_DDMRM::S_IceRay::S_material::S_illumination::GC_ambient I_ambient( I_emission );

                   T_color I_summae( ::color::constant::black_t{} );
                   T_color I_color;

                   I_ambient.F_process( I_color );

                   I_summae += I_color;

                   M2_memoryColor->Fv_store( F_output<T_color>( En_outColor_result ), I_summae );
                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_color >  T2_memoryColor;
               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memoryColor  = dynamic_cast<T2_memoryColor* >( P_memory->F_get<T_color>(   ) );
                  }

               private:
                 T2_memoryColor    *M2_memoryColor;
             };

          }
        }
      }
    }
  }

#endif
