#ifndef _0c941b45a2f74f459e47f6d561e2b62e
#define _0c941b45a2f74f459e47f6d561e2b62e

#include "../system/system.h"

struct  IceRayC_Type_PictureStruct {};
typedef IceRayC_Type_PictureStruct* IceRayC_Type_PictureHandle;

IceRayC__EXPORT IceRayC__DECLSPEC void                  IceRayC_Type_Picture_Release( IceRayC_Type_PictureHandle P_this );


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_PictureHandle IceRayC_Type_Picture0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_PictureHandle IceRayC_Type_Picture1( char * filename );

IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_Type_Picture_Load( IceRayC_Type_PictureHandle P_this, char * filename );

#endif
