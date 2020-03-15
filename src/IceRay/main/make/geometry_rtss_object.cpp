#include "../../geometry/rtss/object.hpp"



typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_object;

typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure GTs_rtss;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object GTs_rtss_object;


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {


GTs_object * make_rtss_object()
 {
  return new GTs_rtss_object();
 }

GTs_object * make_rtss_object( GTs_object * P_object )
 {
  return new GTs_rtss_object( dynamic_cast<GTs_rtss*> ( P_object) );
 }

     }
   }
 }

