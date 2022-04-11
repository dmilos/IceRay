#include   "./fisheye.hpp"
#include   "math/geometry/deg2rad.hpp"


using namespace GS_DDMRM::S_IceRay::S_camera;


S_sphere::GC_fisheye::GC_fisheye()
  :GC_fisheye( ::math::geometry::deg2rad(180), ::math::geometry::deg2rad(180) )
 {
 }

S_sphere::GC_fisheye::GC_fisheye( T_scalar const& P_horizont, T_scalar const& P_vertical, T_scalar const& P_radius )
 :M2_horizont( P_horizont )
 ,M2_vertical( P_vertical )
 ,M2_radius( P_radius )
 {
 }

S_sphere::GC_fisheye::~GC_fisheye()
 {
 }

S_sphere::GC_fisheye::T_size
S_sphere::GC_fisheye::Fv_beam
 (
   T_beam         &  P_beam
  ,T_coord2D const&  P_uv
 )const
 {
  static T_scalar const Isc_phi = ::math::constants::PHI;

  T_coord & I_origin = P_beam[0].M_origin;

  I_origin[0] = 0;
  I_origin[1] = 0;
  I_origin[2] = 0;

  T_coord2D I_uv;
  I_uv[0] = M2_horizont * P_uv[0];
  I_uv[1] = M2_vertical * P_uv[1];

  T_scalar I_angle = - atan2( I_uv[1], I_uv[0] );
  T_scalar I_len   = ::math::linear::vector::length( I_uv );

 T_coord &  I_direction = P_beam[0].M_direction;
 I_direction[0] =  cos( I_angle ) * sin( I_len );
 I_direction[1] =  cos( I_len );
 I_direction[2] = -sin( I_angle ) * sin( I_len );

  ::math::linear::vector::scale( I_direction, M2_radius );

  return 1;
 }

void
S_sphere::GC_fisheye::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
 {
  static T_scalar const Isc_phi = ::math::constants::PHI;
  // TODO  Check/fix
 }
