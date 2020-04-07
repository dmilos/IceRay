#include <limits>

#include "./direction.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_ray;





GC_direction::GC_direction()
 {
 }

GC_direction::~GC_direction()
 {
 }

void
GC_direction::Fv_trace( T_color & P_color, T_ray const& P_ray )
 {
  P_color[0] = fabs( P_ray.M_direction[0] );
  P_color[1] = fabs( P_ray.M_direction[1] );
  P_color[2] = fabs( P_ray.M_direction[2] );
 }
