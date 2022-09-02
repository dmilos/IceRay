#ifndef _316ce8b0570640088b1365924a6e3ca8
#define _316ce8b0570640088b1365924a6e3ca8

#include "../../system/system.h"
#include "../../type/coord.h"


struct  IceRayC_Render_Scanner_Struct {};
typedef IceRayC_Render_Scanner_Struct* IceRayC_Render_Scanner_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool             IceRayC_Render_Scanner_Release( IceRayC_Render_Scanner_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Scanner_Handle IceRayC_Render_Scanner_Block0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool             IceRayC_Render_Scanner_Block_Hot( IceRayC_Render_Scanner_Handle P_this, IceRayC_TypeCoordSize2D* P_hot );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool             IceRayC_Render_Scanner_Block_Window( IceRayC_Render_Scanner_Handle P_this, IceRayC_TypeCoordSize2D* P_A, IceRayC_TypeCoordSize2D* P_b );



IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Scanner_Handle IceRayC_Render_Scanner_Parallel0();


#endif
