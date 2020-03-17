#ifndef _32ce049216b944f7a33cc585162e8bc2
#define _32ce049216b944f7a33cc585162e8bc2

#include "../../system/system.h"
#include "../../type/size.h"


struct IceRayC_Material_PigmentStruct {};
typedef IceRayC_Material_PigmentStruct* IceRayC_Material_PigmentHandle;

IceRayC__EXPORT IceRayC__DECLSPEC void   IceRayC_Material_PigmentRelease( IceRayC_Material_PigmentHandle P_this );


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_PigmentHandle IceRayC_Material_PigmentSurface0();

//IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_PigmentHandle IceRayC_Material_PigmentSurface_Append( IceRayC_Material_PigmentHandle , IceRayC_Material_Pigment_InstructionHandle );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_PigmentHandle IceRayC_Material_PigmentSimple0();


#include "./instruction.h"

#endif
