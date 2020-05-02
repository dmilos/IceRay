#include "./paraboloid.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_paraboloid::C_intersect
 {
   //unsigned M_magic;
  bool M_hit;
 };

GC_paraboloid::GC_paraboloid( )
 {
  T_coord I_lo, I_hi;
  I_lo[0] = -1; I_lo[1] = -1; I_lo[2] = 0;
  I_hi[0] =  1; I_hi[1] =  1; I_hi[2] = 1;

  F1_box( T_box{ I_lo, I_hi } );
 }

GC_paraboloid::~GC_paraboloid( )
 {
 }

bool GC_paraboloid::Fv_intersect( T_scalar     & P_lambda ,T_state      & P_state ,T_ray   const& P_ray )const
 { // y = x*x + y*y
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  auto const& I_direction = P_ray.M_direction;
  auto const& I_origin    = P_ray.M_origin;

  T_scalar a = I_direction[0] * I_direction[0]  +  I_direction[1] * I_direction[1];
  T_scalar b = T_scalar( 2 ) * ( P_ray.M_direction[0] * P_ray.M_origin[0]  +  P_ray.M_direction[1] * P_ray.M_origin[1] ) - P_ray.M_direction[2];
  T_scalar c = P_ray.M_origin[0] * P_ray.M_origin[0]  +  P_ray.M_origin[1] * P_ray.M_origin[1]  -  P_ray.M_origin[2];

  if( ( - Is_epsilon < a ) && ( a < Is_epsilon ) )
   {
    T_scalar I_lambda = -c/b;
    if( ( -Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
     {
      T_scalar I_height = I_lambda * P_ray.M_direction[2] + P_ray.M_origin[2];
      if( ( 0 < I_height ) && ( I_height < 1 ) )
       {
        P_lambda = I_lambda;
        return true;
       }
     }
    return false;
   }

  T_scalar d = b * b - T_scalar(4) * a * c;
  if( d < Is_epsilon )
   {
    return false;
   }

  d = sqrt( d );
  b = -b;
  if( a < 0 )
   {
    d = -d;
   }

  T_scalar I_lambda = -1;
  I_lambda = ( b - d )/a * T_scalar( 0.5 );
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    T_scalar I_height = I_lambda * P_ray.M_direction[2] + P_ray.M_origin[2];
    if( ( I_height < T_scalar( 1 ) ) )
     {
      P_lambda = I_lambda;
      return true;
     }
   }

  I_lambda = ( b + d ) / a * T_scalar( 0.5 );
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    T_scalar I_height = I_lambda * P_ray.M_direction[2] + P_ray.M_origin[2];
    if(  ( I_height < T_scalar( 1 ) ) )
     {
      P_lambda = I_lambda;
      return true;
     }
   }

  return false;
 }

void GC_paraboloid::Fv_normal( T_coord           & P_normal, T_coord      const& P_point, T_state  const& P_intersect )const
 {
  P_normal = P_point;
  P_normal[ 2/*T_coord::dimension()-1*/ ] = T_scalar( - 0.5 );

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_paraboloid::T_location GC_paraboloid::Fv_inside( T_coord const& P_point )const
 {
  T_scalar I_distance = ( P_point[0] * P_point[0]  +  P_point[1] * P_point[1] ) - P_point[2] ;

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

void
GC_paraboloid::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_paraboloid::T_size
GC_paraboloid::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

