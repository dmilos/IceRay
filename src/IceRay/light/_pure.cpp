#include <cstdint>

#include "./_pure.hpp"


using namespace GS_DDMRM::S_IceRay::S_light;

GC__pure::GC__pure( T_size const& P_max )
  : GC__pure( T_interval{}, P_max )
 {
  ;
 }

GC__pure::GC__pure( T_interval const& P_interval, T_size const& P_max )
 :M2_box(P_interval), M2_max(P_max)
 {
  ;
 }

GC__pure::~GC__pure( )
 {
  ;
 }



