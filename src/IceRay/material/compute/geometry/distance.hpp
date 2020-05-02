#ifndef Dh_DDMRM_Iceray_material_compute_distance_HPP_
 #define Dh_DDMRM_Iceray_material_compute_distance_HPP_

 #include <tuple>
 #include <limits>

 #include "../../../type/basic/size.hpp"
 #include "../../../geometry/_pure/distance.hpp"
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

           class GC_distance
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D       T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                  T_scalar;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance  T_geometry;

                 enum Ee_input{  En_inCoord_Point = 0, En_inGeometryDistance_This  = 0 };
                 enum Ee_output{ En_outScalar_Distance = 0 };

             public:
               GC_distance
                (
                 T_scalar const& P_inCoord_Point = 0
                )
                {
                 F_input( T_memory::En_geometryDistance, En_inGeometryDistance_This,  0 );
                 F_input( T_memory::En_coord3D,          En_inCoord_Point,  P_inCoord_Point );

                 F_output( T_memory::En_scalar, En_outScalar_Distance, 1 );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_coord    const& I_point    = M2_memoryCoord->Fv_load( F_input()[ T_memory::En_coord3D ][ En_inCoord_Point ] );
                 T_geometry const* I_geometry = M2_memoryGeometry->Fv_load( F_input()[ T_memory::En_geometryDistance ][ En_inGeometryDistance_This ] );

                 T_scalar I_distance = I_geometry->Fv_distance( I_point );

                 M2_memoryScalar->Fv_store(  F_output()[ T_memory::En_scalar   ][ En_outScalar_Distance ], I_distance    );

                 return true;
                }

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>     T2_memoryScalar;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord >     T2_memoryCoord;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_geometry*>  T2_memoryGeometryDistance;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                  F1_memory() = P_memory;
                  M2_memoryScalar   = dynamic_cast<T2_memoryScalar* >( P_memory->F_get( T_memory::En_scalar   ) );
                  M2_memoryCoord    = dynamic_cast<T2_memoryCoord * >( P_memory->F_get( T_memory::En_coord3D  ) );
                  M2_memoryGeometry = dynamic_cast<T2_memoryGeometryDistance * >( P_memory->F_get( T_memory::En_geometryDistance ) );
                }

             private:
               T2_memoryScalar           *M2_memoryScalar;
               T2_memoryCoord            *M2_memoryCoord;
               T2_memoryGeometryDistance *M2_memoryGeometry;
           };

          }
        }
      }
    }
  }

#endif
