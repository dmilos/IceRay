#ifndef _f63c6fb88af248c5a6cf6a6a60ce423d
#define _f63c6fb88af248c5a6cf6a6a60ce423d

#include "../../system/system.h"
#include "../../type/type.h"

#include "./handle.h"
#include "./rtss.h"


struct  IceRayC_Geometry_Blobby_Element_Struct {};
typedef IceRayC_Geometry_Blobby_Element_Struct* IceRayC_Geometry_Blobby_Element_Handle;


IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Geometry_Blobby_Element_Release( IceRayC_Geometry_Blobby_Element_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle                IceRayC_Geometry_Blobby_System0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_System_RTSS( IceRayC_Geometry_Handle  P_system, IceRayC_Geometry_RTSS_Handle P_rtss );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_System_Push( IceRayC_Geometry_Handle  P_system, IceRayC_Geometry_Blobby_Element_Handle P_element );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Sphere0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Sphere1( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeScalar P_influence, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Sphere_Influence(   IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_TypeScalar P_core );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Sphere_Radius( IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Sphere_Center( IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_TypeCoordScalar3D* P_center );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_USphere0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_USphere1( IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_USphere_Core( IceRayC_Geometry_Blobby_Element_Handle P_this,IceRayC_TypeScalar P_core );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_UCylinderZ0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_UCylinderZ1( IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_UCylinderZ_Core( IceRayC_Geometry_Blobby_Element_Handle P_this,IceRayC_TypeScalar P_core );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_UWaterZ0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_UWaterZ1( IceRayC_TypeScalar P_level );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_UWaterZ_Level( IceRayC_Geometry_Blobby_Element_Handle P_this,IceRayC_TypeScalar P_level );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Translate0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Translate1( IceRayC_Geometry_Blobby_Element_Handle P_child, IceRayC_TypeCoordScalar3D* P_translate );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Translate_Move( IceRayC_Geometry_Blobby_Element_Handle P_this,  IceRayC_TypeCoordScalar3D* P_translate );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Translate_Child( IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_Geometry_Blobby_Element_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Affine0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Affine1(    IceRayC_Geometry_Blobby_Element_Handle P_element, IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Affine_2World_Get( IceRayC_Geometry_Blobby_Element_Handle P_this,  IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Affine_2World_Set( IceRayC_Geometry_Blobby_Element_Handle P_this,  IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Affine_2World_Get( IceRayC_Geometry_Blobby_Element_Handle P_this,  IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Affine_2World_Set( IceRayC_Geometry_Blobby_Element_Handle P_this,  IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                      IceRayC_Geometry_Blobby_Element_Affine_Child( IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_Geometry_Blobby_Element_Handle P_child );

#endif

