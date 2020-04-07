#ifndef _316ce8b0570640088b1365924a6e3ca8
#define _316ce8b0570640088b1365924a6e3ca8

#include "../../system/system.h"


struct  IceRayC_Render_Scanner_Struct {};
typedef IceRayC_Render_Scanner_Struct* IceRayC_Render_Scanner_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Render_Scanner_Release( IceRayC_Render_Scanner_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Scanner_Handle IceRayC_Render_Scanner_Block0();
IceRayC__EXPORT IceRayC__DECLSPEC  int                           IceRayC_Render_Scanner_BlockHot( IceRayC_Render_Scanner_Handle P_this, IceRayC_TypeSize P_x, IceRayC_TypeSize P_y );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Scanner_Handle IceRayC_Render_Scanner_Parallel0();


#endif
