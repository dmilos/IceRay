#include "./pixel.h"
#include "IceRay/render/1pixel/pixel.hpp"


void IceRayC_Render_Pixel_Release( IceRayC_Render_Pixel_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_Pixel_Handle IceRayC_Render_Pixel_Constant0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC_constant{};
  return reinterpret_cast< IceRayC_Render_Pixel_Handle>( nullptr );
 }

IceRayC_Render_Pixel_Handle IceRayC_Render_Pixel_UV0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC_UV{};
  return reinterpret_cast< IceRayC_Render_Pixel_Handle>( nullptr );
 }

IceRayC_Render_Pixel_Handle IceRayC_Render_PixelBasic0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base{};
  return reinterpret_cast< IceRayC_Render_Pixel_Handle>( nullptr );
 }
