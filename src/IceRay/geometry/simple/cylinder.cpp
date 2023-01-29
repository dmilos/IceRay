#include "./cylinder.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_cylinder::C_intersect
 {
   //unsigned M_magic;
   bool M_hit;
 };


GC_cylinder::GC_cylinder(  T_scalar const& P_radius, T_scalar const& P_length )
 {
  F_radius( P_radius );
  F_length( P_length );
}

GC_cylinder::~GC_cylinder( )
 {
 }

void
GC_cylinder::Fv_reset( T_state &P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  return ;
 }

GC_cylinder::T_size
GC_cylinder::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool GC_cylinder::Fv_intersect( T_scalar     & P_lambda ,T_state      & P_state ,T_ray   const& P_ray )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  C_intersect &I_intersect = P_state.F_content<C_intersect>();

  auto const& I_direction = P_ray.M_direction;
  auto const& I_origin    = P_ray.M_origin;

  T_scalar a = I_direction[0] * I_direction[0]  +  I_direction[1] * I_direction[1]; //!< Always positive
  if( ( - Is_epsilon < a ) && ( a < Is_epsilon ) )
   {
    return I_intersect.M_hit = false;
   }

  T_scalar b = I_direction[0] * I_origin[0]  +  I_direction[1] * I_origin[1];
  T_scalar c = I_origin[0] * I_origin[0]  +  I_origin[1] * I_origin[1]  -  M2_r2;

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
    if( ( T_scalar( M2_ml2 ) < I_height ) && ( I_height < T_scalar( M2_pl2 ) ) )
     {
      P_lambda = I_lambda;
      return I_intersect.M_hit = true;
     }
   }

  I_lambda = ( b + d )/a;
  if( ( Is_epsilon < I_lambda ) && ( I_lambda < P_lambda ) )
   {
    T_scalar I_height = I_lambda * P_ray.M_direction[2] + P_ray.M_origin[2];
    if( ( T_scalar( M2_ml2 ) < I_height ) && ( I_height < T_scalar( M2_pl2 ) ) )
     {
      P_lambda = I_lambda;
      return I_intersect.M_hit = true;
     }
   }

  return I_intersect.M_hit = false;
 }

void GC_cylinder::Fv_normal( T_coord           & P_normal, T_coord      const& P_point, T_state  const& P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  P_normal = P_point;
  P_normal[ 2/*T_coord::dimension()-1*/] = T_scalar(0);

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_cylinder::T_location GC_cylinder::Fv_inside
 (
  T_coord const& P_point
 )const
 {

  if( P_point[2] < M2_ml2 )
   {
    return En_out;
   }
  if( M2_pl2 < P_point[2] )
   {
    return En_out;
   }

  static T_scalar Is_epsilon = 0;
  T_scalar I_distance = ( P_point[0] * P_point[0]  +  P_point[1] * P_point[1] ) - M2_r2;
  if( I_distance  < Is_epsilon )
   {
    return En_in;
   }

  if( Is_epsilon < I_distance )
   {
    return En_out;
   }

  return En_surface;
 }

GC_cylinder::T_scalar
GC_cylinder::Fv_distance( T_coord const& P_point )const
 {
  return sqrt( P_point[0] * P_point[0]  +  P_point[1] * P_point[1] ) - M2_radius;
 }

bool               GC_cylinder::F_radius( T_scalar const& P_radius )
 {
  M2_radius = P_radius;
  M2_r2  = M2_radius * M2_radius;

  T_coord I_lo, I_hi;
  I_lo[0] = -M2_radius; I_lo[1] = -M2_radius; I_lo[2] = M2_ml2;
  I_hi[0] =  M2_radius; I_hi[1] =  M2_radius; I_hi[2] = M2_pl2;
  F1_box( T_box{ I_lo, I_hi } );

  return true;
 }

bool               GC_cylinder::F_length( T_scalar const& P_length )
 {
  M2_length = P_length;
  M2_ml2  = -M2_length / T_scalar( 2 ) ;
  M2_pl2  = +M2_length / T_scalar( 2 ) ;

  T_coord I_lo, I_hi;
  I_lo[0] = -M2_radius; I_lo[1] = -M2_radius; I_lo[2] = M2_ml2;
  I_hi[0] =  M2_radius; I_hi[1] =  M2_radius; I_hi[2] = M2_pl2;
  F1_box( T_box{ I_lo, I_hi } );

  return true;
 }
