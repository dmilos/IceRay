#include "./utriangle.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_utriangle::C_intersect
 {
  bool M_hit;
 };


GC_utriangle::GC_utriangle()
 {
 }

GC_utriangle::~GC_utriangle( )
 {
 }

bool GC_utriangle::Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray  )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar t = P_ray.M_direction[2];

  if( ( - Is_epsilon < t ) && ( t < Is_epsilon ) )
   {
    return false; //!< Miss
   }

  T_coord const& I_origin = P_ray.M_origin;

  T_scalar I_lambda;
  I_lambda = -  I_origin[2] / t ;

  if( ( I_lambda < Is_epsilon ) || ( P_lambda < I_lambda ) )
   {
    return false;  //!< far or behind
   }

  T_coord I_intersect;
  ::math::linear::vector::combine( I_intersect, I_origin, I_lambda, P_ray.M_direction );
  auto const& u = I_intersect[0];
  auto const& v = I_intersect[1];

  if( I_intersect[0] < T_scalar( 0 ) ) return false;
  if( I_intersect[1] < T_scalar( 0 ) ) return false;


  if( T_scalar( 1 ) < ( u + v ) )
   {
    return false; //!< Miss
   }

  P_lambda = I_lambda;
  return true;  //!< YES
 }

void GC_utriangle::Fv_normal( T_coord &P_normal, T_coord const& P_point,  T_state const& P_intersect )const
 {
  ::math::linear::vector::load( P_normal, 0,0, 1 );
 }

GC_utriangle::T_location GC_utriangle::Fv_inside(T_coord const& P_point/*, T_state &P_intersect*/ )const
 {
  return En_out;
 }

GC_utriangle::T_scalar GC_utriangle::Fv_distance( T_coord const& P_point )const
 {
  // TODO
  return 1;
 }

bool   GC_utriangle::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const&P_intersect )const
 {
  P_uvw[0] = P_point[0];
  P_uvw[1] = P_point[1];
  P_uvw[2] = P_point[2];
  return true;
 }

void  GC_utriangle::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return;
 }

GC_utriangle::T_size GC_utriangle::Fv_weight( )const
 {
  return sizeof( C_intersect );
 }
