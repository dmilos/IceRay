#include "./implicit.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;



struct GC_implicit::C_intersect
 {
  bool M_hit;
 };


GC_implicit::GC_implicit()
 {
  T_coord I_lo, I_hi;

  math::linear::vector::load( I_lo, -1, -1, -1 );
  math::linear::vector::load( I_hi, +1, +1, +1 );

  F1_box(     T_box{ I_lo, I_hi } );

  F_interval( T_box{ I_lo, I_hi } );
  M2_delta     =  1.0 / 100000.0;
  M2_sampling  =  1.0 / 100.0;
  M2_iteration = 24;
 }

GC_implicit::~GC_implicit( )
 {
 }

bool GC_implicit::Fv_intersect( T_scalar     & P_lambda, T_state      & P_state, T_ray   const& P_ray  )const
 {
  static const T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  C_intersect& I_head = P_state.F_content<C_intersect>();
  T_state      I_tail;  P_state.F_tail<C_intersect>( I_tail );

  T_coord const& I_origin    = P_ray.M_origin;
  T_coord const& I_direction = P_ray.M_direction;

  auto const& I_box = F_box();

  std::tuple<unsigned, T_scalar, unsigned, T_scalar > I_line;

  if( false == ::math::geometry::interval::intersect( I_line, I_box, { I_origin, I_direction }, Is_epsilon ) )
   {
    return I_head.M_hit = false;
   }

  T_scalar I_begin = std::get<1>( I_line );
  if( P_lambda < I_begin )
   {
    return I_head.M_hit = false;
   }
  T_scalar I_end = std::get<3>( I_line );
  if( I_end < Is_epsilon )
   {
    return I_head.M_hit = false;
   }

  if( I_begin < Is_epsilon )
   {
    I_begin = M2_sampling;
   }

  if( P_lambda < I_end )
   {
    I_end = P_lambda + M2_sampling; // M2_sampling * ( (int)(P_lambda/ M2_sampling ) ) + M2_sampling;
   }

  T_coord I_point;  //!< local  coordinate
  ::math::linear::vector::combine( I_point, I_origin, I_begin, I_direction );

  I_point = ::math::geometry::interval::remap( I_point, I_box, M2_interval );

  T_coord I_step;  //!< local  coordinate
  I_step[0] = I_direction[0] * ( M2_interval[1][0] - M2_interval[0][0] ) / ( I_box[1][0] - I_box[0][0] );
  I_step[1] = I_direction[1] * ( M2_interval[1][1] - M2_interval[0][1] ) / ( I_box[1][1] - I_box[0][1] );
  I_step[2] = I_direction[2] * ( M2_interval[1][2] - M2_interval[0][2] ) / ( I_box[1][2] - I_box[0][2] );

  ::math::linear::vector::scale( I_step, M2_sampling );

  auto I_0 = F2_value( I_point ); 

  for( T_scalar I_lambda = I_begin; I_lambda < I_end; /* empty */)
   {
    I_lambda += M2_sampling;
    math::linear::vector::addition( I_point, I_step );
    auto I_1 = F2_value( I_point );
    if( math::function::signum( I_0 ) == math::function::signum( I_1 ) )
     {
      I_1 = I_0; //!< No need. Just debug.
      continue;
     }

    T_scalar I_sampling = 0.5*M2_sampling;

    math::linear::vector::scale( I_step, 0.5 );

    math::linear::vector::subtraction( I_point, I_step );
    I_lambda -= I_sampling;

    for( T_size I_iteration=0; I_iteration < M2_iteration; ++I_iteration )
     {
      auto I_m = F2_value( I_point );
      math::linear::vector::scale<T_scalar>( I_step, 0.5 );
      I_sampling *= 0.5;

      if( math::function::signum( I_0 ) == math::function::signum( I_m ) )
       {
        I_0 = I_m;
        math::linear::vector::addition( I_point, I_step );
        I_lambda += I_sampling;
        continue;
       }
      if( math::function::signum( I_m ) == math::function::signum( I_1 ) )
       {
        I_1 = I_m;
        math::linear::vector::subtraction( I_point, I_step );
        I_lambda -= I_sampling;
        continue;
       }
       break; //!< point of no reach
     }

    //if( P_lambda < I_lambda )
    // {
    //  return I_head.M_hit = false;
    // }
    ::math::linear::vector::combine( I_point, I_origin, I_lambda, I_direction );
    if( false == ::math::geometry::interval::in( I_box, I_point ) )
     {
      return I_head.M_hit = false;
     }

    P_lambda = I_lambda;
    return I_head.M_hit = true;
   }

  return I_head.M_hit = false;
 }

void GC_implicit::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state  const& P_intersect
 )const
 {
  static const T_scalar Is_epsilon = 1e-6;
  T_coord I_point;
  auto const& I_box = F_box();
  
  I_point = ::math::geometry::interval::remap( P_point, I_box, M2_interval );

  auto I_0 = F2_value( I_point );
  I_point[0] += M2_delta; P_normal[0] = F2_value( I_point )-I_0;  I_point[0] -= M2_delta;
  I_point[1] += M2_delta; P_normal[1] = F2_value( I_point )-I_0;  I_point[1] -= M2_delta;
  I_point[2] += M2_delta; P_normal[2] = F2_value( I_point )-I_0;  //I_point[2] -= M2_delta;

  auto I_length = math::linear::vector::length( P_normal );
  if( true == std::isnan( I_length ) )
   {
    math::linear::vector::load( P_normal, 0, 0, 1 );
    return;
   }
  if( I_length < Is_epsilon )
   {
    math::linear::vector::load( P_normal, 0, 0, 1 );
    return;
   }

  math::linear::vector::scale( P_normal, 1 / I_length  );
 }

GC_implicit::T_location  GC_implicit::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  static T_scalar Is_Epsilon = 1e-9;
  T_coord I_point;
  I_point = ::math::geometry::interval::remap( P_point, F_box(), M2_interval );

  T_scalar I_distance = F2_value( I_point );

  if( I_distance < -Is_Epsilon)
   {
    return En_in;
   }

  if( Is_Epsilon < I_distance )
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
  typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_library   T_library;

  T_mapper  I_mapper;
  T_library  I_library;

  I_mapper.F_tie( "result", 0 );
  I_mapper.F_tie( "X", 1 ); I_mapper.F_tie( "x", 1 );  M2_x = 1;
  I_mapper.F_tie( "Y", 2 ); I_mapper.F_tie( "y", 2 );  M2_y = 2;
  I_mapper.F_tie( "Z", 3 ); I_mapper.F_tie( "z", 3 );  M2_z = 3;

  T_compiler I_compiler( I_library, I_mapper );
  I_compiler.F_compile( M2_program, P_expression );

  if( false == I_compiler.F_result().F_valid() )
   {
    return bool( false );
   }

  M2_memory.F_apply( I_mapper );
  M2_program.F_memory( M2_memory );
  M2_result = I_compiler.F_result().M_position;
  M2_expression = P_expression;

  //M2_program.F_execute();
  //M2_memory.F_get( M2_result );
  return bool( true );

 }


GC_implicit::T_scalar GC_implicit::F2_value( T_coord const& P_coord )const
 {
  M2_memory.F_set( M2_x, P_coord[0] );
  M2_memory.F_set( M2_y, P_coord[1] );
  M2_memory.F_set( M2_z, P_coord[2] );

  M2_program.F_execute();

  auto I_result = M2_memory.F_get( M2_result );

  if( true == std::isnan( I_result ) )
   {
    return 0;
   }

  return I_result;
}
