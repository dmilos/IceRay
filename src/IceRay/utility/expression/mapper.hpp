#ifndef Dh_DDMRM_Iceray_utility_expression_mapper_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_mapper_HPP_

// GS_DDMRM::S_IceRay::S_utility::S_expression::GC_mapper

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

        class GC_mapper
         {
          public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_size T_size;
            typedef GS_DDMRM::S_IceRay::S_type::GT_string T_string;

            typedef std::map<T_string,T_size> T_container;
            typedef std::map<T_size,T_string> T_reverse;

            bool F_tie( T_string const& P_name, T_size const& P_index );
            bool F_untie( T_string const& P_name, T_size const& P_index );

            T_container const& F_container()const;
            T_reverse const& F_reverse()const;
          private:
            T_container M2_container;
            T_reverse M2_reverse;
         };

       }
     }
   }
 }

#endif
