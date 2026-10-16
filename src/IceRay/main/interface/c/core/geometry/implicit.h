#ifndef _a4dffdc439204534a8b4518ecb816566
#define _a4dffdc439204534a8b4518ecb816566

#include "../../system/system.h"
#include "../../type/type.h"

#include "./handle.h"


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Implicit0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Implicit1( IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Implicit_Hull( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Implicit_Expression( IceRayC_Geometry_Handle P_this, char *P_expression );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Implicit_Interval( IceRayC_Geometry_Handle P_this, IceRayC_TypeInterval3D *P_interval );

IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Implicit_Delta(     IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_delta     );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Implicit_Sampling(  IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_sampling  );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Implicit_Iteration( IceRayC_Geometry_Handle P_this, IceRayC_TypeSize   P_iteration );

#endif
