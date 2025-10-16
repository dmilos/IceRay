#ifndef Dh_DDMRM_Iceray_utility_expression_compiler_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_compiler_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_expression::GC_compiler

#include <map>
#include "math/math.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/basic/string.hpp"

#include "./program.hpp"
#include "./mapper.hpp"




namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

        class GC_compiler
         {
          public:
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
           typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
           typedef GS_DDMRM::S_IceRay::S_type::GT_string T_string;

           typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_program   T_program;
           typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_mapper    T_mapper;

           bool F_compile( T_program & P_program, T_mapper & P_mappe, T_string const& P_expressionr );
         };

       }
     }
   }
 }

#endif
