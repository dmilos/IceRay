#ifndef f62931457bf84c3c848e7a4bfefabdff
#define f62931457bf84c3c848e7a4bfefabdff

#include "./scalar.h"

typedef struct IceRayC_Type_Math_Homography1D_Struct{ IceRayC_TypeScalar value[2][2];  } IceRayC_Type_Math_Homography1D_Struct;
typedef struct IceRayC_Type_Math_Homography2D_Struct{ IceRayC_TypeScalar value[3][3];  } IceRayC_Type_Math_Homography2D_Struct;
typedef struct IceRayC_Type_Math_Homography3D_Struct{ IceRayC_TypeScalar value[4][4];  } IceRayC_Type_Math_Homography3D_Struct;
typedef struct IceRayC_Type_Math_Homography4D_Struct{ IceRayC_TypeScalar value[5][5];  } IceRayC_Type_Math_Homography4D_Struct;

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography1D_ID( IceRayC_Type_Math_Homography1D_Struct *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography2D_ID( IceRayC_Type_Math_Homography2D_Struct *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography3D_ID( IceRayC_Type_Math_Homography3D_Struct *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography4D_ID( IceRayC_Type_Math_Homography4D_Struct *P_that );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography1D_Zero( IceRayC_Type_Math_Homography1D_Struct *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography2D_Zero( IceRayC_Type_Math_Homography2D_Struct *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography3D_Zero( IceRayC_Type_Math_Homography3D_Struct *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography4D_Zero( IceRayC_Type_Math_Homography4D_Struct *P_that );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography1D_Convert( IceRayC_Type_Math_Homography1D_Struct *P_that, IceRayC_Type_Math_Affine1D  * P_source );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography2D_Convert( IceRayC_Type_Math_Homography2D_Struct *P_that, IceRayC_Type_Math_Affine2D  * P_source );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography3D_Convert( IceRayC_Type_Math_Homography3D_Struct *P_that, IceRayC_Type_Math_Affine3D  * P_source );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Homography4D_Convert( IceRayC_Type_Math_Homography4D_Struct *P_that, IceRayC_Type_Math_Affine4D  * P_source );

#endif
