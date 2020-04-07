#include "./cone.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_cone::C_intersect
 {
  bool M_hit;
 };


GC_cone::GC_cone()
 {
  T_coord I_lo, I_hi;
  I_lo[0] = -1; I_lo[1] = -1;I_lo[2] = 0;
  I_hi[0] =  1; I_hi[1] =  1;I_hi[2] = 1;

  F1_box( T_box{ I_lo, I_hi } );
 }


GC_cone::~GC_cone( )
 {

 }

bool GC_cone::Fv_intersect( T_scalar     & P_lambda, T_state      & P_intersect, T_ray   const& P_ray  )const
 {
  static const T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  auto const& I_direction = P_ray.M_direction;
  auto const& I_origin    = P_ray.M_origin;

  T_scalar a = I_direction[0] * I_direction[0] + I_direction[1] * I_direction[1] - I_direction[2] * I_direction[2];
  if( ( - Is_epsilon < a ) && ( a < Is_epsilon ) )
   {
    return false;
   }

  T_scalar b = I_direction[0] * I_origin[0] + I_direction[1] * I_origin[1] - I_direction[2] * I_origin[2];
  T_scalar c = I_origin[0]    * I_origin[0] + I_origin[1]    * I_origin[1] - I_origin[2] * I_origin[2];

  T_scalar d = b * b  -  a * c;
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

  T_scalar I_lambda = T_scalar( -1 );
  T_scalar I_height;
  I_lambda = (b-d)/a;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    I_height = I_lambda * I_direction[2] + I_origin[2];
    if( ( T_scalar( 0 ) < I_height ) && ( I_height < T_scalar( 1 ) ) )
     {
      P_lambda = I_lambda;
      return true;
     }
   }

  I_lambda = (b+d)/a;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    I_height = I_lambda * I_direction[2] + I_origin[2];
    if( ( T_scalar( 0 ) < I_height ) && ( I_height < T_scalar( 1 ) ) )
     {
      P_lambda = I_lambda;
      return true;
     }
   }

  return false;
 }

void GC_cone::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state  const& P_intersect
 )const
 {
  P_normal = P_point;
  P_normal[ 2/*T_coord::dimension()-1*/] = -P_point[2/*T_coord::dimension()-1*/ ];
  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_cone::T_location  GC_cone::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  T_scalar I_distance = ( ( P_point[0] * P_point[0]  +  P_point[1] * P_point[1] ) - (P_point[2] * P_point[2]) );

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

GC_cone::T_scalar
GC_cone::Fv_distance( T_coord const& P_point )const
 {
  return -1;
 }

void
GC_cone::Fv_reset( T_state &P_intersect )const
 {
  return ;
 }

GC_cone::T_size
GC_cone::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }
