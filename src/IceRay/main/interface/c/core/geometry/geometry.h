#ifndef a4ff2885f266411bb260d2e1749a7b7e
#define a4ff2885f266411bb260d2e1749a7b7e

#include "../../system/system.h"
#include "../../type/type.h"


struct IceRayC_GeometryStruct {};
typedef IceRayC_GeometryStruct* IceRayC_GeometryHandle;


IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Geometry_Release( IceRayC_GeometryHandle );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometrySphere0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometrySphere1( IceRayC_TypeCoord3D center, IceRayC_TypeScalar radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int              IceRayC_GeometrySphere_Center( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D center );
IceRayC__EXPORT IceRayC__DECLSPEC  int              IceRayC_GeometrySphere_Radius( IceRayC_GeometryHandle P_this, IceRayC_TypeScalar radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryUSphere();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBox0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBox1( IceRayC_TypeCoord3D lo, IceRayC_TypeCoord3D hi );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryTorus0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryTorus1( IceRayC_TypeScalar P_minor );
IceRayC__EXPORT IceRayC__DECLSPEC  int              IceRayC_GeometryTorus_Minor( IceRayC_GeometryHandle P_this, IceRayC_TypeScalar P_minor );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryTriangle0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryTriangle1( IceRayC_TypeCoord3D e0, IceRayC_TypeCoord3D ex, IceRayC_TypeCoord3D ey );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometrySmoke0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometrySmoke1( IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi, IceRayC_TypeScalar P_density );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryMotionBlur0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryMotionBlur_Child( IceRayC_GeometryHandle P_this, IceRayC_GeometryHandle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryPlane0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryPlane( IceRayC_TypeCoord3D P_origin, IceRayC_TypeCoord3D P_normal );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryHField();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryDisc0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryDisc1(  IceRayC_TypeCoord3D P_center, IceRayC_TypeCoord3D P_normal, IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_GeometryDisc_Center( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_GeometryDisc_Normal( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_GeometryDisc_Radius( IceRayC_GeometryHandle P_this, IceRayC_TypeScalar P_radius );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryCylinder0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryCone0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryParaboloid0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryHyperboloid0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryHyperboloid1( IceRayC_TypeScalar P_core );
IceRayC__EXPORT IceRayC__DECLSPEC  int              IceRayC_GeometryHyperboloid_Core( IceRayC_GeometryHandle P_this, IceRayC_TypeScalar P_core );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometrySaddle0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryCSG0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryCSG1( IceRayC_GeometryHandle P_left, IceRayC_GeometryHandle Pright );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryCSG_Set(   IceRayC_GeometryHandle P_this,  IceRayC_GeometryHandle P_left, IceRayC_GeometryHandle Pright );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryCSG_Left(  IceRayC_GeometryHandle P_this, IceRayC_GeometryHandle P_left );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryCSG_Right( IceRayC_GeometryHandle P_this, IceRayC_GeometryHandle P_right );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryAffine0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryAffine1( IceRayC_GeometryHandle child, IceRayC_TypeAffine3D P_affine );
//IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryAffine2( IceRayC_GeometryHandle child, IceRayC_TypeMatric3D P_affine, IceRayC_TypeCoord3D P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryAffine_Child( IceRayC_GeometryHandle P_this, IceRayC_GeometryHandle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryAffine_Affine( IceRayC_GeometryHandle P_this, IceRayC_TypeAffine3D P_affine );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryAffine_Scale( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_origin, IceRayC_TypeCoord3D P_scale );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryAffine_Translate( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryTranslate0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryTranslate1(            IceRayC_GeometryHandle P_child, IceRayC_TypeCoord3D translation );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryTranslate_Translation( IceRayC_GeometryHandle P_this, IceRayC_TypeCoord3D translation );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryTranslate_Child(       IceRayC_GeometryHandle P_this, IceRayC_GeometryHandle child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryVacuum0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryVacuum1( IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBlobbySystem0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBlobbySystem_RTSS( IceRayC_GeometryHandle  P_system, IceRayC_GeometryHandle* P_rtss );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBlobbySystem_Add( IceRayC_GeometryHandle  P_system, IceRayC_GeometryHandle* P_element );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBlobbySphere0( IceRayC_TypeCoord3D P_center, IceRayC_TypeScalar P_influence, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBlobbyUSphere( IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBlobbyUCylinderZ( IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBlobbyUWaterZ( IceRayC_TypeScalar P_level);
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_GeometryHandle IceRayC_GeometryBlobbyTranslate( IceRayC_GeometryHandle P_element, IceRayC_TypeCoord3D P_translate );


#endif
