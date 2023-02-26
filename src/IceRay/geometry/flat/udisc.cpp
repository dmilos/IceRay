#include "./udisc.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_udisc::C_intersect
 {
  bool M_hit;
 };

GC_udisc::GC_udisc
 (
 )
 :GC_udisc( T_scalar( 1 ) )
 {
 }

GC_udisc::GC_udisc
 (
   T_scalar const& P_radius
 )
 {
  M2_radius = P_radius;
  F1_box
   ( T_box{ 
     ::math::linear::vector::fill( T_coord{}, -M2_radius )
    ,::math::linear::vector::fill( T_coord{}, +M2_radius )
   } );
 }

bool GC_udisc::Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray  )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar I_nd =  P_ray.M_direction[2];

  if( ( -Is_epsilon < I_nd ) && ( I_nd <  Is_epsilon ) )
   {
    return false;
   }

  T_scalar I_no = - P_ray.M_origin[2];

  T_scalar I_lambda = I_no/I_nd;

  if( I_lambda < Is_epsilon )
   {
    return false;
   }

  if( P_lambda < I_lambda )
   {
    return false;
   }

  T_coord I_point = P_ray.M_direction;
  ::math::linear::vector::scale(  I_point, I_lambda );
  ::math::linear::vector::addition( I_point , P_ray.M_origin );

  T_scalar I_distance = ::math::linear::vector::length( I_point );

  if( I_distance < M2_radius )
   {
    P_lambda = I_lambda;
    return true;
   }

  return false;
 }

void GC_udisc::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
::math::linear::vector::load( P_normal, 0,0, 1 );
 }

GC_udisc::T_location GC_udisc::Fv_inside( T_coord const& P_point/*, T_state &P_intersect*/ )const
 {
  return En_out;
 }

GC_udisc::T_scalar GC_udisc::Fv_distance( T_coord const& P_point )const
{ // TODO
    return 1;
}

void GC_udisc::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_udisc::T_size
GC_udisc::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool GC_udisc::F_radius( T_scalar const& P_radius )
 {
  M2_radius = P_radius;
  return bool( true );
 }

