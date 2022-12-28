#ifndef _67559bc4b87c473998992308ef219db8
#define _67559bc4b87c473998992308ef219db8

#include "./handle.h"
#include "../../../../type/int.h"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Integer_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Addition0     )( S P_result, S P_left,   S P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Load0         )( S P_result, S P_r, S P_g, S P_b )
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Multiply0     )( S P_result, S P_left,   S P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Scale0        )( S P_result, S P_scalar, S P_coord );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Subtraction0  )( S P_result, S P_left,   S P_right );

#undef H
#undef S
#undef F
#undef P


#endif
