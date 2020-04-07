#include "first.hpp"

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
  P_color = F1v_ray()->Fv_trace( I_color, P_beam.F_top() );
 }