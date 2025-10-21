#include "./expression.hpp"

#include "IceRay/utility/expression/expression.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;

S_hfield::S_generator::GC_expression::GC_expression( T_string const& P_expression )
 {
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_compiler  T_compiler;
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_program   T_program;
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_memory    T_memory;
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_mapper    T_mapper;
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_library    T_library;

  T_string  M2_expression;
  T_program M2_program;
  T_memory  M2_memory;
  T_mapper  M2_mapper;
  T_library  M2_library;

  M2_mapper.F_tie( "result", 0 );
  M2_mapper.F_tie( "X", 1 ); M2_mapper.F_tie( "x", 1 );
  M2_mapper.F_tie( "Y", 2 ); M2_mapper.F_tie( "y", 2 );
  M2_mapper.F_tie( "Z", 3 ); M2_mapper.F_tie( "z", 3 );

  T_compiler I_compiler( M2_library, M2_mapper );
  I_compiler.F_compile( M2_program, P_expression );
  M2_program.F_memory( M2_memory );
  M2_program.F_execute( );
  M2_expression = P_expression;
 }

S_hfield::S_generator::GC_expression::T_scalar S_hfield::S_generator::GC_expression::Fv_value( T_size const& P_x, T_size const& P_y )const
 { // TODO
  auto width  = this->F_size()[0];
  auto height = this->F_size()[1];

  auto x = P_x /( width  - 1.0 ); x = 2*x-1;
  auto y = P_y /( height - 1.0 ); y = 2*y-1;
  return (sin( atan2( 5*x, 5*y ) )+1)/2.0;
 }

S_hfield::S_generator::GC_expression::T_scalar S_hfield::S_generator::GC_expression::Fv_value( T_size2D const& P_position )const
 {
  return Fv_value( { P_position[0], P_position[1] } );
 }
