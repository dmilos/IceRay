#include "./ucylinder.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_ucylinder::C_intersect
 {
   //unsigned M_magic;
   bool M_hit;
 };


GC_ucylinder::GC_ucylinder(   )
 {
  T_coord I_lo, I_hi;
  I_lo[0] = -1; I_lo[1] = -1; I_lo[2] = -1;
  I_hi[0] =  1; I_hi[1] =  1; I_hi[2] = +1;

  F_box( I_lo, I_hi );
 }

GC_ucylinder::~GC_ucylinder( )
 {

 }

void
GC_ucylinder::Fv_reset( T_state &P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return ;
 }

GC_ucylinder::T_size
GC_ucylinder::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool GC_ucylinder::Fv_intersect( T_scalar     & P_lambda ,T_state      & P_state ,T_ray   const& P_ray )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  T_scalar a = P_ray.M_direction[0] * P_ray.M_direction[0]  +  P_ray.M_direction[1] * P_ray.M_direction[1]; //!< Alway positive
  if( ( - Is_epsilon < a ) && ( a < Is_epsilon ) )
   {
    return I_intersect.M_hit = false;
   }

  T_scalar b = P_ray.M_direction[0] * P_ray.M_origin[0]  +  P_ray.M_direction[1] * P_ray.M_origin[1];
  T_scalar c = P_ray.M_origin[0] * P_ray.M_origin[0]  +  P_ray.M_origin[1] * P_ray.M_origin[1]  -  1;

  if( true == I_intersect.M_hit )
   {
    c = 0;
   }

  T_scalar d = b * b  -  a * c;
  if( d < Is_epsilon )
   {
    return I_intersect.M_hit = false;
   }

  d = sqrt( d );
  b = -b;

  T_scalar I_lambda = (b-d)/a;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    T_scalar I_height = I_lambda * P_ray.M_direction[2] + P_ray.M_origin[2];
    if( ( T_scalar( 0 ) < I_height ) && ( I_height < T_scalar( +1 ) ) )
     {
      P_lambda = I_lambda;
      return I_intersect.M_hit = true;
     }
   }

  I_lambda = ( b + d )/a;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    T_scalar I_height = I_lambda * P_ray.M_direction[2] + P_ray.M_origin[2];
    if( ( T_scalar( 0 ) < I_height ) && ( I_height < T_scalar( +1 ) ) )
     {
      P_lambda = I_lambda;
      return I_intersect.M_hit = true;
     }
   }

  return I_intersect.M_hit = false;
 }

void GC_ucylinder::Fv_normal( T_coord           & P_normal, T_coord      const& P_point, T_state  const& P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  P_normal = P_point;
  P_normal[ 2/*T_coord::dimension()-1*/] = T_scalar(0);

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_ucylinder::T_location GC_ucylinder::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  if( T_scalar(1) < P_point[2] )
   {
    return En_out;
   }
  if( P_point[2] < T_scalar(0) )
   {
    return En_out;
   }

  T_scalar I_distance = ( P_point[0] * P_point[0]  +  P_point[1] * P_point[1] ) - 1;

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

GC_ucylinder::T_scalar
GC_ucylinder::Fv_distance( T_coord const& P_point )const
 {
  return sqrt( P_point[0] * P_point[0]  +  P_point[1] * P_point[1] ) - 1;
 }

