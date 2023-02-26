
#include "./circle.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


GC_circle::GC_circle()
 :M2_x(::math::linear::vector::fill( M2_x, 0 ) )
 ,M2_y(::math::linear::vector::fill( M2_y, 0 ) )
 ,M2_sample( 1 )
 {
  M2_x[0] = 1;
  M2_y[1] = 1;
  F_sample( 1 );
  //M2_randGold = rand()/(T_scalar)RAND_MAX;
 }

GC_circle::GC_circle
 (
   T_spot  const&  P_spot
  ,T_coord const&  P_x
  ,T_coord const&  P_y
  ,T_size  const&  P_sample
 )
 :M2_spot( P_spot )
 ,M2_x( P_x )
 ,M2_y( P_y )
 ,M2_sample( 1 )
 {
  F_sample( P_sample );
 }

GC_circle::~GC_circle()
 {
 }

GC_circle::T_size
GC_circle::Fv_swarm( T_swarm &P_swarm,  T_coord const& P_point )const
 {
  T_size I_i;
  T_scalar I_x, I_y;
  T_spot I_spot( M2_spot );

  for( I_i = 0; I_i < M2_sample; I_i++ )
   {
    //T_scalar I_theta = ::math::constants::PHI_two * M2_randGold1D.next(); //!< win
    T_scalar I_theta = ::math::constants::PHI_two * M2_randCongruent1D.next(); //!< win
    //T_scalar I_theta  = ::math::constants::PHI_two * M2_randSobol1D.next();
    //T_scalar I_theta  = ::math::constants::PHI_two * M2_randVDC.next();
    //T_scalar I_theta  = ::math::constants::PHI_two * M2_randStandard1D.next();
    //T_scalar I_thetaT = ::math::constants::PHI_two * M2_randTable1D.next();

    I_y = cos( I_theta );
    I_x = sin( I_theta );

    ::math::linear::vector::combine( I_spot.F_center(), T_scalar(1), M2_spot.F_center(), I_x, M2_x, I_y, M2_y );
    P_swarm.F_push( I_spot );
   }

  return M2_sample;
 }

bool
GC_circle::F_sample( T_size const& P_sample )
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

bool
GC_circle::F_spot( T_spot const& P_spot )
 {
  M2_spot = P_spot;

  M2_spot.F_0() /= M2_sample;
  M2_spot.F_1() /= M2_sample;
  M2_spot.F_2() /= M2_sample;

  return bool( true );
 }
