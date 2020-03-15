#define _QUADRIC_C_

#include "./quadric.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_quadric::C_intersect
 {
  unsigned M_magic;
  bool M_hit;
 };

GC_quadric::GC_quadric()
 {
  using namespace ::math::linear::vector;
  T_coord I_lo; ::math::linear::vector::fill( I_lo, -1 );
  T_coord I_hi; ::math::linear::vector::fill( I_hi, +1 );
  F_box( I_lo, I_hi );

  ::math::linear::matrix::id( M2_matrix );
   F_matrix( M2_matrix );

   ::math::linear::vector::fill( M2_coord, T_scalar( 0 ) );
   F_coord( M2_coord );

   F_scalar( T_scalar( -1 ) );
 }

GC_quadric::GC_quadric( T_matrix const& P_matrix, T_coord const& P_coord, T_scalar const& P_scalar )
 : GC_quadric() 
 {
  F_matrix( P_matrix );
  F_coord( P_coord );
  F_scalar( P_scalar );
 }


void
GC_quadric::Fv_reset( T_state & P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  I_intersect.M_magic = 123456789;
  return;
 }

GC_quadric::T_size
GC_quadric::Fv_weight( )const
 {
  return sizeof( C_intersect );
 }

bool GC_quadric::Fv_intersect
 (
  T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray
  )const
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  auto const& I_origin = P_ray.M_origin;
  auto const& I_direction = P_ray.M_direction;

  std::tuple<unsigned, T_scalar, unsigned, T_scalar > I_interval;
  if( false == ::math::geometry::interval::intersect( I_interval, F_box(), { I_origin, I_direction }, Is_epsilon ) )
   {
    return I_intersect.M_hit = false; 
   }

  T_scalar I_infinum  = std::max<T_scalar>( std::get<1>( I_interval ), Is_epsilon );
  T_scalar I_supremum = std::min<T_scalar>( std::get<3>( I_interval ), P_lambda  );

  if( I_supremum < I_infinum )
   {
    return I_intersect.M_hit = false; 
   }

//  ( l *d + o ) (M(l *d + o) + v  ) + s = 0
//  ( l *d + o ) ( l* M(d) + M(o) + v ) + s = 0
//  ( l *d + o ) ( l* D + O + v ) + s = 0

  T_coord  O;  ::math::linear::matrix::transform( O, M2_matrix,I_origin );
  T_coord  D;  ::math::linear::matrix::transform( D, M2_matrix, I_direction );

  T_scalar a = ::math::linear::vector::dot( I_direction, D );

  T_scalar b =    + ::math::linear::vector::dot( I_direction, O ) 
                  + ::math::linear::vector::dot( I_direction, F_coord() ) 
                  + ::math::linear::vector::dot( I_origin, D ) 
               ;
  T_scalar c =   ::math::linear::vector::dot(  I_origin, O )
               + ::math::linear::vector::dot(  I_origin, F_coord() )
               + F_scalar()
          ;

  if( Is_epsilon < fabs( a ) )
   {
    if( true == I_intersect.M_hit )
     {
      T_scalar I_lambda = - b / a;
      if( (I_infinum < I_lambda ) && ( I_lambda < I_supremum ) )
       {
        P_lambda = I_lambda;
        return I_intersect.M_hit = true;
       }
      return I_intersect.M_hit = false;
     }

    T_scalar d = b * b  - 4*a*c;
    if( d < Is_epsilon )
     {
      return I_intersect.M_hit = false;
     }

    d = sqrt( d );
    if( d < Is_epsilon )
     {
      return I_intersect.M_hit = false;
     }

    if( a < 0 )
     {
      d = -d;
     }

    {
     T_scalar I_lambda = (- b-d)/(2*a);
     if( (I_infinum < I_lambda ) && ( I_lambda < I_supremum ) )
      {
       P_lambda = I_lambda;
       return I_intersect.M_hit = true;
      }
    }
    {
     T_scalar I_lambda = (-b+d)/(2*a);
     if( (I_infinum < I_lambda ) && ( I_lambda < I_supremum ) )
      {
       P_lambda = I_lambda;
       return I_intersect.M_hit = true;
      }
    }
    return I_intersect.M_hit = false;
   }

  if( Is_epsilon < fabs( b ) )
   {
    if( true == I_intersect.M_hit )
     {
      return I_intersect.M_hit = false;
     }

    T_scalar I_lambda = -c / b;
    if( (I_infinum < I_lambda ) && ( I_lambda < I_supremum ) )
     {
      P_lambda = I_lambda;
      return I_intersect.M_hit = true;
     }
   }

  return I_intersect.M_hit = false;
 }

void GC_quadric::Fv_normal
 (
  T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect
 )const
 {
   P_normal[0] = 2 * ::math::linear::vector::dot( M2_matrix[0], P_point );
   P_normal[1] = 2 * ::math::linear::vector::dot( M2_matrix[1], P_point );
   P_normal[2] = 2 * ::math::linear::vector::dot( M2_matrix[2], P_point );
  ::math::linear::vector::addition( P_normal, F_coord() );
  ::math::linear::vector::length( P_normal , T_scalar( 1 ) );
 }

GC_quadric::T_location
GC_quadric::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_coord  P;

  ::math::linear::matrix::transform( P, M2_matrix, P_point );
  ::math::linear::vector::addition( P, F_coord() );

  T_scalar value = ::math::linear::vector::dot( P_point, P ) + F_scalar();

  if( Is_epsilon < value )
   return En_in;

  if( value < Is_epsilon  )
   return En_out;

  return En_surface;
 }

bool GC_quadric::F_matrix( T_matrix const& P_matrix )
 {
  M2_matrix = P_matrix; 
  return bool( true );
 }

bool  GC_quadric::F_coord( T_coord const& P_coord )
 {
  M2_coord = P_coord; 
  return bool( true ); 
 }

bool  GC_quadric::F_scalar( T_scalar const& P_scalar )
 {
  M2_scalar = P_scalar;
  return bool( true );
 }


