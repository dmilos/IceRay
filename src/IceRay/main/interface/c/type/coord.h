#ifndef cb0b687ed3f74c1b85aeb61578d21596
#define cb0b687ed3f74c1b85aeb61578d21596

#include "./size.h"
#include "./scalar.h"

typedef struct IceRayC_TypeCoord1D{ IceRayC_TypeScalar value[1]; } IceRayC_TypeCoord1D, IceRayC_TypeCoordScalar1D;
typedef struct IceRayC_TypeCoord2D{ IceRayC_TypeScalar value[2]; } IceRayC_TypeCoord2D, IceRayC_TypeCoordScalar2D;
typedef struct IceRayC_TypeCoord3D{ IceRayC_TypeScalar value[3]; } IceRayC_TypeCoord3D, IceRayC_TypeCoordScalar3D;
typedef struct IceRayC_TypeCoord4D{ IceRayC_TypeScalar value[4]; } IceRayC_TypeCoord4D, IceRayC_TypeCoordScalar4D;

typedef struct IceRayC_TypeSize1D{ IceRayC_TypeSize value[1]; } IceRayC_TypeSize1D, IceRayC_TypeCoordSize1D;
typedef struct IceRayC_TypeSize2D{ IceRayC_TypeSize value[2]; } IceRayC_TypeSize2D, IceRayC_TypeCoordSize2D;
typedef struct IceRayC_TypeSize3D{ IceRayC_TypeSize value[3]; } IceRayC_TypeSize3D, IceRayC_TypeCoordSize3D;
typedef struct IceRayC_TypeSize4D{ IceRayC_TypeSize value[4]; } IceRayC_TypeSize4D, IceRayC_TypeCoordSize4D;


#endif
