#include "./identity.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_transform;


struct GC_identity::C_intersect
 {
  bool M_hit;
 };
 
GC_identity::T_affine  GC_identity::M2s_ID;

GC_identity::GC_identity()
 :GC_identity( nullptr )
 {
  //std::cout << __FUNCTION__ << "[" << __LINE__ << "] " << "id:" << F_id() << " vid:" << F_id();
 }

GC_identity::GC_identity( T_geometry *P_child )
 {
  // std::cout << __FUNCTION__ << "[" << __LINE__ << "] " << "id:" << F_id() << " vid:" << F_id();
  F_child( P_child );
 }

GC_identity::~GC_identity( )
 {
 }

GC_identity::T_size const&    GC_identity::Fv_quantity()const
 {
  static T_size Irs_quantity = 1;
  return Irs_quantity;
 }

GC_identity::T__base*         GC_identity::Fv_base( T_size const& P_index )const
 {
  return M2_geometry.M2__base;
 }

bool             GC_identity::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();

  if( false == I_head.M_hit )
   {
    P_fragment.M_index = 1;
    P_fragment.M__base = nullptr;
    return false;
   }

  ++P_fragment.M_depth;
  P_fragment.M_index = 0;
  P_fragment.M__base = M2_geometry.M2__base;
  P_state.F_tail<C_intersect>( P_fragment.M_state );

  return true;
 }

bool GC_identity::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray  )const
 {
  C_intersect &I_head = P_state.F_content<C_intersect>();
  T_state      I_tail;  P_state.F_tail<C_intersect>(I_tail);

  return I_head.M_hit = M2_geometry.M2_intersect->Fv_intersect( P_lambda, I_tail, P_ray );
 }

void GC_identity::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state           I_tail;  P_state.F_tail<C_intersect>(I_tail);

   M2_geometry.M2_normal->Fv_normal( P_normal, P_point, I_tail );
 }

GC_identity::T_location GC_identity::Fv_inside( T_coord const& P_point/*, T_state &P_state*/ )const
 {
  // C_intersect const&I_head = P_state.F_content<C_intersect>();
  // T_state           I_tail;  P_state.F_tail<C_intersect>(I_tail);

  return M2_geometry.M2_inside->Fv_inside( P_point );
 }

GC_identity::T_scalar
GC_identity::Fv_distance( T_coord const& P_point )const
 {
  return M2_geometry.M2_distance->Fv_distance( P_point );
 }

bool
GC_identity::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const & P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state           I_tail;  P_state.F_tail<C_intersect>(I_tail);

  return M2_geometry.M2_uvw->Fv_uvw( P_uvw,  P_point, I_tail );
 }

GC_identity::T_affine const&  GC_identity::Fv_2world( T_state const&P_state )const
 {
  return M2s_ID;
}

GC_identity::T_affine const&  GC_identity::Fv_2local( T_state const&P_state )const
{
  return M2s_ID;
}
void    GC_identity::Fv_reset( T_state &P_intersect )const
 {
  C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  T_state        I_tail;  P_intersect.F_tail<C_intersect>(I_tail);

  I_head.M_hit = false;

  M2_geometry.M2__base->Fv_reset( I_tail );
 }

GC_identity::T_size  GC_identity::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_geometry.M2__base->Fv_weight();

  return Ir_weigh;
 }

GC_identity::T_size const& GC_identity::Fv_id( T_state const&P_state )const
 {
  return M2_geometry.M2__base->Fv_id( P_state );
 }

bool GC_identity::F_child( T_geometry *P_child )
 {
  M2_geometry.M2__base = ( ( nullptr == P_child ) ? &Fs_vacuum() : P_child );

  M2_geometry.M2_intersect = dynamic_cast<T2_intersect*>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_intersect) M2_geometry.M2_intersect = & Fs_vacuum();
  M2_geometry.M2_normal    = dynamic_cast<T2_normal   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_normal   ) M2_geometry.M2_normal    = & Fs_vacuum();
  M2_geometry.M2_inside    = dynamic_cast<T2_inside   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_inside   ) M2_geometry.M2_inside    = & Fs_vacuum();
  M2_geometry.M2_distance  = dynamic_cast<T2_distance *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_distance ) M2_geometry.M2_distance  = & Fs_vacuum();
  M2_geometry.M2_uvw       = dynamic_cast<T2_uvw      *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_uvw      ) M2_geometry.M2_uvw       = & Fs_vacuum();

  F1_box( M2_geometry.M2__base->F_box() );
  return true;
 }

GC_identity::T_vacuum & GC_identity::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }
