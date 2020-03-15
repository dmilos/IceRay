#ifndef f27b1a89b6d346119afe2c9694aa4502
#define f27b1a89b6d346119afe2c9694aa4502

#include "../../system/system.h"

typedef  void * IceRayC_RenderEnginePure;
typedef  void * IceRayC_RenderScannerPure;
typedef  void * IceRayC_RenderPixelPure;
typedef  void * IceRayC_RenderPiercePure;
typedef  void * IceRayC_RenderRayPure;


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderEnginePure IceRayC_RenderEngine();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderEnginePure IceRayC_RenderEngine_Scanner(IceRayC_RenderEnginePure, IceRayC_RenderScannerPure );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderEnginePure IceRayC_RenderEngine_Pixel(IceRayC_RenderEnginePure, IceRayC_RenderPixelPure);
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderEnginePure IceRayC_RenderEngine_Pierce(IceRayC_RenderEnginePure, IceRayC_RenderPiercePure);
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderEnginePure IceRayC_RenderEngine_Ray(IceRayC_RenderEnginePure, IceRayC_RenderRayPure);

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderEnginePure IceRayC_RenderEngine_Start();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderEnginePure IceRayC_RenderEngine_Stop();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderEnginePure IceRayC_RenderEngine_Progress();

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderScannerPure IceRayC_RenderScannerBlock();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderScannerPure IceRayC_RenderScannerParallel();

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderPixelPure IceRayC_RenderPixelBasic();

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderPiercePure IceRayC_RenderPierceBasic();

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_RenderRayPure   IceRayC_CoreRenderRayC2A();

#endif
