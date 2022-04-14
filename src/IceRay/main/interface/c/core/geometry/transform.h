#ifndef _d7a71bc3ff7e4c049da6d3f05d4313ed
#define _d7a71bc3ff7e4c049da6d3f05d4313ed


#include "../../system/system.h"
#include "../../type/type.h"

#include "./handle.h"

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Identity0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Identity1(      IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Identity_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate1(      IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate2(      IceRayC_Geometry_Handle P_child, IceRayC_TypeCoordScalar3D* translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Translate_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Translate_2Local_Get(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Translate_2Local_Set(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Translate_2World_Get(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Translate_2World_Set(  IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* translation );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine1( IceRayC_Geometry_Handle child, IceRayC_Type_Math_Affine3D* P_2world );
// TODO IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine2( IceRayC_Geometry_Handle child, IceRayC_TypeMatrix3D P_affine, IceRayC_TypeCoordScalar3D* P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_2Local_Get( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_2Local_Set( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_2World_Get( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Affine_2World_Set( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D* P_2world );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Homography0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Homography1( IceRayC_Geometry_Handle P_child, IceRayC_Type_Math_Homography3D* P_2world );

IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Homography_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Homography_2Local_Get( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Homography3D* P_2local );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Homography_2Local_Set( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Homography3D* P_2local );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Homography_2World_Get( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Homography3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_Homography_2World_Set( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Homography3D* P_2world );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_MotionBlur0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_MotionBlur1( IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Transform_MotionBlur2( IceRayC_Geometry_Handle P_child, IceRayC_TypeCoordScalar3D* P_direction );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_MotionBlur_Child(     IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Transform_MotionBlur_Direction( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_direction );

#endif



