#ifndef x98f13e758cf040b095aa2adb09a21529
#define x98f13e758cf040b095aa2adb09a21529

#include "./scalar.h"
#include "IceRay/type/color.hpp"

typedef struct IceRayC_TypeColorGray { IceRayC_TypeScalar value ;    } IceRayC_TypeColorGray, IceRayC_Type_Color_Gray;
typedef struct IceRayC_TypeColorRGB  { IceRayC_TypeScalar value[3];  } IceRayC_TypeColorRGB , IceRayC_Type_Color_RGB ;
typedef struct IceRayC_TypeColorHSL  { IceRayC_TypeScalar value[3];  } IceRayC_TypeColorHSL , IceRayC_Type_Color_HSL ;
typedef struct IceRayC_TypeColorRGBA { IceRayC_TypeScalar value[4];  } IceRayC_TypeColorRGBA, IceRayC_Type_Color_RGBA;

IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Color_HSL2RGB( IceRayC_TypeColorRGB *P_left, IceRayC_TypeColorHSL* P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int  IceRayC_Type_Color_RGB2HSL( IceRayC_TypeColorHSL *P_left, IceRayC_TypeColorRGB* P_right );

#endif
