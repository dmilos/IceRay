#include "./spline.hpp"
#include "math/math.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;



GC_spline::GC_spline( )
 :M2_sample( 1 )
 {
  ::math::linear::vector::load( M2_cp[0], -1, -1, 0 );
  ::math::linear::vector::load( M2_cp[1], +1, -1, 0 );
  ::math::linear::vector::load( M2_cp[2], -1, +1, 0 );
  ::math::linear::vector::load( M2_cp[3],  1,  1, 0 );
 }

GC_spline::GC_spline
(
   T_spot  const& P_spot
  ,T_coord const P_cp[4]
  ,T_size  const& P_sample
 )
 :M2_spot( P_spot )
 ,M2_sample( 1 )
 {
  M2_cp[0] = P_cp[0];
  M2_cp[1] = P_cp[1];
  M2_cp[2] = P_cp[2];
  M2_cp[4] = P_cp[4];

  F_sample( P_sample );

  //M2_counter = 0;
 }

GC_spline::~GC_spline()
 {
 }

GC_spline::T_size
GC_spline::Fv_swarm
 (
  T_swarm      & P_swarm
 ,T_coord const& P_point
 )const
 {
  T_size I_index;
  T_spot I_spot( M2_spot );

  for( I_index = 0; I_index < M2_sample; I_index++ )
   {
  //T_scalar I_parm = M2_randVDC.next();
  //T_scalar I_parm = M2_randStandard1D.next();
  //T_scalar I_parm = M2_randGold.next();
  //T_scalar I_parm = M2_randSobol1D.next();
  //T_scalar I_parm = M2_randGold1D.next();
    T_scalar I_parm = M2_randCongruent1D.next();

    I_spot.F_center( M2_spot.F_center() );
    using namespace ::math::linear::vector;

    T_scalar I_t = ( T_scalar(1) - I_parm ) ;

    T_scalar I_t0 =     I_t    *    I_t * I_t;   
    T_scalar I_t1 = 3 * I_t    *    I_t * I_parm; 
    T_scalar I_t2 = 3 * I_t    * I_parm * I_parm; 
    T_scalar I_t3 =     I_parm * I_parm * I_parm;   

    I_spot.F_center()[0] = I_t0 * M2_cp[0][0] + I_t1 * M2_cp[0][0] + I_t2 * M2_cp[2][0] + I_t3 * M2_cp[3][0];
    I_spot.F_center()[1] = I_t0 * M2_cp[0][1] + I_t1 * M2_cp[0][1] + I_t2 * M2_cp[2][1] + I_t3 * M2_cp[3][1];
    I_spot.F_center()[2] = I_t0 * M2_cp[0][2] + I_t1 * M2_cp[0][2] + I_t2 * M2_cp[2][2] + I_t3 * M2_cp[3][2];

    P_swarm.F_push( I_spot );
   }

  return M2_sample;
 }

bool
GC_spline::F_sample( T_size const& P_sample )
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

bool
GC_spline::F_spot( T_spot const& P_spot )
 {
  M2_spot = P_spot;

  M2_spot.F_0() /= M2_sample;
  M2_spot.F_1() /= M2_sample;
  M2_spot.F_2() /= M2_sample;

  return bool( true );
 }

GC_spline::T_coord const&
GC_spline::F_cp( T_size const& P_index )const
 {
  if( 3 < P_index )
   {
    return M2_spot.F_center();
   }
  if( 0 == P_index )
   {
    return M2_spot.F_center();
   }
  return M2_cp[ P_index - 1];
 }

bool
GC_spline::F_cp( T_size const& P_index, T_coord const& P_value )
 {
  if( 3 < P_index )
   {
    return false;
   }
  if( 0 == P_index )
   {
    M2_spot.F_center(P_value );
    return true;
   }
  M2_cp[ P_index - 1 ] = P_value;
  return true;
 }
