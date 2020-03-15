#ifndef _DDMRM_Iceray_geometry__pure_valid_hpp_
 #define _DDMRM_Iceray_geometry__pure_valid_hpp_

 // GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_valid

#include "./_base.hpp"









 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {

         class GC_valid
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:
             enum Ee_status
              {
                En_OK = -1
               ,En_error = 0
               ,En_partial
              };

             enum  T_type { OK, partial };

                      GC_valid(){}
             virtual ~GC_valid(){}

             virtual Ee_status Fv_valid ( )const{ return En_OK; }
          };

        }
      }
    }
  }

#endif
