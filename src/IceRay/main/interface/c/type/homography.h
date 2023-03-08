#ifndef f62931457bf84c3c848e7a4bfefabdff
#define f62931457bf84c3c848e7a4bfefabdff

#include "./scalar.h"
#include "./matrix.h"
#include "./affine.h"

typedef IceRayC_Type_Math_Matrix2D IceRayC_Type_Math_Homography1D_Struct, IceRayC_Type_Math_Homography1D;
typedef IceRayC_Type_Math_Matrix3D IceRayC_Type_Math_Homography2D_Struct, IceRayC_Type_Math_Homography2D;
typedef IceRayC_Type_Math_Matrix4D IceRayC_Type_Math_Homography3D_Struct, IceRayC_Type_Math_Homography3D;

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Core1D( IceRayC_Type_Math_Homography1D *P_result, IceRayC_TypeScalar  P_A, IceRayC_TypeScalar  P_B );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Core2D( IceRayC_Type_Math_Homography2D *P_result, IceRayC_TypeCoordScalar2D *P_point );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Core3D( IceRayC_Type_Math_Homography3D *P_result, IceRayC_TypeCoordScalar3D *P_point );

#define C3D IceRayC_TypeCoordScalar3D
IceRayC__EXPORT IceRayC__DECLSPEC   int IceRayC_Type_Math_Homography_Construct3D
  ( IceRayC_Type_Math_Homography3D *P_result
        ,C3D *P_tO, C3D *P_tX, C3D* P_tY, C3D * P_tZ, C3D * P_tT
        ,C3D *P_sO, C3D *P_sX, C3D* P_sY, C3D * P_sZ, C3D * P_sT
       );

#undef C3D

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Transform1D( IceRayC_TypeCoordScalar1D *P_result, IceRayC_Type_Math_Homography1D *P_matrix, IceRayC_TypeCoordScalar1D *P_point );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Transform2D( IceRayC_TypeCoordScalar2D *P_result, IceRayC_Type_Math_Homography2D *P_matrix, IceRayC_TypeCoordScalar2D *P_point );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Transform3D( IceRayC_TypeCoordScalar3D *P_result, IceRayC_Type_Math_Homography3D *P_matrix, IceRayC_TypeCoordScalar3D *P_point );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_System1D( IceRayC_Type_Math_Homography1D *P_result, IceRayC_TypeScalar         P_pivot, IceRayC_TypeScalar         P_X, IceRayC_TypeScalar P_T );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_System2D( IceRayC_Type_Math_Homography2D *P_result, IceRayC_TypeCoordScalar2D *P_pivot, IceRayC_TypeCoordScalar2D *P_X, IceRayC_TypeCoordScalar2D* P_Y, IceRayC_TypeCoordScalar2D * P_T );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_System3D( IceRayC_Type_Math_Homography3D *P_result, IceRayC_TypeCoordScalar3D *P_pivot, IceRayC_TypeCoordScalar3D *P_X, IceRayC_TypeCoordScalar3D* P_Y, IceRayC_TypeCoordScalar3D * P_Z, IceRayC_TypeCoordScalar3D * P_T );

#endif
