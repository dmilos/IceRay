#ifndef Dh_DDMRM_Iceray_material_compute_illumination_HeidrichSeidel_Phong_HPP_
 #define Dh_DDMRM_Iceray_material_compute_illumination_HeidrichSeidel_Phong_HPP_

 #include <tuple>
 #include <limits>

 #include "../../illumination/HeidrichSeidel/phong.hpp"
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

             class GC_Phong
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
                   En_inSize_LightCount=0,
                   En_inColor_Specular =0, En_inColor_Shininess=1,
                   En_inCoord_Point =0, En_inCoord_Normal=1, En_inCoord_Groove = 2
                  };
                 enum Ee_output{ En_outColor_result=0 };

               public:
                 GC_Phong
                  (
                    T_size const& P_point      = 0
                   ,T_size const& P_normal     = 1
                   ,T_size const& P_lightCount = 0
                   ,T_size const& P_specular   = 0
                   ,T_size const& P_shininess  = 1
                   ,T_size const& P_groove     = 2
                   ,T_size const& P_result     = 0
                  )
                  {
                   F_input<T_coord>( En_inCoord_Point,     P_point );
                   F_input<T_coord>( En_inCoord_Normal,    P_normal );
                   F_input<T_size>(  En_inSize_LightCount, P_lightCount );

                   F_input<T_color>(    En_inColor_Specular,    P_specular );
                   F_input<T_color>(    En_inColor_Shininess,   P_shininess );

                   F_input<T_coord>(    En_inCoord_Groove,      P_groove );

                   F_output<T_color>( En_outColor_result,     P_result );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {


                   auto const&  I_incoming = P_intersect.M_incoming;
                   T_color const& I_specular  = M2_memoryColor->Fv_load( F_input()[ T_memory::En_color ][ En_inColor_Specular  ] );
                   T_color const& I_shininess = M2_memoryColor->Fv_load( F_input()[ T_memory::En_color ][ En_inColor_Shininess ] );
                   T_coord const& I_point     = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord ][ En_inCoord_Point     ] );
                   T_coord const& I_normal    = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord ][ En_inCoord_Normal    ] );
                   T_coord const& I_groove    = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord ][ En_inCoord_Groove    ] );
                   T_size         I_count     = M2_memorySize->Fv_load(  F_input()[ T_memory::En_size  ][ En_inSize_LightCount ] );

                   GS_DDMRM::S_IceRay::S_material::S_illumination::S_HeidrichSeidel::GC_phong I_HeidrichSeidel( I_specular, I_shininess, I_groove );

                   T_color I_summae( ::color::constant::black_t{} );
                   T_color I_color;
                   T_coord I_2light;
                   T_color I_energy;

                   for( T_size I_lightIndex=0; I_lightIndex < I_count; ++I_lightIndex )
                    {
                     T_spot const& I_spot = M2_memorySpot->Fv_load( I_lightIndex );
                     I_spot.F_energy( I_energy, I_point );
                      ::math::linear::vector::subtraction( I_2light, I_spot.F_center(), I_point );
                     ::math::linear::vector::length( I_2light, T_scalar(1) );

                     if( true == I_HeidrichSeidel.F_process( I_color, I_energy, I_2light, I_normal, I_incoming.M_direction ) )
                      {
                       I_summae += I_color;
                      }
                    }

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
                   M2_memorySize   = dynamic_cast<T2_memorySize * >( P_memory->F_get<T_size>(    ) );
                   M2_memoryCoord  = dynamic_cast<T2_memoryCoord* >( P_memory->F_get( T_memory::En_coord3D ) );
                   M2_memoryColor  = dynamic_cast<T2_memoryColor* >( P_memory->F_get<T_color>(   ) );
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
