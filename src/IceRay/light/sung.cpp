#include <cmath>
#include "math/constants.hpp"
#include "./sung.hpp"
#include "./point.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


GC_sung::GC_sung( )
 : GC_sung( & Fs_point() )
 {
 }

GC_sung::GC_sung
 (
   T__pure *P_child
 )
 : M2_child( P_child )
 {
  F1_max() = M2_child->F_max();
 }

GC_sung::T_size
GC_sung::Fv_swarm
 (
   T_swarm      & P_swarm
  ,T_coord const& P_point
 )const
 {
  T_coord I_zero{0};

  auto I_begin  = P_swarm.F_size();
  auto Ir_count = M2_child->Fv_swarm( P_swarm, I_zero );
  auto I_end    = P_swarm.F_size();

  for( T_size I_index=I_begin; I_index < I_end; ++I_index )
   {
    ::math::linear::vector::addition( P_swarm[I_index].F_center(), P_point );
   }

  return Ir_count;
 }


GC_sung:: T__pure & GC_sung::Fs_point()
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;
  static Tf_point Irs_point( T_coord{ 0, 0, 1 } );

  return Irs_point; 
 }
