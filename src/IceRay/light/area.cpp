#include <cstdint>

#include "math/random/vdc.hpp"
#include "math/random/sobol1d.hpp"


#include "./area.hpp"


using namespace GS_DDMRM::S_IceRay::S_light;




GC_area::GC_area( )
 :M2_sample( 1 )
 ,M2_x( ::math::linear::vector::fill( M2_x, 0 ) )
 ,M2_y( ::math::linear::vector::fill( M2_y, 0 ) )
 {
  M2_x[0] = 1;
  M2_y[1] = 1;

  F_sample( 1 );
 }

GC_area::GC_area
 (
   T_spot  const&  P_spot
  ,T_coord const&  P_c1
  ,T_coord const&  P_c2
  ,T_size  const&  P_sample
 )
 : M2_sample( 1 )
 , M2_spot( P_spot )
 , M2_x( P_c1 )
 , M2_y( P_c2 )
 {
  F_sample( P_sample );
 }

GC_area::T_size
GC_area::Fv_swarm
 (
   T_swarm       & P_swarm
  ,T_coord const & P_point
 )const
 {
  T_size I_index;
  T_spot I_spot( M2_spot );

  for( I_index = 0; I_index < M2_sample; I_index++ )
   {
    //T_scalar I_x, I_y; M2_randStandard2D( I_x, I_y );
     T_scalar I_x, I_y; M2_randSobol2D.next( I_x, I_y );
    //T_coord2D I_c2D; M2_randVaLND.next( I_c2D );

    ::math::linear::vector::combine( I_spot.F_center(), T_scalar(1), M2_spot.F_center(), I_x, M2_x, I_y, M2_y );
  //::math::linear::vector::combine( I_spot.F_center(), T_scalar(1), M2_spot.F_center(), I_c2D[0], M2_x, I_c2D[1], M2_y );
    P_swarm.F_push( I_spot );
   }
  return M2_sample;
 }

bool
GC_area::F_sample( T_size const& P_sample )
 {
  M2_spot.F_0() *= M2_sample;
  M2_spot.F_1() *= M2_sample;
  M2_spot.F_2() *= M2_sample;

  M2_sample = P_sample;

  M2_spot.F_0() /= M2_sample;
  M2_spot.F_1() /= M2_sample;
  M2_spot.F_2() /= M2_sample;

  this->F1_max() = P_sample;

  return bool( true );
 }

bool  GC_area::F_spot( T_spot const& P_spot )
 {
  M2_spot = P_spot;

  M2_spot.F_0() /= M2_sample;
  M2_spot.F_1() /= M2_sample;
  M2_spot.F_2() /= M2_sample;

  return bool( true );
 }
