#include "./vacuum.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object;

bool GC_vacuum::Fv_intersect( T_scalar &P_lambda, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_ray const& P_ray )const
 {
  return false;
 }

void GC_vacuum::Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
  P_height = 0;
 }

void GC_vacuum::Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
  ::math::linear::vector::fill( P_normal, 0 );
 }