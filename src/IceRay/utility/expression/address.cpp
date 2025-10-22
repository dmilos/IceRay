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
 : M_length( 0 ), M_position( -1 )
 {
 }

GC_address::GC_address( T_size const& P_length, T_size const& P_position, bool const& P_constant )
 : M_length( P_length ), M_position( P_position ), M_constant( P_constant )
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
