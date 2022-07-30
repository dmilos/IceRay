#include   "./package.hpp"
#include   "math/math.hpp"


using namespace GS_DDMRM::S_IceRay::S_camera;


S_sphere::GC_package::GC_package()
  :GC_package(::math::geometry::deg2rad(90), ::math::geometry::deg2rad(90)  )
 {
 }

S_sphere::GC_package::GC_package( T_scalar const& P_horizont, T_scalar const& P_vertical )
 : M2_horizontal( P_horizont )
 , M2_vertical( P_vertical )
 {
 }

S_sphere::GC_package::~GC_package()
 {
 }

S_sphere::GC_package::T_size
S_sphere::GC_package::Fv_beam
 (
   T_beam         &  P_beam
  ,T_coord2D const&  P_uv
 )const
 {
  static T_scalar const Isc_phi = ::math::constants::PHI;

  ::math::linear::vector::fill( P_beam[0].M_origin, T_scalar(0) );

  T_coord & I_direction = P_beam[0].M_direction;

  T_coord2D I_uv;
  T_scalar I_length = ::math::linear::vector::dominant( P_uv ).second;
  ::math::linear::vector::length( I_uv, P_uv, I_length );

  I_direction[0] = sin( I_uv[0] * M2_horizontal );
  I_direction[1] = 1;
  I_direction[2] = sin( I_uv[1] * M2_vertical );

  ::math::linear::vector::length( I_direction, T_scalar( 1 ) );
  return 0;
 }

void
S_sphere::GC_package::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
 {
  static T_scalar const Isc_phi = ::math::constants::PHI;
  // TODO  Ceheck/fix
 }
