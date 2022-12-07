#ifndef Dh_DDMRM_Iceray_material_compute_transmission_jitter_rand_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_jitter_rand_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_jitter::GC_rand

#include "../../instruction.hpp"
#include "IceRay/utility/random.hpp"
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
           namespace S_jitter
            {

             class GC_random //! TODO everything. Use rays and randomly move them inside their cone.
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
                   ,En_inSize_Leader  = 0
                   ,En_inSize_Count   = 1
                   ,En_inScalar_Angle = 0
                //,En_inScalar_Gauss = 1
                  };
                 enum Ee_output
                  {
                    En_outSize_RayCount=0
                   ,En_outRay_out=1
                  };

               public:
                 GC_random
                  (
                    T_size const& P_inCoord_Normal //= 1
                   ,T_size const& P_inLeader       //= 0
                   ,T_size const& P_inCount        //= 1
                   ,T_size const& P_inAngle        //= 0
                //,T_size const& P_inGauss        //= 1
                  )
                  {
                   F_input<T_coord>(   En_inCoord_Normal,  P_inCoord_Normal );
                   F_input<T_size>(    En_inSize_Leader,   P_inLeader       );
                   F_input<T_size>(    En_inSize_Count,    P_inCount        );
                   F_input<T_scalar>(  En_inScalar_Angle,  P_inAngle  );
                 //F_input<T_scalar>(  En_inScalar_Gauss,  P_inGauss        );

                 //F_output<T_size>( En_outSize_RayCount,     P_outSize_RayCount );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord  const& I_normal = M2_memoryCoord->Fv_load(   F_input<T_coord> ( En_inCoord_Normal ) );
                   T_size   const& I_leader = M2_memorySize->Fv_load(    F_input<T_size  >( En_inSize_Leader  ) );
                   T_size   const& I_count  = M2_memorySize->Fv_load(    F_input<T_size  >( En_inSize_Count   ) );
                   T_scalar const& I_angle  =  M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_Angle ) );
                 //T_scalar const& I_gauss  = M2_memoryScalar->Fv_load(  F_input<T_scalar>( En_inScalar_Gauss ) );

                   T_coord2D I_disc2d;
                   for( T_size I_index= 0; I_index < I_count; ++I_index )
                    {
                     auto      & I_original = P_next.Fv_expose( I_index );
                     T_coord I_y = I_original.M_direction;
                     T_coord I_x; ::math::linear::vector::cross( I_x, I_y, I_normal ); ::math::linear::vector::length( I_x, T_scalar( 1 ) );
                     T_coord I_z; ::math::linear::vector::cross( I_z, I_x, I_y );      ::math::linear::vector::length( I_z, T_scalar( 1 ) );

                     GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_disc2d, M2_randStandard2D );
                     // 2. TODO calc new direction
                     // 3. do not correct
                    }

                   return true;
                  }

               private:
                 mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard2D    M2_randStandard2D;
               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>    T2_memorySize;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>  T2_memoryScalar;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>   T2_memoryCoord;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize   = P_memory->F_get<T_size>();
                   M2_memoryScalar = P_memory->F_get<T_scalar>();
                   M2_memoryCoord = P_memory->F_get<T_coord>();
                  }
               private:
                 T2_memorySize     *M2_memorySize;
                 T2_memoryScalar   *M2_memoryScalar;
                 T2_memoryCoord    *M2_memoryCoord;
              };

            }
          }
        }
      }
    }
  }

#endif
