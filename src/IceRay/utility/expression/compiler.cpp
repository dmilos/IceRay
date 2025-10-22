#include <regex>

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
  T_address address;
  
  address = F2_constant( 0, M2_expression->size() );
  if( true == address.F_valid() )
   {
    return true;
   }

  address = F2_binary( 0, M2_expression->size() );
  if (true == address.F_valid())
   {
    return true;
   }
  address = F2_variable( 0, M2_expression->size() );
  if (true == address.F_valid())
   {
    return true;
   }

  return false;
 }

GC_compiler::T_address GC_compiler::F2_constant( T_size const& P_begin, T_size const& P_end )
 {
  auto I_begin = P_begin;
  auto I_end = P_end;
  F2_trimspace( I_begin, I_end );
  T_string subexpress(M2_expression->begin() + I_begin, M2_expression->begin() + I_end);

  static std::regex pattern("([1-9]+)([0-9]+)");
  if( false == std::regex_match(subexpress, pattern ) )
   {
    return T_address{};
   }

  if( false == M2_mapper.F_exists( subexpress ) )
   {
    M2_mapper.F_tie( subexpress, M2_mapper.F_next() );
   }

  if( false == M2_mapper.F_exists( subexpress ) )
   {
    return T_address{};
   }

  return T_address{1, M2_mapper.F_container().find(subexpress)->second  };

  return T_address{};
 }

GC_compiler::T_address GC_compiler::F2_variable( T_size const& P_begin, T_size const& P_end )
 {
  auto I_begin = P_begin;
  auto I_end = P_end;
  F2_trimspace(I_begin, I_end);
  static std::regex pattern("([_a-zA-Z]+)([_0-9a-zA-Z]+)");

  T_string subexpress( M2_expression->begin() + I_begin, M2_expression->begin() + I_end );
  if( false == std::regex_match(subexpress, pattern ) )
   {
    return T_address{};
   }

  if( false == M2_mapper.F_exists( subexpress ) )
   {
    return T_address{};
   }

  return T_address{1, M2_mapper.F_container().find(subexpress)->second  };
 }
GC_compiler::T_address GC_compiler::F2_binary( T_size const& P_begin, T_size const& P_end )
 {
  // for()

  return T_address{};
 }

GC_compiler::T_address GC_compiler::F2_function( T_size const& P_begin, T_size const& P_end )
 {
  return T_address{};
 }

void GC_compiler::F2_trimspace( T_size& P_begin, T_size& P_end ) const
 {
    while( 0 != std::isspace( M2_expression->at(P_begin) ) ) ++P_begin;
    while( 0 != std::isspace( M2_expression->at(P_end-1) ) ) --P_end;
 }



       }
     }
   }
 }
