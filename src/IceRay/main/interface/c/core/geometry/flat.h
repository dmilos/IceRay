#ifndef _aa64708707404cc89d093407417b0a07
#define _aa64708707404cc89d093407417b0a07

#include "../../system/system.h"
#include "../../type/type.h"


#include "./handle.h"

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Box0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Box1( IceRayC_TypeCoordScalar3D* lo, IceRayC_TypeCoordScalar3D* hi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Box_Lo( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_lo );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Box_Hi( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_hi );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Triangle0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Triangle1( IceRayC_TypeCoordScalar3D* e0, IceRayC_TypeCoordScalar3D* ex, IceRayC_TypeCoordScalar3D* ey );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_Origin( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_origin );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_eX( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_eX );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Triangle_eY( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_eY );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_TriangleU0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_UDisc0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_UDisc1( IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Disc0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Disc1(  IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeCoordScalar3D* P_normal, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Center( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Normal( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Radius( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_radius );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_UDisc0();
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_UDisc_Radius( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Plane0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Plane1( IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Plane_Origin( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_origin );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Plane_Normal( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_normal );

#endif
