#ifndef _1bf693e54f7347ceac3e3d8ffc62fccd
#define _1bf693e54f7347ceac3e3d8ffc62fccd

#include "./pigment.h"

struct IceRayC_Material_Pigment_InstructionStruct {}; //!< IceRayC_Material_Pigment_Surfcace_Instruction_Struct
typedef IceRayC_Material_Pigment_InstructionStruct* IceRayC_Material_Pigment_InstructionHandle;

struct IceRayC_Material_Pigment_Surfcace_Instruction_Struct {}; 
typedef IceRayC_Material_Pigment_Surfcace_Instruction_Struct* IceRayC_Material_Pigment_Surfcace_Instruction_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC void                                       IceRayC_Material_Pigment_Surface_Instruction_Release( IceRayC_Material_Pigment_InstructionHandle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_Pigment_InstructionHandle IceRayC_Material_Pigment_Surface_Instruction_NOP0();

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_Pigment_InstructionHandle IceRayC_Material_Pigment_Surface_Instruction_Ambinet0( IceRayC_TypeSize P_result, IceRayC_TypeSize P_emmision );


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_Pigment_InstructionHandle IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmA0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_Pigment_InstructionHandle IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmB0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_Pigment_InstructionHandle IceRayC_Material_Pigment_Surface_Instruction_Light_SwarmC0();

#endif
