#include "./program.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {


 

void GC_program::F_memory( T_memory& P_memory )
 {
  for( auto & I_instruction: M2_container )
   {
    I_instruction.F_memory( P_memory );
   }
 }


void GC_program::F_execute( )
 {
  for( auto const& I_instruction: M2_container )
   {
    I_instruction.F_execute();
   }
 }



        }
      }
    }
  }
