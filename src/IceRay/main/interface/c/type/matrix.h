#ifndef _5379ff013fad4335bbd80cd08b095c3f
#define _5379ff013fad4335bbd80cd08b095c3f

#include "./scalar.h"
#include "./coord.h"

typedef struct IceRayC_Type_Math_Matrix1D_Struct{ IceRayC_TypeScalar value[2][1];  } IceRayC_Type_Math_Matrix1D;
typedef struct IceRayC_Type_Math_Matrix2D_Struct{ IceRayC_TypeScalar value[3][2];  } IceRayC_Type_Math_Matrix2D;
typedef struct IceRayC_Type_Math_Matrix3D_Struct{ IceRayC_TypeScalar value[4][3];  } IceRayC_Type_Math_Matrix3D;
typedef struct IceRayC_Type_Math_Matrix4D_Struct{ IceRayC_TypeScalar value[5][4];  } IceRayC_Type_Math_Matrix4D;


IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_ID( IceRayC_Type_Math_Matrix3D *P_that );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_Zero( IceRayC_Type_Math_Matrix3D *P_that );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_Move( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeCoordScalar3D* P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_ScaleS( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_ScaleV( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeCoordScalar3D* P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_RotateX( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_RotateY( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_RotateZ( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_RotateA( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeCoordScalar3D* P_direction, IceRayC_TypeScalar P_alpha );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix1D_Multiply( IceRayC_Type_Math_Matrix1D *P_that, IceRayC_Type_Math_Matrix1D* P_left, IceRayC_Type_Math_Matrix1D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix2D_Multiply( IceRayC_Type_Math_Matrix2D *P_that, IceRayC_Type_Math_Matrix2D* P_left, IceRayC_Type_Math_Matrix2D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_Multiply( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_Type_Math_Matrix3D* P_left, IceRayC_Type_Math_Matrix3D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix4D_Multiply( IceRayC_Type_Math_Matrix4D *P_that, IceRayC_Type_Math_Matrix4D* P_left, IceRayC_Type_Math_Matrix4D* P_right );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix1D_Addition(    IceRayC_Type_Math_Matrix1D *P_that, IceRayC_Type_Math_Matrix1D* P_left, IceRayC_Type_Math_Matrix1D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix2D_Addition(    IceRayC_Type_Math_Matrix2D *P_that, IceRayC_Type_Math_Matrix2D* P_left, IceRayC_Type_Math_Matrix2D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_Addition(    IceRayC_Type_Math_Matrix3D *P_that, IceRayC_Type_Math_Matrix3D* P_left, IceRayC_Type_Math_Matrix3D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix4D_Addition(    IceRayC_Type_Math_Matrix4D *P_that, IceRayC_Type_Math_Matrix4D* P_left, IceRayC_Type_Math_Matrix4D* P_right );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix1D_Subtraction( IceRayC_Type_Math_Matrix1D *P_that, IceRayC_Type_Math_Matrix1D* P_left, IceRayC_Type_Math_Matrix1D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix2D_Subtraction( IceRayC_Type_Math_Matrix2D *P_that, IceRayC_Type_Math_Matrix2D* P_left, IceRayC_Type_Math_Matrix2D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_Subtraction( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_Type_Math_Matrix3D* P_left, IceRayC_Type_Math_Matrix3D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix4D_Subtraction( IceRayC_Type_Math_Matrix4D *P_that, IceRayC_Type_Math_Matrix4D* P_left, IceRayC_Type_Math_Matrix4D* P_right );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix1D_Scale( IceRayC_Type_Math_Matrix1D *P_that, IceRayC_Type_Math_Matrix1D* P_left, IceRayC_Type_Math_Matrix1D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix2D_Scale( IceRayC_Type_Math_Matrix2D *P_that, IceRayC_Type_Math_Matrix2D* P_left, IceRayC_Type_Math_Matrix2D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix3D_Scale( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_Type_Math_Matrix3D* P_left, IceRayC_Type_Math_Matrix3D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Matrix4D_Scale( IceRayC_Type_Math_Matrix4D *P_that, IceRayC_Type_Math_Matrix4D* P_left, IceRayC_Type_Math_Matrix4D* P_right );


#endif
