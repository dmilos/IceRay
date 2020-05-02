#ifndef Dh_DDMRM_Iceray_material_compute_light_swarm1_HPP_
 #define Dh_DDMRM_Iceray_material_compute_light_swarm1_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_swarmC

 #include "../../../type/basic/size.hpp"
 #include "../../../type/color.hpp"
 #include "../../../type/math/coord.hpp"
 #include "../../../light/_pure.hpp"
 #include "../../../light/type/spot.hpp"
 #include "../../../light/point.hpp"
 #include "../../../geometry/_pure/intersect.hpp"

 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_light
          {

           class GC_swarmC// Combination of GC_generator and SpotSwarm and SpotCull
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:

               typedef GS_DDMRM::S_IceRay::S_type::GT_bool               T_bool;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;

               typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;
               typedef GS_DDMRM::S_IceRay::S_light::GC__pure             T_light;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state      T_state;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory      T_memory;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction T_instruction;

               enum Ee_input
                {

                  En_inCoord_Point    = 0
                 ,En_inCoord_Normal   = 1
                 ,En_inSize_SpotBegin     = 0

                };
               enum Ee_output{ En_outSize_SpotEnd = 1 };

             public:
               explicit GC_swarmC
                (
                  T_light * P_light = nullptr
                 ,T_size const& P_outSize_SpotEnd       = 0
                 ,T_size const& P_inCoord_Point     = 0
                 ,T_size const& P_inCoord_Normal    = 0
                 ,T_size const& P_inSize_SpotEnd      = 0
               //,T_size const& P_inBool_Cull       = 0
                )
               :M2_light( P_light )
                {
                 F_output<T_size>( En_outSize_SpotEnd,    P_outSize_SpotEnd );


                 F_input<T_coord>( En_inCoord_Point,      P_inCoord_Point  );
                 F_input<T_coord>( En_inCoord_Normal,     P_inCoord_Normal );
                 F_input<T_size>(  En_inSize_SpotBegin,   P_inSize_SpotEnd   );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 auto const&  I_incoming = P_intersect.M_incoming;
               //T_ray     const&   I_ray      = M2_memoryRay->Fv_load( F_input()[ T_memory::En_ray ][ En_inRay_incoming] );

                 T_light const* I_light = M2_light;
                 T_coord const& I_point  = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Point ) );
                 T_coord const& I_normal = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal ) );
                 T_size  const& I_begin  = M2_memorySize->Fv_load(  F_input<T_size>( En_inSize_SpotBegin ) );


                 M2_swarm.F_clear();
                 I_light->Fv_swarm( M2_swarm, I_point /*,P_state*/ );

                 T_size I_end = I_begin;

                 T_coord I_2light;
                 for( auto const& I_spot : M2_swarm )
                  {


                    ::math::linear::vector::subtraction( I_2light, I_spot.F_center(), I_point );
                 //::math::linear::vector::length( I_2light, T_scalar(1) );

                   if( ::math::linear::vector::dot( I_2light, I_normal ) < 0 )
                    {
                     continue;
                    }


                   M2_memorySpot->Fv_store( I_end, I_spot );
                   ++I_end;
                  }

                 M2_memorySize->Fv_store( F_output<T_size>( En_outSize_SpotEnd ), I_end );
                 return true;
                }

             public:  // property light  light
               T_light    const* F_light()const{ return M2_light; }
               void              F_light( T_light* P_light )
                {
                 M2_light = P_light;
                 if( nullptr == M2_light )
                  {
                   M2_light = &F2s_light();
                  }
                 M2_swarm.F_reserve( M2_light->F_max() );
                }
             protected:
               T_light         * & F1_light(){ return M2_light; }
             private:
               T_light *M2_light;
             private:
               mutable T_light::T_swarm M2_swarm;

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>   T2_memorySize;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>  T2_memoryCoord;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_spot>   T2_memorySpot;


             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                 T_instruction::Fv_memory( P_memory );
                 M2_memorySize  = dynamic_cast<T2_memorySize * >( P_memory->F_get<T_size>(  ) );
                 M2_memoryCoord = dynamic_cast<T2_memoryCoord* >( P_memory->F_get( T_memory::En_coord ) );
                 M2_memorySpot  = dynamic_cast<T2_memorySpot * >( P_memory->F_get( T_memory::En_spot  ) );

                }

             private:
               T2_memorySize     *M2_memorySize;
               T2_memoryCoord    *M2_memoryCoord;
               T2_memorySpot     *M2_memorySpot;
             private:
               static T_light & F2s_light()
                {
                 static GS_DDMRM::S_IceRay::S_light::GC_point Is_light;
                 return Is_light;
                }

           };

          }
        }
      }
    }
  }

#endif
