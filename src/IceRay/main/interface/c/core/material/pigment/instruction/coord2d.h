#ifndef _f09cdb78cdb04d3fac50946ea6067483
#define _f09cdb78cdb04d3fac50946ea6067483

#include "./handle.h"
#include "../../../../type/coord.h"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Coord2D_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Addition0     )( S P_result, S P_left,   S P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Load0         )( S P_result, S P_X, S P_Y );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Multiply0     )( S P_result, S P_left,   S P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Scale0        )( S P_result, S P_scalar, S P_coord );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Subtraction0  )( S P_result, S P_left,   S P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Unit0         )( S P_result, S P_model );

#undef H
#undef S
#undef F
#undef P

#endif

