#include "ellipsoid.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_ellipsoid::C_intersect
 {
  bool M_hit;
 };

GC_ellipsoid::GC_ellipsoid( )
 {
  ::math::linear::affine::id( M2_2world    );
  ::math::linear::affine::id( M2_2local    );
  ::math::linear::matrix::id( M2_transpose );

  F_box
   (
     ::math::linear::vector::fill<T_scalar>( T_coord{}, -1 )
    ,::math::linear::vector::fill<T_scalar>( T_coord{},  1 )
   );
 }

GC_ellipsoid::GC_ellipsoid( T_coord const&  P_center, T_coord const& P_radius )
 : GC_ellipsoid( )
 {
  F_load
   ( P_center
    ,::math::linear::vector::load<T_scalar,T_scalar>( T_coord{}, P_radius[0], 0, 0 )
    ,::math::linear::vector::load<T_scalar,T_scalar>( T_coord{}, 0, P_radius[1], 0 )
    ,::math::linear::vector::load<T_scalar,T_scalar>( T_coord{}, 0, 0, P_radius[2] )
   );
 }

GC_ellipsoid::GC_ellipsoid( T_coord const& P_center, T_coord const& P_eX, T_coord const& P_eY, T_coord const& P_eZ )
 : GC_ellipsoid()
 {
  F_load( P_center, P_eX, P_eY, P_eZ );
 }

GC_ellipsoid::~GC_ellipsoid(){}

bool GC_ellipsoid::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  T_coord I_origin;
  ::math::linear::affine::transform( I_origin, F_2local(), P_ray.M_origin );

  T_coord I_direction;
  ::math::linear::matrix::transform( I_direction, F_2local().matrix(), P_ray.M_direction );

  T_scalar a = ::math::linear::vector::dot( I_direction, I_direction ); //!< Always positive

  if( ( -Is_epsilon < a ) && ( a < Is_epsilon ) )
   {
    return I_intersect.M_hit = false;
   }

  T_scalar b = ::math::linear::vector::dot( I_direction, I_origin );
  T_scalar c = ::math::linear::vector::dot( I_origin, I_origin ) - T_scalar(1);

  if( true == I_intersect.M_hit )
   {
    if( -Is_epsilon < b )
     {
      return I_intersect.M_hit = false;
     }

    T_scalar I_lambda = - b / a;
    if( I_lambda < P_lambda )
     {
      P_lambda = I_lambda;
      return I_intersect.M_hit = true;
     }

    return I_intersect.M_hit = false;
   }

  T_scalar d = b * b  - a * c;
  if( d < Is_epsilon )
   {
    return I_intersect.M_hit = false;
   }

  d = sqrt( d );
  b = -b;
  T_scalar I_lambda;

  I_lambda = ( b - d ) / a;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    P_lambda = I_lambda;
    return I_intersect.M_hit = true;
   }

  I_lambda = ( b + d ) /a;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    P_lambda = I_lambda;
    return I_intersect.M_hit = true;
   }

  return I_intersect.M_hit = false;
 }

void GC_ellipsoid::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state      const& P_intersect
 )const
 {
  T_coord I_normal;
  ::math::linear::affine::transform( I_normal, F_2local(), P_point );

  ::math::linear::matrix::transform( P_normal, M2_transpose, I_normal );

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_ellipsoid::T_location GC_ellipsoid::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  static T_scalar Is_epsilon = 1e-8;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );

  T_scalar  I_distance = ::math::linear::vector::length( I_point ) - T_scalar( 1 );

  if( I_distance  < Is_epsilon )
   {
    return En_in;
   }

  if( Is_epsilon < I_distance )
   {
    return En_out;
   }

  return En_surface;
 }

GC_ellipsoid::T_scalar
GC_ellipsoid::Fv_distance( T_coord const& P_point )const
 {
  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );

  T_scalar Ir_distance = ::math::linear::vector::length( I_point );

  //TODO retransform
  return ::math::linear::vector::length( P_point );
 }

void
GC_ellipsoid::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_ellipsoid::T_size
GC_ellipsoid::Fv_weight( )const
 {
  return sizeof( C_intersect );
 }

bool GC_ellipsoid::F_center( T_coord const& P_center )
 {
  T_coord I_eX = F_2world().matrix()[0];
  T_coord I_eY = F_2world().matrix()[1];
  T_coord I_eZ = F_2world().matrix()[2];

  return F_load( P_center, I_eX, I_eY, I_eZ );
 }

bool GC_ellipsoid::F_system( T_coord const& P_eX, T_coord const& P_eY, T_coord const& P_eZ )
 {
  T_coord const& I_center = F_2world().vector();

  return F_load( I_center, P_eX, P_eY, P_eZ );
 }

bool GC_ellipsoid::F_load( T_coord const& P_center, T_coord const& P_eX, T_coord const& P_eY, T_coord const& P_eZ )
 {
  ::math::linear::affine::system( M2_2world, P_center, P_eX, P_eY, P_eZ );
  ::math::linear::affine::invert( M2_2local, F_2world() );
  ::math::linear::matrix::transpose( M2_transpose, F_2local().matrix() );

  T_interval I_unit{ {-1,-1,-1}, {1,1,1} };
  T_interval I_box;
  ::math::geometry::interval::transform( I_box, F_2world(),I_unit );

  Fv_box( I_box );

  return true;
 }
