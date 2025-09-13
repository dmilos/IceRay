#include "./first.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_sheaf;

GC_first::GC_first()
 {
 }

GC_first::~GC_first()
 {
 }

void
GC_first::Fv_do( T_color &P_color, T_beam  const& P_beam )
 {
  T_color I_color;

  {
    I_color = T_color( ::color::constant::black_t{} );
    auto I_ray = P_beam.front();
    ::math::linear::vector::length( I_ray.M_direction, T_scalar( 1 ) );
    F1v_ray()->Fv_trace( I_color, I_ray );
    P_color += I_color;
  }
  P_color /= 1;
}