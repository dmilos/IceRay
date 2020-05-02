#ifndef Dh_DDMRM_Iceray_material_compute_light_UVW_HPP_
 #define Dh_DDMRM_Iceray_material_compute_light_UVW_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_spotUVW

 #include "../../../type/basic/size.hpp"
 #include "../../../type/color.hpp"
 #include "../../../type/math/coord.hpp"
 #include "../../../light/_pure.hpp"
 #include "../../../light/type/spot.hpp"
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
         namespace S_spot
          {

           class GC_UVW //!< of incoming ray
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:

               typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

               typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;
               typedef GS_DDMRM::S_IceRay::S_light::GC__pure             T_light;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state      T_state;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               enum Ee_input
                 {
                  En_inCoord_Point = 0, En_inCoord_Normal = 1,
                  En_inSpot_Index = 0
                 };
               enum Ee_output{ En_outCoord_UVW = 2 };

             public:
               GC_UVW
                (
                  T_size const& P_out        = 2
                 ,T_size const& P_inCoord_Point      = 0
                 ,T_size const& P_inCoord_Normal     = 1
                 ,T_size const& P_spotIndex  = 1
                )
                {
                 F_input<T_coord>(   En_inCoord_Point,  P_inCoord_Point     );
                 F_input<T_coord>(   En_inCoord_Normal, P_inCoord_Normal    );
                 F_input<T_spot>(    En_inSpot_Index,   P_spotIndex ); //!< Index of spot in memory

                 F_output<T_coord>( En_outCoord_UVW, P_out );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 auto const&  I_incoming = P_intersect.M_incoming;
                 T_coord const& I_point  = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Point  ) );
                 T_coord const& I_normal = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal ) );
                 T_spot const&  I_spot   = M2_memorySpot->Fv_load(  F_input<T_spot>(  En_inSpot_Index   ) );

                 T_coord I_reflected;  ::math::linear::vector::reflect(     I_reflected, I_incoming.M_direction, I_normal ); ::math::linear::vector::length( I_reflected, T_scalar(1) );
                 T_coord I_2light;      ::math::linear::vector::subtraction( I_2light, I_spot.F_center(), I_point ); ::math::linear::vector::length( I_2light, T_scalar(1) );
                 T_coord I_2viewer;     ::math::linear::vector::negate(      I_2viewer, I_incoming.M_direction );

                 //T_coord const& I_z = I_normal;
                 T_coord I_decline; ::math::linear::vector::cross( I_decline, I_normal, I_reflected );  ::math::linear::vector::length( I_decline, T_scalar(1) );
                 //::math::linear::vector::cross( I_x, I_y, I_z ); ::math::linear::vector::length( I_x, T_scalar(1) );
                 //::math::linear::vector::cross( I_y, I_z, I_x ); ::math::linear::vector::length( I_y, T_scalar(1) );

                 T_scalar I_dot0 = ::math::linear::vector::dot( I_reflected, I_2light );
                 T_scalar I_dot1 = sin( 60*::math::linear::vector::dot( I_2light, I_decline ) );

                 T_coord I_UVW;
                 I_UVW[0] = 0*( I_dot0 + 1 )/2; if( I_dot0 < 0 ) I_dot0 = 0;
                 I_UVW[1] = ( I_dot1 + 1 )/2;
                 if( I_dot1 < 0 ) 
                  {
                   //I_UVW[1] = 0;
                  }
                 I_UVW[2] =0;    //* - ::math::linear::vector::dot( I_z, I_incoming );

                 if( ::math::linear::vector::dot( I_2viewer, I_normal ) < 0 )
                  {
                   I_UVW[0] = I_UVW[1] = I_UVW[2] = 0.3;
                  }
                 if( ::math::linear::vector::dot( I_2light, I_normal ) < 0 )
                  {
                   I_UVW[0] = I_UVW[1] = I_UVW[2] = 0.6;
                  }

                 M2_memoryCoord->Fv_store( F_output<T_coord>( En_outCoord_UVW ), I_UVW );

                 return true;
                }

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>  T2_memoryCoord;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>   T2_memorySize;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_spot>   T2_memorySpot;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                 F1_memory() = P_memory;
                 M2_memorySize  = dynamic_cast<T2_memorySize * >( P_memory->F_get<T_size>(  ) );
                 M2_memoryCoord = dynamic_cast<T2_memoryCoord* >( P_memory->F_get<T_coord>( ) );
                 M2_memorySpot  = dynamic_cast<T2_memorySpot * >( P_memory->F_get<T_spot>(  ) );
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
