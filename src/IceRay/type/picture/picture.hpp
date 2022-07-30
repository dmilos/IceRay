#ifndef Dh_DDMM_IceRay_type_picture_HPP_
 #define Dh_DDMM_IceRay_type_picture_HPP_

 //GS_DDMRM::S_IceRay::S_type::S_picture::GC_type::T_color;
 //GS_DDMRM::S_IceRay::S_type::S_picture::GC_type::GT__pure
 //GS_DDMRM::S_IceRay::S_type::S_picture::GC_type::GT_memory

 #include "./_pure.hpp"
 #include "./memory.hpp"

 #include "IceRay/type/math/coord.hpp"
 #include "IceRay/type/color.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_picture
        {

         struct GC_type
          {
           typedef GS_DDMRM::S_IceRay::S_type::GT_report          T_report;
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_char   T_color;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D T_coord;

            typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure    GT__pure;
            typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory    GT_memory;

          };

        }
      }
    }
  }

#endif

#include "./_pure.hpp"
#include "./crop.hpp"
#include "./memory.hpp"
#include "./default.hpp"
