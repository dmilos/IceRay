#ifndef Dh_DDMRM_Iceray_material_compute_transmission_blossom_LD_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_blossom_LD_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_LD

#include "../../instruction.hpp"
#include "IceRay/utility/table/ld.hpp"
#include "math/math.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_transmission
          {
           namespace S_blossom
            {

             class GC_LD
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                    En_inCoord_Normal = 1
                   ,En_inSize_Count   = 0
                   ,En_inSize_Leader  = 1
                   ,En_inScalar_Angle = 0
                   ,En_inScalar_Gauss = 1
                  };
                 enum Ee_output
                  {
                   //En_outSize_RayCount
                    En_outSize_RayStart
                  };

               public:
                 GC_LD
                  (
                    T_size const& P_inCoord_Normal     //= 1
                   ,T_size const& P_inCount            //= 1
                   ,T_size const& P_inLeader           //= 0
                   ,T_size const& P_inAngle            //= 0
                   ,T_size const& P_inGauss            //= 1
                 //,T_size const& P_outSize_RayCount  // = 1
                   ,T_size const& P_outSize_RayStart  // = 2
                  )
                  {
                   static auto dummy = F2s_init();

                   F_input<T_coord>(   En_inCoord_Normal,  P_inCoord_Normal );
                   F_input<T_size>(    En_inSize_Count,    P_inCount        );
                   F_input<T_size>(    En_inSize_Leader,   P_inLeader       );
                   F_input<T_scalar>(  En_inScalar_Angle,  P_inAngle        );
                   F_input<T_scalar>(  En_inScalar_Gauss,  P_inGauss        );

                   //F_output<T_size>( En_outSize_RayCount,     P_outSize_RayCount );
                   F_output<T_size>( En_outSize_RayStart, P_outSize_RayStart );
                   M2_index = 0;
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord  const& I_normal   = M2_memoryCoord->Fv_load(  F_input<T_coord >( En_inCoord_Normal ) );
                   T_size   const& I_leader   = M2_memorySize->Fv_load(   F_input<T_size  >( En_inSize_Leader  ) );
                   T_size   const& I_count    = M2_memorySize->Fv_load(   F_input<T_size  >( En_inSize_Count   ) );
                   T_scalar const& I_angle    = M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_Angle ) );
                   T_scalar const& I_gauss    = M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_Gauss ) );

                   auto      & I_original = P_next.Fv_expose( I_leader );
                   F_execute
                    (
                      P_next
                     ,I_normal
                     ,I_original
                     ,I_count
                     ,I_angle
                     ,I_gauss
                    );
                   I_original.M_status = T_ray::Ee_status::En_abandoned;
                   return true;
                  }

               public:
                 T_size F_execute
                  (
                    T_beam        & P_next
                   ,T_coord  const& P_normal
                   ,T_ray    const& P_heading
                   ,T_size   const& P_count
                   ,T_scalar const& P_angle
                   ,T_scalar const& P_gauss
                  )const
                  {
                   T_size   const& I_count = P_count;

                   T_coord I_y = P_heading.M_direction;
                   T_coord I_x; ::math::linear::vector::cross( I_x, I_y, P_normal ); ::math::linear::vector::length( I_x, T_scalar( 1 ) );
                   T_coord I_z; ::math::linear::vector::cross( I_z, I_x, I_y );      ::math::linear::vector::length( I_z, T_scalar( 1 ) );

                   T_scalar I_radius = sin( P_angle );
                   ::math::linear::vector::length( I_x, I_radius );
                   ::math::linear::vector::length( I_z, I_radius );
                   I_radius *= I_radius;

                   T_scalar const& I_perimeter = 1;
                   auto     const& I_table     = M2s_table.F_structure().F_spot();
                   T_size I_total=0;
                   T_size I_beginA = P_next.Fv_size();

                   T_coord I_direction;

                   for( T_size I_index=0; I_index < I_count; ++I_index )
                    {
                     T_coord2D I_disc2d = I_table[ ( M2_index ++ )%I_table.size() ];

                     T_scalar I_height = sqrt( T_scalar( 1 ) - I_radius * ::math::linear::vector::dot( I_disc2d, I_disc2d ) );
                     ::math::linear::vector::combine( I_direction, I_disc2d[0], I_x, I_height, I_y, I_disc2d[1], I_z );
                     ::math::linear::vector::length( I_direction, T_scalar( 1 ) );

                     //T_scalar I_check = ::math::linear::vector::dot( I_direction, P_normal );
                     //if( I_check < T_scalar(0) )
                     // {
                     //  I_check = I_check;
                     //  continue;
                     // }

                     {
                      P_next.Fv_push();  ++I_total;
                      auto & I_ray = P_next.Fv_top();

                      I_ray.M_geometryID  = P_heading.M_geometryID;
                      I_ray.M_depth       = P_heading.M_depth;
                      I_ray.M_origin      = P_heading.M_origin;
                      I_ray.M_state       = P_heading.M_state;
                      I_ray.M_direction   = I_direction;
                      I_ray.M_derivation  = P_heading.M_derivation;
                      I_ray.M_ior         = P_heading.M_ior;
                      I_ray.M_intesity    = P_heading.M_intesity / I_count;  //!< todo Not optimized;  P_gauss?
                      I_ray.M_coefficient = T_scalar(1) / I_count;     //!< todo Not optimized; P_gauss?
                      I_ray.M_hierarchy   = T_ray::Ee_hierarchy::En_solo;
                      //if( 0 == I_index ) I_ray.M_hierarchy = T_ray::Ee_hierarchy::En_back;
                      //if( (P_count-1) == I_index ) I_ray.M_hierarchy = T_ray::Ee_hierarchy::En_lead;
                     }
                   }

                  //M2_memorySize->Fv_store( F_output<T_size>(En_outSize_RayCount), I_total );
                  M2_memorySize->Fv_store(  F_output<T_size>(En_outSize_RayStart), I_beginA );
                  return P_count;
                 }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>    T2_memorySize;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>   T2_memoryCoord;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>  T2_memoryScalar;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_color>   T2_memoryColor;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize   = P_memory->F_get<T_size>();
                   M2_memoryCoord  = P_memory->F_get<T_coord>();
                   M2_memoryColor  = P_memory->F_get<T_color>();
                   M2_memoryScalar = P_memory->F_get<T_scalar>();
                  }
               private:
                 T2_memorySize     *M2_memorySize;
                 T2_memoryCoord    *M2_memoryCoord;
                 T2_memoryColor    *M2_memoryColor;
                 T2_memoryScalar   *M2_memoryScalar;

               private:
                 static bool F2s_init() 
                  {
                   M2s_table.F_init( 10000 );
#if defined( ICERAY_SWITCH_DEBUG )
                   std::cout << __FILE__ << " " << M2s_table.F_structure().F_spot().size() << std::endl;
#endif
                   return true; 
                  }
               private:
                 mutable T_size M2_index;
               private:
                 static GS_DDMRM::S_IceRay::S_utility::S_table::GC_LD   M2s_table;
              };

            }
          }
        }
      }
    }
  }

#endif
