#include "./_base.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_ray;

GC__base::GC__base()
 : M2_geometry( &Fs_vacuum() )
 {
 }

GC__base::~GC__base()
 {
 }

bool GC__base::Fv_geometry( T_geometry * P_geometry )
 {
  M2_geometry = P_geometry;
  return true;
 }

GC__base::T_vacuum & GC__base::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }
