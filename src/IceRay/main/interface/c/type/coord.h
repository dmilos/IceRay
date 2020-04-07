#ifndef cb0b687ed3f74c1b85aeb61578d21596
#define cb0b687ed3f74c1b85aeb61578d21596

#include "./size.h"
#include "./scalar.h"

#include "../system/system.h"



typedef struct IceRayC_TypeCoordScalar1D{ IceRayC_TypeScalar value[1]; } IceRayC_TypeCoordScalar1D;
typedef struct IceRayC_TypeCoordScalar2D{ IceRayC_TypeScalar value[2]; } IceRayC_TypeCoordScalar2D;
typedef struct IceRayC_TypeCoordScalar3D{ IceRayC_TypeScalar value[3]; } IceRayC_TypeCoordScalar3D;
typedef struct IceRayC_TypeCoordScalar4D{ IceRayC_TypeScalar value[4]; } IceRayC_TypeCoordScalar4D;

typedef struct IceRayC_TypeCoordSize1D{ IceRayC_TypeSize value[1]; } IceRayC_TypeCoordSize1D;
typedef struct IceRayC_TypeCoordSize2D{ IceRayC_TypeSize value[2]; } IceRayC_TypeCoordSize2D;
typedef struct IceRayC_TypeCoordSize3D{ IceRayC_TypeSize value[3]; } IceRayC_TypeCoordSize3D;
typedef struct IceRayC_TypeCoordSize4D{ IceRayC_TypeSize value[4]; } IceRayC_TypeCoordSize4D;


IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord1D_Fill( IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeScalar );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord2D_Fill( IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeScalar );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord3D_Fill( IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeScalar );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord4D_Fill( IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeScalar );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord1D_Load( IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeScalar );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord2D_Load( IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeScalar, IceRayC_TypeScalar );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord3D_Load( IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeScalar, IceRayC_TypeScalar, IceRayC_TypeScalar );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord4D_Load( IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeScalar, IceRayC_TypeScalar, IceRayC_TypeScalar, IceRayC_TypeScalar );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_TypeScalar  IceRayC_Type_Math_Coord1D_Length( IceRayC_TypeCoordScalar1D *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_TypeScalar  IceRayC_Type_Math_Coord2D_Length( IceRayC_TypeCoordScalar2D *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_TypeScalar  IceRayC_Type_Math_Coord3D_Length( IceRayC_TypeCoordScalar3D *P_that );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_TypeScalar  IceRayC_Type_Math_Coord4D_Length( IceRayC_TypeCoordScalar4D *P_that );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_TypeScalar  IceRayC_Type_Math_Coord1D_Distance( IceRayC_TypeCoordScalar1D* P_left, IceRayC_TypeCoordScalar1D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_TypeScalar  IceRayC_Type_Math_Coord2D_Distance( IceRayC_TypeCoordScalar2D* P_left, IceRayC_TypeCoordScalar2D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_TypeScalar  IceRayC_Type_Math_Coord3D_Distance( IceRayC_TypeCoordScalar3D* P_left, IceRayC_TypeCoordScalar3D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_TypeScalar  IceRayC_Type_Math_Coord4D_Distance( IceRayC_TypeCoordScalar4D* P_left, IceRayC_TypeCoordScalar4D* P_right );


IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord3D_Cross(    IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeCoordScalar3D* P_left, IceRayC_TypeCoordScalar3D* P_right );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord1D_Addition(    IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeCoordScalar1D* P_left, IceRayC_TypeCoordScalar1D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord2D_Addition(    IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeCoordScalar2D* P_left, IceRayC_TypeCoordScalar2D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord3D_Addition(    IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeCoordScalar3D* P_left, IceRayC_TypeCoordScalar3D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord4D_Addition(    IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeCoordScalar4D* P_left, IceRayC_TypeCoordScalar4D* P_right );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord1D_Subtraction( IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeCoordScalar1D* P_left, IceRayC_TypeCoordScalar1D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord2D_Subtraction( IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeCoordScalar2D* P_left, IceRayC_TypeCoordScalar2D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord3D_Subtraction( IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeCoordScalar3D* P_left, IceRayC_TypeCoordScalar3D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord4D_Subtraction( IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeCoordScalar4D* P_left, IceRayC_TypeCoordScalar4D* P_right );

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord1D_Scale(    IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeScalar P_left, IceRayC_TypeCoordScalar1D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord2D_Scale(    IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeScalar P_left, IceRayC_TypeCoordScalar2D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord3D_Scale(    IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeScalar P_left, IceRayC_TypeCoordScalar3D* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Math_Coord4D_Scale(    IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeScalar P_left, IceRayC_TypeCoordScalar4D* P_right );



#endif
