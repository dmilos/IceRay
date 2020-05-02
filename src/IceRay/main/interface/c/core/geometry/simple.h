#ifndef _a4ff2885f266411bb260d2e1749a7b7e
#define _a4ff2885f266411bb260d2e1749a7b7e

#include "../../system/system.h"
#include "../../type/type.h"


#include "./handle.h"

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Sphere0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Sphere1( IceRayC_TypeCoordScalar3D* center, IceRayC_TypeScalar radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Sphere_Center( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Sphere_Radius( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Box0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Box1( IceRayC_TypeCoordScalar3D* lo, IceRayC_TypeCoordScalar3D* hi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Box_Lo( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_lo );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Box_Hi( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_hi );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid1( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid2( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeCoordScalar3D* P_eX, IceRayC_TypeCoordScalar3D* P_eY, IceRayC_TypeCoordScalar3D*  P_eZ );

IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Ellipsoid_Center(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Ellipsoid_RadiusS( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Ellipsoid_RadiusV( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Ellipsoid_System(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_eX, IceRayC_TypeCoordScalar3D* P_eY, IceRayC_TypeCoordScalar3D * P_eZ );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Torus0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Torus1( IceRayC_TypeScalar P_minor );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Torus_Minor( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_minor );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Triangle0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Triangle1( IceRayC_TypeCoordScalar3D* e0, IceRayC_TypeCoordScalar3D* ex, IceRayC_TypeCoordScalar3D* ey );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_Origin( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_origin );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_eX( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_eX );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_eY( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_eY );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Quadric0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Disc0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Disc1(  IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeCoordScalar3D* P_normal, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Center( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Normal( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Radius( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_radius );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_MotionBlur0();
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_MotionBlur_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Plane0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Plane1( IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Plane_Origin( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_origin );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Plane_Normal( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_normal );

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


#endif
