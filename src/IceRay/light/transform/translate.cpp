#include <cmath>
#include "math/constants.hpp"
#include "./translate.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


S_transform::GC_translate::GC_translate( )
:GC__parent( nullptr )
 {
  T_coord I_zero;
  ::math::linear::vector::fill( I_zero, 0 );
  F_2world( I_zero );
 }

S_transform::GC_translate::GC_translate
 (
   T__pure *P_child
  ,T_coord const& P_2world
 )
 :GC__parent( P_child )
 {
  F_2world( P_2world );
 }

S_transform::GC_translate::~GC_translate( )
 {
 }

S_transform::GC_translate::T_size
S_transform::GC_translate::Fv_swarm
 (
   T_swarm      & P_swarm
  ,T_coord const& P_point
 )const
 {
  T_coord I_point;

  ::math::linear::vector::addition( I_point, P_point, M2_2local );
  T_size I_new = F_child().Fv_swarm( P_swarm, I_point );

  for( T_size I_index = P_swarm.F_size() - I_new; I_index < P_swarm.F_size(); ++I_index )
   {
    ::math::linear::vector::addition( P_swarm[ I_index ].F_center(), M2_2world );
   }
  return I_new;
 }

bool  S_transform::GC_translate::F_2local( T_coord const& P_2local )
 {
  M2_2local = P_2local;
 ::math::linear::vector::negate( M2_2world, M2_2local );
  return bool( true );
 }
bool  S_transform::GC_translate::F_2world( T_coord const& P_2world )
 {
  M2_2world = P_2world; 
 ::math::linear::vector::negate( M2_2local, M2_2world );
  return bool( true );
 }
