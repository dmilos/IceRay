#include <cmath>
#include "math/constants.hpp"
#include "./suns.hpp"
#include "./point.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


GC_suns::GC_suns
 (
   T_spot const& P_spot
 )
 : M2_spot( P_spot )
 {
  F1_max() = 1;
 }

GC_suns::T_size
GC_suns::Fv_swarm
 (
   T_swarm      & P_swarm
  ,T_coord const& P_point
 )const
 {
  T_coord I_zero{0};

  P_swarm.F_push( M2_spot );

  ::math::linear::vector::addition( P_swarm.F_back().F_center(), P_point );

  return 1;
 }
