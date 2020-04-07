#include "./scanner.h"
#include "IceRay/render/0scanner/scanner.hpp"


void IceRayC_Render_Scanner_Release( IceRayC_Render_Scanner_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_Scanner_Handle IceRayC_Render_Scanner_Block0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block{};
  return reinterpret_cast< IceRayC_Render_Scanner_Handle >( nullptr );
 }

int IceRayC_Render_Scanner_BlockHot( IceRayC_Render_Scanner_Handle P_this, IceRayC_TypeSize P_x, IceRayC_TypeSize P_y )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block Tf_block;

  auto I_this = dynamic_cast< Tf_block *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hot( Tf_block::T_cell2D{ P_x, P_y } );
  return 1;
 }

IceRayC_Render_Scanner_Handle IceRayC_Render_Scanner_Parallel0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_scanner::GC_parallel{};
  return reinterpret_cast< IceRayC_Render_Scanner_Handle>( nullptr );
 }
