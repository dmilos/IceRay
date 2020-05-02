#include <cmath>
#include "./obstruct.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;




GC_obstruct::GC_obstruct(  )
 :M2_child( nullptr )
 ,M2_barrier( nullptr )
 {
 }

GC_obstruct::GC_obstruct( T__pure *P_light, T_barrier * P_barrier )
 :M2_child( P_light )
 ,M2_barrier( nullptr )
 {
  F_barrier( P_barrier );
 }

GC_obstruct::T_size
GC_obstruct::Fv_swarm
 (
  T_swarm      & P_swarm
 ,T_coord const& P_point
 )const
 {
  if( nullptr == M2_child )
   {
    return 0;
   }

  T_size I_start = P_swarm.F_size();
  M2_swarm.F_clear();
  M2_child->Fv_swarm( M2_swarm, P_point );

  T_size Ir_count = 0;
  if( nullptr == M2_barrier )
   {
    for( auto const& I_spot: M2_swarm )
     {
       P_swarm.F_push( I_spot );
      ++Ir_count;
     }
    return Ir_count;
   }

   //if( M2_stateMemory.size() != M2_barrier->Fv_weight() )
   // {
   //  throw nullptr;
   // }

  T2_ray I_ray;
  I_ray.M_origin = P_point;
  for( auto const& I_spot: M2_swarm )
   {
     ::math::linear::vector::subtraction( I_ray.M_direction, I_spot.F_center(), I_ray.M_origin );

    T_scalar I_lambda = ::math::linear::vector::length( I_ray.M_direction, T_scalar(1) );

    M2_barrier->Fv_reset( M2_stateInstance );
    if( true == M2_barrier->Fv_intersect( I_lambda, M2_stateInstance, I_ray ) )
     {
      continue;
     }
    P_swarm.F_push( I_spot );

    ++Ir_count;
   }

  return Ir_count;
 }

bool   GC_obstruct::F_barrier( T_barrier * P_barrier )
 {
  M2_barrier = P_barrier;
  if( nullptr == M2_barrier )
   {
    M2_stateMemory.resize( 0 );
    M2_stateInstance = T2_state();
    return true;
   }

  M2_stateMemory.resize( M2_barrier->Fv_weight() );
  M2_stateInstance = T2_state( M2_stateMemory.data() );

  return bool( true );
 }

bool   GC_obstruct::F_child( T__pure * P_light )
 {
  M2_child = P_light;
  return bool( true );
 }
