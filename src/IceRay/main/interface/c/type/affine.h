#ifndef c55aed2882e3488dad1e09a70432d100
#define c55aed2882e3488dad1e09a70432d100

#include "./scalar.h"
#include "./coord.h"

typedef struct IceRayC_Type_Math_Affine1D_Struct{ IceRayC_TypeScalar value[2][1];  } IceRayC_Type_Math_Affine1D;
typedef struct IceRayC_Type_Math_Affine2D_Struct{ IceRayC_TypeScalar value[3][2];  } IceRayC_Type_Math_Affine2D;
typedef struct IceRayC_Type_Math_Affine3D_Struct{ IceRayC_TypeScalar value[4][3];  } IceRayC_Type_Math_Affine3D;
typedef struct IceRayC_Type_Math_Affine4D_Struct{ IceRayC_TypeScalar value[5][4];  } IceRayC_Type_Math_Affine4D;

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine1D_ID( IceRayC_Type_Math_Affine1D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine2D_ID( IceRayC_Type_Math_Affine2D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_ID( IceRayC_Type_Math_Affine3D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine4D_ID( IceRayC_Type_Math_Affine4D *P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine1D_Zero( IceRayC_Type_Math_Affine1D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine2D_Zero( IceRayC_Type_Math_Affine2D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_Zero( IceRayC_Type_Math_Affine3D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine4D_Zero( IceRayC_Type_Math_Affine4D *P_this );


IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_System( IceRayC_Type_Math_Affine3D *P_this, IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_X, IceRayC_TypeCoordScalar3D* P_Y, IceRayC_TypeCoordScalar3D* P_Z );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_SystemZ( IceRayC_Type_Math_Affine3D *P_this, IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_Z );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_Move( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_ScaleS( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_ScaleV( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_RotateX( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_RotateY( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_RotateZ( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_RotateA( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_direction, IceRayC_TypeScalar P_alpha );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_RotateD( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_pivot, IceRayC_TypeCoordScalar3D* P_direction, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_LookAt( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_eye, IceRayC_TypeCoordScalar3D* P_view, IceRayC_TypeCoordScalar3D* P_up );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine3D_Compose( IceRayC_Type_Math_Affine3D *P_that, IceRayC_Type_Math_Affine3D* P_left, IceRayC_Type_Math_Affine3D* P_right );


#endif
