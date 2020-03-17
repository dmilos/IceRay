#ifndef ca27ba03041b45ad95927e99ad3673f9
#define ca27ba03041b45ad95927e99ad3673f9

#include "../../system/system.h"
#include "../../type/type.h"

#include "../geometry/geometry.h"

typedef struct   IceRayC_TypeSpot
{
  IceRayC_TypeCoord3D m_coord;
  IceRayC_TypeColorRGB  m_c0;
  IceRayC_TypeColorRGB  m_c1;
  IceRayC_TypeColorRGB  m_c2;
}IceRayC_TypeSpot;

struct IceRayC_Light_Struct {};
typedef IceRayC_Light_Struct* IceRayC_Light_Handle;


IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Light_Release( IceRayC_Light_Handle P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Area0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Area_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Area_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Area_Origin( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_origin );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Area_X( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_X );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Area_Y( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_Y );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Blocked0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Blocked_Barrier( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_barrier  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Chandelier0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Chandelier_push( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Circle0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Circle_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Circle_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Circle_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Circle_X( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_X );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Circle_Y( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_Y );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Clipped0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Clipped_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Clipped_Shell( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_shell );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Disc0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Disc_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Disc_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Disc_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Disc_X( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_X );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Disc_Y( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_Y );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Line0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Line_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Line_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Line_Start( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_start );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Line_End( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_end );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Point0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Point1( IceRayC_TypeCoord3D center, IceRayC_TypeColorRGB c0, IceRayC_TypeColorRGB c1, IceRayC_TypeColorRGB c2 );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Point_Spot( IceRayC_Light_Handle P_this , IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Point_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Reflector0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Reflector_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Reflector_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Reflector_Direction( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_direction );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Reflector_Inner( IceRayC_Light_Handle P_this, IceRayC_TypeScalar P_innner );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Reflector_Outter( IceRayC_Light_Handle P_this, IceRayC_TypeScalar P_outter );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Spline0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Spline_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Spline_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Spline_CP_0( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_0 );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Spline_CP_1( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_1 );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Spline_CP_2( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_2 );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Spline_CP_3( IceRayC_Light_Handle P_this, IceRayC_TypeCoord3D P_3 );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Sun0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Sun1( IceRayC_Light_Handle *P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Light_Sun_Child ( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );

#endif
