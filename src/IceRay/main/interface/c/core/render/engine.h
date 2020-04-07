#ifndef f27b1a89b6d346119afe2c9694aa4502
#define f27b1a89b6d346119afe2c9694aa4502

#include "../../system/system.h"

struct  IceRayC_Render_Engine_Struct {};
typedef IceRayC_Render_Engine_Struct* IceRayC_Render_Engine_Handle;

#include "./scanner.h"
#include "./pixel.h"
#include "./scanner.h"
#include "./pierce.h"
#include "./sheaf.h"
#include "./ray.h"

#include "../../type/picture.h"


IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_RenderEngine_Release( IceRayC_Render_Engine_Handle P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Engine_Handle IceRayC_Render_Engine0();
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Scanner( IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Scanner_Handle P_scanner );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Pixel(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Pixel_Handle P_pixel );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Pierce(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Pierce_Handle P_perce );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Sheaf(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Sheaf_Handle P_sheaf );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Ray( IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Ray_Handle P_ray );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Start( IceRayC_Render_Engine_Handle P_this, IceRayC_Type_Picture_Handle P_picture );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Stop(IceRayC_Render_Engine_Handle P_this);
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Progress(IceRayC_Render_Engine_Handle P_this);

#endif
