#include "./engine.hpp"

using namespace GS_DDMRM::S_IceRay::S_render;

GC_engine::T2_scanner  GC_engine::M2s_scanner;
GC_engine::T2_pixel  GC_engine::M2s_pixel;
GC_engine::T2_pierce  GC_engine::M2s_pierce;

GC_engine::GC_engine()
 :M2_scanner( nullptr )
 ,M2_pixel  ( nullptr )
 ,M2_pierce ( nullptr )
 {
  F_scanner( &M2s_scanner );
  F_pixel(   &M2s_pixel   );
  F_pierce(  &M2s_pierce  );
 }

GC_engine::~GC_engine()
 {
 }

void GC_engine::F_do( T_picture & P_picture )
 {
  if( nullptr == M2_scanner ) return;
  if( nullptr == M2_pixel   ) return;
  if( nullptr == M2_pierce  ) return;

  M2_scanner->Fv_render( P_picture );
 }

bool
GC_engine::F_work()
 {
  if( nullptr == F_scanner() ) return false;
  return M2_scanner->F_work();
 }

void
GC_engine::F_stop()
 {
  if( NULL == F_scanner() ) return ;
  return M2_scanner->Fv_stop();
 }

GC_engine::T_scalar
GC_engine::F_progress()const
 {
  if( NULL == M2_scanner ) return -1;
  return M2_scanner->F_progress();
 }

void
GC_engine::F_scanner( T_scanner   * P_scanner    )
 {
  if( true == F_work() ) return;
  M2_scanner = P_scanner;
  if( NULL == M2_scanner ) return;
  M2_scanner->Fv_pixel( M2_pixel );
 }

void
GC_engine::F_pixel   (T_pixel   * P_pixel    )
 {
  if( true == F_work() ) return;
  M2_pixel = P_pixel;
  F_scanner( M2_scanner );
  if( NULL == M2_pixel ) return;
  M2_pixel->F_pierce( M2_pierce );
 }

void
GC_engine::F_pierce    (T_pierce    * P_pierce     )
 {
  if( true == F_work() ) return;
  M2_pierce = P_pierce;
  F_pixel( M2_pixel );
  if( NULL == M2_pierce ) return;
 }

