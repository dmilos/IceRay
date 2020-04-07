#include "./translate.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_transform;


struct GC_translate::C_intersect
 {
  bool M_hit;
 };




GC_translate::GC_translate()
 :GC_translate( nullptr, ::math::linear::vector::fill( T_coord{}, 0 ) )
 {
  //std::cout << __FUNCTION__ << "[" << __LINE__ << "] " << "id:" << F_id() << " vid:" << Fv_id();
 }

GC_translate::GC_translate( T_geometry *P_child )
 :GC_translate( P_child, ::math::linear::vector::fill( T_coord{}, 0 ) )
 {
  //std::cout << __FUNCTION__ << "[" << __LINE__ << "] " << "id:" << F_id() << " vid:" << Fv_id();
 }

GC_translate::GC_translate( T_coord const& P_move )
 :GC_translate( nullptr, P_move )
 {
  //std::cout << __FUNCTION__ << "[" << __LINE__ << "] " << "id:" << F_id() << " vid:" << Fv_id();
 }

GC_translate::GC_translate( T_geometry *P_child, T_coord const& P_move )
 {
  ::math::linear::vector::fill( M2_re, T_scalar( 0 ) );
  ::math::linear::vector::fill( M2_im, T_scalar( 0 ) );
  F_child( nullptr );

  F_move( P_move );
  F_child( P_child );
 }

GC_translate::~GC_translate( )
 {
 }

GC_translate::T_size const&    GC_translate::Fv_quantity()const
 {
  static T_size Irs_quantity = 1;
  return Irs_quantity;
 }

GC_translate::T__base*         GC_translate::Fv_base( T_size const& P_index )const
 {
  return M2_geometry.M2__base;
 }

bool             GC_translate::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
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

bool GC_translate::Fv_intersect( T_scalar &P_lambda, T_state &P_state , T_ray const& P_ray  )const
 {
  C_intersect &I_head = P_state.F_content<C_intersect>();
  T_state      I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T2_intersect::T_ray I_ray = P_ray;
  ::math::linear::vector::addition( I_ray.M_origin, M2_im );
  return I_head.M_hit = M2_geometry.M2_intersect->Fv_intersect( P_lambda, I_tail, I_ray );
 }

void GC_translate::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state           I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point( P_point );
   ::math::linear::vector::addition( I_point, M2_im );
   M2_geometry.M2_normal->Fv_normal( P_normal, I_point, I_tail );
 }

GC_translate::T_location GC_translate::Fv_inside( T_coord const& P_point/*, T_state &P_state*/ )const
 {
  // C_intersect const&I_head = P_state.F_content<C_intersect>();
  // T_state           I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point( P_point );
  ::math::linear::vector::addition( I_point, M2_im );
  return M2_geometry.M2_inside->Fv_inside( I_point );
 }

GC_translate::T_scalar
GC_translate::Fv_distance( T_coord const& P_point )const
 {
  T_coord I_point( P_point );
  ::math::linear::vector::addition( I_point, M2_im );
  return M2_geometry.M2_distance->Fv_distance( I_point );
 }

bool
GC_translate::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const & P_state )const
 {
  C_intersect const&I_head = P_state.F_content<C_intersect>();
  T_state           I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point( P_point );
  ::math::linear::vector::addition( I_point, M2_im );
  return M2_geometry.M2_uvw->Fv_uvw( P_uvw,  I_point, I_tail );
 }

void    GC_translate::Fv_reset( T_state &P_intersect )const
 {
  C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  T_state        I_tail;  P_intersect.F_tail<C_intersect>(I_tail);

  I_head.M_hit = false;

  M2_geometry.M2__base->Fv_reset( I_tail );
 }

GC_translate::T_size  GC_translate::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_geometry.M2__base->Fv_weight();

  return Ir_weigh;
 }

GC_translate::T_size const& GC_translate::Fv_id( T_state const&P_state )const
 {
  return M2_geometry.M2__base->Fv_id( P_state );
 }

GC_translate::T_affine const&  GC_translate::Fv_2world( T_state const&P_state )const
 {
  return this->M2_2world;
 }

GC_translate::T_affine const&  GC_translate::Fv_2local( T_state const&P_state )const
{
  return this->M2_2local;
}

GC_translate::T_coord    const& GC_translate::F_move()const
 {
  return M2_re;
 }

bool                            GC_translate::F_move( T_coord const& P_move )
 {
  M2_re = P_move; ::math::linear::vector::negate( M2_im, P_move );
  M2_2world.vector() = M2_re;
  M2_2local.vector() = M2_im;

  T_box I_box;
  ::math::geometry::interval::translate( I_box, M2_geometry.M2__base->F_box(), M2_re );
  F1_box( I_box );

  return bool( true );
 }

bool GC_translate::F_child( T_geometry *P_child )
 {
  M2_geometry.M2__base = ( ( nullptr == P_child ) ? &Fs_vacuum() : P_child );

  M2_geometry.M2_intersect = dynamic_cast<T2_intersect*>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_intersect) M2_geometry.M2_intersect = & Fs_vacuum();
  M2_geometry.M2_normal    = dynamic_cast<T2_normal   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_normal   ) M2_geometry.M2_normal    = & Fs_vacuum();
  M2_geometry.M2_inside    = dynamic_cast<T2_inside   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_inside   ) M2_geometry.M2_inside    = & Fs_vacuum();
  M2_geometry.M2_distance  = dynamic_cast<T2_distance *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_distance ) M2_geometry.M2_distance  = & Fs_vacuum();
  M2_geometry.M2_uvw       = dynamic_cast<T2_uvw      *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_uvw      ) M2_geometry.M2_uvw       = & Fs_vacuum();

  T_box I_box;
  ::math::geometry::interval::translate( I_box, M2_geometry.M2__base->F_box(), M2_re );
  F1_box( I_box );
  return true;
 }

GC_translate::T_vacuum & GC_translate::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }
