#ifndef _abdcc1a9bd8942dd8db4f5d6f50964d9
#define _abdcc1a9bd8942dd8db4f5d6f50964d9


#include "../../system/system.h"
#include "../../type/type.h"

#include "./handle.h"

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect1( IceRayC_Geometry_Handle P_left, IceRayC_Geometry_Handle P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Left0( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_left );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Left1( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_left, int location );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Right0( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Right1( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_right, int location );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Enclose0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Enclose1( IceRayC_Geometry_Handle P_child, IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Enclose_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Enclose_Hull(  IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_hull  );

#endif
