#ifndef a4ff2885f266411bb260d2e1749a7b7e
#define a4ff2885f266411bb260d2e1749a7b7e

#include "../../system/system.h"
#include "../../type/type.h"


struct  IceRayC_Geometry_Struct {};
typedef IceRayC_Geometry_Struct* IceRayC_Geometry_Handle;


IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Geometry_Release( IceRayC_Geometry_Handle );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Sphere0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Sphere1( IceRayC_TypeCoordScalar3D center, IceRayC_TypeScalar radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Sphere_Center( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Sphere_Radius( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Box0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Box1( IceRayC_TypeCoordScalar3D lo, IceRayC_TypeCoordScalar3D hi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Box_Lo( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_lo );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Box_Hi( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_hi );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid1( IceRayC_TypeCoordScalar3D P_center, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid2( IceRayC_TypeCoordScalar3D P_center, IceRayC_TypeCoordScalar3D P_eX, IceRayC_TypeCoordScalar3D P_eY, IceRayC_TypeCoordScalar3D  P_eZ );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Ellipsoid_Center( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_center );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Torus0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Torus1( IceRayC_TypeScalar P_minor );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Torus_Minor( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_minor );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Triangle0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Triangle1( IceRayC_TypeCoordScalar3D e0, IceRayC_TypeCoordScalar3D ex, IceRayC_TypeCoordScalar3D ey );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_Origin( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_origin );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_eX( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_eX );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_eY( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_eY );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Quadric0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Disc0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Disc1(  IceRayC_TypeCoordScalar3D P_center, IceRayC_TypeCoordScalar3D P_normal, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Center( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Normal( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Radius( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_radius );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_MotionBlur0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_MotionBlur_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Plane0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Plane1( IceRayC_TypeCoordScalar3D P_origin, IceRayC_TypeCoordScalar3D P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Plane_Origin( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_origin );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Plane_Normal( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_normal );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_HField();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Cylinder0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Cone0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Paraboloid0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid1( IceRayC_TypeScalar P_core );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Hyperboloid_Core( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_core );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Saddle0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_USphere0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_UCylinder0();


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect1( IceRayC_Geometry_Handle P_left, IceRayC_Geometry_Handle P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Left0( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_left );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Left1( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_left, int location );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Right0( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Right1( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_right, int location );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Enclose0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Enclose1( IceRayC_Geometry_Handle P_child, IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Enclose_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Enclose_Hull(  IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_hull  );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Identity0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Identity1(      IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Identity_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine1( IceRayC_Geometry_Handle child, IceRayC_Type_Math_Affine3D P_affine );
//IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine2( IceRayC_Geometry_Handle child, IceRayC_TypeMatric3D P_affine, IceRayC_TypeCoordScalar3D P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_2World( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D P_2world );
//IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_Scale( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D P_origin, IceRayC_TypeCoordScalar3D P_scale );
//IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_Translate( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate1(      IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate2(      IceRayC_Geometry_Handle P_child, IceRayC_TypeCoordScalar3D translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Translate_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Translate_Move(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D translation );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist1( IceRayC_TypeScalar P_density );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist2( IceRayC_TypeScalar P_density, IceRayC_TypeScalar P_precision );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist3( IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist4( IceRayC_Geometry_Handle P_hull, IceRayC_TypeScalar P_density );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist5( IceRayC_Geometry_Handle P_hull, IceRayC_TypeScalar P_density, IceRayC_TypeScalar P_precision );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Mist_Density( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_density );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Mist_Precision( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_precision );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Mist_Hull( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_hull );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke2( IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Smoke_Hull( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_hull );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum1( IceRayC_TypeCoordScalar3D P_lo, IceRayC_TypeCoordScalar3D P_hi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Vacuum_Lo( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D P_lo );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Vacuum_Hi( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D P_hi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Vacuum_Box( IceRayC_Geometry_Handle P_that, IceRayC_TypeInterval3D P_box );




#endif
