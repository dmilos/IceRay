#include "./engine.hpp"

#include "./0scanner/block.hpp"
#include "./1pixel/_base.hpp"
#include "./2pierce/uv.hpp"
#include "./2pierce/projector.hpp"
#include "./3sheaf/all.hpp"
#include "./4ray/distance.hpp"


using namespace GS_DDMRM::S_IceRay::S_render;

GC_engine::GC_engine()
 :M2_scanner( &Fs_scanner()  )
 ,M2_pixel  ( &Fs_pixel() )
 ,M2_pierce ( &Fs_pierce() )
 ,M2_sheaf  ( &Fs_sheaf() )
 ,M2_ray    ( &Fs_ray() )
 {
  F_scanner( nullptr );
  F_pixel(   nullptr );
  F_pierce(  nullptr );
  F_sheaf(   nullptr );
  F_ray(     nullptr );
 }

GC_engine::~GC_engine()
 {
 }

void GC_engine::F_do( T_picture & P_picture )
 {
  M2_scanner->Fv_render( P_picture );
 }

bool
GC_engine::F_work()const
 {
  return M2_scanner->F_work();
 }

void
GC_engine::F_stop()
 {
  return M2_scanner->Fv_stop();
 }

GC_engine::T_scalar
GC_engine::F_progress()const
 {
  return M2_scanner->F_progress();
 }

void
GC_engine::F_scanner( T_scanner   * P_scanner )
 {
  if( true == F_work() ) return;
  M2_scanner = P_scanner;
  if( nullptr == M2_scanner )
   {
    M2_scanner = &Fs_scanner();
   }
  M2_scanner->Fv_pixel( M2_pixel );
 }

GC_engine::T_scanner & GC_engine::Fs_scanner()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block T2_scanner;
  static T2_scanner  Irs_scanner;
  return Irs_scanner;
 }

void
GC_engine::F_pixel   (T_pixel   * P_pixel    )
 {
  if( true == F_work() ) return;

  M2_pixel = P_pixel;
  if( nullptr == M2_pixel )
   {
    M2_pixel = &Fs_pixel();
   }
  F_scanner( M2_scanner );

  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base  T_pixelPierce;
  auto I_pixel = dynamic_cast<T_pixelPierce*>( M2_pixel );
  if( nullptr != I_pixel )
   {
    I_pixel->F_pierce( M2_pierce );
   }
 }

GC_engine::T_pixel & GC_engine::Fs_pixel()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base Tf_pixel;
  static Tf_pixel Irs_pixel;
  return Irs_pixel;
 }

void GC_engine::F_pierce    (T_pierce    * P_pierce     )
 {
  if( true == F_work() ) return;
  M2_pierce = P_pierce;
  if( nullptr == M2_pierce )
   {
    M2_pierce = &Fs_pierce();
   }
  F_pixel( M2_pixel );

  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector Tf_projector;
  auto I_projector = dynamic_cast<Tf_projector*>( M2_pierce );
  if( nullptr != I_projector )
   {
    I_projector->Fv_sheaf( M2_sheaf );
   }
}

GC_engine::T_pierce & GC_engine::Fs_pierce()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_UV     Tf_pierce;
  static Tf_pierce Irs_pierce;
  return Irs_pierce;
 }

void           GC_engine::F_sheaf( T_sheaf  * P_sheaf    )
 {
  M2_sheaf = P_sheaf;
  if( nullptr == M2_sheaf )
   {
    M2_sheaf = &Fs_sheaf();
   }

  F_pierce( M2_pierce );
  M2_sheaf->Fv_ray( M2_ray );
 }

GC_engine::T_sheaf & GC_engine::Fs_sheaf()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_all Tf_all;
  static Tf_all Irs_sheaf;
  return Irs_sheaf;
 }

void           GC_engine::F_ray( T_ray  * P_ray    )
 {
  M2_ray = P_ray;
  if( nullptr == M2_ray )
   {
    M2_ray = &Fs_ray();
   }
  F_sheaf( M2_sheaf );
 }

GC_engine::T_ray & GC_engine::Fs_ray()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC_distance Tf_distance;
  static Tf_distance Irs_pixel;
  return Irs_pixel;
 }
