#ifndef _092560462dfc4c18ae99181e0408d219
#define _092560462dfc4c18ae99181e0408d219

#include "../../system/system.h"

#include "../camera/camera.h"
#include "./sheaf.h"

struct  IceRayC_Render_PierceStruct {};
typedef IceRayC_Render_PierceStruct* IceRayC_Render_Pierce_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool            IceRayC_Render_Pierce_Release( IceRayC_Render_Pierce_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pierce_Handle IceRayC_Render_Pierce_UV0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Pierce_Handle IceRayC_Render_Pierce_Projector0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool            IceRayC_Render_Pierce_Projector_Camera( IceRayC_Render_Pierce_Handle, IceRayC_Camera_Handle P_camera );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool            IceRayC_Render_Pierce_Projector_Sheaf( IceRayC_Render_Pierce_Handle, IceRayC_Render_Sheaf_Handle P_sheaf );

#endif
