#ifndef Dh_DDMRM_Iceray_utility_expression_cell_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_cell_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_expression::GC_cell

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

        class GC_cell
         {
          public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;

          public:
            GC_cell( bool const& P_free=false, bool const& P_constant=true );

          public:
            bool F_valid()const;

          public:
            bool   M_free;
            bool   M_constant;
         };

       }
     }
   }
 }

#endif
