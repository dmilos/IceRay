#ifndef _e3c61c8f62634e81978ff68424b2493c
#define _e3c61c8f62634e81978ff68424b2493c

#include "./handle.h"
#include "../../../../type/int.h"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


IceRayC__EXPORT IceRayC__DECLSPEC   H   F( Expression0 )( S P_output, S P_input );
IceRayC__EXPORT IceRayC__DECLSPEC   int F( Expression_Expression)( H P_handle, char *P_expression );
IceRayC__EXPORT IceRayC__DECLSPEC   int F( Expression_String2Index)( H P_handle, S P_index, char*P_expression );
IceRayC__EXPORT IceRayC__DECLSPEC   int F( Expression_Index2Index )( H P_handle, S P_target, S P_source );

#undef H
#undef S
#undef F
#undef P


#endif
