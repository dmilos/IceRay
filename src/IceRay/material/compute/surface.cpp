#include "./surface.hpp"
#include "./memory/constant.hpp"

using namespace GS_DDMRM::S_IceRay::S_material::S_compute;

GC_surface::GC_surface
 (
   T_size const& P_result
  ,T_size const& P_inScalar_Lambda
  ,T_size const& P_inCoord_Point
  ,T_size const& P_inCoord_Normal
  ,T_size const& P_inCoord_Incident
  ,T_size const& P_inCoord_Origin
 )
 {
  using namespace GS_DDMRM::S_IceRay::S_material::S_compute::S_memory;
  M2_scalar = M2_pocessor.F_memory().F_get<T_scalar>( );
  M2_color  = M2_pocessor.F_memory().F_get<T_color>( );
  M2_coord  = M2_pocessor.F_memory().F_get<T_coord>( );
//M2_ray    = dynamic_cast< T2_ray   *> (  M2_pocessor.F_memory().F_get<>( T_memory::T_component::En_ray     ) );

  M2_result   = P_result;            //! = En_Color_DynamicResult
  M2_lambda   = P_inScalar_Lambda;   //! = En_Scalar_DynamicLambda
  M2_point    = P_inCoord_Point;     //! = En_inCoord3D_Dynamic_Point
  M2_normal   = P_inCoord_Normal;    //! = En_inCoord3D_Dynamic_Normal
  M2_incident = P_inCoord_Incident;  //! = En_inCoord3D_Dynamic_Incident
  M2_origin   = P_inCoord_Origin;    //! = En_inCoord3D_Dynamic_Origin

 }

bool GC_surface::Fv_color( T_color & P_color, T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
 {
  M2_scalar->Fv_store( M2_lambda,    P_intersect.M_intersection.M_lambda );

  M2_coord->Fv_store(  M2_point,     P_intersect.M_intersection.M_point  );
  M2_coord->Fv_store(  M2_normal,    P_intersect.M_intersection.M_normal ); 
  M2_coord->Fv_store(  M2_incident,  P_intersect.M_incoming.M_direction  ); 
  M2_coord->Fv_store(  M2_origin,    P_intersect.M_incoming.M_origin     );

//M2_coord->Fv_store(  M2_bump,      P_intersect.TODO  );
//M2_coord->Fv_store(  M2_UVW,       P_intersect.TODO  );

//M2_geometryBase->Fv_store(  M2_geometry, P_intersect.M_geometry );
//M2_ray->Fv_store(  M2_incoming, P_intersect.M_ray    );
//M2_color->Fv_store(  M2_result, ::color:constant::black_t{} );
//M2_color->Fv_store(  M2_result, P_color );

  if( false == M2_pocessor.Fv_execute( P_next, P_intersect, P_state ) )
   {
    return false;
   }

  P_color = M2_color->Fv_load( M2_result );
  return true;
 }
