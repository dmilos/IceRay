#ifndef Dh_DDMRM_Iceray_material_compute_light_spotCull_HPP_
 #define Dh_DDMRM_Iceray_material_compute_light_spotCull_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_spotCull

 #include "../../../light/_pure.hpp"

 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_spot
          {

           class GC_cull //! Remove spot that are on the other side of tangent plane. Ignore incoming ray
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:

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
                 En_inCoord_Point = 0, En_inCoord_Normal = 1,
                 En_inSize_SpotBegin = 0, En_inSize_SpotEnd = 1
                };

               enum Ee_output
                {
                 En_outSize_SpotEnd = 2
                };

             public:
               explicit GC_cull
                (
                  T_size const& P_inCoord_Point     //= 0
                 ,T_size const& P_inCoord_Normal    //= 1
                 ,T_size const& P_outSize_SpotEnd   //= 1
                 ,T_size const& P_inSize_SpotBegin  //= 0
                 ,T_size const& P_inSize_SpotEnd    //= 1
                )
                {
                 F_output<T_size>( En_outSize_SpotEnd, P_outSize_SpotEnd );

                 F_input<T_coord>( En_inCoord_Point,    P_inCoord_Point );
                 F_input<T_coord>( En_inCoord_Normal,   P_inCoord_Normal );
                 F_input<T_size>(  En_inSize_SpotBegin, P_inSize_SpotBegin );
                 F_input<T_size>(  En_inSize_SpotEnd,   P_inSize_SpotEnd );

                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_coord const& I_point  = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Point  ) );
                 T_coord const& I_normal = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal ) );
                 T_size  const& I_spotBegin  = M2_memorySize->Fv_load( F_input<T_size>( En_inSize_SpotBegin ) );
                 T_size         I_spotEnd    = M2_memorySize->Fv_load( F_input<T_size>( En_inSize_SpotEnd ) );

                 T_coord I_2light;
                 for( T_size I_spotIndex = I_spotBegin; I_spotIndex < I_spotEnd; ++I_spotIndex )
                  {
                   T_spot const& I_spot = M2_memorySpot->Fv_load( I_spotIndex );

                   ::math::linear::vector::subtraction( I_2light, I_spot.F_center(), I_point );

                   if( 0 < ::math::linear::vector::dot( I_2light, I_normal ) )
                    {
                     continue;
                    }

                   --I_spotEnd;
                   M2_memorySpot->Fv_store( I_spotBegin + I_spotIndex, M2_memorySpot->Fv_load( I_spotEnd ) );
                   --I_spotIndex;
                  }

                 M2_memorySize->Fv_store( F_output<T_size>( En_outSize_SpotEnd ), I_spotEnd );
                 return true;
                }

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>   T2_memorySize;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>  T2_memoryCoord;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_spot>   T2_memorySpot;

             public: // get spots, get coord3d
               void    Fv_memory( T_memory * P_memory  )
                {
                 T_instruction::Fv_memory( P_memory );
                 M2_memorySize  = dynamic_cast<T2_memorySize * >( P_memory->F_get<T_size>() );
                 M2_memoryCoord = dynamic_cast<T2_memoryCoord* >( P_memory->F_get<T_coord>() );
                 M2_memorySpot  = dynamic_cast<T2_memorySpot * >( P_memory->F_get<T_spot>() );
                }

             private:
               T2_memorySize     *M2_memorySize;
               T2_memoryCoord    *M2_memoryCoord;
               T2_memorySpot     *M2_memorySpot;
            };

          }
        }
      }
    }
  }

#endif
