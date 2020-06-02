#ifndef _DDMRM_type_general_parent_hpp_
 #define _DDMRM_type_general_parent_hpp_

// GS_DDMRM::S_type::S_general::GC_parent

#include "../basic/basic.hpp"



 namespace GS_DDMRM
  {
   namespace S_type
    {
     namespace S_general
      {
       class GC_child;

       class GC_parent
        {
         public:

           typedef GS_DDMRM::S_type::S_general::GC_child            T_child;
           typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
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

#endif
