#include "./plane.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_plane::C_intersect
 {
  bool M_hit;
 };

GC_plane::GC_plane( )
 :M2_pivot(  ::math::linear::vector::fill( M2_pivot, 0 ))
 ,M2_normal( ::math::linear::vector::fill( M2_normal, 0 ))
 {
  static T_scalar Is_infinity = 1e+12;// T_scalar( std::numeric_limits<T_scalar>::???() );

  M2_normal[ T_coord().size() - 1 ] =1;

  F1_box( T_box{
     ::math::linear::vector::fill( T_coord{}, -Is_infinity )
    ,::math::linear::vector::fill( T_coord{}, +Is_infinity )
   } );

 }


GC_plane::GC_plane
 (
   T_coord const& P_origin
  ,T_coord const& P_normal
 )
 {
  static T_scalar Is_infinity= 1e+12;// T_scalar( std::numeric_limits<T_scalar>::???() );

  M2_pivot = P_origin;
  M2_normal = P_normal;
  ::math::linear::vector::length( M2_normal , P_normal, T_scalar(1) );

  using namespace ::math::linear::vector;
  T_coord I_lo; ::math::linear::vector::fill( I_lo, Is_infinity );
  T_coord I_hi; ::math::linear::vector::fill( I_hi, Is_infinity );
  F1_box( T_box{ I_lo, I_hi } );
 }

GC_plane::~GC_plane()
 {

 }

bool GC_plane::Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray  )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();

  if( true == I_intersect.M_hit )
   {
    return false;
   }

  T_scalar I_lambda =  ::math::linear::vector::dot( P_ray.M_direction, M2_normal );
  if( ( -Is_epsilon < I_lambda ) && (  I_lambda < Is_epsilon ) )
   {
    return false;
   }

  using namespace ::math::linear::vector;
  I_lambda = ::math::linear::vector::dot( M2_pivot - P_ray.M_origin,  M2_normal ) / I_lambda;

  if( ( I_lambda < Is_epsilon ) || ( P_lambda < I_lambda ) )
   {
    return false;
   }

  P_lambda = I_lambda;

  I_intersect.M_hit = true;
  return true;
 }

void GC_plane::Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
  P_normal = M2_normal;
 }

GC_plane::T_location  GC_plane::Fv_inside( T_coord const& P_point/*, T_state &P_intersect*/ )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_coord I_point; ::math::linear::vector::subtraction( I_point, P_point, M2_pivot );
  T_scalar I_distance = ::math::linear::vector::dot( I_point, M2_normal );

  if( +Is_epsilon < I_distance  )
   {
    return En_out;
   }

  if( I_distance  < -Is_epsilon )
   {
    return En_in;
   }

  return En_surface;
 }

GC_plane::T_scalar
GC_plane::Fv_distance( T_coord const& P_point )const
 {
  using namespace ::math::linear::vector;
  return ::math::linear::vector::dot( P_point - M2_pivot, M2_normal );
 }

void
GC_plane::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_plane::T_size
GC_plane::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

