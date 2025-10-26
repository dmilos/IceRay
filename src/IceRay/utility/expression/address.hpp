#ifndef Dh_DDMRM_Iceray_utility_expression_address_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_address_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_expression::GC_address

#include <map>
#include "math/math.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/basic/string.hpp"






namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

        class GC_address
         {
          public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;

          public:
            GC_address();
            GC_address( T_size const& P_length, T_size const& P_position );

          public:

            bool F_valid()const;

          public:
            T_size M_length;
            T_size M_position;
         };

       }
     }
   }
 }

#endif
