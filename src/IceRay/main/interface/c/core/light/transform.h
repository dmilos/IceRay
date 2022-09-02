#ifndef de13016a992840e9b03f83d77d1b5699
#define de13016a992840e9b03f83d77d1b5699

#include "./light.h"

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Identity0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Identity1(      IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Identity_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Translate0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Translate1(      IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Translate2(      IceRayC_Light_Handle P_child, IceRayC_TypeCoordScalar3D* translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Translate_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Translate_2Local_Get(  IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Translate_2Local_Set(  IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Translate_2World_Get(  IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Translate_2World_Set(  IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* translation );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Affine0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Affine1( IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Affine2( IceRayC_Light_Handle P_child, IceRayC_Type_Math_Affine3D *P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Affine_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Affine_2Local_Get( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Affine_2Local_Set( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Affine_2World_Get( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Affine3D* P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Affine_2World_Set( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Affine3D* P_2world );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Light_Handle IceRayC_Light_Transform_Homography0();
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Homography_Child(  IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Homography_2Local_Get( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Homography3D * P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Homography_2Local_Set( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Homography3D * P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Homography_2World_Get( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Homography3D * P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                  IceRayC_Light_Transform_Homography_2World_Set( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Homography3D * P_2world );


#endif
