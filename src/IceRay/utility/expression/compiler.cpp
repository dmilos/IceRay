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
  M2_tmpPrefix="_tmpVal";
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

  Ir_result = F2_binary( {"+","-" }, I_begin, I_end );
  if( true == Ir_result.F_valid())
   {
    return Ir_result;
   }
  Ir_result = F2_binary( {"*","/" }, I_begin, I_end );
  if( true == Ir_result.F_valid())
   {
    return Ir_result;
   }

  //Ir_result = F2_binary( { "^" }, I_begin, I_end );
  //if( true == Ir_result.F_valid())
  // {
  //  return Ir_result;
  // }
 
  Ir_result = F2_function( I_begin, I_end );
  if( true == Ir_result.F_valid())
   {
    return Ir_result;
   }

  return Ir_result;
 }

GC_compiler::T_address GC_compiler::F2_constant( T_size const& P_begin, T_size const& P_end )
 {
  if( false == F2_isConstant( *M2_expression, P_begin, P_end ) )
   {
    return T_address{};
   }

  T_string subexpress(M2_expression->begin() + P_begin, M2_expression->begin() + P_end );
  if( false == M2_mapper.F_exists( subexpress ) )
   {
    M2_mapper.F_tie( subexpress, M2_mapper.F_end() );
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

  return T_address{ 1, M2_mapper.F_container().find(subexpress)->second };
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
    T_size I_result;
    switch( (F2_isTemp(I_left.M_position)?0:1) + ( F2_isTemp(I_right.M_position)?0:2) )
     {
      case( 0 ): I_result = std::min( I_left.M_position, I_right.M_position ); break;
      case( 1 ): I_result = I_right.M_position; break;
      case( 2 ): I_result = I_left.M_position;break;
      case( 3 ):
       {
        T_string I_tmp; F2_makeTemp( I_tmp );
        M2_mapper.F_add( I_tmp );
        I_result = M2_mapper.F_index( I_tmp );
       }
       break;
     }

    I_instruction.F_address( I_result, I_left.M_position, I_right.M_position );
    M2_program->F_push( I_instruction );

    return T_address{ 1, I_result };
   }

  return T_address{};
 }

GC_compiler::T_address GC_compiler::F2_function( T_size const& P_begin, T_size const& P_end )
 {
  T_string I_name;   I_name.reserve( 10 );
  T_size I_index = P_begin; 
  for( ; I_index < P_end;++I_index )
   {
    auto const& I_char = M2_expression->at( I_index );
    if( '(' == I_char )
     {
      break;
     }
    I_name.push_back( I_char );
   }
  auto I_instruction = M2_library.F_get( I_name );
  if( false == I_instruction.F_valid() )
   {
    return T_address{};
   }
  T_argument  I_list;
  F2_enclose( I_index, P_end, I_list );
  if( 0 == I_list.size() )
   {
    return T_address{};
   }
   T_size I_result = -1;

  for( auto const& I_argument : I_list )
   {
    if( true == F2_isTemp( I_argument.M_position ) )
     {
      I_result = std::min( I_argument.M_position, I_result );
     }
   }
  if( -1 == I_result  )
   {
    T_string I_tmp; F2_makeTemp( I_tmp );
    M2_mapper.F_add( I_tmp );
    I_result = M2_mapper.F_index( I_tmp );
   }
  switch( I_list.size() )
   {
    case(0): return T_address{ 1, I_result };
    case(1): I_instruction.F_address( I_result, I_list[0].M_position ); break;
    case(2): I_instruction.F_address( I_result, I_list[0].M_position, I_list[1].M_position ); break;
    case(3): I_instruction.F_address( I_result, I_list[0].M_position, I_list[1].M_position, I_list[2].M_position ); break;
    case(4): I_instruction.F_address( I_result, I_list[0].M_position, I_list[1].M_position, I_list[2].M_position, I_list[3].M_position ); break;
  }

  M2_program->F_push( I_instruction );

  return T_address{ 1, I_result };
 }

GC_compiler::T_size GC_compiler::F2_enclose( T_size const& P_begin, T_size const& P_end, T_argument& P_list )
{
  P_list.clear();
  if( P_end < P_begin + 3 )
   {
    return P_list.size();
   }

  if( ( '(' != M2_expression->at( P_begin ) ) || ( ')' != M2_expression->at( P_end -1) ) )
   {
    return P_list.size();
   }
  int I_counter = 1;
  for( T_size I_index = P_begin+1; I_index < P_end-1; ++I_index )
   {
    switch( M2_expression->at( I_index ) )
     {
      case( '(' ): ++I_counter; continue;
      case( ')' ): --I_counter; continue;
     }
    if( 0 == I_counter )
     {
      return P_list.size();
     }
   }

  return F2_comma( P_begin+1, P_end -1, P_list );
 }

GC_compiler::T_size GC_compiler::F2_comma( T_size const& P_begin, T_size const& P_end, T_argument& P_list )
 {
  P_list.clear();   P_list.reserve( 5 );
  T_size I_counter = 0;
  T_size I_begin = P_begin;
  for( T_size I_index = P_begin; I_index < P_end; ++I_index )
   {
    auto const& I_char = M2_expression->at( I_index );
    switch( I_char )
     {
      case('('): ++I_counter; continue;
      case(')'): --I_counter; continue;
     }
     if( 0 != I_counter )
      {
       continue;
      }
    if( ',' != I_char )
     {
      continue;
     }
    T_address I_address = F2_expression( I_begin, I_index );
    if( false == I_address.F_valid() )
     {
      P_list.clear();
      return P_list.size();
     }
    P_list.push_back( I_address );
    I_begin = I_index+1;
   }

  T_address I_address = F2_expression( I_begin, P_end );
  if( false == I_address.F_valid() )
   {
    P_list.clear();
    return P_list.size();
   }
  P_list.push_back( I_address );

  return P_list.size();
 }


void GC_compiler::F2_trimspace( T_size& P_begin, T_size& P_end ) const
 {
  while( 0 != std::isspace( M2_expression->at(P_begin) ) ) ++P_begin;
  while( 0 != std::isspace( M2_expression->at(P_end-1) ) ) --P_end;
 }

bool GC_compiler::F2_isConstant( T_string const& P_string, T_size const& P_begin, T_size const& P_end ) const
 {
  std::size_t I_total;
  try
   {
    auto I_value = std::stod( T_string( P_string.begin()+ P_begin, P_string.begin() + P_end ), &I_total );
   }
  catch( ... )
   {
    return false;
   }
  return I_total == (P_end - P_begin);

  //static std::regex pattern( "0|([1-9][0-9]*)(\\.[0-9]*)?" );
  //return std::regex_match( P_string.begin()+ P_begin, P_string.begin() + P_end, pattern );
 }

bool GC_compiler::F2_isTemp( T_size const& P_index )const
 {
  T_string const& I_name = M2_mapper.F_name( P_index );

  if( I_name.size() < M2_tmpPrefix.size() ) return false;

  return 0 == I_name.compare( 0, M2_tmpPrefix.size(), M2_tmpPrefix );
 }

void GC_compiler::F2_makeTemp( T_string & P_tmp ) const
 {
  P_tmp = M2_tmpPrefix
     +std::to_string(rand())
     +std::to_string(rand())
     +std::to_string(rand())
     +std::to_string(rand());
 }


       }
     }
   }
 }
