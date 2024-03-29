#ifndef Dh_DDMRM_Iceray_material_compute_illumination_phong_HPP_
 #define Dh_DDMRM_Iceray_material_compute_illumination_phong_HPP_

 #include <tuple>
 #include <limits>

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

           class GC_phong
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction T_instruction;

               enum Ee_output{ En_outColor_result=0 };

               enum Ee_input
                {
                 En_inColor_Specular=0, En_inColor_Shininess=1,
                 En_inSize_SpotBegin=0 ,En_inSize_SpotEnd=1,
               //En_inSize_RayCount=1, En_inRay_Start
                };

             public:
               GC_phong
                (
                  T_size const& P_result      = 0
                 ,T_size const& P_inSize_SpotBegin  = 0
                 ,T_size const& P_inSize_SpotEnd    = 1
                 ,T_size const& P_specular    = 0
                 ,T_size const& P_shininess   = 1
                )
                {
                 F_output<T_color>( En_outColor_result,     P_result );

                 F_input<T_size>(   En_inSize_SpotBegin,    P_inSize_SpotBegin   );
                 F_input<T_size>(   En_inSize_SpotEnd,      P_inSize_SpotEnd     );
                 F_input<T_color>(  En_inColor_Specular,    P_specular   );
                 F_input<T_color>(  En_inColor_Shininess,   P_shininess  );

               //F_input<T_size>(     En_inSize_RayCount,     P_rayCount   );
               //F_input<T_size>(     En_inSize_RayStart,     P_rayStart   );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
               //T_coord const& I_point     = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Point     ) );
               //T_coord const& I_normal    = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal    ) );
                 T_size         I_spotBegin  = M2_memorySize->Fv_load(  F_input<T_size>( En_inSize_SpotBegin  ) );
                 T_size         I_spotEnd    = M2_memorySize->Fv_load(  F_input<T_size>( En_inSize_SpotEnd    ) );
                 T_color const& I_specular  = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Specular  ) );
                 T_color const& I_shininess = M2_memoryColor->Fv_load( F_input<T_color>( En_inColor_Shininess ) );

                 T_size  const& I_rayCount = P_next.Fv_size(); //M2_memorySize->Fv_load(  F_input<T_ray>( En_inSize_RayCount ) );
               //T_size  const& I_rayStart = M2_memorySize->Fv_load(  F_input()[ T_memory::En_size  ][ En_inSize_RayStart ] );


                 GS_DDMRM::S_IceRay::S_material::S_illumination::GC_phong I_phong( I_specular, I_shininess );

                 T_color I_summae( ::color::constant::black_t{} );
                 T_color I_color;
                 T_coord I_2light;
                 T_color I_energy;

                 for( T_size I_spotIndex = I_spotBegin; I_spotIndex < I_spotEnd; ++I_spotIndex )
                  {
                   T_spot const& I_spot = M2_memorySpot->Fv_load( I_spotIndex );

                   for( T_size I_rayIndex = 0; I_rayIndex < I_rayCount; ++I_rayIndex )
                    {
                     auto const& I_ray = P_next.Fv_get( I_rayIndex );
                     T_coord const& I_origin = I_ray.M_origin;

                     I_spot.F_energy( I_energy, I_origin );
                     ::math::linear::vector::subtraction( I_2light, I_spot.F_center(), I_origin );
                     ::math::linear::vector::length( I_2light , T_scalar(1) );

                     if( true == I_phong.F_process( I_color, I_energy, I_ray.M_direction, I_2light ) )
                      {
                       I_color *= I_ray.M_coefficient;
                       ::color::operation::multiply( I_color, I_ray.M_intesity );
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

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_spot>    T2_memorySpot;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                 T_instruction::Fv_memory( P_memory );
                 M2_memorySize   = P_memory->F_get<T_size>();

                 M2_memoryColor  = P_memory->F_get<T_color>(   );

                 M2_memorySpot   = P_memory->F_get<T_spot>( );
                }

             private:
               T2_memorySize     *M2_memorySize;
               T2_memoryColor    *M2_memoryColor;

               T2_memorySpot     *M2_memorySpot;
            };

          }
        }
      }
    }
  }

#endif
