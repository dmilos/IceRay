#ifndef Dh_DDMRM_Iceray_type_container_jurisdiction_HPP_
 #define Dh_DDMRM_Iceray_type_container_jurisdiction_HPP_

// GS_DDMRM::S_IceRay::S_type::S_container::GT_jurisdiction

 
 #include "container/medium.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_container
        {

         template< typename N_data, typename N_allocator = std::allocator<N_data> >
          using GT_jurisdiction = GS_DDMRM::S_container::GC_medium<N_data, N_allocator>;

        }
      }
    }                                                                             
  }

#endif