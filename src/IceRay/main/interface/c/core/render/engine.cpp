#include "./render.h"
#include "IceRay/render/render.hpp"

#include "IceRay/render/4ray/classic2/algorithm.hpp"


#include "./sheaf.h"
#include "./pierce.h"
#include "./pixel.h"
#include "./ray.h"
#include "./scanner.h"


void IceRayC_RenderEngine_Release( IceRayC_Render_Engine_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::GC_engine Tf_engine;
  auto I_this = reinterpret_cast<Tf_engine*> ( P_this );
  delete I_this;
 }

IceRayC_Render_Engine_Handle IceRayC_Render_Engine0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::GC_engine Tf_engine;
  return reinterpret_cast< IceRayC_Render_Engine_Handle>( new Tf_engine{} );
 }

int IceRayC_Render_Engine_Scanner( IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Scanner_Handle P_scanner )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>( P_this );
  auto I_scanner = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure*>(P_scanner);
  I_this-> F_scanner( I_scanner );
  return 1;
 }

int IceRayC_Render_Engine_Pixel(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Pixel_Handle P_pixel )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_scanner = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure*>(P_pixel);
  I_this-> F_scanner( I_scanner );
  return 1;
 }

int IceRayC_Render_Engine_Pierce(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Pierce_Handle P_perce )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_pierce = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure*>(P_perce);
  I_this-> F_pierce( I_pierce );
  return 1;
 }

int IceRayC_Render_Engine_Sheaf(IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Sheaf_Handle P_sheaf )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_sheaf = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure*>(P_sheaf);
  I_this-> F_sheaf( I_sheaf );
  return 1;
 }

int IceRayC_Render_Engine_Ray( IceRayC_Render_Engine_Handle P_this, IceRayC_Render_Ray_Handle P_ray )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_ray = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure*>(P_ray);
  I_this-> F_ray( I_ray );
  return 1;
 }

int IceRayC_Render_Engine_Start( IceRayC_Render_Engine_Handle P_this, IceRayC_Type_Picture_Handle P_picture )
 {
  typedef  GS_DDMRM::S_IceRay::S_render::GC_engine Tf_engine;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure       Tf_picture;

  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);

  I_this->F_do( *reinterpret_cast<Tf_picture*>( P_picture ) );
  return 0;
 }

int IceRayC_Render_Engine_Stop(IceRayC_Render_Engine_Handle P_this)
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  I_this->F_stop();
  return 0;
}

int IceRayC_Render_Engine_Progress(IceRayC_Render_Engine_Handle P_this)
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  return I_this->F_progress();
 }










