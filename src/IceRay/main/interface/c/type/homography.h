#ifndef f62931457bf84c3c848e7a4bfefabdff
#define f62931457bf84c3c848e7a4bfefabdff

#include "./scalar.h"
#include "./matrix.h"
#include "./affine.h"

typedef IceRayC_Type_Math_Matrix2D IceRayC_Type_Math_Homography1D_Struct, IceRayC_Type_Math_Homography1D;
typedef IceRayC_Type_Math_Matrix3D IceRayC_Type_Math_Homography2D_Struct, IceRayC_Type_Math_Homography2D;
typedef IceRayC_Type_Math_Matrix4D IceRayC_Type_Math_Homography3D_Struct, IceRayC_Type_Math_Homography3D;

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Construct1D( IceRayC_Type_Math_Matrix2D *P_result, IceRayC_TypeScalar  P_A, IceRayC_TypeScalar  P_B );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Construct2D( IceRayC_Type_Math_Matrix3D *P_result, IceRayC_TypeCoordScalar2D *P_point );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Construct3D( IceRayC_Type_Math_Matrix4D *P_result, IceRayC_TypeCoordScalar3D *P_point );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Transform1D( IceRayC_TypeCoordScalar1D *P_result, IceRayC_Type_Math_Matrix2D *P_matrix, IceRayC_TypeCoordScalar1D *P_point );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Transform2D( IceRayC_TypeCoordScalar2D *P_result, IceRayC_Type_Math_Matrix3D *P_matrix, IceRayC_TypeCoordScalar2D *P_point );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography_Transform3D( IceRayC_TypeCoordScalar3D *P_result, IceRayC_Type_Math_Matrix4D *P_matrix, IceRayC_TypeCoordScalar3D *P_point );


#endif
