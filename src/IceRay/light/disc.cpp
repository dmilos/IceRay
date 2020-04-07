#include <cstdint>

#include "math/random/vdc.hpp"
#include "math/random/sobol1d.hpp"


#include "./disc.hpp"


using namespace GS_DDMRM::S_IceRay::S_light;




GC_disc::GC_disc( )
 :M2_sample( 1 )
 ,M2_x( ::math::linear::vector::fill( M2_x, 0 ) )
 ,M2_y( ::math::linear::vector::fill( M2_y, 0 ) )
 {
  M2_x[0] = 1;
  M2_y[1] = 1;

  F_sample( 1 );
 }

GC_disc::GC_disc
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

GC_disc::T_size
GC_disc::Fv_swarm
 (
   T_swarm       & P_swarm
  ,T_coord const & P_point
 )const
 {
  T_size I_index;
  T_spot I_spot( M2_spot );

  for( I_index = 0; I_index < M2_sample; I_index++ )
   {
    //T_coord2D I_point;
     T_scalar I_x, I_y;

    GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_x, I_y, M2_randSobol2D  );
   // GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_point, M2_VaLND );
   // GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_point[0], I_point[1], M2_randSobol2D  );
   // GS_DDMRM::S_IceRay::S_utility::S_random::GF_disc2D( I_point, M2_randStandard2D );

    // Position is not optimal;
    using namespace ::math::linear::vector;
    I_spot.F_center( M2_spot.F_center() + I_x * M2_x  +  I_y * M2_y );
    P_swarm.F_push( I_spot );
   }

  return M2_sample;
 }

bool
GC_disc::F_sample( T_size const& P_sample )
 {
  M2_spot.F_0() *= M2_sample;
  M2_spot.F_1() *= M2_sample;
  M2_spot.F_2() *= M2_sample;

  M2_sample = P_sample;

  M2_spot.F_0() /= M2_sample;
  M2_spot.F_1() /= M2_sample;
  M2_spot.F_2() /= M2_sample;

  F1_max() = F_sample();

  return bool( true );
 }

bool  GC_disc::F_spot( T_spot const& P_spot )
 {
  M2_spot = P_spot;

  M2_spot.F_0() /= M2_sample;
  M2_spot.F_1() /= M2_sample;
  M2_spot.F_2() /= M2_sample;

  return bool( true );
 }
