#include "./strategy.h"
#include "./strategy.hpp"

#include "IceRay/render/1pixel/strategy/strategy.hpp"


GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure *          c2cpp( IceRayC_Render_Pixel_Strategy_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure*> ( P_that );
 }

IceRayC_Render_Pixel_Strategy_Handle                       cpp2c( GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Pixel_Strategy_Handle >( P_this );
 }

IceRayC_Type_Bool IceRayC_Render_Pixel_Strategy_Release( IceRayC_Render_Pixel_Strategy_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }

IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Center0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_center{};
  return cpp2c( I_pure );
 }
IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Grid0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_grid{};
  return cpp2c( I_pure );
 }
IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Grid1( IceRayC_Type_Size P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_grid{ P_size };
  return cpp2c( I_pure );
 }
IceRayC_Type_Bool           IceRayC_Render_Pixel_Strategy_Grid_Size( IceRayC_Render_Pixel_Strategy_Handle P_this, IceRayC_Type_Size P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_grid    Tf_grid;

  auto I_this = dynamic_cast<Tf_grid*>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_size( P_size );
  return 1;
 }

IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Random0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_random{};
  return cpp2c( I_pure );
 }
 
 IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Random1( IceRayC_Type_Size P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_random{ P_size };
  return cpp2c( I_pure );
 }
IceRayC_Type_Bool           IceRayC_Render_Pixel_Strategy_Random_Size( IceRayC_Render_Pixel_Strategy_Handle P_this, IceRayC_Type_Size P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_random    Tf_random;

  auto I_this = dynamic_cast<Tf_random*>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_size( P_size );
  return 1;
 }

IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Sobol0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_sobol{};
  return cpp2c( I_pure );
 }
 
IceRayC_Render_Pixel_Strategy_Handle IceRayC_Render_Pixel_Strategy_Sobol1( IceRayC_Type_Size P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_sobol{ P_size };
  return cpp2c( I_pure );
 }
IceRayC_Type_Bool           IceRayC_Render_Pixel_Strategy_Sobol_Size( IceRayC_Render_Pixel_Strategy_Handle P_this, IceRayC_Type_Size P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_sobol    Tf_sobol;

  auto I_this = dynamic_cast<Tf_sobol*>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_size( P_size );
  return 1;
 }
