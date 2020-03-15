#ifndef e6d24b382fc44b2e80407a9f0b6e90ea
#define e6d24b382fc44b2e80407a9f0b6e90ea

#include "../../system/system.h"

#include "../material/material.h"
#include "../geometry/geometry.h"

typedef  void * IceRayC_Object;

struct IceRayC_ObjectStruct {};
typedef IceRayC_ObjectStruct* IceRayC_ObjectHandle;

IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Object_Release( IceRayC_ObjectHandle );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_ObjectHandle  IceRayC_Object0( );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_ObjectHandle  IceRayC_Object1( IceRayC_GeometryHandle P_geometry );

#endif
