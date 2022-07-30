#include   "./horizontal.hpp"
#include   "math/math.hpp"


using namespace GS_DDMRM::S_IceRay::S_camera;


S_cylinder::GC_horizontal::GC_horizontal()
 : GC_horizontal( 2, ::math::geometry::deg2rad( 90 ), 1 )
 {
 }

S_cylinder::GC_horizontal::GC_horizontal( T_scalar const& P_width, T_scalar const& P_theta, T_scalar const& P_radius )
 : M2_width( P_width )
 , M2_theta( P_theta )
 , M2_radius( P_radius )
 {
 }

S_cylinder::GC_horizontal::~GC_horizontal()
 {
 }

S_cylinder::GC_horizontal::T_size
S_cylinder::GC_horizontal::Fv_beam
 (
   T_beam         &  P_beam
  ,T_coord2D const&  P_uv
 )const
 {
  static T_scalar const Is_pi = ::math::constants::PHI;

  T_coord & I_origin = P_beam[0].M_origin;

  I_origin[0] = P_uv[0] * (M2_width/T_scalar(2));
  I_origin[1] = 0;
  I_origin[2] = 0;

  T_coord & I_direction = P_beam[0].M_direction;

  I_direction[0] = 0;
  I_direction[1] = M2_radius * cos( P_uv[1] * M2_theta/T_scalar(2) );
  I_direction[2] = M2_radius * sin( P_uv[1] * M2_theta/T_scalar(2) );

  return 1;
 }

void
S_cylinder::GC_horizontal::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
 {
  T_coord I_eY;
  I_eY[0] = P_uv[0] * (M2_width / T_scalar(2) );
  I_eY[1] = M2_radius * cos( P_uv[1] * M2_theta/T_scalar(2) );
  I_eY[2] = M2_radius * sin( P_uv[1] * M2_theta/T_scalar(2) );

  // TODO Ceheck/fix
  T_coord I_z;  ::math::linear::vector::load( I_z, 0, 0, 1 );
  T_coord I_eX; ::math::linear::vector::cross( I_eX, I_eY, I_z  ); ::math::linear::vector::length( I_eX, T_scalar(1) );
  T_coord I_eZ; ::math::linear::vector::cross( I_eZ, I_eY, I_eX ); ::math::linear::vector::length( I_eZ, T_scalar(1) );

  ::math::linear::vector::load<T_scalar,T_scalar>( P_affine.vector(), 0, 0, P_uv[1] );
  ::math::linear::matrix::system( P_affine.matrix(), I_eX, I_eY, I_eZ );
 }
