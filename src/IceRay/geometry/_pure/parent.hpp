#ifndef _DDMRM_Iceray_geometry__pure_parent_hpp_
 #define _DDMRM_Iceray_geometry__pure_parent_hpp_

// GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_parent

#include "./_base.hpp"









 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__pure
        {
         class GC_child;

         class GC_parent
          : virtual public GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base
          {
           public:

             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_child            T_child;
           public:
                      GC_parent();
             virtual ~GC_parent();

           public:
             virtual void        Fv_release( T_child *P_parent )=0;
             virtual void        Fv_attach(  T_child *P_parent )=0;
             virtual T_size      Fv_size   ()const=0; // Number of childrens
          };

        }
      }
    }
  }

#endif
