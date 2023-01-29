#ifndef _a4ff2885f266411bb260d2e1749a7b7e
#define _a4ff2885f266411bb260d2e1749a7b7e

#include "../../system/system.h"
#include "../../type/type.h"


#include "./handle.h"

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_HField0();
//IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_HField_Function( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_HField_Function_Handle P_function );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_HField_Lo( IceRayC_Geometry_Handle, IceRayC_TypeCoordScalar3D* P_lo );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_HField_Hi( IceRayC_Geometry_Handle, IceRayC_TypeCoordScalar3D* P_hi );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Torus0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Torus1( IceRayC_TypeScalar P_minor );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Torus_Minor( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_minor );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_USphere0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Sphere0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Sphere1( IceRayC_TypeCoordScalar3D* center, IceRayC_TypeScalar radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Sphere_Center( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* center );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Sphere_Radius( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar radius );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid1( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid2( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeCoordScalar3D* P_eX, IceRayC_TypeCoordScalar3D* P_eY, IceRayC_TypeCoordScalar3D*  P_eZ );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Ellipsoid_Center(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Ellipsoid_RadiusS( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Ellipsoid_RadiusV( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Ellipsoid_System(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_eX, IceRayC_TypeCoordScalar3D* P_eY, IceRayC_TypeCoordScalar3D * P_eZ );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Quadric0();


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_CylinderU0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Cylinder0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Cylinder1( IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Cylinder2( IceRayC_TypeScalar P_radius, IceRayC_TypeScalar P_height );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Cylinder_Radius( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Cylinder_Height( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_height );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Cone0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Paraboloid0();


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid1( IceRayC_TypeScalar P_core );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_Hyperboloid_Core( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_core );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Saddle0();



#endif
