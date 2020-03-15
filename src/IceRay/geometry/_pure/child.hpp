#ifndef _DDMRM_Iceray_geometry__pure_child_hpp_
 #define _DDMRM_Iceray_geometry__pure_child_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_child

#include "./_base.hpp"









 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {
         class GC_parent;

         class GC_child
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_parent            T_parent;
           public:
             explicit GC_child( T_parent *P_parent = nullptr );
             virtual ~GC_child();

           public:
             virtual void        Fv_parent( T_parent *P_parent );
           protected:
           private:
             T_parent * M2_parent;
          };

        }
      }
    }
  }

#endif
