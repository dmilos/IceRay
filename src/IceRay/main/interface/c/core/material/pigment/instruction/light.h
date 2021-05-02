#ifndef _cf9d08336a35441a9810d21f0aa8d132
#define _cf9d08336a35441a9810d21f0aa8d132


#include "./handle.h"
#include "../../../light/light.h"
#include "../../../geometry/geometry.h"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Light_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


IceRayC__EXPORT IceRayC__DECLSPEC H F(Generator0)( IceRayC_Light_Handle P_light, S result );

IceRayC__EXPORT IceRayC__DECLSPEC H F(SwarmA0)(                               S P_outSize_SpotEnd, S P_inSize_SpotBegin, S P_inLight_Light, S P_inCoord_Point );
IceRayC__EXPORT IceRayC__DECLSPEC H F(SwarmB0)(                               S P_outSize_SpotEnd, S P_inSize_SpotBegin, S P_inLight_Light, S P_inCoord_Point, S P_inCoord_Normal, S P_inBool_Cull );
IceRayC__EXPORT IceRayC__DECLSPEC H F(SwarmC0)( IceRayC_Light_Handle P_light, S P_outSize_SpotEnd, S P_inSize_SpotBegin,                    S P_inCoord_Point, S P_inCoord_Normal );

#undef F

#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Spot_##D_P

IceRayC__EXPORT IceRayC__DECLSPEC H F(Cull0 )( S P_point, S P_normal, S P_outSize_SpotEnd, S P_inSize_SpotBegin, S P_inSize_SpotEnd );
IceRayC__EXPORT IceRayC__DECLSPEC H F(UWV0  )( S P_point, S P_normal, S P_out,    S P_spotIndex );

IceRayC__EXPORT IceRayC__DECLSPEC H F(Confine0  )( IceRayC_Geometry_Handle P_geometry, S P_outSize_SpotEnd, S P_inSize_SpotBegin, S P_inSize_SpotEnd );
IceRayC__EXPORT IceRayC__DECLSPEC H F(Obstruct0 )( IceRayC_Geometry_Handle P_geometry, S P_outSize_SpotEnd, S P_inSize_SpotBegin, S P_inSize_SpotEnd );



#undef H
#undef S
#undef F
#undef P


#endif

