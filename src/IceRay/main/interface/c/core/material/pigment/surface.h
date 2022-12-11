#ifndef _468cf08313234a4b95615a4dc8642d2f
#define _468cf08313234a4b95615a4dc8642d2f

#include "../../../system/system.h"
#include "../../../type/size.h"
#include "../../../type/size.h"

#include "./handle.h"
#include "./instruction/handle.h"


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Material_PigmentHandle     IceRayC_Material_Pigment_Surface0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Append( IceRayC_Material_PigmentHandle P_this, IceRayC_Material_Pigment_Surfcace_Instruction_Handle P_instruction );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Result( IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_result );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Lambda( IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_lambda );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Point(  IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_point  );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Normal( IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Incident( IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_incident );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Origin(   IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_origin   );

#endif
