#ifndef Dh_DDMRM_Iceray_material_compute_normal_HPP_
 #define Dh_DDMRM_Iceray_material_compute_normal_HPP_

 #include <tuple>
 #include <limits>

 #include "../../../type/basic/size.hpp"
 #include "../../../geometry/_pure/normal.hpp"
 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_geometry
          {

           class GC_normal
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D       T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                  T_scalar;
               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal     T_geometry;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               enum Ee_input{  En_inCoord_Point  = 0 };
               enum Ee_output{ En_outCoord_Normal = 0 };

             public:
               GC_normal
                (
                  T_size const& P_outCoord_Normal = 1
                 ,T_size const& P_inCoord_Point   = 0
                )
                {
                 F_output<T_coord>( En_outCoord_Normal, P_outCoord_Normal );

                 F_input<T_coord>( En_inCoord_Point,  P_inCoord_Point );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_coord const& I_point = M2_memoryCoord->Fv_load(    F_input<T_coord>( En_inCoord_Point ) );

                 T_coord  I_normal;

                 // TODO  I_geometry->Fv_normal( I_normal, I_point, P_state );

                 //if( T_scalar( 0 ) < ::math::linear::vector::dot( I_normal, I_incoming.M_direction ) )
                 // {
                 //  ::math::linear::vector::negative( I_normal );
                 // }

                 M2_memoryCoord->Fv_store(  F_output<T_coord>( En_outCoord_Normal ), I_normal );

                 return true;
                }

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<bool>         T2_memoryBool;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>     T2_memoryScalar;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord >     T2_memoryCoord;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_geometry*>  T2_memoryGeometryNormal;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                  F1_memory() = P_memory;
                  M2_memoryBool     = P_memory->F_get<bool>();
                  M2_memoryScalar   = P_memory->F_get<T_scalar>();
                  M2_memoryCoord    = P_memory->F_get<T_coord>();
                  M2_memoryGeometry = dynamic_cast<T2_memoryGeometryNormal * >( P_memory->F_get( T_memory::T_component::En_geometryNormal ) );
                }

             private:
               T2_memoryBool           *M2_memoryBool;
               T2_memoryScalar         *M2_memoryScalar;
               T2_memoryCoord          *M2_memoryCoord;
               T2_memoryGeometryNormal *M2_memoryGeometry;
           };

          }
        }
      }
    }
  }

#endif
