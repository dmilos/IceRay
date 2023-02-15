#include "./triangle.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object;

bool GC_triangle::Fv_intersect( T_scalar &P_lambda, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_ray const& P_ray )const
 {
  static T_scalar Is_epsilon = 1e-9;
  T_coord I_origin; 
  T_coord I_X;      
  T_coord I_Y;      
  T_coord I_normal; 

  auto const& I_direction = P_ray.M_direction;

  T_scalar dot_down;

  T_scalar I_lambdaA = -1;
  ::math::linear::vector::load<T_scalar,T_scalar>( I_origin, 0, 0, P_00 );
  ::math::linear::vector::load<T_scalar,T_scalar>( I_X, 1, 0, P_10 - P_00 );
  ::math::linear::vector::load<T_scalar,T_scalar>( I_Y, 0, 1, P_01 - P_00 );
  ::math::linear::vector::cross( I_normal, I_X, I_Y );

  dot_down = ::math::linear::vector::dot( P_ray.M_direction, I_normal );
  if( Is_epsilon < fabs( dot_down ) )
   {
    T_coord I_heading;
    ::math::linear::vector::subtraction( I_heading, I_origin, P_ray.M_origin );
    T_scalar dot_up = ::math::linear::vector::dot( I_heading, I_normal );

    //point = P_ray.M_origin + ( dot_up / dot_down ) * P_ray.M_direction;
    I_lambdaA = dot_up / dot_down;
    if( Is_epsilon < I_lambdaA )
     {
      T_scalar I_x = P_ray.M_origin[0] + I_lambdaA * I_direction[0];
      T_scalar I_y = P_ray.M_origin[1] + I_lambdaA * I_direction[1];
      if( ( 0 <= I_x ) && ( 0 <= I_y ) && ( ( I_x + I_y ) <= 1 ) )
       {
       }else{ I_lambdaA = -1; }
     }else{ I_lambdaA = -1; }
   }else{ I_lambdaA = -1; }

  T_scalar I_lambdaB = -1;
    
  ::math::linear::vector::load<T_scalar,T_scalar>( I_origin, 1, 1, P_11 );
  ::math::linear::vector::load<T_scalar,T_scalar>( I_X, -1, 0, P_01 - P_11 );
  ::math::linear::vector::load<T_scalar,T_scalar>( I_Y, 0, -1, P_10 - P_11 );
  ::math::linear::vector::cross( I_normal, I_X, I_Y );
  dot_down = ::math::linear::vector::dot( P_ray.M_direction, I_normal );
  if( Is_epsilon < fabs( dot_down ) )
   {
    T_coord I_heading;
    ::math::linear::vector::subtraction( I_heading, I_origin, P_ray.M_origin );
    T_scalar dot_up = ::math::linear::vector::dot( I_heading, I_normal );

    //point = P_ray.M_origin + ( dot_up / dot_down ) * P_ray.M_direction;
    I_lambdaB = dot_up / dot_down;
    if( Is_epsilon < I_lambdaB )
     {
      T_scalar I_x = P_ray.M_origin[0] + I_lambdaB * I_direction[0];
      T_scalar I_y = P_ray.M_origin[1] + I_lambdaB * I_direction[1];
      if( ( I_x <= 1 ) && ( I_y <= 1 ) && ( 1 <= ( I_x + I_y ) ) )
       {
       }else{ I_lambdaB = -1; }
     }else{ I_lambdaB = -1; }
   }else{ I_lambdaB = -1; }
   /**/
  switch( ( ( 0 < I_lambdaA )?1:0  ) + ( (0 < I_lambdaB )?2:0 ) )
   {
    case( 0 ): return false;
    case( 1 ): if( I_lambdaA < P_lambda ) { P_lambda = I_lambdaA; return true; }
    case( 2 ): if( I_lambdaB < P_lambda ) { P_lambda = I_lambdaB; return true; }
    case( 3 ): 
     {
      T_scalar I_lambda = std::min( I_lambdaA, I_lambdaB );
      if( I_lambda < P_lambda ) { P_lambda = I_lambda; return true; } 
     } break;
   }

  return false;
 }

void GC_triangle::Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
  if( P_x + P_y < T_scalar(1) )
   { // TODO check
    T_scalar I_y0 = ::math::function::to_any<T_scalar>( P_x, P_00, P_10 );
    T_scalar I_y1 = ::math::function::to_any<T_scalar>( P_x, P_01, P_01 + (P_10 - P_00 ) );

    P_height = ::math::function::to_any( P_y, I_y0, I_y1 );
    return;
   }
  if( T_scalar(1) < P_x + P_y )
   { // TODO check
    T_scalar a = ::math::function::to_any( T_scalar(1)-P_x, P_11, P_01 );
    T_scalar b = ::math::function::to_any( T_scalar(1)-P_x, P_10, P_10 + (P_01 - P_11 ) );

    P_height = ::math::function::to_any( T_scalar(1)-P_y, a, b );
   }

 }

void GC_triangle::Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
  T_coord I_X;
  T_coord I_Y;
 
  if( P_x + P_y < T_scalar(1) )
   {
    ::math::linear::vector::load<T_scalar,T_scalar>( I_X, 1, 0, P_10 - P_00 );
    ::math::linear::vector::load<T_scalar,T_scalar>( I_Y, 0, 1, P_01 - P_00 );
   }
  if( T_scalar(1) < P_x + P_y )
   {
    ::math::linear::vector::load<T_scalar,T_scalar>( I_X, -1, 0, P_01 - P_11 );
    ::math::linear::vector::load<T_scalar,T_scalar>( I_Y, 0, -1, P_10 - P_11 );
   }

  ::math::linear::vector::cross( P_normal, I_X, I_Y );
  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }