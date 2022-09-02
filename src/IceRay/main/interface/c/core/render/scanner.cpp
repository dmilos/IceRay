#include "./scanner.h"
#include "./scanner.hpp"
#include "../../type/coord.hpp"

#include "IceRay/render/0scanner/scanner.hpp"


GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure *          c2cpp( IceRayC_Render_Scanner_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure*> ( P_that );
 }

IceRayC_Render_Scanner_Handle                       cpp2c( GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Scanner_Handle >( P_this );
 }

IceRayC_Type_Bool IceRayC_Render_Scanner_Release( IceRayC_Render_Scanner_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }

IceRayC_Render_Scanner_Handle IceRayC_Render_Scanner_Block0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block{};
  return cpp2c( I_pure );
 }

IceRayC_Type_Bool IceRayC_Render_Scanner_Block_Hot( IceRayC_Render_Scanner_Handle P_this, IceRayC_TypeCoordSize2D* P_hot )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block Tf_block;

  auto I_this = dynamic_cast< Tf_block *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hot( c2cpp( *P_hot ) );
  return 1;
 }

IceRayC_Type_Bool IceRayC_Render_Scanner_Block_Window( IceRayC_Render_Scanner_Handle P_this, IceRayC_TypeCoordSize2D* P_a, IceRayC_TypeCoordSize2D* P_b )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block Tf_block;

  auto I_this = dynamic_cast< Tf_block *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_window( Tf_block::T_range( c2cpp( *P_a ), c2cpp( *P_b ) ) );
  return 1;
 }

IceRayC_Render_Scanner_Handle IceRayC_Render_Scanner_Parallel0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_scanner::GC_parallel{};
  return cpp2c( I_pure );
 }
