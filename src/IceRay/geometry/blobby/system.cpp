#include <algorithm>
#include "./system.hpp"
#include "../rtss/list.hpp"

#include "math/polynomial/quartic/solve.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_blobby;


struct GC_system::C_intersect
 {
  C_intersect()
   {
    M_hit = false;
    GC_system::T_coefficient::Fs_reset( M_coefficient );
   }
  bool M_hit;
  GC_system::T_coefficient::T_typedef M_coefficient;
 };


GC_system::GC_system()
 {
  M2_compartment =  0;
  M2_rtss =  nullptr;
  F_rtss( new GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_list );
 }

GC_system::~GC_system( )
 {
 }

bool GC_system::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_state
  ,T_ray   const& P_ray
 )const
 {
  static T_scalar Is_epsilon = 1e-8;// T_scalar( std::numeric_limits<T_scalar>::epsilon() );
  static T_scalar Is_epsilon_quartic      = 1e-10;
  static T_scalar Is_epsilon_lambda       = 1e-5; // 9.018249101e-06
  static T_scalar Is_epsilon_coefficient  = 1e-8;

  C_intersect &I_state_this    = P_state.F_content<C_intersect>();
  T_state      I_state_element;  P_state.F_tail<C_intersect>( I_state_element );
  T_state      I_state_rtss;     I_state_element.F_tail( I_state_rtss, M2_compartment );

  T_rtss::T_list   const& I_owners = M2_rtss->Fv_owners( P_ray.M_origin );

  I_state_this.M_hit = false;
  T_coefficient::Fs_reset( I_state_this.M_coefficient );
  I_state_this.M_coefficient[0] = -1;

  T_coefficient::T_typedef I_coefficient;
  for( auto const& I_index : I_owners )
   {
    auto & I_element = M2_element[ I_index ];
    if( T_element::En_in != I_element->Fv_inside( P_ray.M_origin ) )
     {
      continue;
     }

    I_element->Fv_reset( I_state_element );
    if( false == I_element->Fv_coefficient( I_coefficient, I_state_element, P_ray ) )
     {
      continue;
     }
    T_coefficient::Fs_accumulate( I_state_this.M_coefficient, I_coefficient );
   }

  T_scalar I_lambda = P_lambda;
  T_scalar I_rest = P_lambda;
  T_scalar I_pass = 0;
  T_scalar I_root[4];
  T_rtss::T_fragment I_fragment;
  T_ray I_ray( P_ray );
  std::array<T_scalar,5> I_monic;
  std::array<T_scalar,5> I_depressed;
  std::array<T_scalar,5> I_optimal;

  while( true == M2_rtss->Fv_intersect( I_lambda, I_state_rtss, I_ray ) )
   {
    // todo make monic and depressed
    //if( NAN == ::math::polynomial::monicing( I_monic.data(), I_state_this.M_coefficient.data(), 5 ) )
    // {
    //
    // }
    T_scalar I_shift = 0; //::math::polynomial::quartic::depressing( I_depressed.data(), I_monic.data() );

    {
      ::math::polynomial::optimize( I_optimal, I_state_this.M_coefficient, 1e-5 );
     // monic

     // depress

     // monic

    }

    int I_count = ::math::polynomial::quartic::solve::general( I_root, I_optimal.data(), Is_epsilon_coefficient );

    for( int I_index=0; I_index < I_count; ++I_index )
     {
      I_root[I_index] += I_shift;
      T_scalar I_zero = ::math::polynomial::evaluate( I_root[I_index], I_optimal );

      if( I_root[I_index] - I_pass < Is_epsilon_lambda )
       {
        continue;
       }

      if(  I_lambda < I_root[I_index] - I_pass )
       {
        continue;
       }

      I_lambda = I_root[I_index] - I_pass;
      I_state_this.M_hit = true;
     }

    if( true == I_state_this.M_hit )
     {
      P_lambda = I_pass + I_lambda;
      return true;
     }

    ::math::linear::vector::combine( I_ray.M_origin, I_ray.M_origin, I_lambda, I_ray.M_direction );
    I_rest -= I_lambda;
    I_pass += I_lambda;
    I_lambda = I_rest;

    if( true == M2_rtss->Fv_fragment( I_fragment, I_state_rtss ) )
     {
      if( true == M2_element[ I_fragment.M_index ]->Fv_coefficient( I_coefficient, I_fragment.M_state, P_ray ) )
       {
        T_coefficient::Fs_accumulate( I_state_this.M_coefficient, I_coefficient );
       }
     }
   }

  return false;
 }

void GC_system::Fv_normal
 (
   T_coord       & P_normal
  ,T_coord  const& P_point
  ,T_state  const& P_state
 )const
 {
  P_normal[0]=0;
  P_normal[1]=0;
  P_normal[2]=0;

  T_rtss::T_list const& I_owners =  M2_rtss->Fv_owners( P_point );

  T_coord I_normal;

  for( auto const& I_index : I_owners )
   {
    M2_element[ I_index ]->Fv_normal( I_normal, P_point, P_state );
    ::math::linear::vector::addition( P_normal, I_normal );
   }

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_system::T_location GC_system::Fv_inside
 (
  T_coord const& P_point
 )const
 {
  T_rtss::T_list const& I_owners =  M2_rtss->Fv_owners( P_point );

  T_scalar I_summae = 0;
  for( auto const& I_index : I_owners )
   {
    auto & I_element = M2_element[ I_index ];
    if( T_element::En_in != I_element->Fv_inside( P_point ) )
     {
      continue;
     }

    I_summae += I_element->Fv_intensity( P_point );
   }

  return ( I_summae < T_scalar(1)? En_out: En_in );
 }

void
GC_system::Fv_reset( T_state &P_state )const
 {
  C_intersect &I_intersect = P_state.F_content<C_intersect>();
  I_intersect.M_hit = false;
  T_coefficient::Fs_reset( I_intersect.M_coefficient );
  return;
 }

GC_system::T_size
GC_system::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_compartment;
  Ir_weigh += M2_rtss->Fv_weight();

  return Ir_weigh;
 }

void GC_system::F_add( T_element * P_element )
 {
  M2_compartment = std::max( M2_compartment, P_element->Fv_weight() );
  M2_element.push_back( P_element );

  M2_rtss->Fv_push( P_element );
  T_geometry::F1_box( M2_rtss->F_box() );
 }

void GC_system::F_rtss( T_rtss * P_rtss )
 {
  M2_rtss = std::shared_ptr<T_rtss>( P_rtss, [](auto p) { } );
  for( auto & I_element: M2_element )
   {
    M2_rtss->Fv_push( I_element );
   }
 }

