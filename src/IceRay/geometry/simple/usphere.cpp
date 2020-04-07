/* 0017 *********************************************************************/
#define _UNIT_SPHERE_C_

#include "usphere.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_usphere::C_intersect
 {
  bool M_hit;
 };

GC_usphere::GC_usphere( )
 {

    F1_box( T_box{
     ::math::linear::vector::fill( T_coord{}, -1 )
    ,::math::linear::vector::fill( T_coord{},  1 )
   } );

 }

bool GC_usphere::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state  & P_intersect
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  T_scalar b = ::math::linear::vector::dot( P_ray.M_direction, P_ray.M_origin );

  T_scalar d = b * b  + T_scalar(1) - ::math::linear::vector::dot( P_ray.M_origin, P_ray.M_origin );

  if( d < Is_epsilon )
   {
    return false;
   }

  d = sqrt( d );
  b = -b;
  T_scalar I_lambda;

  I_lambda = b - d ;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    P_lambda = I_lambda;
    return true;
   }

  I_lambda = b + d ;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    P_lambda = I_lambda;
    return true;
   }

  return false;
 }

void GC_usphere::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state  const& P_intersect
 )const
 {
  P_normal =  P_point ;
 }

GC_usphere::T_location GC_usphere::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  T_scalar  I_distance = ::math::linear::vector::length( P_point ) - T_scalar(1);

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

GC_usphere::T_scalar
GC_usphere::Fv_distance( T_coord const& P_point )const
 {
  return ::math::linear::vector::length( P_point );
 }

void
GC_usphere::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_usphere::T_size
GC_usphere::Fv_weight( )const
 {
  return sizeof( C_intersect );
 }
