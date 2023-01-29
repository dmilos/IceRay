#include "./sphere.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_sphere::C_intersect
 {
  bool M_hit;
 };

GC_sphere::GC_sphere()
 : M2_center( ::math::linear::vector::fill( M2_center, 0 ) )
 , M2_radius( 1 )
 {
  M1_r2  = 1;
  M1_o_r = 1;

  F1_box( T_box{
     ::math::linear::vector::fill( T_coord{}, -1 )
    ,::math::linear::vector::fill( T_coord{},  1 )
   } );

 }

GC_sphere::GC_sphere
 (
   T_coord  const& P_center
  ,T_scalar const& P_radius
 )
 : M2_center( P_center )
 , M2_radius( P_radius )
 {

  if( P_radius < 1e-9 )
   {
    // bad_init
    return ;
   }

  M2_radius = M2_radius;

  M1_r2  = M2_radius * M2_radius;
  M1_o_r = T_scalar( 1 ) / M2_radius;

  M2_center = M2_center;

  using namespace ::math::linear::vector;

  F1_box( T_box{
     P_center -  ::math::linear::vector::fill( T_coord{}, M2_radius )
    ,P_center +  ::math::linear::vector::fill( T_coord{}, M2_radius )
   } );

 }

GC_sphere::~GC_sphere( )
 {

 }

bool GC_sphere::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  auto const& I_direction = P_ray.M_direction;
  auto const& I_origin    = P_ray.M_origin;

  T_coord I_position;
   ::math::linear::vector::subtraction( I_position, I_origin, M2_center );
//T_scalar a = ::math::linear::vector::dot( I_direction, I_direction ); //!< Always positive
  T_scalar b = ::math::linear::vector::dot( I_direction, I_position );
  T_scalar c = ::math::linear::vector::dot( I_position, I_position ) - M1_r2;

  if( true == I_intersect.M_hit )
   {
    if( -Is_epsilon < b )
     {
      return I_intersect.M_hit = false;
     }

    T_scalar I_lambda = T_scalar(-2) * b;
    if( I_lambda < P_lambda )
     {
      P_lambda = I_lambda;
      return I_intersect.M_hit = true;
     }

    return I_intersect.M_hit = false;
   }

  T_scalar d = b * b  - c;
  if( d < Is_epsilon )
   {
    return I_intersect.M_hit = false;
   }

  d = sqrt( d );
  b = -b;
  T_scalar I_lambda;

  I_lambda = b - d ;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    P_lambda = I_lambda;
    return I_intersect.M_hit = true;
   }

  I_lambda = b + d ;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    P_lambda = I_lambda;
    return I_intersect.M_hit = true;
   }

  return I_intersect.M_hit = false;
 }

void GC_sphere::Fv_normal
 (
   T_coord        & P_normal
  ,T_coord   const& P_point
  ,T_state   const& P_state
 )const
 {
  static T_scalar Is_epsilon = 1e-12;
  static T_scalar Is_one_small = T_scalar(1)-10*Is_epsilon;
  static T_scalar Is_one_exact = T_scalar(1);
  static T_scalar Is_one_big   = T_scalar(1)+Is_epsilon;

  //C_intersect const&I_intersect = P_state.F_content<C_intersect const>();

  ::math::linear::vector::subtraction( P_normal, P_point, M2_center );
  ::math::linear::vector::length( P_normal, Is_one_small );
 }

GC_sphere::T_location
GC_sphere::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  T_scalar  I_distance = ::math::linear::vector::distance( P_point, M2_center ) - M2_radius;

  if( I_distance  < 0 )
   {
    return En_in;
   }

  if( 0 < I_distance )
   {
    return En_out;
   }

  return En_surface;
 }

GC_sphere::T_scalar
GC_sphere::Fv_distance( T_coord const& P_point )const
 {
  return ::math::linear::vector::distance( P_point, M2_center );
 }

void
GC_sphere::Fv_reset( T_state & P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_sphere::T_size
GC_sphere::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool    GC_sphere::Fv_box( T_box const& P_box )
 {
  static T_scalar Is_epsilon = 1e-6;
  T_coord I_center; ::math::geometry::interval::center( I_center, P_box );

  T_coord I_size;   ::math::geometry::interval::size( I_size, P_box );
  T_scalar I_radius = std::min<T_scalar>( { I_size[0], I_size[1], I_size[2] } );

  if( fabs( I_radius ) < Is_epsilon )
   {
    return false;
   }

  F_center( I_center );
  F_radius( I_radius );

  return true;
 }

bool   GC_sphere::F_radius( T_scalar const& P_radius )
 {
  M2_radius = P_radius;

  M1_r2  = M2_radius * M2_radius;
  M1_o_r = T_scalar( 1 ) / M2_radius;

  using namespace ::math::linear::vector;
  T_coord I_lo = F_center() -  ::math::linear::vector::fill( T_coord{}, M2_radius );
  T_coord I_hi = F_center() +  ::math::linear::vector::fill( T_coord{}, M2_radius );
  F1_box( T_box{ I_lo, I_hi } );

  return bool( true );
 }

bool   GC_sphere::F_center( T_coord const& P_center )
 {
  M2_center = P_center;

  using namespace ::math::linear::vector;
  T_coord I_lo = F_center() -  ::math::linear::vector::fill( T_coord{}, M2_radius );
  T_coord I_hi = F_center() +  ::math::linear::vector::fill( T_coord{}, M2_radius );
  F1_box( T_box{ I_lo, I_hi } );

  return bool( true );
 }

GC_sphere::T__base*        GC_sphere::Fv_blank()const
 {
  return new GC_sphere();
 }

GC_sphere::T__base*        GC_sphere::Fv_clone()const
 {
  return new GC_sphere( F_center(), F_radius() );
 }

void            GC_sphere::Fv_release( T__base* P_this )const
 {
  delete  P_this;
 }

