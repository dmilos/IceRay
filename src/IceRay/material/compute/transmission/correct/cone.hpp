    #ifndef Dh_DDMRM_Iceray_material_compute_transmission_corrector_HPP_
 #define Dh_DDMRM_Iceray_material_compute_transmission_corrector_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::GC_corrector

#include "../../instruction.hpp"

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
           namespace S_correct
            {

             class GC_cone  //!< (re)calculate max angle( direction and side-direction) depend on normal of surface and cone's axis
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                    En_inCoord_Normal = 1
                   ,En_inCoord_Axis   = 0
                   ,En_inScalar_Angle = 0
                  };

                 enum Ee_output
                  {
                    En_outScalar_Angle = 1
                  };

               public:
                 GC_cone
                  (
                    T_size const& P_inCoord_Normal // = 1
                   ,T_size const& P_inCoord_Axis   // = 2
                   ,T_size const& P_inAngle        // = 0
                   ,T_size const& P_outAngle       // = 1
                  )
                  {
                   F_input<T_coord>(   En_inCoord_Normal,  P_inCoord_Normal );
                   F_input<T_coord>(   En_inCoord_Axis,    P_inCoord_Axis   );
                   F_input<T_scalar>(  En_inScalar_Angle,  P_inAngle        );

                   F_output<T_scalar>( En_outScalar_Angle,     P_outAngle );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord  const& I_normal = M2_memoryCoord->Fv_load(  F_input<T_coord >( En_inCoord_Normal ) );
                   T_coord  const& I_axis   = M2_memoryCoord->Fv_load(  F_input<T_coord >( En_inCoord_Axis   ) );
                   T_scalar const& I_angle  = M2_memoryScalar->Fv_load( F_input<T_scalar>( En_inScalar_Angle ) );

                   auto I_max = ::math::linear::vector::angle( I_normal, I_axis );
                   if( ::math::geometry::deg2rad( 90 ) < I_max )
                    { //! Correct if axis is incident ray
                     I_max = ::math::geometry::deg2rad( 180 ) - I_max;
                    }

                   I_max = ::math::geometry::deg2rad( 90 ) - I_max;

                   if( I_angle < I_max )
                    {
                     I_max = I_angle;
                    }

                   M2_memoryScalar->Fv_store( F_output<T_scalar>( En_outScalar_Angle ), I_max );
                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>  T2_memoryScalar;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>    T2_memoryCoord;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memoryScalar = P_memory->F_get<T_scalar>();
                   M2_memoryCoord   = P_memory->F_get<T_coord>();
                  }
               private:
                 T2_memoryScalar   *M2_memoryScalar;
                 T2_memoryCoord     *M2_memoryCoord;
              };

            }
          }
        }
      }
    }
  }

#endif
