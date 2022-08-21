#ifndef Dh_DDMRM_Iceray_material_compute_geometry_intersect_HPP_
 #define Dh_DDMRM_Iceray_material_compute_geometry_intersect_HPP_

 #include <tuple>
 #include <limits>
 //#if defined ( __GNUC__ )
 #include <cfloat> // MSVC
 //#endif

 #include "../../../type/basic/size.hpp"
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
         namespace S_geometry
          {

           class GC_intersect
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D       T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                  T_scalar;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect  T_geometry;

               enum Ee_input{ En_inRay_Incoming = 0, En_inGeometryIntersect_This= 0, En_inState_State = 0 };
               enum Ee_output{ En_outScalar_Lambda = 0, En_outCoord_Point=0, En_outCoord_Normal, En_outBool_valid=0, En_outState_State = 1 };

             public:
               GC_intersect()
                {
                 F_input( T_memory::En_geometryIntersect, En_inGeometryIntersect_This,  0 );
                 F_input( T_memory::En_ray,               En_inRay_Incoming,  0 );
               // TODO F_input( T_memory::En_memory,      En_inState_State,  0 );

                 F_output<T_scalar>( En_outScalar_Lambda, 0 );
                 F_output<T_coord>(  En_outCoord_Point,   0 );
                 F_output<T_coord>(  En_outCoord_Normal,  1 );
               // TODO F_output( T_memory::En_memory,   En_outState_State, 1 );

                 F_output( T_memory::En_bool,     En_outBool_valid,    0 );
                }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 static T_scalar Is_infinity = DBL_MAX; //std::numeric_limits<T_scalar>::max();
                 T_ray     const&   I_ray      = M2_memoryRay->Fv_load( F_input()[ T_memory::En_ray ][ En_inRay_Incoming] );
                 T_geometry const  *I_geometry = M2_memoryGeometry->Fv_load( F_input()[ T_memory::En_geometryIntersect][ En_inGeometryIntersect_This ] );
                 // TODO T_memory          &I_state = M2_memoryMemory->Fv_direct( F_input()[ T_memory::En_memory ][ En_inState_State ] );

                 T_scalar I_lambda = Is_infinity;

               //if TODO ( true == I_geometry->Fv_intersect( I_lambda, P_state, I_ray ) )
                  {
                   using namespace ::math::linear::vector;
                   T_coord I_point = I_ray.M_origin + I_lambda * I_ray.M_direction; //<! TODO not optimal
                   //TODO ::math::linear::vector::combine( I_point, 1, I_ray.M_origin,I_lambda, I_ray.M_direction )

                   M2_memoryScalar->Fv_store( F_output<T_scalar>(En_outScalar_Lambda), I_lambda );
                   M2_memoryCoord->Fv_store(  F_output<T_coord>(En_outCoord_Point),    I_point  );
                // todo M2_memoryCoord->Fv_store(  F_output<T_coord>(En_outCoord_Normal),   I_normal );
                   M2_memoryBool->Fv_store(   F_output()[ T_memory::En_bool    ][ En_outBool_valid ],    true     );
                   return true;
                  }

                 M2_memoryScalar->Fv_store( F_output<T_scalar>(En_outScalar_Lambda), DBL_MAX );
                 M2_memoryBool->Fv_store( F_output()[ T_memory::En_bool ][ En_outBool_valid ], false );
                 return false;
                }


             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<bool>      T2_memoryBool;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>  T2_memoryScalar;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord >  T2_memoryCoord;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_ray   >  T2_memoryRay;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_geometry*>  T2_memoryGeometryIntersect;

             public:
               void    Fv_memory( T_memory * P_memory  )
                {
                 F1_memory() = P_memory;
                 M2_memoryBool     = P_memory->F_get<bool>();
                 M2_memoryScalar   = P_memory->F_get<T_scalar>();
                 M2_memoryCoord    = P_memory->F_get<T_coord>();
                 M2_memoryRay      = dynamic_cast<T2_memoryRay * >( P_memory->F_get( T_memory::En_ray ) );
                 M2_memoryGeometry = dynamic_cast<T2_memoryGeometryIntersect * >( P_memory->F_get( T_memory::En_geometryIntersect ) );
                }

             private:
               T2_memoryBool    *M2_memoryBool;
               T2_memoryScalar  *M2_memoryScalar;
               T2_memoryCoord   *M2_memoryCoord;
               T2_memoryRay     *M2_memoryRay;
               T2_memoryGeometryIntersect * M2_memoryGeometry;
           };

          }
        }
      }
    }
  }

#endif
