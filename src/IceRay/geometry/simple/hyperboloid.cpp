#include "./hyperboloid.hpp"

#include <iostream>
#include <iomanip>

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_hyperboloid::C_intersect
 {
  bool M_hit;
 };


GC_hyperboloid::GC_hyperboloid( )
 : GC_hyperboloid( 0.5 )
 {
 }

GC_hyperboloid::GC_hyperboloid( T_scalar const& P_core )
 {
    F1_box( T_box{  ::math::linear::vector::fill( T_coord{}, -1 ), ::math::linear::vector::fill( T_coord{}, +1 ) } );

  this->F_core( P_core );
 }

GC_hyperboloid::~GC_hyperboloid( )
 {
 }

bool GC_hyperboloid::Fv_intersect( T_scalar     & P_lambda ,T_state      & P_state ,T_ray   const& P_ray )const
 { // x*x + y*y = c*c +  * ( 1 - c*c ) * z*z
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  auto const& I_direction = P_ray.M_direction;
  auto const& I_origin    = P_ray.M_origin;

  T_scalar a = I_direction[0] * I_direction[0] + I_direction[1] * I_direction[1] - M2_a * I_direction[2] * I_direction[2];
  T_scalar b = I_direction[0] * I_origin[0] + I_direction[1] * I_origin[1] - ( M2_a *I_direction[2] * I_origin[2] );
  T_scalar c = I_origin[0]    * I_origin[0] + I_origin[1]    * I_origin[1] - ( M2_a *I_origin[2]  * I_origin[2] + M2_c );

  if( true == I_intersect.M_hit )
   {
    if( -Is_epsilon < b )
     {
      return I_intersect.M_hit = false;
     }

    T_scalar I_lambda = T_scalar( -2 ) * b / a;
    T_scalar I_height = I_lambda * I_direction[2] + I_origin[2];
    if( ( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) ) && ( ( T_scalar( -1 ) < I_height ) && ( I_height < T_scalar( 1 ) ) ) )
     {
      P_lambda = I_lambda;
      T_coord I_point;
      Fv_inside( ::math::linear::vector::combine( I_point, I_origin, P_lambda, I_direction ) );
      return I_intersect.M_hit = true;
     }

    return I_intersect.M_hit = false;
   }


  T_scalar d = b * b  - a*c;
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
   T_scalar I_lambda = ( b - d ) /a ;
   T_scalar I_height = I_lambda * I_direction[2] + I_origin[2];
   if( ( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) ) && ( ( T_scalar( -1 ) < I_height ) && ( I_height < T_scalar( 1 ) ) ) )
    {
     P_lambda = I_lambda;
     T_coord I_point;
     Fv_inside( ::math::linear::vector::combine( I_point, I_origin, P_lambda, I_direction ) );
     return I_intersect.M_hit = true;
    }
  }

  {
   T_scalar I_lambda = ( b + d ) / a;
   T_scalar I_height = I_lambda * I_direction[2] + I_origin[2];
   if( ( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) ) && ( ( T_scalar( -1 ) < I_height ) && ( I_height < T_scalar( 1 ) ) ) )
    {
     P_lambda = I_lambda;
     T_coord I_point;
     Fv_inside( ::math::linear::vector::combine( I_point, I_origin, P_lambda, I_direction ) );
     return I_intersect.M_hit = true;
    }
  }

  return I_intersect.M_hit = false;
 }

void GC_hyperboloid::Fv_normal
 (
   T_coord       & P_normal
  ,T_coord  const& P_point
  ,T_state  const& P_state
 )const
 {
  P_normal = P_point;
  P_normal[ 2/*T_coord::dimension()-1*/ ] *= -M2_a;

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_hyperboloid::T_location GC_hyperboloid::Fv_inside( T_coord const& P_point )const
 {
  static T_scalar Is_epsilon = 1e-10;
  T_scalar I_distance = P_point[0]    * P_point[0] + P_point[1]    * P_point[1] - ( M2_a *P_point[2]  * P_point[2] + M2_c );

  if( I_distance  < -Is_epsilon )
   {
    return En_in;
   }

  if( Is_epsilon < I_distance )
   {
    return En_out;
   }

  return En_surface;

 }

void
GC_hyperboloid::Fv_reset( T_state &P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_hyperboloid::T_size
GC_hyperboloid::Fv_weight( )const
 {
  T_size Ir_weigh = 0;
  Ir_weigh += sizeof( C_intersect );
  return Ir_weigh;
 }

bool GC_hyperboloid::F_core( T_scalar const& P_core )
 {
  M2_core = P_core;
  M2_a = T_scalar(1)-M2_core*fabs( M2_core );
  M2_b = T_scalar(1)-M2_core*fabs( M2_core );
  M2_c = P_core * fabs( M2_core );

  F1_box()[0][0] = F1_box()[0][1] = - std::max<T_scalar>( 1, fabs( M2_core ) );
  F1_box()[1][0] = F1_box()[1][1] = + std::max<T_scalar>( 1, fabs( M2_core ) );

  return true;
 }
