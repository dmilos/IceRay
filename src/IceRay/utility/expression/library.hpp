#ifndef Dh_DDMRM_Iceray_utility_expression_library_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_library_HPP_

// GS_DDMRM::S_IceRay::S_utility::S_expression::GC_library

#include <map>
#include "math/math.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/basic/string.hpp"

#include "./instruction.hpp"
 


namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

        class GC_library
         {
          public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_size T_size;
            typedef GS_DDMRM::S_IceRay::S_type::GT_string T_string;
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;

            typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_instruction  T_instruction;

            typedef std::map<T_string,T_instruction> T_container;
          public:
            GC_library();

          public:
            T_container const& F_container()const;
          private:
            T_container M2_container;
         };

       }
     }
   }
 }

#endif
