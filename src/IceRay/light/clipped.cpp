#include "./clipped.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;




GC_clipped::GC_clipped( )
 :M2_child( nullptr )
 ,M2_shell( nullptr )
 ,M2_side( T_inside::En_in )
 {
 }

GC_clipped::GC_clipped( T__pure *P_child, T_inside* P_shell )
 :M2_child( P_child )
 ,M2_shell( P_shell )
 ,M2_side( T_inside::En_in )
 {
 }

GC_clipped::T_size
GC_clipped::Fv_swarm
 (
  T_swarm      & P_swarm
 ,T_coord const& P_point
 )const
 {
  if( nullptr == M2_child )
   {
    return 0;
   }

  T_size Ir_count = 0;
  M2_swarm.F_clear();
  M2_child->Fv_swarm( M2_swarm, P_point );

  if( nullptr == M2_shell )
   {
    return Ir_count;
   }

  for( auto const& I_spot : M2_swarm  )
   {
    if( M2_side == M2_shell->Fv_inside( I_spot.F_center() ) )
     {
      continue;
     }

    P_swarm.F_push( I_spot );

    ++Ir_count;
   }

  return Ir_count;
 }
