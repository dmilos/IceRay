#include <cmath>
#include "math/constants.hpp"
#include "./homography.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


S_transform::GC_homography::GC_homography( )
 {
  ::math::linear::matrix::id( M2_2world );
  F_2world( M2_2world );
 }

S_transform::GC_homography::GC_homography
 (
   T__pure *P_child
 )
 : GC__parent( P_child )
 {
  ::math::linear::matrix::id( M2_2world );
  F_2world( M2_2world );
 }

S_transform::GC_homography::~GC_homography( )
 {
 }

S_transform::GC_homography::T_size
S_transform::GC_homography::Fv_swarm
 (
   T_swarm      & P_swarm
  ,T_coord const& P_point
 )const
 {
   T_coord I_point;

  ::math::linear::homography::transform( I_point, M2_2local, P_point );

  T_size I_new = F_child().Fv_swarm( P_swarm, I_point );

  for( T_size I_index = P_swarm.F_size() - I_new; I_index < P_swarm.F_size(); ++I_index )
   {
    ::math::linear::homography::transform( P_swarm[ I_index ].F_center(), M2_2world );
   }

  return I_new;
 }

 bool  S_transform::GC_homography::F_2world( T_homography const& P_2world )
 {
  M2_2world = P_2world;
  ::math::linear::matrix::invert( M2_2local, M2_2world );
  return bool( true );
 }

bool  S_transform::GC_homography::F_2local( T_homography const& P_2local )
 {
  M2_2local = P_2local;
  ::math::linear::matrix::invert( M2_2world, M2_2local );
  return bool( true );
 }
