#include "./_pure.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_pierce;



GC__pure::GC__pure( void )
 {
 
 }

GC__pure::~GC__pure( void )
 {
 
 }


void GC__pure::F_render( T_color & P_color, T_coord const& P_coord )
 {
  F1v_render( P_color, P_coord );
 }

void  GC__pure::F_resolution( T_resolution const& P_resolution )
 {
  ::math::linear::vector::load(  M2_scale, P_resolution[0], P_resolution[1] );
  ::math::linear::vector::invert( M2_scale, { T_scalar( P_resolution[0] ), T_scalar( P_resolution[1] ) }  );
 }