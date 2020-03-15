#include <cstring>
#include "./list.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_RTSS;



struct GC_list::C_intersect
 {
  GC_list::T_size M_index;
 };


GC_list::GC_list( )
 : M2_compartment( 0 )
 {

 }

GC_list::~GC_list( )
 {

 }

void    GC_list::Fv_reset( T_state & P_state )const
 {
  C_intersect &I_head = P_state.F_content<C_intersect>();
  I_head.M_index = Fs_invalid();
 }

GC_list::T_size
GC_list::Fv_weight( )const
 {
  T_size Ir_size = 0;

  Ir_size += sizeof( C_intersect );
  Ir_size += M2_compartment; // hit
  Ir_size += M2_compartment; // candidate
  Ir_size += M2_compartment; // test subject

  return Ir_size;
}

GC_list::T_size const& GC_list::Fv_id( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  if( I_intersect.M_index == Fs_invalid() )
   {
    return Fs_invalid();
   }
  T_state I_mainHit;      P_state.F_tail<C_intersect>( I_mainHit );

  return M2_collection[I_intersect.M_index].M__base->Fv_id( I_mainHit );
 }

bool      GC_list::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const
 {
  C_intersect &I_head = P_state.F_content<C_intersect>();
  T_state        I_mainHit; P_state.F_tail<C_intersect>(I_mainHit) ;
  T_state        I_state_best; I_mainHit.F_tail( I_state_best, M2_compartment ) ;
  T_state        I_state_subject; I_state_best.F_tail( I_state_subject, M2_compartment ) ;

  T_scalar I_lambda = P_lambda;
  T_size   I_winner = I_head.M_index;
  bool I_hit = false;

  for( T_size I_index =0; I_index <  M2_collection.size(); ++I_index )  // Broken loop
   {
    auto const& I_candidate = M2_collection[I_index];
    if( I_head.M_index == I_index )
     {
      if( true == I_candidate.M_intersect->Fv_intersect( I_lambda, I_mainHit, P_ray ) )
       {
        I_winner = I_index;
        std::memcpy( I_state_best.F_ptr(), I_mainHit.F_ptr(), I_candidate.M_intersectSize );
        I_hit = true;
       }
     }
    else
     {
      I_candidate.M_intersect->Fv_reset( I_state_subject );
      if( true == I_candidate.M_intersect->Fv_intersect( I_lambda, I_state_subject, P_ray ) )
       {
        I_winner = I_index;
        std::memcpy( I_state_best.F_ptr(), I_state_subject.F_ptr(), I_candidate.M_intersectSize );
        I_hit = true;
       }
     }
   }

  if( true == I_hit )
   {
    P_lambda = I_lambda;
    I_head.M_index = I_winner;
    std::memcpy( I_mainHit.F_ptr(), I_state_best.F_ptr(), M2_compartment );
   }
  else
   {
    I_head.M_index = Fs_invalid();
   }
  return I_hit;
 }

GC_list::T_size GC_list::Fv_push( T__base * P_object )
 {
  C2_geometry I_geometry;

   I_geometry.M__base = P_object;

   I_geometry.M_intersect      = dynamic_cast<T_intersect*>(I_geometry.M__base); if( nullptr == I_geometry.M_intersect) I_geometry.M_intersect = & Fs_vacuum();
   I_geometry.M_intersectSize  = I_geometry.M__base->Fv_weight();

  M2_collection.push_back( I_geometry );
  M2_index.push_back( M2_index.size() );

  M2_compartment = std::max( M2_compartment, I_geometry.M__base->Fv_weight() );

  if( 1 == M2_index.size() )
   {
    Fv_box( P_object->F_box() );
   }
  else
   {
    T_box I_box;
    ::math::geometry::interval::extend( I_box, F_box(), P_object->F_box() );
    Fv_box( I_box );
   }

  return M2_index.back();
 }

void GC_list::Fv_erase( T__base  * P_object )
 {
  //M2_collection.erase( P_object );
 }

void GC_list::Fv_clear()
 {
  M2_collection.clear();
  M2_index.clear();
 }

void   GC_list::Fv_optimize()
 {
 }

GC_list::T_list const&
GC_list::Fv_owners( T_coord const& P_point )const
 {
  return M2_index;
 }

void  GC_list::Fv_prepare( T_coord const& P_point, T_state & P_state )const
 {
  Fv_reset( P_state );
 }

GC_list::T_size const&
GC_list::Fv_quantity( )const
 {
  return M2_size = M2_collection.size();
 }

GC_list::T__base*
GC_list::Fv_base( T_size const& P_index )const
 {
  if( P_index < M2_collection.size())
   {
    return M2_collection[P_index].M__base;
   }
  return &Fs_vacuum();
 }

bool GC_list::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();

  P_fragment.M__base = nullptr;

  if( Fs_invalid() == I_head.M_index )
   {
    P_fragment.M_index = I_head.M_index;
    return false;
   }

  ++P_fragment.M_depth;
  P_fragment.M_index = I_head.M_index;
  P_fragment.M__base = M2_collection[P_fragment.M_index].M__base;
  P_state.F_tail<C_intersect>( P_fragment.M_state );

  return true;
 }
