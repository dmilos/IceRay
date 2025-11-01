#ifndef _7ae067a596e14eb29bc19710083b566a
#define _7ae067a596e14eb29bc19710083b566a

#include "../../system/system.h"
#include "../../type/bool.h"

#include "./strategy.h"
#include "./filter.h"


struct  IceRayC_Render_Pixel_Struct {};
typedef IceRayC_Render_Pixel_Struct* IceRayC_Render_Pixel_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool IceRayC_Render_Pixel_Release( IceRayC_Render_Pixel_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Handle IceRayC_Render_Pixel_Constant0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Handle IceRayC_Render_Pixel_UV0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Handle IceRayC_Render_Pixel_Basic0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool           IceRayC_Render_Pixel_Basic_Strategy( IceRayC_Render_Pixel_Handle P_this, IceRayC_Render_Pixel_Strategy_Handle );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool           IceRayC_Render_Pixel_Basic_Filter(   IceRayC_Render_Pixel_Handle P_this, IceRayC_Render_Pixel_Filter_Handle );


#endif
