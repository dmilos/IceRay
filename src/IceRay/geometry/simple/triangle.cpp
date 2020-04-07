#include "./triangle.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_triangle::C_intersect
 {
  bool M_hit;
 };


GC_triangle::GC_triangle()
 :GC_triangle
 (
   ::math::linear::vector::fill( T_coord{}, 0 )
  ,::math::linear::vector::make<T_scalar>( 1, 0, 0 )
  ,::math::linear::vector::make<T_scalar>( 0, 1, 0 )
 )
 {
 }

GC_triangle::GC_triangle
 (
  T_coord const& P_v1,
  T_coord const& P_v2,
  T_coord const& P_v3
 )
 {
  F2_setP( P_v1, P_v2, P_v3 );
 }

GC_triangle::~GC_triangle( )
 {
 }

bool GC_triangle::Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray  )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar t = ::math::linear::vector::dot( P_ray.M_direction, F_normal() );

  if( ( - Is_epsilon < t ) && ( t < Is_epsilon ) )
   {
    return false; //!< Miss
   }

  T_coord I_origin;
   ::math::linear::vector::subtraction( I_origin, P_ray.M_origin, M2_origin );

  T_scalar I_lambda;
  I_lambda = - ::math::linear::vector::dot( I_origin, F_normal() ) / t ;

  if( ( I_lambda < Is_epsilon ) || ( P_lambda < I_lambda ) )
   {
    return false;  //!< far or behind
   }

  T_coord I_intersect;
  ::math::linear::vector::combine( I_intersect, I_origin, I_lambda, P_ray.M_direction );

   auto  u = ::math::linear::vector::dot( M2_u, I_intersect ); if( u < T_scalar( 0 ) ) return false;
   auto  v = ::math::linear::vector::dot( M2_v, I_intersect ); if( v < T_scalar( 0 ) ) return false;


  if( T_scalar( 1 ) < ( u + v ) )
   {
    return false; //!< Miss
   }

  P_lambda = I_lambda;
  return true;  //!< YES
 }

void GC_triangle::Fv_normal( T_coord &P_normal, T_coord const& P_point,  T_state const& P_intersect )const
 {
  P_normal = F_normal();
 }

GC_triangle::T_location GC_triangle::Fv_inside(T_coord const& P_point/*, T_state &P_intersect*/ )const
 {
  return En_out;
 }

GC_triangle::T_scalar GC_triangle::Fv_distance( T_coord const& P_point )const
 {
  // TODO
  return 1;
 }

bool   GC_triangle::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const&P_intersect )const
 {
  T_coord I_point; ::math::linear::vector::subtraction( I_point, P_point, M2_origin );
  P_uvw[0] = ::math::linear::vector::dot( I_point, M2_u  );
  P_uvw[1] = ::math::linear::vector::dot( I_point, M2_v  );
  P_uvw[2] = ::math::linear::vector::dot( I_point, M2_w  );
  return true;
 }

void  GC_triangle::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_triangle::T_size GC_triangle::Fv_weight( )const
 {
  return sizeof( C_intersect );
 }

bool   GC_triangle::F_eX( T_coord const& P_eX )
 {
  M1_eX = P_eX;
  return F2_setV( M2_origin, F_eX(), F_eY() );
 }

bool  GC_triangle::F_eY( T_coord const& P_eY )
 {
  M1_eY = P_eY;
  return F2_setV( M2_origin, F_eX(), F_eY() );
 }

bool GC_triangle::F2_setP( T_coord const& P_v1, T_coord const& P_v2, T_coord const& P_v3 )
 {
  M2_origin = P_v1;
  ::math::linear::vector::subtraction( M1_eX, P_v2, P_v1 );
  ::math::linear::vector::subtraction( M1_eY, P_v3, P_v1 );

  ::math::linear::vector::cross( M1_normal, F_eX(), F_eY() );
  ::math::linear::vector::length( M1_normal, T_scalar(1) );

  T_matrix I_2world; ::math::linear::matrix::system( I_2world, M1_eX, M1_eY, M1_normal );
  T_matrix I_2local; ::math::linear::matrix::invert( I_2local, I_2world );

  M2_u = I_2local[0];
  M2_v = I_2local[1];
  M2_w = I_2local[2];

  T_box I_box;
  ::math::geometry::interval::load( I_box, P_v1, P_v2 );
  ::math::geometry::interval::extend( I_box, P_v3 );
  F1_box( I_box );
  return true;
 }

bool GC_triangle::F2_setV( T_coord const& P_o, T_coord const& P_eX, T_coord const& P_eY )
 {
  T_coord I_vX; ::math::linear::vector::addition( I_vX, P_eX, P_o );
  T_coord I_vY; ::math::linear::vector::addition( I_vY, P_eY, P_o );

  return F2_setP( P_o, I_vX, I_vY );
 }
