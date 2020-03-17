#include <cmath>
#include "math/constants.hpp"
#include "math/geometry/deg2rad.hpp"
#include "./reflector.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;



GC_reflector::GC_reflector( )
 :M2_direction( ::math::linear::vector::fill( M2_direction, 0 ) )
 ,M2_inner( ::math::geometry::deg2rad( 0 ) )
 ,M2_outter( ::math::geometry::deg2rad( 90 ) )
 {
  M2_direction[0] = 1;
  M2_inner = cos( M2_inner );
  M2_outter = cos( M2_outter );
 }

GC_reflector::GC_reflector
 (
   T_coord  const& P_position
  ,T_coord  const& P_direction
  ,T_scalar const& P_in
  ,T_scalar const& P_out 
 )
 :M2_spot( P_position )
 ,M2_direction( P_direction )
 ,M2_inner( P_in )
 ,M2_outter( P_out )
 {
  M2_inner = cos( M2_inner );
  M2_outter = cos( M2_outter );
 }

GC_reflector::GC_reflector
 (
  T_spot   const& P_spot,
  T_coord  const& P_direction,
  T_scalar const& P_in,
  T_scalar const& P_out
 )
 :M2_spot( P_spot )
 ,M2_direction( P_direction )
 ,M2_inner( P_in )
 ,M2_outter( P_out )
 {
  ::math::linear::vector::length( M2_direction, P_direction, T_scalar(1) );

  if( M2_inner > M2_outter )
   {
    std::swap( M2_inner, M2_outter );
   }

  M2_inner = cos( M2_inner );
  M2_outter = cos( M2_outter );
 }

GC_reflector::T_size
GC_reflector::Fv_swarm
(
  T_swarm      & P_swarm
 ,T_coord const& P_point
)const
 {
  static const T_scalar Is_small = 0.0001;
  T_scalar I_alfa, I_d;
  T_coord  I_v;
  T_spot I_spot( M2_spot );

  ::math::linear::vector::subtraction( I_v, P_point, I_spot.F_center() );
  I_d = ::math::linear::vector::length(  I_v );

  I_alfa = ::math::linear::vector::dot( I_v,  M2_direction );

  I_alfa /= I_d;

  if( M2_outter < I_alfa )
   return 0;  //!< nothig

  if( I_alfa < Is_small )
   {
    I_alfa = Is_small;
   }

  if( M2_inner < I_alfa  )
   {
    I_alfa = T_scalar( 1 ) ;
   }
   else
    {
     I_alfa=( I_alfa - M2_outter ) / ( M2_inner - M2_outter );
     I_alfa = I_alfa*I_alfa*( T_scalar( 3 ) - I_alfa - I_alfa );
    }

  I_spot.F_0() *= I_alfa;
  I_spot.F_1() *= I_alfa;
  I_spot.F_2() *= I_alfa;

  P_swarm.F_push( I_spot );

  return 1;
 }
