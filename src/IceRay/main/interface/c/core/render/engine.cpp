#include "./engine.h"
#include "./engine.hpp"

#include "IceRay/render/engine.hpp"

#include "./sheaf.h"
#include "./sheaf.hpp"
#include "./pierce.h"
#include "./pierce.hpp"
#include "./pixel.h"
#include "./pixel.hpp"
#include "./ray.h"
#include "./ray.hpp"
#include "./scanner.h"
#include "./scanner.hpp"


GS_DDMRM::S_IceRay::S_render::GC_engine *          c2cpp( IceRayC_Render_Engine_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*> ( P_that );
 }

IceRayC_Render_Engine_Handle                       cpp2c( GS_DDMRM::S_IceRay::S_render::GC_engine* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Engine_Handle >( P_this );
 }

IceRayC_Type_Bool IceRayC_Render_Engine_Release( IceRayC_Render_Engine_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::GC_engine Tf_engine;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }

IceRayC_Render_Engine_Handle IceRayC_Render_Engine0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::GC_engine Tf_engine;
  return cpp2c( new Tf_engine{} );
 }

IceRayC_Type_Bool IceRayC_Render_Engine_Scanner( IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Scanner_Handle P_scanner )
 {
  auto I_this    = c2cpp( P_this );
  auto I_scanner = c2cpp(P_scanner);
  I_this-> F_scanner( I_scanner );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Render_Engine_Pixel(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Pixel_Handle P_pixel )
 {
  auto I_this  = c2cpp(P_this);
  auto I_pixel = c2cpp(P_pixel);
  I_this-> F_pixel( I_pixel );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Render_Engine_Pierce(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Pierce_Handle P_perce )
 {
  auto I_this   = c2cpp(P_this);
  auto I_pierce = c2cpp(P_perce);
  I_this-> F_pierce( I_pierce );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Render_Engine_Sheaf(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Sheaf_Handle P_sheaf )
 {
  auto I_this  = c2cpp(P_this);
  auto I_sheaf = c2cpp(P_sheaf);
  I_this-> F_sheaf( I_sheaf );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Render_Engine_Ray( IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Ray_Handle P_ray )
 {
  auto I_this = c2cpp(P_this);
  auto I_ray  = c2cpp(P_ray);
  I_this-> F_ray( I_ray );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Render_Engine_Start( IceRayC_Render_Engine_Handle P_this, IceRayC_Type_Picture_Handle P_picture )
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure       Tf_picture;

  auto I_this    = c2cpp(P_this);

  I_this->F_do( *reinterpret_cast<Tf_picture*>( P_picture ) );
  return 0;
 }

IceRayC_Type_Bool IceRayC_Render_Engine_Stop(IceRayC_Render_Engine_Handle P_this)
 {
  auto I_this    = c2cpp(P_this);
  I_this->F_stop();
  return 0;
}

IceRayC_Type_Scalar IceRayC_Render_Engine_Progress(IceRayC_Render_Engine_Handle P_this)
 {
  auto I_this    = c2cpp(P_this);
  return I_this->F_progress();
 }
