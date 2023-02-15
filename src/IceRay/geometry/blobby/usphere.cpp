#include "./usphere.hpp"
#include "./system.hpp"


using namespace GS_DDMRM::S_IceRay::S_geometry::S_blobby;



struct GC_usphere::C_intersect
 {
  enum Ee_hit{ En_undefined = 1, En_enter = 2, En_exit = 3, En_miss = 4, En_2far, En_behind };
  Ee_hit M_hit;
 };


GC_usphere::GC_usphere(  )
 :GC_usphere( 0.5 )
 {
 }

/* (x^2 - inf^2)^2 / ( rad^2 - inf^2 )^2 = c1 * ( x^2 - c0 )^2  == 1 */
GC_usphere::GC_usphere( T_scalar const& P_core )
 :M2_core( P_core )
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar I_f = M2_core * M2_core - 1;
  I_f *= I_f;

  if( ( -Is_epsilon < I_f ) && ( I_f < Is_epsilon ) )
   {
    M2_core = 1 * 0.999;
    I_f = M2_core * M2_core - 1 ;
    I_f *= I_f;
   }

  M2_c1 = 1.0 / I_f;

  T_coord I_lo; ::math::linear::vector::fill( T_coord(), -1 );
  T_coord I_hi; ::math::linear::vector::fill( T_coord(), +1 );
  F1_box( T_box{ I_lo, I_hi } );
 }

GC_usphere::~GC_usphere( )
 {
 }

void
GC_usphere::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = C_intersect::En_undefined;
  return;
 }

GC_usphere::T_size
GC_usphere::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool GC_usphere::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  C_intersect  &I_intersect = P_state.F_content<C_intersect>();

//T_scalar a = ::math::linear::vector::dot( P_ray.M_direction, P_ray.M_direction );
  T_scalar b = ::math::linear::vector::dot( P_ray.M_direction, P_ray.M_origin );
  T_scalar c = ::math::linear::vector::dot( P_ray.M_origin, P_ray.M_origin ) - 1;

  T_scalar d = b * b  - c;

  if( d < Is_epsilon )
   {
    I_intersect.M_hit = C_intersect::En_miss;
    return false;
   }

  d = sqrt( d );
  b = -b;
  T_scalar I_lambda1 = b - d ;
  T_scalar I_lambda2 = b + d ;

  if( P_lambda < I_lambda1 )
   {
    I_intersect.M_hit = C_intersect::En_2far;
    return false;
   }

  if( Is_epsilon < I_lambda1 )
   {
    P_lambda = I_lambda1;
    I_intersect.M_hit = C_intersect::En_enter;
    return true;
   }

  if( P_lambda < I_lambda2 )
   {
    I_intersect.M_hit = C_intersect::En_2far;
    return false;
   }

  if( Is_epsilon < I_lambda2 )
   {
    P_lambda = I_lambda2;
    I_intersect.M_hit = C_intersect::En_exit;
    return true;
   }

  I_intersect.M_hit = C_intersect::En_behind;
  return false;
 }

GC_usphere::T_location
GC_usphere::Fv_inside( T_coord const& P_point/*, T_intersect &P_intersect*/ )const
 {
  T_scalar I_distance = ::math::linear::vector::length( P_point );

  if( I_distance < 1 )
   {
    return En_in;
   }

  return En_out;
 }

void
GC_usphere::Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const
 {

  T_scalar I_distance2 = ::math::linear::vector::dot( P_point, P_point );
  /*l=sqrt(l);*/

  I_distance2 -= 1;
  if( 0 < I_distance2 )
   {
    P_normal[0] = P_normal[1] = P_normal[2] = 0;
    return;
   }

  I_distance2 *= T_scalar( 4 ) *  M2_c1;
  ::math::linear::vector::scale( P_normal, I_distance2, P_point );
 }

bool GC_usphere::Fv_coefficient
 (
   T_coefficient::T_typedef & P_coefficient
  ,T_state             const& P_state
  ,T_ray               const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  C_intersect const &I_intersect = P_state.F_content<C_intersect>();

  switch( I_intersect.M_hit )
   {
    case( C_intersect::En_2far      ): T_coefficient::Fs_reset( P_coefficient ); return true;
    case( C_intersect::En_miss      ): T_coefficient::Fs_reset( P_coefficient ); return true;
    case( C_intersect::En_behind    ): T_coefficient::Fs_reset( P_coefficient ); return true;
    default: ; // !< continue;
   }

  T_coord const& I_direction = P_ray.M_direction;
  T_coord const& I_origin    = P_ray.M_origin;


  T_scalar a = ::math::linear::vector::dot( I_direction, I_direction );
  T_scalar b = 2 * ::math::linear::vector::dot( I_direction, I_origin );
  T_scalar c = ::math::linear::vector::dot( I_origin, I_origin ) - 1;

  //M2_c1*( a*t*t + b*t + c ) * ( a*t*t + b*t + c )

  P_coefficient[ 4 ] = M2_c1 * a * a;
  P_coefficient[ 3 ] = M2_c1 * T_scalar(2) * b * a;
  P_coefficient[ 2 ] = M2_c1 * ( b * b  +  T_scalar(2) * a * c );
  P_coefficient[ 1 ] = M2_c1 * 2 * b * c;
  P_coefficient[ 0 ] = M2_c1 * c * c;

  if( ( Is_epsilon < c ) && ( c < Is_epsilon ) )
   {
    P_coefficient[ 1 ] = 0.0;
    P_coefficient[ 0 ] = 0.0;
   }

  switch( I_intersect.M_hit )
   {
    default:
    case( C_intersect::En_undefined ): break;  // !< notnig
    case( C_intersect::En_enter     ): break;  // !< notnig
    case( C_intersect::En_exit      ): T_coefficient::Fs_invert( P_coefficient );  break;
   }

  return true;
 }

GC_usphere::T_scalar GC_usphere::Fv_intensity( T_coord const& P_point )const
 {
  T_scalar I_x = ::math::linear::vector::length( P_point );

  T_scalar I_intensity = ( I_x*I_x - T_scalar(1) );
  I_intensity *= I_intensity;
  I_intensity /= M2_c1;

  return I_intensity;
 }
