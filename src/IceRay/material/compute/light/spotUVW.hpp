#ifndef Dh_DDMRM_Iceray_material_compute_light_UVW_HPP_
 #define Dh_DDMRM_Iceray_material_compute_light_UVW_HPP_


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
         namespace S_light
          {

           class GC_spotUVW //!< of incoming ray
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:

               typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

               typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;
               typedef GS_DDMRM::S_IceRay::S_light::GC__pure             T_light;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state      T_state;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect T_geometry;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               enum Ee_input
                 {
                  En_inCoord_Point = 0, En_inCoord_Normal = 1,
                  En_inSpot_Index = 0
                 };
               enum Ee_output{ En_outCoord_UVW = 2 };

             public:
               GC_spotUVW
                (
                  T_size const& P_point      = 0
                 ,T_size const& P_normal     = 1
                 ,T_size const& P_spotIndex  = 1
                 ,T_size const& P_out        = 2
                )
                {
                 F_input<T_coord>(   En_inCoord_Point,  P_point     );
                 F_input<T_coord>(   En_inCoord_Normal, P_normal    );
                 F_input<T_spot>(    En_inSpot_Index,   P_spotIndex ); //!< Index of spot in memory

                 F_output<T_coord>( En_outCoord_UVW, P_out );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_coord const& I_point  = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Point  ) );
                 T_coord const& I_normal = M2_memoryCoord->Fv_load( F_input<T_coord>( En_inCoord_Normal ) );
                 T_spot const&  I_spot   = M2_memorySpot->Fv_load(  F_input<T_spot>(  En_inSpot_Index   ) );

                 T_coord I_x;
                 T_coord I_y;  ::math::linear::vector::subtraction( I_y, I_spot.F_center(), I_point );
                 T_coord const& I_z = I_normal;

                 ::math::linear::vector::cross( I_x, I_y, I_z ); ::math::linear::vector::length( I_x, T_scalar(1) );
                 ::math::linear::vector::cross( I_y, I_z, I_x ); ::math::linear::vector::length( I_y, T_scalar(1) );

                 T_coord const& I_incoming = P_intersect.M_incoming.M_direction;

                 T_coord I_UVW;
                 I_UVW[0] =   ::math::linear::vector::dot( I_x, I_incoming );
                 I_UVW[1] =   ::math::linear::vector::dot( I_y, I_incoming );
                 I_UVW[2] = - ::math::linear::vector::dot( I_z, I_incoming );

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
