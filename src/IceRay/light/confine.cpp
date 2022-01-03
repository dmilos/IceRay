#include "./confine.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;




GC_confine::GC_confine( )
 :M2_hull( nullptr )
 ,M2_child( nullptr )
 ,M2_side( T_inside::En_in )
 {
 }

GC_confine::GC_confine( T__pure *P_child, T_inside* P_hull )
 :M2_hull( P_hull )
 ,M2_child( P_child )
 ,M2_side( T_inside::En_in )
 {
 }

GC_confine::T_size
GC_confine::Fv_swarm
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

  if( nullptr == M2_hull )
   {
    return Ir_count;
   }

  for( auto const& I_spot : M2_swarm  )
   {
    if( M2_side != M2_hull->Fv_inside( I_spot.F_center() ) )
     {
      continue;
     }

    P_swarm.F_push( I_spot );

    ++Ir_count;
   }

  return Ir_count;
 }

bool GC_confine::F_hull( T_inside * P_hull )
 {
  M2_hull = P_hull; 
  return bool( true ); 
 }

bool GC_confine::F_child( T__pure * P_child )
 {
  M2_child = P_child;
  return bool( true );
 }

