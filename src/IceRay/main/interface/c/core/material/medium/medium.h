#ifndef _07122216d7fa47a6ac5c808621c8f5e9
#define _07122216d7fa47a6ac5c808621c8f5e9

#include "../../../system/system.h"
#include "../../../type/color.hpp"


struct IceRayC_Material_MediumStruct {};
typedef IceRayC_Material_MediumStruct* IceRayC_Material_MediumHandle;

IceRayC__EXPORT IceRayC__DECLSPEC void    IceRayC_Material_Medium_Release( IceRayC_Material_MediumHandle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Transparent0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Solid0();

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Constant0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Constant1( IceRayC_TypeColorRGB P_value, IceRayC_TypeColorRGB P_deplete);
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Constant_Value(   IceRayC_Material_MediumHandle P_this, IceRayC_TypeColorRGB* P_value   );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Constant_Deplete( IceRayC_Material_MediumHandle P_this, IceRayC_TypeColorRGB* P_deplete );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Linear0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Linear1( IceRayC_TypeColorRGB  P_value, IceRayC_TypeScalar P_A, IceRayC_TypeScalar  P_B );

IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Linear_Value(   IceRayC_Material_MediumHandle P_this, IceRayC_TypeColorRGB* P_value   );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Linear_A( IceRayC_Material_MediumHandle P_this, IceRayC_Type_Scalar P_A );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Linear_B( IceRayC_Material_MediumHandle P_this, IceRayC_Type_Scalar P_B );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Quadratic0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Quadratic1( IceRayC_TypeColorRGB P_value, IceRayC_TypeScalar P_A, IceRayC_TypeScalar P_B, IceRayC_TypeScalar P_C );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Quadratic_Value(      IceRayC_Material_MediumHandle P_that, IceRayC_TypeColorRGB* P_value );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Quadratic_A(      IceRayC_Material_MediumHandle P_this, IceRayC_Type_Scalar P_A );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Quadratic_B(      IceRayC_Material_MediumHandle P_this, IceRayC_Type_Scalar P_B );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Quadratic_C(      IceRayC_Material_MediumHandle P_this, IceRayC_Type_Scalar P_C );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Exponential0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Exponential1( IceRayC_TypeColorRGB P_value, IceRayC_TypeScalar P_half );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Exponential_Value(   IceRayC_Material_MediumHandle P_this, IceRayC_TypeColorRGB* P_value   );
IceRayC__EXPORT IceRayC__DECLSPEC int                            IceRayC_Material_Medium_Exponential_Half(    IceRayC_Material_MediumHandle P_this, IceRayC_Type_Scalar   P_half );




#endif
