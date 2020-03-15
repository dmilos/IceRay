#include "./disc.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


struct GC_disc::C_intersect
 {
  bool M_hit;
 };

GC_disc::GC_disc
 (
 )
 :GC_disc( ::math::linear::vector::fill( T_coord{}, 0 ), {0,0,1}, 1 )
 {
 }

GC_disc::GC_disc
 (
   T_coord  const& P_center
  ,T_coord  const& P_normal
  ,T_scalar const& P_radius
 )
 {
  M2_radius = P_radius;
  ::math::linear::vector::length( M2_normal, P_normal, T_scalar( 1 ) );
  M2_center = P_center;
  using namespace ::math::linear::vector;
  F_box
   (
     P_center -  ::math::linear::vector::fill( T_coord{}, -M2_radius )
    ,P_center +  ::math::linear::vector::fill( T_coord{}, +M2_radius )
   );
 }

bool GC_disc::Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray  )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar I_nd = ::math::linear::vector::dot( M2_normal, P_ray.M_direction );

  if( ( -Is_epsilon < I_nd ) && ( I_nd <  Is_epsilon ) )
   {
    return false;
   }

  using namespace ::math::linear::vector;
  T_scalar I_no = ::math::linear::vector::dot( M2_normal, M2_center - P_ray.M_origin );

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
  I_point *= I_lambda;
  I_point += P_ray.M_origin;

  T_scalar I_distance = ::math::linear::vector::distance( I_point, M2_center );

  if( I_distance < M2_radius )
   {
    P_lambda = I_lambda;
    return true;
   }

  return false;
 }

void GC_disc::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
  P_normal = M2_normal;
 }

GC_disc::T_location GC_disc::Fv_inside( T_coord const& P_point/*, T_state &P_intersect*/ )const
 {
  return En_out;
 }

GC_disc::T_scalar GC_disc::Fv_distance( T_coord const& P_point )const
{ // TODO
    return 1;
}

void GC_disc::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_disc::T_size
GC_disc::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool GC_disc::F_radius( T_scalar const& P_radius )
 {
  M2_radius = P_radius;
  return bool( true );
 }

bool GC_disc::F_normal( T_coord const& P_normal )
 {
  ::math::linear::vector::length( M2_normal, P_normal, T_scalar( 1 ) );
  return bool( true );
 }

bool GC_disc::F_center( T_coord const& P_center )
 {
  M2_center = P_center;
  return bool( true );
 }


