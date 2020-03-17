#ifndef f27b1a89b6d346119afe2c9694aa4502
#define f27b1a89b6d346119afe2c9694aa4502

#include "../../system/system.h"

struct  IceRayC_Render_EngineStruct {};
typedef IceRayC_Render_EngineStruct* IceRayC_Render_EngineHandle;

struct  IceRayC_Render_ScannerStruct {};
typedef IceRayC_Render_ScannerStruct* IceRayC_Render_ScannerHandle;

struct  IceRayC_Render_PixelStruct {};
typedef IceRayC_Render_PixelStruct* IceRayC_Render_PixelHandle;

struct  IceRayC_Render_PierceStruct {};
typedef IceRayC_Render_PierceStruct* IceRayC_Render_PierceHandle;

struct  IceRayC_Render_BeamStruct {};
typedef IceRayC_Render_BeamStruct* IceRayC_Render_BeamHandle;

struct  IceRayC_Render_RayStruct {};
typedef IceRayC_Render_RayStruct* IceRayC_Render_RayHandle;


IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_RenderEngine_Release( IceRayC_Render_EngineHandle P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Render_EngineHandle IceRayC_Render_Engine0();
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Scanner( IceRayC_Render_EngineHandle P_this, IceRayC_Render_ScannerHandle P_scanner );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Pixel(IceRayC_Render_EngineHandle P_this, IceRayC_Render_PixelHandle P_pixel );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Pierce(IceRayC_Render_EngineHandle P_this, IceRayC_Render_PierceHandle P_perce );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Beam(IceRayC_Render_EngineHandle P_this, IceRayC_Render_BeamHandle P_beam );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Ray( IceRayC_Render_EngineHandle P_this, IceRayC_Render_RayHandle P_ray );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Start( IceRayC_Render_EngineHandle P_this );
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Stop(IceRayC_Render_EngineHandle P_this);
IceRayC__EXPORT IceRayC__DECLSPEC  int IceRayC_Render_Engine_Progress(IceRayC_Render_EngineHandle P_this);
#endif
