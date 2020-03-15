
#include "math/geometry/spline/bezier3/bezier.hpp"


#include "../../geometry/spline/spline.hpp"


#include "../../type/math/coord.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    GTs_coord;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_object;

typedef GS_DDMRM::S_math::S_geometry::S_spline::S_bezier3::GC_category<GTs_scalar, 2, 1, 3> GTs_category;
typedef GS_DDMRM::S_IceRay::S_geometry::GC_spline<GTs_category> GTs_spline;

typedef GS_DDMRM::S_math::S_geometry::S_spline::GC_struct<GTs_category> GTs_struct;

typedef GS_DDMRM::S_math::S_geometry::S_spline::GC_id<GTs_category> GTs_id;

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {


GTs_object * make_spline213(  )
 {
  GTs_struct I_struct;  
   GTs_id::Fs_make( I_struct );

   I_struct.M_c[0][0][0] = -1; I_struct.M_c[0][0][1] = -1; I_struct.M_c[0][0][2] =  0;

   I_struct.M_c[0][1][0] =  1; I_struct.M_c[0][1][1] = -1; I_struct.M_c[0][1][2] = -0;
   I_struct.M_c[1][0][0] = -1; I_struct.M_c[1][0][1] =  1; I_struct.M_c[1][0][2] =  0;

   I_struct.M_c[1][1][0] =  1; I_struct.M_c[1][1][1] =  1; I_struct.M_c[1][1][2] =  1;


   return new GTs_spline( I_struct );
  }

     }
   }
 }

