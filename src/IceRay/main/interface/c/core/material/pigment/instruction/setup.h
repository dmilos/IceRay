#ifndef _a938c255ac9b4d388854587fb68e36d9
#define _a938c255ac9b4d388854587fb68e36d9

#include "./handle.h"
#include "../../../../type/int.h"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Setup_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle

IceRayC__EXPORT IceRayC__DECLSPEC  H F( ToViewer0      )( );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( PlaneIncident0 )( );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( PlaneSurface0  )( );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( PlaneReflect0  )( );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Reflect0       )( );

#undef H
#undef S
#undef F
#undef P


#endif
