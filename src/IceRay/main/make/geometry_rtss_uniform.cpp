#include "../../geometry/rtss/uniform.hpp"

#include "../../type/math/coord.hpp"

typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size GTs_dimension;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_object;

typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure GTs_rtss;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_uniform GTs_uniform;


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {


GTs_object * make_rtss_uniform( GTs_dimension const& P_dimension )
 {
  return new GTs_uniform( P_dimension );
 }


     }
   }
 }

