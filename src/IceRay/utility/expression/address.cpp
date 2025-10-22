#include "./address.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {


GC_address::GC_address(   )
 {
 }

GC_address::GC_address( T_size const& P_length, T_size const& P_position )
 : M_length( P_length ), M_position( P_position )
 {
 }


bool GC_address::F_valid()const
 {
  return 0 != M_length;
 }

        }
      }
    }
  }
