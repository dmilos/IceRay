#ifndef Dh_DDMRM_Iceray_material_compute_UVW_HPP_
 #define Dh_DDMRM_Iceray_material_compute_UVW_HPP_

 #include <tuple>
 #include <limits>

 #include "../../../type/basic/size.hpp"
 #include "../../../geometry/_pure/uvw.hpp"
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

           class GC_UVW
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D       T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                  T_scalar;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_uvw  T_geometry;

               enum Ee_input{  En_inCoord_Point  = 0, En_inGeometryUVW_This  = 0, En_inState_State = 0};
               enum Ee_output{ En_outBool_Valid = 0, En_outCoord_UVW = 0 };

             public:
               GC_UVW
                (
                  T_size const& P_inCoord_Point = 0
                 ,T_size const& P_outCoord_UVW = 2
                )
                {
                 F_input( T_memory::En_geometryUVW, En_inGeometryUVW_This,  0 );
                 F_input( T_memory::En_coord3D,     En_inCoord_Point,  P_inCoord_Point );
               // TODO F_input( T_memory::En_memory,      En_inState_State,  0 );

                 F_output( T_memory::En_coord3D, En_outCoord_UVW, P_outCoord_UVW );
                 F_output( T_memory::En_bool,    En_outBool_Valid, 0 );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_coord    const& I_point    = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord3D ][ En_inCoord_Point ] );
                 T_geometry const* I_geometry = M2_memoryGeometry->Fv_load( F_input()[ T_memory::En_geometryUVW ][ En_inGeometryUVW_This ] );

                 T_coord  I_UVW; //!< TODO default value is box coordinate

                 if( false == I_geometry->Fv_uvw( I_UVW, I_point, P_state ) )
                  {
                   M2_memoryBool->Fv_store( F_output()[ T_memory::En_bool][ En_outBool_Valid], false );
                   return true;
                  }

                 M2_memoryCoord->Fv_store(  F_output()[ T_memory::En_coord3D ][ En_outCoord_UVW ], I_UVW  );
                 M2_memoryBool->Fv_store(   F_output()[ T_memory::En_bool    ][ En_outBool_Valid], true   );

                 return true;
                }

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<bool>         T2_memoryBool;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>     T2_memoryScalar;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord >     T2_memoryCoord;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_geometry*>  T2_memoryGeometryUVW;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                 F1_memory() = P_memory;
                 M2_memoryBool     = P_memory->F_get<bool>();
                 M2_memoryScalar   = P_memory->F_get<T_scalar>();
                 M2_memoryCoord    = P_memory->F_get<T_coord>();
                 M2_memoryGeometry = dynamic_cast<T2_memoryGeometryUVW * >( P_memory->F_get( T_memory::En_geometryUVW ) );
                }

             private:
               T2_memoryBool        *M2_memoryBool;
               T2_memoryScalar      *M2_memoryScalar;
               T2_memoryCoord       *M2_memoryCoord;
               T2_memoryGeometryUVW *M2_memoryGeometry;
           };

          }
        }
      }
    }
  }

#endif
