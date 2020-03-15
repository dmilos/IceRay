#ifndef Dh_DDMRM_Iceray_material_compute_light_spotCull_HPP_
 #define Dh_DDMRM_Iceray_material_compute_light_spotCull_HPP_


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
         namespace S_light
          {

           class GC_spotCull //! Remove spot that are on the other side of tangent plane. Ignore incoming ray
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:

               typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;

               typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;
               typedef GS_DDMRM::S_IceRay::S_light::GC__pure             T_light;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state      T_state;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect  T_geometry;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory      T_memory;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction T_instruction;

               enum Ee_input
                {
                 En_inCoord_Point = 0, En_inCoord_Normal = 1,
                 En_inSpot_Begin = 0, En_inSpot_Count
                };

               enum Ee_output
                {
                 En_outSize_SpotTotal = 0 
                };

             public:
               explicit GC_spotCull
                (
                  T_size const& P_point       = 0
                 ,T_size const& P_normal      = 1
                 ,T_size const& P_spotBegin   = 0
                 ,T_size const& P_spotCount   = 1
                )
                {
                 F_input<T_coord>( En_inCoord_Point,  P_point );
                 F_input<T_coord>( En_inCoord_Normal, P_normal );
                 F_input<T_spot>(  En_inSpot_Begin,   P_spotBegin );
                 F_input<T_size>(  En_inSpot_Count,   P_spotCount );

                 F_output<T_size>( En_outSize_SpotTotal, P_spotCount );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_coord const& I_point  = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Point  ) );
                 T_coord const& I_normal = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal ) );
                 T_size  const& I_begin  = F_input<T_spot>( En_inSpot_Begin );
                 T_size         I_count  = M2_memorySize->Fv_load( F_input<T_size>( En_inSpot_Count ) );

                 T_size         I_total   =  I_count;

                 T_coord I_2light;
                 for( T_size I_index = 0; I_index < I_count; ++I_index )
                  {
                   T_spot const& I_spot = M2_memorySpot->Fv_load( I_begin + I_index );

                    ::math::linear::vector::subtraction( I_2light, I_spot.F_center(), I_point );

                   if( 0 < ::math::linear::vector::dot( I_2light, I_normal ) )
                    {
                     continue;
                    }

                   M2_memorySpot->Fv_store( I_begin + I_index, M2_memorySpot->Fv_load( I_begin + I_count - 1 ) );
                   --I_index;
                   --I_total;
                   --I_count;
                  }

                 M2_memorySize->Fv_store( F_output<T_size>( En_outSize_SpotTotal ), I_total );
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
