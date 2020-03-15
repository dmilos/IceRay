#include "_pure.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_scanner;

GC__pure::T2__base GC__pure::M2s_pixel;

GC__pure::GC__pure()
 :GC__pure( nullptr )
 {
  Fv_pixel( &M2s_pixel );
 }

GC__pure::GC__pure( T_pixel * P_pixel )
 :M2_progress( T_scalar( 0 ) )
 ,M2_work( false )
 ,M2_pixel( P_pixel )
 {
  Fv_pixel( &M2s_pixel );
 }

GC__pure::~GC__pure()
 {
 }

GC__pure::T_report
GC__pure::Fv_pixel( T_pixel * P_pixel )
 {
  if( true == F_work() )
   {
    return T_report( false );
   }
  M2_pixel = P_pixel;

  return T_report( true );
 }

void GC__pure::Fv_render( T_picture & P_image )
 {
  F1_work() = true;

  M2_pixel->F_resolution( P_image.F_size() );

  F1v_render( P_image );
  F1_work() = false;
 }