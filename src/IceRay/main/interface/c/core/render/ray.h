#ifndef f8d904309b2543a588747a56c4e59a9a
#define f8d904309b2543a588747a56c4e59a9a

#include "../../system/system.h"
#include "../../type/interval.h"

#include "../object/object.h"
#include "../geometry/geometry.h"

struct  IceRayC_Render_Ray_Struct {};
typedef IceRayC_Render_Ray_Struct* IceRayC_Render_Ray_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Render_Ray_Release( IceRayC_Render_Ray_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Ray_Handle   IceRayC_Render_Ray_Direction0();


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Ray_Handle   IceRayC_Render_Ray_Distance0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Ray_Handle   IceRayC_Render_Ray_Distance1( IceRayC_Geometry_Handle P_geometry );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Render_Ray_Distance_Geometry( IceRayC_Render_Ray_Handle P_this, IceRayC_Geometry_Handle P_geometry );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Render_Ray_Distance_Clip( IceRayC_Render_Ray_Handle P_this, IceRayC_TypeInterval1D P_clip );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_Ray_Handle   IceRayC_Render_Ray_Trace0();
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Render_Ray_Trace_Object( IceRayC_Render_Ray_Handle P_this, IceRayC_Object_Handle P_object );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Render_Ray_Trace_Depth( IceRayC_Render_Ray_Handle P_this, IceRayC_TypeSize P_depth );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Render_Ray_Trace_Trash( IceRayC_Render_Ray_Handle P_this, IceRayC_TypeScalar P_trash );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Render_Ray_Trace_Next( IceRayC_Render_Ray_Handle P_this, IceRayC_TypeSize P_next );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Render_Ray_Trace_IOR( IceRayC_Render_Ray_Handle P_this, IceRayC_TypeScalar P_IOR );


#endif
