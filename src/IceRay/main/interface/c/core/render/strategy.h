#ifndef _9a9c4ec5248c4e2d8d1658ede6a0df3f
#define _9a9c4ec5248c4e2d8d1658ede6a0df3f

#include "../../system/system.h"
#include "../../type/bool.h"
#include "../../type/size.h"

struct  IceRayC_Render_Pixel_Strategy_Struct {};
typedef IceRayC_Render_Pixel_Strategy_Struct* IceRayC_Render_Pixel_Strategy_Handle;



IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool IceRayC_Render_Pixel_Strategy_Release( IceRayC_Render_Pixel_Strategy_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Center0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Grid0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Grid1( IceRayC_Type_Size  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                    IceRayC_Render_Pixel_Strategy_Grid_Size( IceRayC_Render_Pixel_Strategy_Handle, IceRayC_Type_Size );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Random0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Random1( IceRayC_Type_Size  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                    IceRayC_Render_Pixel_Strategy_Random_Size( IceRayC_Render_Pixel_Strategy_Handle, IceRayC_Type_Size );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Sobol0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Sobol1( IceRayC_Type_Size  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool                    IceRayC_Render_Pixel_Strategy_Sobol_Size( IceRayC_Render_Pixel_Strategy_Handle, IceRayC_Type_Size );


#endif

