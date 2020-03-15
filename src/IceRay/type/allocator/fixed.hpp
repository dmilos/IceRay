#ifndef Dh_DDMRM_Iceray_type_allocator_hpp_
 #define Dh_DDMRM_Iceray_type_allocator_hpp_

 #include "memory/allocator/fixed.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_allocator
        {
         typedef GS_DDMRM::S_system::S_allocator::S_fixed::GC_manager GT_manager;
       //typedef GS_DDMRM::S_system::S_allocator::S_fixed::GC_manager GT_chunk;

         // template< typename N_type> F_head()
         // template< typename N_head, N_tail> F_tail()
         // template< typename N_head, N_tail> F_tail()
        }

      }
    }
  }

#endif
