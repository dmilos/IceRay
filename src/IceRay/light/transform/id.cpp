#include <cmath>
#include "math/constants.hpp"
#include "./id.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


S_transform::GC_identity::GC_identity( )
 {
 }

S_transform::GC_identity::GC_identity
 (
   T__pure *P_child
 )
 : GC__parent( P_child )
 {
 }

S_transform::GC_identity::~GC_identity( )
 {
 }

S_transform::GC_identity::T_size
S_transform::GC_identity::Fv_swarm
 (
   T_swarm      & P_swarm
  ,T_coord const& P_point
 )const
 {

  // TODO
  return 0;
 }
