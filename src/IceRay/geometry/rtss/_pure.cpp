#include "./_pure.hpp"


using namespace GS_DDMRM::S_IceRay::S_geometry::S_RTSS;

GC__pure:: GC__pure( )
 {
 }

GC__pure::~GC__pure( )
 {
 }

GC__pure::T_vacuum & GC__pure::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }
