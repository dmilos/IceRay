#ifndef e6d24b382fc44b2e80407a9f0b6e90ea
#define e6d24b382fc44b2e80407a9f0b6e90ea

#include "../../system/system.h"

#include "../material/material.h"
#include "../geometry/geometry.h"


struct IceRayC_Object_Struct {};
typedef IceRayC_Object_Struct* IceRayC_Object_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool          IceRayC_Object_Release( IceRayC_Object_Handle P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Object_Handle      IceRayC_Object0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Object_Handle      IceRayC_Object1( IceRayC_Geometry_Handle P_geometry );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle    IceRayC_Object_Cast2Geometry( IceRayC_Object_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool          IceRayC_Object_Geometry_Set(  IceRayC_Object_Handle P_this, IceRayC_Geometry_Handle  P_gemetry );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle    IceRayC_Object_Geometry_Get(  IceRayC_Object_Handle P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool          IceRayC_Object_Pigment(       IceRayC_Object_Handle P_this, IceRayC_Material_PigmentHandle  P_pigment );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool          IceRayC_Object_Medium(        IceRayC_Object_Handle P_this, IceRayC_Material_MediumHandle   P_medium  );

#endif
