#include "./flat.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object;

bool GC_flat::Fv_intersect( T_scalar &P_lambda, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_ray const& P_ray )const
 {
  static T_scalar Is_epsilon = 1e-8;
  T_scalar I_level = ( P_00+ P_01 + P_10+ P_11 ) * 0.25;

  auto const& I_origin    = P_ray.M_origin;
  auto const& I_direction = P_ray.M_direction;

  if( ( - Is_epsilon < I_direction[2] ) && ( I_direction[2] < Is_epsilon ) )
   {
    return false;
   }

  T_scalar I_lambda = (I_level - I_origin[2] )/ I_direction[2];

  if( ( I_lambda < +Is_epsilon ) || ( P_lambda < I_lambda ) ) return false;

  T_scalar I_x = I_origin[0] + I_lambda *I_direction[0];
  if( ( I_x < 0 ) || ( 1 < I_x ) ) return false;

  T_scalar I_y = I_origin[1] + I_lambda *I_direction[1];
  if( ( I_y < 0 ) || ( 1 < I_y ) ) return false;

  P_lambda = I_lambda;
  return true;
 }

void GC_flat::Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
  T_scalar I_level = ( P_00+ P_01+ P_10+ P_11 ) * 0.25;
  P_height = I_level;
 }

void GC_flat::Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_01, T_scalar const& P_10, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
  ::math::linear::vector::fill( P_normal, 0 );
  P_normal[2] = T_scalar( 1 );
 }