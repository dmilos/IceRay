#include "./compiler.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {


GC_compiler::GC_compiler( T_library const& P_library, T_mapper  & P_mapper )
 : M2_library( P_library ), M2_mapper( P_mapper )
 {

 }

bool GC_compiler::F_compile( T_program & P_program, T_string const& P_expression )
 {
  M2_program = &P_program;
  M2_expression = &P_expression;
  auto address = F2_constant( 0, M2_expression->size() );
  return false;
 }
GC_compiler::T_size GC_compiler::F2_null()const
 {
  return T_size(-1);
 }

GC_compiler::T_size GC_compiler::F2_constant( T_size const& P_begin, T_size const& P_end ) 
 {
  return T_size(-1);
 }
GC_compiler::T_size GC_compiler::F2_variable( T_size const& P_begin, T_size const& P_end ) 
 {
  return T_size(-1);
 }
GC_compiler::T_size GC_compiler::F2_operator( T_size const& P_begin, T_size const& P_end ) 
 {
  return T_size(-1);
 }
GC_compiler::T_size GC_compiler::F2_function( T_size const& P_begin, T_size const& P_end ) 
 {
  return T_size(-1);
 }


       }
     }
   }
 }
