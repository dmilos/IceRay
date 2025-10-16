#ifndef Dh_DDMRM_Iceray_utility_expression_memory_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_memory_HPP_

// GS_DDMRM::S_IceRay::S_utility::S_expression::GC_memory

#include "math/math.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/basic/size.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_expression
        {

         class GC_memory
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::GT_size T_size;

             typedef std::vector<T_scalar> T_container;

             T_scalar const& F_get( T_size const& P_index );
             bool F_set( T_size const& P_index, T_scalar const& P_value );
             bool F_set( T_size const& P_index, T_size const & P_size, T_scalar * P_value );
             bool F_resize( T_size const& P_size );

             T_container      & F_container();
             T_container const& F_container()const;
          private:
             T_container M2_container;
          };

        }
      }
    }
  }

#endif
