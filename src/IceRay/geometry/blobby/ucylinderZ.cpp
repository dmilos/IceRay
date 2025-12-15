#include "./ucylinderZ.hpp"
#include "./system.hpp"


using namespace GS_DDMRM::S_IceRay::S_geometry::S_blobby;




struct GC_ucylinderZ::C_intersect
 {
  enum Ee_hit{ En_undefined = 1, En_enter = 2, En_exit = 3, En_miss = 4, En_2far, En_behind };
  Ee_hit M_hit;
 };

GC_ucylinderZ::GC_ucylinderZ(  )
 :GC_ucylinderZ( 0.5 )
 {
 }

/* (x^2 - inf^2)^2 / ( rad^2 - inf^2 )^2 = c1 * ( x^2 - c0 )^2  == 1 */
GC_ucylinderZ::GC_ucylinderZ( T_scalar const& P_radius )
 : M2_radius( P_radius )
 , M2_c1( 1 )
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar I_f = M2_radius * M2_radius - 1;
  I_f *= I_f;

  if( ( -Is_epsilon < I_f ) && ( I_f < Is_epsilon ) )
   {
    M2_radius = 1 * 0.999;
    I_f = M2_radius * M2_radius - 1 * 1;
    I_f *= I_f;
   }

  M2_c1 = 1.0 / I_f;

  T_coord I_lo; ::math::linear::vector::fill( I_lo, -1 ); I_lo[2] = 0;
  T_coord I_hi; ::math::linear::vector::fill( I_hi, +1 );
  F1_box( T_box{ I_lo, I_hi } );
 }

GC_ucylinderZ::~GC_ucylinderZ( )
 {
 }

void
GC_ucylinderZ::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = C_intersect::En_undefined;
  return;
 }

GC_ucylinderZ::T_size
GC_ucylinderZ::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool GC_ucylinderZ::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  static T_scalar Is_infinity= 1e+12;// T_scalar( std::numeric_limits<T_scalar>::???() );

  C_intersect  &I_intersect = P_state.F_content<C_intersect>();

  T_ray I_ray( P_ray );
  I_ray.M_direction[ T_coord().size() - 1 ] = T_scalar( 0 );
  I_ray.M_origin[ T_coord().size() - 1 ] = T_scalar( 0 );

  T_scalar a = ::math::linear::vector::dot( I_ray.M_direction, I_ray.M_direction );

  if( ( - Is_epsilon < a ) && ( a < Is_epsilon ) )
   {
    I_intersect.M_hit = C_intersect::En_miss;
    return false;
   }

  T_scalar b = ::math::linear::vector::dot( I_ray.M_direction, I_ray.M_origin );
  T_scalar c = ::math::linear::vector::dot( I_ray.M_origin, I_ray.M_origin ) - 1;

  T_scalar d = b * b  -  a * c;
  if( d < Is_epsilon )
   {
    I_intersect.M_hit = C_intersect::En_miss;
    return false;
   }

  d = sqrt( d );

  T_scalar I_min = Is_epsilon;
  T_scalar I_max = P_lambda;

  if( Is_epsilon < P_ray.M_direction[2] )
   {
    I_min = -( P_ray.M_origin[2]  )/P_ray.M_direction[2];
    I_max = -( P_ray.M_origin[2]-1 )/P_ray.M_direction[2];
   }

  if( P_ray.M_direction[2] < - Is_epsilon )
   {
    I_min = -( P_ray.M_origin[2]-1)/P_ray.M_direction[2];
    I_max = -( P_ray.M_origin[2]  )/P_ray.M_direction[2];
   }


  {
   T_scalar I_lambda1 = (- b - d ) / a;

   if( I_min < I_lambda1 )
    {
     I_min = I_lambda1;
    }

   T_scalar I_lambda2 = ( - b + d )/a;
   if( I_lambda2 < I_max )
    {
     I_max = I_lambda2;
    }
  }

  if( I_max < I_min )
   {
    I_intersect.M_hit = C_intersect::En_miss;
    return false;
   }

  if( P_lambda < I_min )
   {
    I_intersect.M_hit = C_intersect::En_2far;
    return false;
   }

  if( Is_epsilon < I_min )
   {
    P_lambda = I_min;
    I_intersect.M_hit = C_intersect::En_enter;
    return true;
   }

  if( P_lambda < I_max )
   {
    I_intersect.M_hit = C_intersect::En_2far;
    return false;
   }

  if( Is_epsilon <  I_max )
   {
    P_lambda = I_max;
    I_intersect.M_hit = C_intersect::En_exit;
    return true;
   }

  I_intersect.M_hit = C_intersect::En_behind;
  return false;
 }

GC_ucylinderZ::T_location
GC_ucylinderZ::Fv_inside( T_coord const& P_point/*, T_intersect &P_intersect*/ )const
 {
  if( P_point[ T_coord().size() - 1 ] < 0 )
   {
    return En_out;
   }
  if( 1 < P_point[ T_coord().size() - 1 ] )
   {
    return En_out;
   }

  T_coord I_point( P_point );
  I_point[ T_coord().size()-1 ] = T_scalar( 0 );

  T_scalar I_distance = ::math::linear::vector::length( I_point );

  if( I_distance < 1 )
   {
    return En_in;
   }
  return En_out;
 }

void
GC_ucylinderZ::Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const
 {
  T_coord I_point( P_point );

  I_point[ T_coord().size() - 1 ] = 0;

  T_scalar I_distance2 = ::math::linear::vector::dot( I_point, I_point );
  /*l=sqrt(l);*/

  I_distance2 -= 1;
  if( 0 < I_distance2 )
   {
    P_normal[0] = P_normal[1] = P_normal[2] = 0;
    return;
   }

  I_distance2 *= T_scalar( 4 ) *  M2_c1;
  ::math::linear::vector::scale( P_normal,I_distance2, I_point );
 }

bool GC_ucylinderZ::Fv_coefficient
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

  T_coord I_direction = P_ray.M_direction;
  T_coord I_origin    = P_ray.M_origin;

  I_direction[ T_coord().size() - 1 ] = T_scalar( 0 );
  I_origin[  T_coord().size() - 1 ] = T_scalar( 0 );

  T_scalar a = ::math::linear::vector::dot( I_direction, I_direction );
  T_scalar b = 2*::math::linear::vector::dot( I_direction, I_origin );
  T_scalar c = ::math::linear::vector::dot( I_origin, I_origin ) - 1;

  //M2_c1*( a*t*t + b*t+ c ) * ( a*t*t + b*t+ c)

  P_coefficient[ 4 ] = M2_c1 * a * a;
  P_coefficient[ 3 ] = M2_c1 * T_scalar(2) * b * a;
  P_coefficient[ 2 ] = M2_c1 * ( b * b  +  T_scalar(2) *a* c );
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
    case( C_intersect::En_exit ) :  T_coefficient::Fs_invert( P_coefficient );  break;
   }

  return true;
 }

// f(x) = (x^2 - inf^2)^2 / ( rad^2 - inf^2 )^2
GC_ucylinderZ::T_scalar GC_ucylinderZ::Fv_intensity( T_coord const& P_point )const
 {
  T_coord I_point( P_point );
  I_point[2] = 0;
  T_scalar I_x = ::math::linear::vector::length( I_point );

  T_scalar I_intensity = ( I_x*I_x - T_scalar(1) );
  I_intensity *= I_intensity;
  I_intensity /= M2_c1;

  return I_intensity;
 }
