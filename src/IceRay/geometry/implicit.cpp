#include "./implicit.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_implicit::C_intersect
 {
  bool M_hit;
 };


GC_implicit::GC_implicit()
 {
  T_coord I_lo, I_hi;
  I_lo[0] = -1; I_lo[1] = -1;I_lo[2] = 0;
  I_hi[0] =  1; I_hi[1] =  1;I_hi[2] = 1;

  F1_box( T_box{ I_lo, I_hi } );
  F_interval( T_box{ I_lo, I_hi } );
  M2_delta =  2.0/ 100000.0;  //  std::min(  )/ 100000;
 }

GC_implicit::~GC_implicit( )
 {

 }

bool GC_implicit::Fv_intersect( T_scalar     & P_lambda, T_state      & P_intersect, T_ray   const& P_ray  )const
 {
  static const T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  auto const& I_direction = P_ray.M_direction;
  auto const& I_origin    = P_ray.M_origin;

  T_scalar I_lambda = T_scalar( -1 );
  auto const& I_box = F_box();

  T_coord I_point;
  I_point[0] = ::math::function::any_to_any<T_scalar>( I_origin[0], I_box[0][0], I_box[1][0], M2_interval[0][0], M2_interval[1][0] );
  I_point[1] = ::math::function::any_to_any<T_scalar>( I_origin[1], I_box[0][1], I_box[1][1], M2_interval[0][1], M2_interval[1][1] );
  I_point[2] = ::math::function::any_to_any<T_scalar>( I_origin[2], I_box[0][2], I_box[1][2], M2_interval[0][2], M2_interval[1][2] );

  auto I_0 = F2_value( I_point );

  T_coord I_step;
  while( true )
   {
    math::linear::vector::addition( I_point, I_step );
    auto I_1 = F2_value( I_point );
    if( math::function::signum( I_0 ) != math::function::signum( I_1 ) )
     {
      break;
     }
   }

  return false;
 }

void GC_implicit::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state  const& P_intersect
 )const
 {
  T_coord I_point;
  auto const& I_box = F_box();

  I_point[0] = ::math::function::any_to_any<T_scalar>( P_point[0], I_box[0][0], I_box[1][0], M2_interval[0][0], M2_interval[1][0] );
  I_point[1] = ::math::function::any_to_any<T_scalar>( P_point[1], I_box[0][1], I_box[1][1], M2_interval[0][1], M2_interval[1][1] );
  I_point[2] = ::math::function::any_to_any<T_scalar>( P_point[2], I_box[0][2], I_box[1][2], M2_interval[0][2], M2_interval[1][2] );

  auto I_0 = F2_value( I_point );
  I_point[0] += M2_delta;    P_normal[0] = F2_value( I_point );  I_point[0] -= M2_delta;
  I_point[1] += M2_delta;    P_normal[1] = F2_value( I_point );  I_point[1] -= M2_delta;
  I_point[2] += M2_delta;    P_normal[2] = F2_value( I_point );//I_point[2] -= M2_delta;

  math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_implicit::T_location  GC_implicit::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  auto const & I_box = F_box(); 
  T_coord I_point;

  I_point[0] = ::math::function::any_to_any<T_scalar>( P_point[0], I_box[0][0], I_box[1][0], M2_interval[0][0], M2_interval[1][0] );
  I_point[1] = ::math::function::any_to_any<T_scalar>( P_point[1], I_box[0][1], I_box[1][1], M2_interval[0][1], M2_interval[1][1] );
  I_point[2] = ::math::function::any_to_any<T_scalar>( P_point[2], I_box[0][2], I_box[1][2], M2_interval[0][2], M2_interval[1][2] );

  T_scalar I_distance = F2_value( I_point );

  if( I_distance  < 0 )
   {
    return En_in;
   }

  if( 0 < I_distance )
   {
    return En_out;
   }

  return En_surface;
 }

GC_implicit::T_scalar
GC_implicit::Fv_distance( T_coord const& P_point )const
 {
  return -1;
 }

void
GC_implicit::Fv_reset( T_state &P_intersect )const
 {
  return ;
 }

GC_implicit::T_size
GC_implicit::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool GC_implicit::Fv_box( T_box const& P_box )
 {
  this->F1_box( P_box );
  return true;
 }

bool GC_implicit::F_expression( T_string const& P_expression ) 
 { 
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_compiler  T_compiler;
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_mapper    T_mapper;
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_library    T_library;

  T_mapper  I_mapper;
  T_library  I_library;

  I_mapper.F_tie( "result", 0 );
  I_mapper.F_tie( "X", 1 ); I_mapper.F_tie( "x", 1 );  M2_x = 1;
  I_mapper.F_tie( "Y", 2 ); I_mapper.F_tie( "y", 2 );  M2_y = 2;
  I_mapper.F_tie( "Z", 2 ); I_mapper.F_tie( "z", 2 );  M2_z = 3;

  T_compiler I_compiler( I_library, I_mapper );
  I_compiler.F_compile( M2_program, P_expression );

  if( false == I_compiler.F_result().F_valid() )
   {
    return bool( false );
   }

  M2_memory.F_resize( I_mapper.F_end() );

  for( auto const& I_item : I_mapper.F_container() )
   {   // to set constants
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


GC_implicit::T_scalar GC_implicit::F2_value( T_coord const& P_coord )const
 {
  M2_memory.F_set( M2_x, P_coord[0] );
  M2_memory.F_set( M2_y, P_coord[1] );
  M2_memory.F_set( M2_y, P_coord[2] );

  M2_program.F_execute();

  auto I_t = M2_memory.F_get( M2_result );

  return I_t;
}
