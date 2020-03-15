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

struct IceRayC_LightStruct {};
typedef IceRayC_LightStruct* IceRayC_LightHandle;


IceRayC__EXPORT IceRayC__DECLSPEC void          IceRayC_Light_Release( IceRayC_LightHandle P_this );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightArea( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightArea_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightArea_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightArea_Origin( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightArea_X( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightArea_Y( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightBlocked0( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightBlocked_Barrier( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightChandelier0( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightChandelier_push( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightCircle0( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightCircle_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightCircle_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightCircle_Origin( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightCircle_X( IceRayC_LightHandle P_this/*, circle */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightCircle_Y( IceRayC_LightHandle P_this/*, circle */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightClipped0( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightClipped_Qarter( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightDisc0( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightDisc_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightDisc_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightDisc_Origin( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightDisc_X( IceRayC_LightHandle P_this/*, TODO IceRayC_TypeCoord3D P_X */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightDisc_Y( IceRayC_LightHandle P_this/*, TODO IceRayC_TypeCoord3D P_X */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightLine0( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightLine_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightLine_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightLine_Start( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightLine_End( IceRayC_LightHandle P_this/*, TODO */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightPoint0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightPoint1( IceRayC_TypeCoord3D center, IceRayC_TypeColorRGB c0, IceRayC_TypeColorRGB c1, IceRayC_TypeColorRGB c2 );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightPoint_Spot( IceRayC_LightHandle P_this , IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightPoint_Center( IceRayC_LightHandle P_this/*, IceRayC_TypeCoord3D P_coord */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightReflector0( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightReflector_Center( IceRayC_LightHandle P_this/*, IceRayC_TypeCoord3D P_coord */   );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightReflector_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightReflector_Direction( IceRayC_LightHandle P_this/*, IceRayC_TypeCoord3D P_direction */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightReflector_In( IceRayC_LightHandle P_this/*, TODO reflector */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightReflector_Out( IceRayC_LightHandle P_this/*, TODO reflector */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightSpline( );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightSpline_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightSpline_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightSpline_CP_0( IceRayC_LightHandle P_this/*, IceRayC_TypeCoord3D P_coord */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightSpline_CP_1( IceRayC_LightHandle P_this/*, IceRayC_TypeCoord3D P_coord */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightSpline_CP_2( IceRayC_LightHandle P_this/*, IceRayC_TypeCoord3D P_coord */ );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightSpline_CP_3( IceRayC_LightHandle P_this/*, IceRayC_TypeCoord3D P_coord */ );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightSun0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightSun1( IceRayC_LightHandle *P_child );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_LightHandle IceRayC_LightSun1( IceRayC_LightHandle *P_child );
IceRayC__EXPORT IceRayC__DECLSPEC int           IceRayC_LightSun_Child ( IceRayC_LightHandle P_this/*, IceRayC_LightHandle P_child */ );


#endif
