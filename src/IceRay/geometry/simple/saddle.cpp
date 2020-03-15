#include "./saddle.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_saddle::C_intersect
 {
  bool M_hit;
 };

GC_saddle::GC_saddle()
 {
  F_box
   (
     ::math::linear::vector::fill( T_coord{}, -1 )
    ,::math::linear::vector::fill( T_coord{},  1 )
   );

 }

GC_saddle::~GC_saddle( )
 {
 }

bool GC_saddle::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 { // z - x*y = 0;
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  auto const& I_direction = P_ray.M_direction;
  auto const& I_origin    = P_ray.M_origin;

  T_scalar a = -I_direction[0]*I_direction[1];
  T_scalar b = I_direction[2] - ( I_direction[1]*I_origin[0] +  I_direction[0]*I_origin[1] );
  T_scalar c = I_origin[2] - I_origin[0]*I_origin[1];

  if( true == I_intersect.M_hit )
   {
    if( -Is_epsilon < b )
     {
      return I_intersect.M_hit = false;
     }

    T_scalar I_lambda =  b / a;
    T_coord I_point; ::math::linear::vector::combine( I_point, I_origin, I_lambda, I_direction );
    if( ( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) ) && ( ::math::geometry::interval::in( F_box(), I_point ) ) )
     {
      P_lambda = I_lambda;
      Fv_inside( ::math::linear::vector::combine( T_coord{}, I_origin, P_lambda, I_direction ) );
      return I_intersect.M_hit = true;
     }

    return I_intersect.M_hit = false;
   }


  T_scalar d = b * b  - T_scalar(4)*a*c;
  if( d < Is_epsilon )
   {
    return I_intersect.M_hit = false;
   }

  d = sqrt( d );
  b = -b;
  if( a < 0 )
   {
    d = -d;
   }

  {
   T_scalar I_lambda = ( b - d ) / a / T_scalar( 2 );
   T_coord I_point; ::math::linear::vector::combine( I_point, I_origin, I_lambda, I_direction );
   if( ( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) ) && ( ::math::geometry::interval::in( F_box(), I_point ) ) )
    {
     P_lambda = I_lambda;
     Fv_inside( ::math::linear::vector::combine( T_coord{}, I_origin, P_lambda, I_direction ) );
     return I_intersect.M_hit = true;
    }
  }

  {
   T_scalar I_lambda = ( b + d ) / a / T_scalar( 2 );
   T_coord I_point; ::math::linear::vector::combine( I_point, I_origin, I_lambda, I_direction );
   if( ( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) ) && ( ::math::geometry::interval::in( F_box(), I_point ) ) )
    {
     P_lambda = I_lambda;
     Fv_inside( ::math::linear::vector::combine( T_coord{}, I_origin, P_lambda, I_direction ) );
     return I_intersect.M_hit = true;
    }
  }

  return I_intersect.M_hit = false;
 }

void GC_saddle::Fv_normal
 (
   T_coord        & P_normal
  ,T_coord   const& P_point
  ,T_state   const& P_state
 )const
 {
  //C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  P_normal[0] = -P_point[1];
  P_normal[1] = -P_point[0];
  P_normal[2] = 1;
  ::math::linear::vector::length( P_normal, T_scalar( 1 ) );
 }

GC_saddle::T_location
GC_saddle::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  static T_scalar Is_epsilon = 1e-10;
  T_scalar  I_distance = P_point[2] - P_point[0]*P_point[1];

  if( I_distance  < -Is_epsilon )
   {
    return En_in;
   }

  if( +Is_epsilon < I_distance )
   {
    return En_out;
   }

  return En_surface;
 }

GC_saddle::T_scalar
GC_saddle::Fv_distance( T_coord const& P_point )const
 { // TODO
  return 0;
 }

void
GC_saddle::Fv_reset( T_state & P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_saddle::T_size
GC_saddle::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }
