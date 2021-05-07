#ifndef Dh_DDMRM_Iceray_material_compute_illumination_CookTorrance_fresnel_HPP_
 #define Dh_DDMRM_Iceray_material_compute_illumination_CookTorrance_fresnel_HPP_

 #include <tuple>
 #include <limits>

 #include "../../illumination/CookTorrance/fresnel.hpp"
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
           namespace S_CookTorrance
            {

             class GC_fresnel
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
                   En_inSize_SpotBegin=0, En_inSize_SpotEnd=1,
                   En_inCoord_Point=0, En_inCoord_Normal=1
                  };
                 enum Ee_output{ En_outColor_result=0 };

               public:
                 GC_fresnel
                  (
                    T_size const& P_result     = 0
                   ,T_size const& P_inCoord_Point      = 0
                   ,T_size const& P_inCoord_Normal     = 1
                   ,T_size const& P_inSize_SpotBegin  = 0
                   ,T_size const& P_inSize_SpotEnd  = 0
                  )
                  {
                   F_output<T_color>( En_outColor_result,     P_result );

                   F_input<T_coord>( En_inCoord_Point,     P_inCoord_Point );
                   F_input<T_coord>( En_inCoord_Normal,    P_inCoord_Normal );
                   F_input<T_size>(   En_inSize_SpotBegin,  P_inSize_SpotBegin   );
                   F_input<T_size>(   En_inSize_SpotEnd,    P_inSize_SpotEnd     );

                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   auto const&  I_incoming = P_intersect.M_incoming;

                   T_coord const& I_point      = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord ][ En_inCoord_Point     ] );
                   T_coord const& I_normal     = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord ][ En_inCoord_Normal    ] );
                   T_size         I_spotBegin  = M2_memorySize->Fv_load(  F_input<T_size>( En_inSize_SpotBegin ) );
                   T_size         I_spotEnd    = M2_memorySize->Fv_load(  F_input<T_size>( En_inSize_SpotEnd ) );

                   T_color I_summae( ::color::constant::black_t{} );
                   // TODO

                   M2_memoryColor->Fv_store( F_output<T_color>( En_outColor_result ), I_summae );
                   return true;
                  }


               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>    T2_memorySize;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_color >  T2_memoryColor;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>   T2_memoryCoord;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_spot>    T2_memorySpot;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize   = P_memory->F_get<T_size>();
                   M2_memoryCoord  = P_memory->F_get<T_coord>( );
                   M2_memoryColor  = P_memory->F_get<T_color>(   );
                   M2_memorySpot   = P_memory->F_get<T_spot>( );
                  }

               private:
                 T2_memorySize     *M2_memorySize;
                 T2_memoryColor    *M2_memoryColor;
                 T2_memoryCoord    *M2_memoryCoord;
                 T2_memorySpot     *M2_memorySpot;
             };


            }
          }
        }
      }
    }
  }

#endif
