#include "../../geometry/simple/box.hpp"

#include "../../type/math/coord.hpp"
#include "../../type/math/interval.hpp"

typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar GTs_coord;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_object;


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {


GTs_object *make_box( GTs_coord const& P_lo, GTs_coord const& P_hi )
  {
   typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;

   return new Tf_box( P_lo, P_hi );
  }

     }
   }
 }

