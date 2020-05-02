#ifndef Dh_DDMRM_Iceray_material_compute_illumination_AshikhminShirley_diffuse_HPP_
 #define Dh_DDMRM_Iceray_material_compute_illumination_AshikhminShirley_diffuse_HPP_

 #include <tuple>
 #include <limits>

 #include "../../illumination/AshikhminShirley/diffuse.hpp"
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
           namespace S_AshikhminShirley
            {

             class GC_diffuse
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
                   En_inCoord_Point = 0, En_inCoord_Normal = 1,
                   En_inColor_Diffuse = 0,  En_inColor_Specular = 1,
                   En_inSize_SpotBegin = 0, En_inSize_SpotEnd = 1
                  };
                 enum Ee_output{ En_outColor_result=0 };

               public:
                 GC_diffuse
                  (
                    T_size const& P_result      = 0
                   ,T_size const& P_inCoord_Point    = 0
                   ,T_size const& P_inCoord_Normal   = 1
                   ,T_size const& P_inSize_SpotBegin = 0
                   ,T_size const& P_inSize_SpotEnd   = 1
                   ,T_size const& P_diffuse     = 1
                   ,T_size const& P_specular    = 1
                  )
                  {
                   F_input<T_coord>( En_inCoord_Point,      P_inCoord_Point      );
                   F_input<T_coord>( En_inCoord_Normal,     P_inCoord_Normal     );
                   F_input<T_size>(   En_inSize_SpotBegin,  P_inSize_SpotBegin   );
                   F_input<T_size>(   En_inSize_SpotEnd,    P_inSize_SpotEnd     );
                   F_input<T_color>( En_inColor_Diffuse,    P_diffuse    );
                   F_input<T_color>( En_inColor_Specular,   P_specular   );

                   F_output<T_color>( En_outColor_result,     P_result );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   auto const&  I_incoming = P_intersect.M_incoming;

                   T_coord const& I_point     = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Point    ) );
                   T_coord const& I_normal    = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal   ) );
                   T_size         I_spotBegin  = M2_memorySize->Fv_load(  F_input<T_size>( En_inSize_SpotBegin  ) );
                   T_size         I_spotEnd    = M2_memorySize->Fv_load(  F_input<T_size>( En_inSize_SpotEnd ) );
                   T_color const& I_diffuse   = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Diffuse  ) );
                   T_color const& I_specular  = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Specular ) );


                   GS_DDMRM::S_IceRay::S_material::S_illumination::S_AshikhminShirley::GC_diffuse I_asd( I_diffuse, I_specular );

                   T_color I_summae( ::color::constant::black_t{} );
                   T_color I_color;
                   T_coord I_2light;
                   T_color I_energy;
                   T_coord I_2viewer; ::math::linear::vector::negate( I_2viewer, I_incoming.M_direction );

                   for( T_size I_spotIndex = I_spotBegin; I_spotIndex < I_spotEnd; ++I_spotIndex )
                    {
                     T_spot const& I_spot = M2_memorySpot->Fv_load( I_spotIndex );
                     I_spot.F_energy( I_energy, I_point );

                      ::math::linear::vector::subtraction( I_2light, I_spot.F_center(), I_point );
                     ::math::linear::vector::length( I_2light , T_scalar(1) );
                     if( true == I_asd.F_process( I_color, I_normal, I_2light, I_2viewer ) )
                      {
                       ::color::operation::multiply( I_color, I_energy );
                       I_summae += I_color;
                      }
                    }

                   M2_memoryColor->Fv_store( F_output<T_color>( En_outColor_result ), I_summae );
                   return true;
                  }


               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>    T2_memorySize;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_color >  T2_memoryColor;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord >  T2_memoryCoord;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_spot>    T2_memorySpot;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize   = dynamic_cast<T2_memorySize * >( P_memory->F_get<T_size>(  ) );
                   M2_memoryColor  = dynamic_cast<T2_memoryColor* >( P_memory->F_get<T_color>( ) );
                   M2_memoryCoord  = dynamic_cast<T2_memoryCoord* >( P_memory->F_get<T_coord>( ) );

                   M2_memorySpot   = dynamic_cast<T2_memorySpot * >( P_memory->F_get( T_memory::En_spot    ) );
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
