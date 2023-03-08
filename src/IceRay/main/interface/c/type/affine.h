#ifndef c55aed2882e3488dad1e09a70432d100
#define c55aed2882e3488dad1e09a70432d100

#include "./scalar.h"
#include "./coord.h"

typedef struct IceRayC_Type_Math_Affine1D_Struct{ IceRayC_TypeScalar value[2][1];  } IceRayC_Type_Math_Affine1D;
typedef struct IceRayC_Type_Math_Affine2D_Struct{ IceRayC_TypeScalar value[3][2];  } IceRayC_Type_Math_Affine2D;
typedef struct IceRayC_Type_Math_Affine3D_Struct{ IceRayC_TypeScalar value[4][3];  } IceRayC_Type_Math_Affine3D;
typedef struct IceRayC_Type_Math_Affine4D_Struct{ IceRayC_TypeScalar value[5][4];  } IceRayC_Type_Math_Affine4D;

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_ID1D( IceRayC_Type_Math_Affine1D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_ID2D( IceRayC_Type_Math_Affine2D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_ID3D( IceRayC_Type_Math_Affine3D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_ID4D( IceRayC_Type_Math_Affine4D *P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_Zero1D( IceRayC_Type_Math_Affine1D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_Zero2D( IceRayC_Type_Math_Affine2D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_Zero3D( IceRayC_Type_Math_Affine3D *P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_Zero4D( IceRayC_Type_Math_Affine4D *P_this );


#define C3D IceRayC_TypeCoordScalar3D
IceRayC__EXPORT IceRayC__DECLSPEC   int IceRayC_Type_Math_Affine_Construct3D
  (
    IceRayC_Type_Math_Affine3D *P_result
   ,C3D *P_tO, C3D *P_tX, C3D* P_tY, C3D * P_tZ
   ,C3D *P_sO, C3D *P_sX, C3D* P_sY, C3D * P_sZ
  );

#undef C3D


IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_System3D( IceRayC_Type_Math_Affine3D *P_this, IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_X, IceRayC_TypeCoordScalar3D* P_Y, IceRayC_TypeCoordScalar3D* P_Z );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_SystemZ3D( IceRayC_Type_Math_Affine3D *P_this, IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_Z );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_Move3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_ScaleS3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_ScaleV3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_RotateX3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_RotateY3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_RotateZ3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_RotateA3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_direction, IceRayC_TypeScalar P_alpha );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_RotateD3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_pivot, IceRayC_TypeCoordScalar3D* P_direction, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_Invert3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_Type_Math_Affine3D* P_right );


IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_LookAt3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_eye, IceRayC_TypeCoordScalar3D* P_view, IceRayC_TypeCoordScalar3D* P_up );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_Compose3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_Type_Math_Affine3D* P_left, IceRayC_Type_Math_Affine3D* P_right );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Affine_Transform3D( IceRayC_TypeCoordScalar3D *P_result, IceRayC_Type_Math_Affine3D* P_affine, IceRayC_TypeCoordScalar3D* P_point );

#endif
