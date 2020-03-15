#include "./render.h"
#include "IceRay/render/render.hpp"

#include "IceRay/render/4ray/classic2/algorithm.hpp"

IceRayC_RenderEnginePure IceRayC_RenderEngine()
 {
  return new GS_DDMRM::S_IceRay::S_render::GC_engine{};
 }

IceRayC_RenderEnginePure IceRayC_RenderEngine_Scanner(IceRayC_RenderEnginePure P_this, IceRayC_RenderScannerPure P_scanner )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_scanner = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure*>(P_scanner);
  I_this-> F_scanner( I_scanner ); 
  return nullptr;
 }

IceRayC_RenderEnginePure IceRayC_RenderEngine_Pixel(IceRayC_RenderEnginePure P_this, IceRayC_RenderPixelPure P_pixel )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_scanner = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure*>(P_pixel);
  I_this-> F_scanner( I_scanner ); 
  return nullptr;
}

IceRayC_RenderEnginePure IceRayC_RenderEngine_Pierce(IceRayC_RenderEnginePure P_this, IceRayC_RenderPiercePure P_perce )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_pierce = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure*>(P_perce);
  I_this-> F_pierce( I_pierce ); 
  return nullptr;
}

IceRayC_RenderEnginePure IceRayC_RenderEngine_Ray( IceRayC_RenderEnginePure P_this, IceRayC_RenderRayPure)
 {
  return nullptr;
 }


IceRayC_RenderEnginePure IceRayC_RenderEngine_Start( IceRayC_RenderEnginePure P_this )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  //I_this->F_start();
  return nullptr;
 }

IceRayC_RenderEnginePure IceRayC_RenderEngine_Stop(IceRayC_RenderEnginePure P_this)
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  I_this->F_stop();
  return nullptr;
}

IceRayC_RenderEnginePure IceRayC_RenderEngine_Progress(IceRayC_RenderEnginePure P_this)
 {
  return nullptr;
 }


IceRayC_RenderScannerPure IceRayC_RenderScannerBlock()
 {
  GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block{};
  return I_pure;
 }

IceRayC_RenderScannerPure IceRayC_RenderScannerParallel()
 {
  GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_scanner::GC_parallel{};
  return I_pure;
 }


IceRayC_RenderPixelPure IceRayC_RenderPixelBasic()
 {
  GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base{};
  return I_pure;
 }

IceRayC_RenderPiercePure IceRayC_RenderPierceBasic()
 {
  GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pierce::GC__base{};
  return I_pure;
 }

IceRayC_RenderRayPure   IceRayC_CoreRenderRayC2A()
 {
  return new GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm {};
 }

