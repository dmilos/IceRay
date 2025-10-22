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

GC_compiler::T_address const& GC_compiler::F_result()const
 {
  return M2_result;
 }

bool GC_compiler::F_compile( T_program & P_program, T_string const& P_expression )
 {
  M2_program    = &P_program;
  M2_expression = &P_expression;

  M2_program->F_clear();

  M2_result = F2_expression( 0, M2_expression->size() );

  return M2_result.F_valid();
 }

GC_compiler::T_address GC_compiler::F2_expression( T_size const& P_begin, T_size const& P_end )
 {
  auto I_begin = P_begin;
  auto I_end   = P_end;

  F2_trimspace( I_begin, I_end );
  T_address Ir_result;

  Ir_result = F2_constant( I_begin, I_end );
  if( true == Ir_result.F_valid() )
   {
    return Ir_result;
   }

  Ir_result = F2_variable( I_begin, I_end );
  if( true == Ir_result.F_valid() )
   {
    return Ir_result;
   }

  //for( {"+", "-", "*", "/", "^" })
  Ir_result = F2_binary( {"+","-" }, I_begin, I_end );
  if( true == Ir_result.F_valid())
   {
    return Ir_result;
   }
  return Ir_result;
 }

GC_compiler::T_address GC_compiler::F2_constant( T_size const& P_begin, T_size const& P_end )
 {
  T_string subexpress(M2_expression->begin() + P_begin, M2_expression->begin() + P_end );

  static std::regex pattern( "(0|([1-9]([0-9]*)))\\.([0-9]*)" );

  if( false == std::regex_match( subexpress, pattern ) )
   {
    return T_address{};
   }

  if( false == M2_mapper.F_exists( subexpress ) )
   {
    M2_mapper.F_tie( subexpress, M2_mapper.F_next() );
   }

  return T_address{ 1, M2_mapper.F_container().find(subexpress)->second  };
 }

GC_compiler::T_address GC_compiler::F2_variable( T_size const& P_begin, T_size const& P_end )
 {
  static std::regex pattern( "([_a-zA-Z]+)([_a-zA-Z0-9]*)" );
  T_string subexpress( M2_expression->begin() + P_begin, M2_expression->begin() + P_end );
  if( false == std::regex_match( subexpress, pattern ) )
   {
    return T_address{};
   }

  if( false == M2_mapper.F_exists( subexpress ) )
   {
    return T_address{};
   }

  return T_address{1, M2_mapper.F_container().find(subexpress)->second  };
 }
GC_compiler::T_address GC_compiler::F2_binary( std::set<T_string> const& P_set, T_size const& P_begin, T_size const& P_end )
 {
  int  I_counter = 0;
  T_string I_current(" ");

  for( T_size I_index = P_begin; I_index < P_end; ++I_index )
   {
    auto const& I_char = M2_expression->at( I_index );
    switch( I_char )
     {
      case( '(' ): ++I_counter; continue;
      case( ')' ): --I_counter; continue;
     }
     I_current[0] = I_char;
    if( ( 0 != I_counter ) || ( 0 == P_set.count( I_current ) ) )
     {
      continue;
     }
    T_address I_left  = F2_expression( P_begin, I_index );
    T_address I_right = F2_expression( I_index+1, P_end );

    auto I_instruction = M2_library.F_get( I_current );
    //switch( I_left.M_constant + 2*I_right.M_constant )
    //{
    // case TODO
    //}
    I_instruction.F_address( std::min( I_left.M_position, I_right.M_position ), I_left.M_position, I_right.M_position );
    M2_program->F_push( I_instruction );

    return T_address{1, std::min( I_left.M_position, I_right.M_position ) };
   }

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
