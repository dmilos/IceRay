#include "./pixel.h"
#include "./pixel.hpp"
#include "./strategy.hpp"
#include "./filter.hpp"

#include "IceRay/render/1pixel/pixel.hpp"

GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure *          c2cpp( IceRayC_Render_Pixel_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure*> ( P_that );
 }

IceRayC_Render_Pixel_Handle                       cpp2c( GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Pixel_Handle >( P_this );
 }

IceRayC_Type_Bool IceRayC_Render_Pixel_Release( IceRayC_Render_Pixel_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
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

IceRayC_Render_Pixel_Handle IceRayC_Render_Pixel_Basic0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base{};
  return cpp2c( I_pure );
 }

IceRayC_Type_Bool           IceRayC_Render_Pixel_Basic_Strategy( IceRayC_Render_Pixel_Handle P_this, IceRayC_Render_Pixel_Strategy_Handle P_strategy )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base    Tf__base;

  auto I_this = dynamic_cast<Tf__base*>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_strategy( c2cpp ( P_strategy ) );
  return 1;
 }

IceRayC_Type_Bool           IceRayC_Render_Pixel_Basic_Filter(   IceRayC_Render_Pixel_Handle P_this, IceRayC_Render_Pixel_Filter_Handle P_filter )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base    Tf__base;

  auto I_this = dynamic_cast<Tf__base*>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_filter( c2cpp ( P_filter ) );
  return 1;

 }
