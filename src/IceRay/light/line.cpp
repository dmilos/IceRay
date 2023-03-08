#include "math/math.hpp"
#include "./line.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;




GC_line::GC_line()
//:GC_line( T_spot{ ::math::linear::vector::load( T_coord{}, -1, -1, 0 ) }, ::math::linear::vector::load( T_coord{}, +1, +1, 0 ), 15 )
//:GC_line( T_spot{ ::math::linear::vector::load( T_coord{}, -1, 0, 0 ) }, ::math::linear::vector::load( T_coord{}, +1, 0, 0 ), 15 )
:GC_line( T_spot{ ::math::linear::vector::load( T_coord{}, 0, -1, 0 ) }, ::math::linear::vector::load( T_coord{}, 0, +1, 0 ), 15 )
 {
 }

GC_line::GC_line
 (
   T_spot  const&  P_spot
  ,T_coord const&  P_end
  ,T_size  const&  P_sample
 )
 :M2_spot( P_spot )
 ,M2_end( P_end )
 ,M2_sample( 1 )
 {
  F_sample( P_sample );
 }

GC_line::~GC_line()
 {

 }

GC_line::T_size
GC_line::Fv_swarm( T_swarm &P_swarm,  T_coord const& P_point )const
 {
  T_coord I_center;
  T_spot I_spot( M2_spot );
  for( T_size I_i = 0; I_i < M2_sample; I_i++ )
   {
    //T_scalar I_theta  = M2_randGold1D.next();
    //T_scalar I_theta = M2_randVDC.next();
    //T_scalar I_theta = M2_randSobol1D.next();
    //T_scalar I_theta = M2_randStandard1D.next();
    //T_scalar I_theta  = M2_randTable1D.next();
    T_scalar I_theta = M2_congurent1D.next();
    //T_scalar I_theta = M2_randPoisson1D.next();

    //static bool I_flip = true; I_flip = ! I_flip;
    // static unsigned I_index = 0; ++I_index;     ::math::linear::vector::convex( I_center, T_scalar( (I_index % 100)/100.0 ), M2_spot.F_center(), M2_end );

    ::math::linear::vector::convex( I_center, I_theta, M2_spot.F_center(), M2_end );

    I_spot.F_center( I_center );

    P_swarm.F_push( I_spot );
   }

  return M2_sample;
 }

bool
GC_line::F_sample( T_size const& P_sample )
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
GC_line::F_spot( T_spot const& P_spot )
 {
  M2_spot = P_spot;

  M2_spot.F_0() /= M2_sample;
  M2_spot.F_1() /= M2_sample;
  M2_spot.F_2() /= M2_sample;

  return bool( true );
 }

