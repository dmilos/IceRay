#include <limits>
#include "./smoke.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_volumetric;



struct GC_smoke::C_intersect
 {
  bool M_hit;
 };

 namespace {

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          GTs_scalar;

  GTs_scalar GFs_randX()
   {
      return rand()/((GTs_scalar)RAND_MAX);
    }

}


GC_smoke::GC_smoke()
 :M2_precision( 0.01 )
 {
  F_hull( &Fs_vacuum() );
  F_expression( "abs(x)*abs(y)" );
 }

GC_smoke::~GC_smoke( )
 {
 }

void
GC_smoke::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_intersect = P_intersect.F_content<C_intersect>();
  I_intersect.M_hit = false;
  T_state      I_tail;  P_intersect.F_tail<C_intersect>(I_tail);

  M2_hull.M__base->Fv_reset( I_tail );
  return;
 }

GC_smoke::T_size
GC_smoke::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += F_hull().Fv_weight();

  return Ir_weigh;
 }

bool GC_smoke::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_intersect
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );

  T_scalar I_begin= P_lambda, I_end=P_lambda;

  // T_scalar I_bound[2];
  // auto count = M2_hull.M_pierce( 2, I_bound, I_intersect.F_tail<C_intersect>(), P_ray ) )
  // switch( count )
  //  {
  //   case( 0 ) :return false;
  //   case( 1 ): I_begin= I_bound[0], I_end=P_lambda;   break;
  //   case( 2 ): I_begin= I_bound[0], I_end=I_bound[1]; break;
  //   return false;
  //  }

  C_intersect &I_head  = P_intersect.F_content<C_intersect>();
  T_state      I_tail;  P_intersect.F_tail<C_intersect>(I_tail);

  bool I_hitB = M2_hull.M_intersect->Fv_intersect( I_begin, I_tail, P_ray );

  auto I_location = M2_hull.M_inside->Fv_inside( P_ray.M_origin /*, P_intersect */ );

  switch( I_location )
   {
    case( T_location::En_in  ):
     {
      I_end = I_begin;
      I_begin = 0;
     }break;
    case( T_location::En_out ):
     {
      if( false == I_hitB )
       {
        return false;
       }

      auto I_ray = P_ray;
      ::math::linear::vector::combine( I_ray.M_origin, P_ray.M_origin, I_begin, P_ray.M_direction );
      I_end -= I_begin;
      bool I_hitE = M2_hull.M_intersect->Fv_intersect( I_end, I_tail, I_ray );
      switch( I_hitE )
       {
        case( false ): I_end  = P_lambda; break;
        case( true  ): I_end += I_begin;  break;
       }
     }break;
    default: return false;
   }
  T_scalar I_bound = GFs_randX();

  T_scalar const& I_precision = M2_precision;
  T_coord I_step;  ::math::linear::vector::scale( I_step, I_precision, P_ray.M_direction );
  T_coord I_point = P_ray.M_origin; 
  T_scalar I_lambda = I_begin;
  T_scalar I_summa = 0.0;

  while( I_lambda < I_end )
   {
    T_scalar I_density = 0.5;
    {
     M2_memory.F_set( M2_x, I_point[0] );
     M2_memory.F_set( M2_y, I_point[1] );
     M2_memory.F_set( M2_z, I_point[2] );
     M2_program.F_execute();

     I_density = M2_memory.F_get( M2_result );
    }

    I_summa  += I_precision * I_density;
    I_lambda += I_precision;
    ::math::linear::vector::addition( I_point, I_step );
    if( I_bound < I_summa )
     {
      //if( not_epsilon( value ) )
      // P_lambda +=   delta
      //            * ( info->next  - exp( -summa ) )
      //            / ( exp( -summa ) - exp( -summa +delta* value ) );
      //
      // P_lambda = ????;

      P_lambda = I_lambda;
      return true;
     }
   }

  return false;
 }

void GC_smoke::Fv_normal
 (
   T_coord           & P_normal
  ,T_coord      const& P_point
  ,T_state  const& P_intersect
 )const
 {
  static T_scalar Is_epsilon = 1e-12;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  T_scalar I_len;

  while( true )
   {
    P_normal[0] = GFs_randX() - 0.5;
    P_normal[1] = GFs_randX() - 0.5;
    P_normal[2] = GFs_randX() - 0.5;
    I_len = ::math::linear::vector::length( P_normal );

    if( ( Is_epsilon < I_len ) && ( I_len < T_scalar( 1 ) ) )
     {
      ::math::linear::vector::scale( P_normal, T_scalar(1)/ I_len );
      return;
     }
   }
 }

GC_smoke::T_location GC_smoke::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  return  M2_hull.M_inside->Fv_inside( P_point /*, P_intersect */ );
 }

GC_smoke::T_scalar
GC_smoke::Fv_distance( T_coord const& P_point )const
 {
  return 0;
 }

bool   GC_smoke::F_expression( T_string const& P_expression )
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

bool   GC_smoke::F_precision( T_scalar const& P_precision )
 {
  M2_precision = P_precision;
  return bool( true );
 }

GC_smoke::T_vacuum & GC_smoke::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }

GC_smoke::T__base const& GC_smoke::F_hull( )const
 {
  return *M2_hull.M__base;
 }

bool GC_smoke::F_hull( T__base * P_hull )
 {
  auto I_old = M2_hull;
  if( nullptr == P_hull )
   {
    P_hull = &Fs_vacuum();
   }

  M2_hull.M__base     = P_hull ;
  M2_hull.M_intersect = dynamic_cast< T_intersect*>( P_hull );
  M2_hull.M_inside    = dynamic_cast< T_inside*>( P_hull );

  if( ( nullptr == M2_hull.M_intersect ) || ( nullptr == M2_hull.M_inside ) )
   {
    M2_hull = I_old;
    return false;
   }

  F1_box( F_hull().F_box() );
  return true;
 }
