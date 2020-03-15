#ifndef _DDMRM_Iceray_geometry__pure_normal_hpp_
 #define _DDMRM_Iceray_geometry__pure_normal_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_normal

#include "./_base.hpp"


#include "../../type/math/coord.hpp"






 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC_normal
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:

             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar            T_coord;
           public:
                      GC_normal(){}
             virtual ~GC_normal(){}

           public:
             virtual void        Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const=0;
          };

        }
      }
    }
  }

#endif
