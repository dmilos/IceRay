#include <cmath>
#include "math/constants.hpp"
#include "./homography.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


S_transform::GC_homography::GC_homography( )
 {
 }

S_transform::GC_homography::GC_homography
 (
   T__pure *P_child
 )
 : GC__parent( P_child )
 {
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

  // TODO transform
  // transform back
  return 0;
 }
