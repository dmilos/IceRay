#ifndef _c719344dbb04491bab3d127f8af974e8
#define _c719344dbb04491bab3d127f8af974e8

#include "../../../type/size.h"
#include "../../../../type/color.hpp"
#include "../../../../type/coord.h"

#include "./handle.h"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Constant_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Size0           )( IceRayC_Type_Size            P_value, S P_result );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Scalar0         )( IceRayC_Type_Scalar          P_value, S P_result );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Color0          )( IceRayC_Type_Color_RGB*      P_value, S P_result );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Coord_Size2D0   )( IceRayC_Type_Coord_Size2D*   P_value, S P_result );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Coord_Size3D0   )( IceRayC_Type_Coord_Size3D*   P_value, S P_result );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Coord_Size4D0   )( IceRayC_Type_Coord_Size4D*   P_value, S P_result );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Coord_Scalar2D0 )( IceRayC_Type_Coord_Scalar2D* P_value, S P_result );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Coord_Scalar3D0 )( IceRayC_Type_Coord_Scalar3D* P_value, S P_result );
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Coord_Scalar4D0 )( IceRayC_Type_Coord_Scalar4D* P_value, S P_result );

#undef H
#undef S
#undef F
#undef P


#endif
