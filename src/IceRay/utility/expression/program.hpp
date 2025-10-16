#ifndef Dh_DDMRM_Iceray_utility_expression_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_expression::GC_program

#include "math/math.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/basic/size.hpp"

#include "./instruction.hpp"
#include "./memory.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_expression
        {

         class GC_program
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::GT_size T_size;
             typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_memory T_memory;
             typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_instruction T_instruction;

             typedef std::vector<T_instruction>  T_container;

             void F_memory( T_memory & P_memory );
             void F_execute();
          private:
             T_container M2_container;
          };

        }
      }
    }
  }

#endif
