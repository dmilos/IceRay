#include "all.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_sheaf;

GC_all::GC_all()
 {
 }

GC_all::~GC_all()
 {
 }

void GC_all::Fv_do( T_color &P_color, T_beam  const& P_beam )
 {
  T_color I_color;

  for( auto & I_ray0 : P_beam )
   {
    I_color = T_color( ::color::constant::black_t{} );
    auto I_ray2 = I_ray0;
    ::math::linear::vector::length( I_ray2.M_direction, T_scalar(1) );
    F1v_ray()->Fv_trace( I_color, I_ray2 );
    P_color += I_color;
   }
 }
