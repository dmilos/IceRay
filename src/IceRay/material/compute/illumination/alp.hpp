#ifndef Dh_DDMRM_Iceray_material_compute_illumination_AmbientLambertPhong_HPP_
 #define Dh_DDMRM_Iceray_material_compute_illumination_AmbientLambertPhong_HPP_

 #include <tuple>
 #include <limits>

 #include "../../illumination/ambient.hpp"
 #include "../../illumination/lambert.hpp"
 #include "../../illumination/phong.hpp"
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

             class GC_AmbientLambertPhong
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
                 typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_output
                  {
                   En_outColor_result=0
                  };
                 enum Ee_input
                  {
                   En_inCoord_Point = 0, En_inCoord_Normal = 1,
                   En_inColor_Emission = 0,
                   En_inColor_Diffuse = 1,
                   En_inColor_Specular=2, En_inColor_Shininess=3,
                   En_inSize_SpotCount=0, En_inSpot_Begin=0,
                  };

               public:
                 GC_AmbientLambertPhong
                  (
                    T_size const& P_result      = 0
                   ,T_size const& P_point       = 0
                   ,T_size const& P_normal      = 1
                   ,T_size const& P_emission    = 0
                   ,T_size const& P_diffuse     = 1
                   ,T_size const& P_specular    = 2
                   ,T_size const& P_shininess   = 3
                   ,T_size const& P_spotCount   = 0
                   ,T_size const& P_spotBegin   = 0
                  )
                  {
                   F_output<T_color>( En_outColor_result,    P_result );

                   F_input<T_coord>( En_inCoord_Point,     P_point );
                   F_input<T_coord>( En_inCoord_Normal,    P_normal );

                   F_input<T_color>(    En_inColor_Emission,  P_emission );

                   F_input<T_color>(    En_inColor_Diffuse,   P_diffuse    );

                   F_input<T_color>(    En_inColor_Specular,    P_specular   );
                   F_input<T_color>(    En_inColor_Shininess,   P_shininess  );

                   F_input<T_size>(     En_inSize_SpotCount,   P_spotCount );
                   F_input<T_spot>(     En_inSpot_Begin,       P_spotBegin );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord const& I_point   = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Point  ) );
                   T_coord const& I_normal  = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal ) );


                   T_color const& I_emission = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Emission ) );

                   T_color const& I_diffuse = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Diffuse ) );

                   T_color const& I_specular  = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Specular  ) );
                   T_color const& I_shininess = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Shininess ) );

                   T_size         I_spotCount= M2_memorySize->Fv_load(  F_input<T_size>( En_inSize_SpotCount ) );
                   T_size         I_spotBegin= M2_memorySize->Fv_load(  F_input<T_size>( En_inSpot_Begin     ) );

                   T_size  const& I_rayCount = P_next.Fv_size(); //M2_memorySize->Fv_load(  F_input()[ T_memory::En_size  ][ En_inSize_RayCount ] );


                   GS_DDMRM::S_IceRay::S_material::S_illumination::GC_ambient I_ambient( I_emission );
                   GS_DDMRM::S_IceRay::S_material::S_illumination::GC_lambert I_lambert( I_diffuse );
                   GS_DDMRM::S_IceRay::S_material::S_illumination::GC_phong I_phong( I_specular, I_shininess );

                   T_color I_summae( ::color::constant::black_t{} );
                   T_color I_color;
                   T_coord I_2light;
                   T_color I_energy;

                   I_ambient.F_process( I_color );

                   I_summae += I_color;


                   for( T_size I_lightIndex=0; I_lightIndex < I_spotCount; ++I_lightIndex )
                    {
                     T_color I_energy;
                     T_spot const& I_spot = M2_memorySpot->Fv_load( I_lightIndex );
                     I_spot.F_energy( I_energy, I_point );
                      ::math::linear::vector::subtraction( I_2light, I_spot.F_center(), I_point );
                     ::math::linear::vector::length( I_2light , T_scalar(1) );
                     if( true == I_lambert.F_process( I_color, I_energy, I_2light, I_normal ) )
                      {
                       I_summae +=I_color;
                      }

                     for( T_size I_rayIndex = 0; I_rayIndex < I_rayCount; ++I_rayIndex )
                      {
                       auto const& I_ray = P_next.Fv_get( I_rayIndex );
                       T_coord const& I_origin = I_ray.M_origin;

                       M2_memorySpot->Fv_load( I_lightIndex ).F_energy( I_energy, I_origin );
                       ::math::linear::vector::subtraction( I_2light, M2_memorySpot->Fv_load( I_lightIndex ).F_center(), I_origin );
                       ::math::linear::vector::length( I_2light , T_scalar(1) );
                       if( true == I_phong.F_process( I_color, I_energy, I_ray.M_direction, I_2light ) )
                        {
                         I_color *= I_ray.M_coefficient;
                         I_summae += I_color;
                        }
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

#endif
