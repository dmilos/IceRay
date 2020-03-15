
#include "../../geometry/rtss/list.hpp"



typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_object;

typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure GTs_rtss;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_list GTs_list;


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {


GTs_object * make_rtss_list()
 {
  return new GTs_list();
 }

     }
   }
 }

