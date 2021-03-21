#ifndef Dh_DDMRM_Iceray_material_compute_transmission_jitter_rand_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_jitter_rand_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_jitter::GC_rand

#include "../../instruction.hpp"
#include "IceRay/utility/random.hpp"
#include "math/geometry/deg2rad.hpp"

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
                   ,En_inRay_Begin    = 0
                   ,En_inRay_End      = 1
                   ,En_inScalar_Angle = 0
                  };
                 enum Ee_output
                  {
                  };

               public:
                 GC_random
                  (
                    T_size const& P_inCoord_Normal = 0
                   ,T_size const& P_RayBegin       = 0
                   ,T_size const& P_RayEnd         = 1
                   ,T_size const& P_inAngle        = 0
                  )
                  {
                   F_input<T_coord>(    En_inCoord_Normal,   P_inCoord_Normal );
                   F_input<T_ray>(      En_inRay_Begin,   P_RayBegin );
                   F_input<T_ray>(      En_inRay_End,    P_RayEnd );
                   F_input<T_scalar>(  En_inScalar_Angle, P_inAngle  );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord const& I_normal = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal ) );

                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>    T2_memorySize;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>  T2_memoryScalar;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>  T2_memoryCoord;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize   = dynamic_cast<T2_memorySize * >(  P_memory->F_get<T_size>() );
                   M2_memoryScalar = dynamic_cast<T2_memoryScalar* >( P_memory->F_get<T_scalar>() );
                   M2_memoryCoord = dynamic_cast<T2_memoryCoord* >(   P_memory->F_get<T_coord>() );
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
