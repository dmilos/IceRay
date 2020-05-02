#include "./pixel.h"
#include "./pixel.hpp"

#include "IceRay/render/1pixel/pixel.hpp"

GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure *          c2cpp( IceRayC_Render_Pixel_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure*> ( P_that );
 }

IceRayC_Render_Pixel_Handle                       cpp2c( GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Pixel_Handle >( P_this );
 }

void IceRayC_Render_Pixel_Release( IceRayC_Render_Pixel_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
 }

IceRayC_Render_Pixel_Handle IceRayC_Render_Pixel_Constant0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC_constant{};
  return cpp2c( I_pure );
 }

IceRayC_Render_Pixel_Handle IceRayC_Render_Pixel_UV0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC_UV{};
  return cpp2c( I_pure );
 }

IceRayC_Render_Pixel_Handle IceRayC_Render_PixelBasic0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base{};
  return cpp2c( I_pure );
 }
