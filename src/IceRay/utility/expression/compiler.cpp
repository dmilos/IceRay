#include "./compiler.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

bool GC_compiler::F_tie(T_string const& P_name, T_size const& P_index )
 {
  M2_table[ P_name ] = P_index;
  M2_reverse[P_index] = P_name;
  return true;
 }

bool GC_compiler::F_compile(T_program& P_program, T_string const& P_string)
 {
  return false;
 }


       }
     }
   }
 }
