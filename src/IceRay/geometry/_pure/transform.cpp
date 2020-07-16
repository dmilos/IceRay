#include "./transform.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S__pure;


GC_transform::GC_transform()
 {
 }

GC_transform::~GC_transform()
 {
 }

GC_transform::T_affine const& GC_transform::Fs_identity ()
 {
  static T_affine Irs_identity  = ::math::linear::affine::id( T_affine{} );
  return  Irs_identity;
 }
