#include <algorithm>
#include "./object.hpp"

#include "./list.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_RTSS;

struct GC_object::C_intersect
 {
  int M_dummy=0x20150802;
 };


GC_object::GC_object( )
 {
  M2_rtss = &M2_list;
  M2_cdwewewews = M2_rtss->Fv_quantity();
 }

GC_object::GC_object( T_rtss *P_rtss )
 {
  this->F_rtss( M2_rtss );
 }


GC_object::~GC_object( )
 {
 }

void
GC_object::Fv_reset( T_state & P_state )const
 {
  C_intersect &I_head = P_state.F_content<C_intersect>();
  T_state     I_tail; P_state.F_tail<C_intersect>(I_tail);

  I_head.M_dummy = 0x12345678;

  M2_rtss->Fv_reset( I_tail );
 }

GC_object::T_size
GC_object::Fv_weight( )const
 {
  T_size Ir_size = 0;

  Ir_size += sizeof( C_intersect );
  Ir_size += M2_rtss->Fv_weight();

  return Ir_size;
}

GC_object::T_size const& GC_object::Fv_id( T_state const&P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state           I_tail;  P_state.F_tail<C_intersect>( I_tail );

  return M2_rtss->Fv_id( I_tail );
 }


GC_object::T_size GC_object::F_push( T__base  * P__base )
 {

  C2_geometry I_geometry;
  I_geometry.M__base = P__base;
  if( nullptr == P__base )
   {
    I_geometry.M__base = & T_rtss::Fs_vacuum();
   }

   I_geometry.M_intersect      = dynamic_cast<T2_intersect*>(I_geometry.M__base); 
    if( nullptr == I_geometry.M_intersect) I_geometry.M_intersect = & T_rtss::Fs_vacuum();

   I_geometry.M_normal         = dynamic_cast<T2_normal   *>(I_geometry.M__base); if( nullptr == I_geometry.M_normal   ) I_geometry.M_normal    = & T_rtss::Fs_vacuum();
   I_geometry.M_inside         = dynamic_cast<T2_inside   *>(I_geometry.M__base); if( nullptr == I_geometry.M_inside   ) I_geometry.M_inside    = & T_rtss::Fs_vacuum();
   I_geometry.M_distance       = dynamic_cast<T2_distance *>(I_geometry.M__base); if( nullptr == I_geometry.M_distance ) I_geometry.M_distance  = & T_rtss::Fs_vacuum();
   I_geometry.M_uvw            = dynamic_cast<T2_uvw      *>(I_geometry.M__base); if( nullptr == I_geometry.M_uvw      ) I_geometry.M_uvw       = & T_rtss::Fs_vacuum();
   I_geometry.M_cluster        = dynamic_cast<T2_cluster  *>(I_geometry.M__base); if( nullptr == I_geometry.M_cluster  ) I_geometry.M_cluster   = & T_rtss::Fs_vacuum();
   I_geometry.M_intersectSize  = I_geometry.M__base->Fv_weight();

  T_size Ir_index =  M2_rtss->Fv_push( I_geometry.M__base );
  if( T_rtss::Fs_invalid() == Ir_index )
   {
    return T_rtss::Fs_invalid();
   }

  M2_container.resize( std::max( M2_container.size(), Ir_index + 1 ) );
  M2_container[ Ir_index ] = I_geometry;
  F1_box( M2_rtss->F_box() );

  return Ir_index;
 }

void GC_object::F_erase( T__base  * P_object )
 {
  M2_rtss->Fv_erase( P_object );
  // auto I_iterator = std::find( M2_container.begin(), M2_container.end(), P_object );
  M2_cdwewewews = M2_rtss->Fv_quantity();
 }

void GC_object::F_clear()
 {
  M2_rtss->Fv_clear();
  M2_container.clear();
  M2_cdwewewews = M2_rtss->Fv_quantity();
 }


void GC_object::F_optimize()
 {
  M2_rtss->Fv_optimize();
 }

GC_object::T_size const&
GC_object::Fv_quantity( )const
 {
  return M2_cdwewewews = M2_rtss->Fv_quantity();
 }

GC_object::T__base*
GC_object::Fv_base( T_size const& P_index )const
 {
  return M2_rtss->Fv_base( P_index );
 }

bool GC_object::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state           I_tail; P_state.F_tail<C_intersect>(I_tail);

  ++P_fragment.M_depth;

  return M2_rtss->Fv_fragment( P_fragment, I_tail );
 }

bool      GC_object::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const
 {
  C_intersect &I_head = P_state.F_content<C_intersect>();
  T_state      I_tail;  P_state.F_tail<C_intersect>(I_tail);

  if( false == M2_rtss->Fv_intersect( P_lambda, I_tail, P_ray ) )
   {
    return false;
   }

  return true;
 }

void      GC_object::Fv_normal   ( T_coord &P_normal, T_coord const& P_point,  T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state           I_tail;  P_state.F_tail<C_intersect>(I_tail) ;

  T_rtss::T_fragment I_fragment;
  if( false == M2_rtss->Fv_fragment( I_fragment, I_tail ) )
   {
    return T_rtss::Fs_vacuum().Fv_normal( P_normal, P_point, P_state );
   }

  return M2_container[ I_fragment.M_index ].M_normal->Fv_normal( P_normal, P_point, I_fragment.M_state );
 }

GC_object::T_location      GC_object::Fv_inside( T_coord const& P_point/*, T_state &P_state*/ )const
 {
  T_location I_location = En_nowhere;
  T_rtss::T_list const& I_container = M2_rtss->Fv_owners( P_point );

  for( auto I_iterator = I_container.begin(); I_iterator != I_container.end(); ++I_iterator )
   {
    I_location = GC_inside::Fs_union( I_location, M2_container[*I_iterator].M_inside->Fv_inside( P_point ) );
   }
  return I_location;
 }

GC_object::T_scalar
GC_object::Fv_distance( T_coord const& P_point )const
 {
  T_scalar Ir_distance  = 1e12;
  T_scalar I_distance;
  T_rtss::T_list const& I_container = M2_rtss->Fv_owners( P_point );

  for( auto I_iterator = I_container.cbegin(); I_iterator != I_container.cend(); ++I_iterator )
   {
    if( ( I_distance = M2_container[*I_iterator].M_distance->Fv_distance( P_point ) < Ir_distance ) )
     {
      Ir_distance  = I_distance;
     }
   }
   return Ir_distance;
 }

bool      GC_object::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state             I_tail ; P_state.F_tail<C_intersect>(I_tail);

  T_rtss::T_fragment I_fragment;
  if( false == M2_rtss->Fv_fragment( I_fragment, I_tail ) )
   {
   return T_rtss::Fs_vacuum().Fv_uvw( P_uvw, P_point, P_state );
   }

  return M2_container[ I_fragment.M_index ].M_uvw->Fv_uvw( P_uvw, P_point, I_fragment.M_state );
 }

GC_object::T_rtss *
GC_object::F_rtss()
 {
  return M2_rtss;
 }

bool
GC_object::F_rtss( T_rtss *P_rtss )
 {
  M2_rtss->Fv_clear();
  M2_rtss = ( ( nullptr == P_rtss )? & M2_list: P_rtss );
  M2_rtss->Fv_clear();

  for( T_size I_index = 0; I_index < M2_rtss->Fv_quantity(); ++I_index )
   {
    T_size Ir_index =  M2_rtss->Fv_push( M2_container[I_index].M__base );
    if( T_rtss::Fs_invalid() == Ir_index )
     {
      //return false; TODO
     }
   }

  F1_box( M2_rtss->F_box() );

  return true;
 }
