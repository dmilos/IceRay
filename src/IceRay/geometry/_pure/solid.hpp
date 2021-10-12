#ifndef _DDMRM_Iceray_geometry__pure_solid_hpp_
 #define _DDMRM_Iceray_geometry__pure_solid_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_solid

#include "./_base.hpp"
#include "IceRay/type/basic/bool.hpp"








 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC_solid
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_bool                T_bool;

           public:
                      GC_solid(){}
             virtual ~GC_solid(){}

           public:
             virtual T_bool      Fv_solid    ( T_state &P_state )const{ return T_bool( true ); }

          };

        }
      }
    }
  }

#endif
