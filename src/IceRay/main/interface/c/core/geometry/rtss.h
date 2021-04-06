#ifndef _579f947a095d4571be744f75c9560b6c
#define _579f947a095d4571be744f75c9560b6c

#include "../../system/system.h"
#include "../../type/type.h"

#include "./handle.h"


struct  IceRayC_Geometry_RTSS_Struct {};
typedef IceRayC_Geometry_RTSS_Struct* IceRayC_Geometry_RTSS_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Geometry_RTSS_Release( IceRayC_Geometry_RTSS_Handle P_that );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_Object0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_Object1( IceRayC_Geometry_RTSS_Handle P_rtss );

IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_RTSS_Object_Rtss( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_RTSS_Handle P_rtss );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_RTSS_Object_Push( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_RTSS_Object_Clear( IceRayC_Geometry_Handle P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_RTSS_Object_Optimize( IceRayC_Geometry_Handle P_that );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_RTSS_Handle IceRayC_Geometry_RTSS_List0( );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_RTSS_Handle IceRayC_Geometry_RTSS_Uniform0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_RTSS_Handle IceRayC_Geometry_RTSS_Uniform1( IceRayC_TypeCoordSize3D* P_size );

IceRayC__EXPORT IceRayC__DECLSPEC  int                          IceRayC_Geometry_RTSS_Uniform_Dimension( IceRayC_Geometry_RTSS_Handle, IceRayC_TypeCoordSize3D* P_size);

#endif

