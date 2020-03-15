#ifndef _DDMRM_Iceray_geometry__pure_distance_hpp_
 #define _DDMRM_Iceray_geometry__pure_distance_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_distance

#include "./_base.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/math/coord.hpp"






 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC_distance
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                       T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D            T_coord;


                      GC_distance(){}
             virtual ~GC_distance(){}

             virtual T_scalar    Fv_distance ( T_coord const& P_point )const=0;
          };

        }
      }
    }
  }

#endif
