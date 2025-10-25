#include "./expression.hpp"


using namespace GS_DDMRM::S_IceRay::S_geometry;

S_hfield::S_generator::GC_expression::GC_expression()
 : GC_expression( "0" )
 {
 }

S_hfield::S_generator::GC_expression::GC_expression( T_string const& P_expression )
 {
  M2_interval[0][0] = -1; M2_interval[1][0] = +1;
  M2_interval[0][1] = -1; M2_interval[1][1] = +1;
  M2_interval[0][2] = -1; M2_interval[1][2] = +1;
  F_expression( P_expression );
 }

S_hfield::S_generator::GC_expression::T_scalar S_hfield::S_generator::GC_expression::Fv_value( T_size const& P_x, T_size const& P_y )const
 {
  auto const I_width  = static_cast<T_scalar>( this->F_size()[0]);
  auto const I_height = static_cast<T_scalar>( this->F_size()[1]);

  auto I_x = ::math::function::any_to_any<T_scalar>( T_scalar( P_x ), T_scalar(0), I_width,  M2_interval[0][0], M2_interval[1][0] );
  auto I_y = ::math::function::any_to_any<T_scalar>( T_scalar( P_y ), T_scalar(0), I_height, M2_interval[0][1], M2_interval[1][1] );

  M2_memory.F_set( M2_x, I_x );
  M2_memory.F_set( M2_y, I_y );
  M2_program.F_execute();

  auto I_z = M2_memory.F_get( M2_result );

  I_z = ::math::function::any_to_any<T_scalar>( I_z, M2_interval[0][2], M2_interval[1][2], T_scalar(0), T_scalar( 1 ) );

  return I_z;
 }

S_hfield::S_generator::GC_expression::T_scalar S_hfield::S_generator::GC_expression::Fv_value( T_size2D const& P_position )const
 {
  return Fv_value( { P_position[0], P_position[1] } );
 }

 bool               S_hfield::S_generator::GC_expression::F_expression( T_string const& P_expression ) 
 { 
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_compiler  T_compiler;
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_mapper    T_mapper;
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_library    T_library;

  T_mapper  I_mapper;
  T_library  I_library;

  I_mapper.F_tie( "result", 0 );
  I_mapper.F_tie( "X", 1 ); I_mapper.F_tie( "x", 1 );  M2_x = 1;
  I_mapper.F_tie( "Y", 2 ); I_mapper.F_tie( "y", 2 );  M2_y = 2;

  T_compiler I_compiler( I_library, I_mapper );
  I_compiler.F_compile( M2_program, P_expression );

  if( false == I_compiler.F_result().F_valid() )
   {
    return bool( false );
   }

  M2_memory.F_resize( I_mapper.F_end() );

  for( auto const& I_item : I_mapper.F_container() )
   {
    std::size_t total;
    T_scalar I_value;
    try
     {
      I_value = std::stod( I_item.first, &total );
     }
    catch(...)
     {
      continue;
     }
    if( total != I_item.first.size() )
     {
      continue;
     }
    M2_memory.F_set( I_item.second, I_value );
   }

  M2_program.F_memory( M2_memory );
  M2_result = I_compiler.F_result().M_position;
  M2_expression = P_expression; 

  M2_program.F_execute();
  M2_memory.F_get( M2_result );
  return bool( true );
 }
