#include   "./vertical.hpp"
#include   "math/geometry/deg2rad.hpp"


using namespace GS_DDMRM::S_IceRay::S_camera;


S_cylinder::GC_vertical::GC_vertical()
 : GC_vertical( ::math::geometry::deg2rad( 180 ), 2, 1 )
 {
 }

S_cylinder::GC_vertical::GC_vertical( T_scalar const& P_phi, T_scalar const& P_height, T_scalar const& P_radius )
 : M2_phi( P_phi )
 , M2_height( P_height )
 , M2_radius( P_radius )
 {
 }

S_cylinder::GC_vertical::~GC_vertical()
 {
 }

S_cylinder::GC_vertical::T_size
S_cylinder::GC_vertical::Fv_beam
 (
   T_beam         &  P_beam
  ,T_coord2D const&  P_uv
 )const
 {
  static T_scalar const Is_pi = ::math::constants::PHI;

  T_coord & I_origin = P_beam[0].M_origin;

  I_origin[0] = 0;
  I_origin[1] = 0;
  I_origin[2] = P_uv[1] * (M2_height/2);

  T_coord & I_direction = P_beam[0].M_direction;

  I_direction[0] = M2_radius * cos(  Is_pi/2 - P_uv[0] * M2_phi/2 );
  I_direction[1] = M2_radius * sin(  Is_pi/2 - P_uv[0] * M2_phi/2 );
  I_direction[2] =  0;

  return 1;
 }

void
S_cylinder::GC_vertical::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
 {
  static T_scalar const Isc_phi = ::math::constants::PHI;

  T_coord I_eY;
  I_eY[0] = M2_radius * cos( Isc_phi/2 - P_uv[0] * M2_phi/2 );
  I_eY[1] = M2_radius * sin( Isc_phi/2 - P_uv[0] * M2_phi/2 );
  I_eY[2] = P_uv[1] * (M2_height / 2 );

  T_coord I_z;  ::math::linear::vector::load( I_z, 0, 0, 1 );
  T_coord I_eX; ::math::linear::vector::cross( I_eX, I_eY, I_z  ); ::math::linear::vector::length( I_eX, T_scalar(1) );
  T_coord I_eZ; ::math::linear::vector::cross( I_eZ, I_eY, I_eX ); ::math::linear::vector::length( I_eZ, T_scalar(1) );

  ::math::linear::vector::load<T_scalar,T_scalar>( P_affine.vector(), 0, 0, P_uv[1] );
  ::math::linear::matrix::system( P_affine.matrix(), I_eX, I_eY, I_eZ );
 }
