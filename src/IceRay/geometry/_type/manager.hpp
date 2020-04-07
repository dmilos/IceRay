#ifndef Dh_DDMRM_Iceray_geometry_type_manager_hpp_
 #define Dh_DDMRM_Iceray_geometry_type_manager_hpp_

#include "memory/allocator/fixed.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S__type
        {

         //typedef GS_DDMRM::S_system::S_allocator::S_chunk::GC_managed GT_chunk;
         typedef GS_DDMRM::S_system::S_allocator::S_fixed::GC_manager GT_allocator;

        }
      }
    }
  }

#endif
