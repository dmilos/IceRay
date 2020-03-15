#ifndef Dh_DDMM_IceRay_type_pointer_dumb_HPP_
 #define Dh_DDMM_IceRay_type_pointer_dumb_HPP_

 #include <vector>
 #include "memory/pointer/dumb.hpp"
 #include "IceRay/type/nothing.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_pointer
        {

         template <typename N_class>
          struct GC_dumb
           : public S_DDMRM::S_type::GC_nothing
           {
            public:
              //typedef GS_DDMRM::S_memory::S_pointer::GC_dumb<N_class> T_typedef;
              typedef N_class* T_typedef;
           };

        }
      }
    }
  }

#endif
