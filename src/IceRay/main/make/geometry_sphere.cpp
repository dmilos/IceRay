#include "../../geometry/simple/sphere.hpp"


#include "../../type/math/coord.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar GTs_coord;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_object;


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {


GTs_object * make_sphere( GTs_coord const& P_center, GTs_scalar const& P_radius )
  {
   typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;

   return new Tf_sphere( P_center, P_radius );
  }

     }
   }
 }

