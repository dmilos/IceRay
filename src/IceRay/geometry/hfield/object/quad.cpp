#include "./quad.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object;

bool GC_quad::Fv_intersect( T_scalar &P_lambda, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_ray const& P_ray )const
 {
  static T_scalar Is_epsilon = 1e-9;
  T_scalar tx, ty, t;

  auto const& I_origin    = P_ray.M_origin;
  auto const& I_direction = P_ray.M_direction;

  tx =  P_10 - P_00;
  ty =  P_01 - P_00;
  t  =  P_11 - P_10 - ( P_01 - P_00 );

  T_scalar const I_a = I_direction[0] * I_direction[1] * t;
  T_scalar const I_b = tx * I_direction[0]  +  ty * I_direction[1] + t*( I_direction[0] * I_origin[1] + I_direction[1] * I_origin[0]) - I_direction[2];
  T_scalar const I_c = P_00 + tx * I_origin[0] + ty * I_origin[1] + t * I_origin[0] * I_origin[1]  -  I_origin[2];

  T_scalar I_lambda = -1.0;

  switch( ::math::polynomial::quadric::solve::general( tx, ty, { I_c, I_b, I_a}, Is_epsilon ) )
   {
    case( 2 ):
      if( Is_epsilon < ty )
       {
        auto I_x = I_origin[0]  +  ty * I_direction[0];
        auto I_y = I_origin[1]  +  ty * I_direction[1];

        if( ( 0 < I_x ) && ( I_x < 1 ) && ( 0 < I_y ) && ( I_y < 1 ) )
         {
          I_lambda = ty;
         }

       }
    case( 1 ):
      if( Is_epsilon < tx )
       {
        auto I_x = I_origin[0]  +  tx * I_direction[0];
        auto I_y = I_origin[1]  +  tx * I_direction[1];

        if( ( 0 <= I_x ) && ( I_x <= 1 ) && ( 0 <= I_y ) && ( I_y <= 1 ) )
         {
          I_lambda = tx;
         }
       }
     break;
    default: ;
   }

  if( ( Is_epsilon < I_lambda ) && (  I_lambda < P_lambda ) )
   {
    P_lambda = I_lambda;

    return true;
   }

  return false;
 }

//!
//!   (01)----(11)
//!    |        |
//!    Y        |
//!    |        |
//!   (00)-X--(10)
//!

void GC_quad::Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {  //! referent
  P_height =  P_00 + 
             (P_10 - P_00) * P_x + 
             (P_01 - P_00) * P_y + 
             ( (P_11 - P_01) - ( P_10 - P_00 ) ) * P_x * P_y;
 }

void GC_quad::Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
#if defined(_DEBUG)
  T_scalar I_height; this->Fv_height( I_height, P_00, P_10, P_01, P_11, P_x, P_y );
#endif
  P_normal[0] =(-1)*(  (P_10 - P_00)  +  P_y * ( ( P_11 - P_01 ) - ( P_10 - P_00 ) )  );
  P_normal[1] =(-1)*(  (P_01 - P_00)  +  P_x * ( ( P_11 - P_01 ) - ( P_10 - P_00 ) )  );
  P_normal[2] = +1.0;
  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }