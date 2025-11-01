#ifndef _8e002057e2054037b130a21f31f07264
#define _8e002057e2054037b130a21f31f07264

#include "../../system/system.h"
#include "../../type/type.h"

#include "./handle.h"

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist1( IceRayC_TypeScalar P_density );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist2( IceRayC_TypeScalar P_density, IceRayC_TypeScalar P_precision );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist3( IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist4( IceRayC_Geometry_Handle P_hull, IceRayC_TypeScalar P_density );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist5( IceRayC_Geometry_Handle P_hull, IceRayC_TypeScalar P_density, IceRayC_TypeScalar P_precision );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Mist_Seed(      IceRayC_Geometry_Handle P_this, IceRayC_TypeSize   P_seed );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Mist_Density(   IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_density );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Mist_Hull(      IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Mist_Precision( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_precision );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke2( IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Smoke_Hull( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Smoke_Density( IceRayC_Geometry_Handle P_this, char *P_density );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum1( IceRayC_TypeCoordScalar3D* P_lo, IceRayC_TypeCoordScalar3D* P_hi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Vacuum_Lo( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_lo );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Vacuum_Hi( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_hi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Volumetric_Vacuum_Box( IceRayC_Geometry_Handle P_this, IceRayC_TypeInterval3D* P_box );

#endif
