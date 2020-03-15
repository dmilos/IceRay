#ifndef Dh_DDMM_IceRay_type_container_medium_HPP_
 #define Dh_DDMM_IceRay_type_container_medium_HPP_

// GS_DDMRM::S_IceRay::S_type::S_container::GT_medium<N_number, N_dimension>

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
          using GT_medium = GS_DDMRM::S_container::GC_medium<N_data, N_allocator>;

        }
      }
    }
  }


#endif

