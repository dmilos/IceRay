#ifndef ca27ba03041b45ad95927e99ad3673f9
#define ca27ba03041b45ad95927e99ad3673f9

#include "../../system/system.h"
#include "../../type/type.h"

#include "../geometry/geometry.h"

typedef struct   IceRayC_TypeSpot
{
  IceRayC_TypeCoordScalar3D m_coord;
  IceRayC_TypeColorRGB  m_c0;
  IceRayC_TypeColorRGB  m_c1;
  IceRayC_TypeColorRGB  m_c2;
}IceRayC_TypeSpot;

struct IceRayC_Light_Struct {};
typedef IceRayC_Light_Struct* IceRayC_Light_Handle;


IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Release( IceRayC_Light_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Dark0( );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Area0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Area_Origin( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D * P_origin );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Area_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize            P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Area_Spot(   IceRayC_Light_Handle P_this, IceRayC_TypeSpot*           P_spot   );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Area_X(      IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D*  P_X      );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Area_Y(      IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D*  P_Y      );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Obstruct0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Obstruct1( IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Obstruct2( IceRayC_Light_Handle P_child, IceRayC_Geometry_Handle P_barrier );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Obstruct_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Obstruct_Barrier( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_barrier  );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Chandelier0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Chandelier_Push( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Circle0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Circle_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Circle_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Circle_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Circle_X( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_X );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Circle_Y( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_Y );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Confine0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Confine_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Confine_Shell( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_shell );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Disc0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Disc_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Disc_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample           );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Disc_Spot(   IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot            );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Disc_X(      IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_X      );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Disc_Y(      IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_Y      );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Line0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Line_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Line_Spot(   IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Line_Start(  IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_start );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Line_End(    IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_end );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Point0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Point1( IceRayC_TypeCoordScalar3D* center, IceRayC_TypeColorRGB* c0, IceRayC_TypeColorRGB* c1, IceRayC_TypeColorRGB *c2 );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Point_Spot(   IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Point_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Reflector0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Reflector_Center(    IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Reflector_Spot(      IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Reflector_Direction( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_direction );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Reflector_Inner(     IceRayC_Light_Handle P_this, IceRayC_TypeScalar P_innner );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Reflector_Outter(    IceRayC_Light_Handle P_this, IceRayC_TypeScalar P_outter );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Sphere0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Sphere1( IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Sphere2( IceRayC_TypeSpot* P_spot, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Sphere3( IceRayC_TypeSpot* P_spot, IceRayC_TypeScalar P_radius, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Sphere_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Sphere_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Sphere_Radius( IceRayC_Light_Handle P_this, IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Spline0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Spline_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Spline_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Spline_CP( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample, IceRayC_TypeCoordScalar3D* P_0 );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_SunG0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_SunG1( IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_SunG_Child ( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_SunS0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_SunS1( IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_SunS_Spot(   IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_SunS_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center );

#endif


#include "./transform.h"
