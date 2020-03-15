#include "./sphere.hpp"


using namespace GS_DDMRM::S_IceRay::S_geometry::S_blobby;



struct GC_sphere::C_intersect
 {
  enum Ee_hit{ En_undefined = 1, En_enter = 2, En_exit = 3, En_miss = 4, En_2far, En_behind };
  Ee_hit M_hit;
 };

GC_sphere::GC_sphere(  )
:GC_sphere( ::math::linear::vector::fill( T_coord{}, 0 ), 0.5, 1 )
 {
 }

GC_sphere::GC_sphere( T_coord const& P_center )
 :GC_sphere( P_center, 0.5, 1 )
 {
 }

/* (x^2 - inf^2)^2 / ( rad^2 - inf^2 )^2 = c1 * ( x^2 - c0 )^2  == 1 */
GC_sphere::GC_sphere( T_coord const& P_center, T_scalar const& P_radius, T_scalar const& P_influence )
 :M2_center( P_center )
 ,M2_radius( P_influence * P_radius )
 ,M2_influence ( P_influence )
 {
  static T_scalar Is_epsilon = 1e-10;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar I_f = M2_radius * M2_radius - M2_influence * M2_influence;
  I_f *= I_f;

  if( ( -Is_epsilon < I_f ) && ( I_f < Is_epsilon ) )
   {
    M2_radius = M2_influence * 0.999;
    I_f = M2_radius * M2_radius - M2_influence * M2_influence;
    I_f *= I_f;
   }

  M2_c0 = M2_influence * M2_influence;
  M2_c1 = 1.0 / I_f;

  T_coord I_lo; ::math::linear::vector::addition( I_lo, P_center, ::math::linear::vector::fill( T_coord(), -P_influence ) );
  T_coord I_hi; ::math::linear::vector::addition( I_hi, P_center, ::math::linear::vector::fill( T_coord(), +P_influence ) );
  F_box( I_lo, I_hi );
 }

GC_sphere::~GC_sphere( )
 {
 }

void
GC_sphere::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = C_intersect::En_undefined;
  return;
 }

GC_sphere::T_size
GC_sphere::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool GC_sphere::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;

  C_intersect  &I_intersect = P_state.F_content<C_intersect>();

//T_scalar a = ::math::linear::vector::dot( P_ray.M_direction, P_ray.M_direction );
  T_coord I_heading;
   ::math::linear::vector::subtraction( I_heading, P_ray.M_origin, M2_center );

  T_scalar b = ::math::linear::vector::dot( P_ray.M_direction, I_heading );
  T_scalar c = ::math::linear::vector::dot( I_heading, I_heading ) - M2_influence * M2_influence;

  switch( I_intersect.M_hit )
   {
    case( C_intersect::En_enter ):
     {
      if( - Is_epsilon < b )
       {
        I_intersect.M_hit = C_intersect::En_miss;
        return false;
       }

      //T_scalar I_lambda2 = -2 * b;
      // if(  P_lambda < I_lambda2 )
      //  {
      //   I_intersect.M_hit = C_intersect::En_2far;
      //   return false;
      //  }
      //
      // P_lambda = I_lambda2;
      // I_intersect.M_hit = C_intersect::En_exit;
      // return true;
      } break;
     case( C_intersect::En_exit  ):
      {
       if( - Is_epsilon < b )
        {
         I_intersect.M_hit = C_intersect::En_miss;
         return false;
        }
       T_scalar I_lambda2 = -2 * b;
       //if(  P_lambda < I_lambda2 )
       // {
       //  I_intersect.M_hit = C_intersect::En_2far;
       //  return false;
       // }
       //
       //P_lambda = I_lambda2;
       //I_intersect.M_hit = C_intersect::En_enter;
       //return true;
      }break;
    }

  T_scalar d = b * b  - c;

  if( d < Is_epsilon )
   {
    I_intersect.M_hit = C_intersect::En_miss;
    return false;
   }

  d = sqrt( d );
  b = -b;

  T_scalar I_lambda1 = b - d;
  T_scalar I_lambda2 = b + d;

  if( P_lambda < I_lambda1 )
   {
    I_intersect.M_hit = C_intersect::En_2far;
    return false;
   }

  if( Is_epsilon < I_lambda1 )
   {
    if( C_intersect::En_undefined != I_intersect.M_hit )
     {
      I_lambda1 = I_lambda1;
     }

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
    if( C_intersect::En_undefined != I_intersect.M_hit )
     {
      I_lambda2 = I_lambda2;
     }

    P_lambda = I_lambda2;
    I_intersect.M_hit = C_intersect::En_exit;
    return true;
   }

  I_intersect.M_hit = C_intersect::En_behind;
  return false;
 }

GC_sphere::T_location
GC_sphere::Fv_inside( T_coord const& P_point/*, T_intersect &P_intersect*/ )const
 {
  T_scalar I_distance = ::math::linear::vector::distance( P_point, M2_center );

  if( I_distance < M2_influence )
   {
    return En_in;
   }

  return En_out;
 }

void
GC_sphere::Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const
 {
  T_coord I_point( P_point );

  ::math::linear::vector::subtraction( I_point, M2_center );

  T_scalar I_distance2 = ::math::linear::vector::dot( I_point, I_point );
  /*l=sqrt(l);*/

  I_distance2 -= M2_c0;
  if( 0 < I_distance2 )
   {
    P_normal[0] = P_normal[1] = P_normal[2] = 0;
    return;
   }

  I_distance2 *= T_scalar( 4 ) *  M2_c1;
  ::math::linear::vector::scale( P_normal, I_distance2, I_point );
 }

bool GC_sphere::Fv_coefficient
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

  T_coord I_origin; ::math::linear::vector::subtraction( I_origin, P_ray.M_origin, M2_center );

//T_scalar a = ::math::linear::vector::dot( P_ray.M_direction, P_ray.M_direction );
  T_scalar b = 2 * ::math::linear::vector::dot( P_ray.M_direction, I_origin );
  T_scalar c = ::math::linear::vector::dot( I_origin, I_origin ) - M2_c0;

  //( a*t*t + b*t+ c) ^2

  P_coefficient[ 4 ] = M2_c1 * 1 * 1;
  P_coefficient[ 3 ] = M2_c1 * 2.0 * b;
  P_coefficient[ 2 ] = M2_c1 * ( b * b  +  2.0 * c );
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

 // f(x) = (x^2 - inf^2)^2 / ( rad^2 - inf^2 )^2
GC_sphere::T_scalar GC_sphere::Fv_intensity( T_coord const& P_point )const
 {
  T_scalar I_x = ::math::linear::vector::distance( P_point, M2_center );

  T_scalar I_intensity = ( I_x*I_x - M2_c0 );
  I_intensity *= I_intensity;
  I_intensity /= M2_c1;

  return I_intensity;
 }
