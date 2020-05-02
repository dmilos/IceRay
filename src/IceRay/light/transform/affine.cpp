#include <cmath>
#include "math/constants.hpp"
#include "./affine.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


S_transform::GC_affine::GC_affine( )
 {
 }

S_transform::GC_affine::GC_affine
 (
   T__pure *P_child
 )
 : GC__parent( P_child )
 {
 }

S_transform::GC_affine::~GC_affine( )
 {
 }

S_transform::GC_affine::T_size
S_transform::GC_affine::Fv_swarm
 (
   T_swarm      & P_swarm
  ,T_coord const& P_point
 )const
 {
   T_coord I_point;

   ::math::linear::affine::transform( I_point, M2_function, P_point );

   T_size I_new = F_child().Fv_swarm( P_swarm, I_point );

   // TODO transform bck

  return 0;
 }
