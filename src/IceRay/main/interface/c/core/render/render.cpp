#include "./render.h"
#include "IceRay/render/render.hpp"

#include "IceRay/render/4ray/classic2/algorithm.hpp"

void IceRayC_RenderEngine_Release( IceRayC_Render_EngineHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::GC_engine Tf_engine;
  auto I_this = reinterpret_cast<Tf_engine*> ( P_this );
  delete I_this;
 }

IceRayC_Render_EngineHandle IceRayC_Render_Engine0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::GC_engine Tf_engine;
  return reinterpret_cast< IceRayC_Render_EngineHandle>( new Tf_engine{} );
 }

int IceRayC_Render_Engine_Scanner( IceRayC_Render_EngineHandle P_this, IceRayC_Render_ScannerHandle P_scanner )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>( P_this );
  auto I_scanner = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure*>(P_scanner);
  I_this-> F_scanner( I_scanner );
  return 1;
 }

int IceRayC_Render_Engine_Pixel(IceRayC_Render_EngineHandle P_this, IceRayC_Render_PixelHandle P_pixel )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_scanner = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure*>(P_pixel);
  I_this-> F_scanner( I_scanner );
  return 1;
 }

int IceRayC_Render_Engine_Pierce(IceRayC_Render_EngineHandle P_this, IceRayC_Render_PierceHandle P_perce )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_pierce = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure*>(P_perce);
  I_this-> F_pierce( I_pierce );
  return 1;
 }

int IceRayC_Render_Engine_Beam(IceRayC_Render_EngineHandle P_this, IceRayC_Render_BeamHandle P_beam )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_beam = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_beam::GC__pure*>(P_beam);
  I_this-> F_beam( I_beam );
  return 1;
 }

int IceRayC_Render_Engine_Ray( IceRayC_Render_EngineHandle P_this, IceRayC_Render_RayHandle P_ray )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  auto I_ray = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure*>(P_ray);
  I_this-> F_ray( I_ray );
  return 1;
 }

int IceRayC_Render_Engine_Start( IceRayC_Render_EngineHandle P_this/*, IcerayC_Type_ImageHandle P_image */ )
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  // I_this->F_start( P_image );
  return 0;
 }

int IceRayC_Render_Engine_Stop(IceRayC_Render_EngineHandle P_this)
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  I_this->F_stop();
  return 0;
}

int IceRayC_Render_Engine_Progress(IceRayC_Render_EngineHandle P_this)
 {
  auto I_this    = reinterpret_cast<GS_DDMRM::S_IceRay::S_render::GC_engine*>(P_this);
  return I_this->F_progress();
 }


void IceRayC_Render_Scanner_Release( IceRayC_Render_ScannerHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_ScannerHandle IceRayC_Render_ScannerBlock0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block{};
  return reinterpret_cast< IceRayC_Render_ScannerHandle >( nullptr );
 }

IceRayC_Render_ScannerHandle IceRayC_Render_ScannerParallel0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_scanner::GC_parallel{};
  return reinterpret_cast< IceRayC_Render_ScannerHandle>( nullptr );
 }


void IceRayC_Render_Pixel_Release( IceRayC_Render_PixelHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_PixelHandle IceRayC_Render_Pixel_Constant0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC_constant{};
  return reinterpret_cast< IceRayC_Render_PixelHandle>( nullptr );
 }

IceRayC_Render_PixelHandle IceRayC_Render_Pixel_UV0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC_UV{};
  return reinterpret_cast< IceRayC_Render_PixelHandle>( nullptr );
 }

IceRayC_Render_PixelHandle IceRayC_Render_PixelBasic0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  Tf__pure * I_pure = new GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base{};
  return reinterpret_cast< IceRayC_Render_PixelHandle>( nullptr );
 }


void IceRayC_Render_Pierce_Release( IceRayC_Render_PierceHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_PierceHandle IceRayC_Render_Pierce_UV0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pierce::GC_UV{};
  return reinterpret_cast< IceRayC_Render_PierceHandle>( nullptr );
 }

IceRayC_Render_PierceHandle IceRayC_Render_Pierce_Projector0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector{};
  return reinterpret_cast< IceRayC_Render_PierceHandle>( I_pure );
 }


void IceRayC_Render_Beam_Release( IceRayC_Render_BeamHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_beam::GC__pure  Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_BeamHandle IceRayC_Render_Beam_ALL0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_beam::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_beam::GC_all{};
  return reinterpret_cast< IceRayC_Render_BeamHandle>( I_pure );
 }

IceRayC_Render_BeamHandle IceRayC_Render_Beam_First0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_beam::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_beam::GC_first{};
  return reinterpret_cast< IceRayC_Render_BeamHandle>( I_pure );
 }

IceRayC_Render_BeamHandle IceRayC_Render_Beam_Random0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_beam::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_beam::GC_random{};
  return reinterpret_cast< IceRayC_Render_BeamHandle>( I_pure );
 }


void IceRayC_Render_Ray_Release( IceRayC_Render_RayHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_RayHandle   IceRayC_Render_Ray_Distance()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC_distance  T_distance;
  Tf__pure* I_this = new T_distance{};
  return reinterpret_cast< IceRayC_Render_RayHandle >( I_this );
 }

IceRayC_Render_RayHandle   IceRayC_Render_Ray_Trace()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm  T_algorithm;
  Tf__pure* I_this = new T_algorithm{};
  return reinterpret_cast< IceRayC_Render_RayHandle >( I_this );
 }

