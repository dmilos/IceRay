#ifndef _07122216d7fa47a6ac5c808621c8f5e9
#define _07122216d7fa47a6ac5c808621c8f5e9

#include "../../system/system.h"
#include "../../type/color.hpp"


struct IceRayC_Material_MediumStruct {};
typedef IceRayC_Material_MediumStruct* IceRayC_Material_MediumHandle;

IceRayC__EXPORT IceRayC__DECLSPEC void    IceRayC_Material_MediumRelease( IceRayC_Material_MediumHandle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Constant0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Constant1( IceRayC_TypeColorRGB P_value, IceRayC_TypeColorRGB P_deplete);

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Linear0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Linear1( IceRayC_TypeColorRGB  P_value, IceRayC_TypeScalar P_c0, IceRayC_TypeScalar  P_c1 );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Quadratic0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Quadratic1( IceRayC_TypeColorRGB P_value, IceRayC_TypeScalar P_c0, IceRayC_TypeScalar P_c1, IceRayC_TypeScalar P_c2 );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Exponential0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Exponential1( IceRayC_TypeColorRGB P_value, IceRayC_TypeScalar P_half );


#endif
