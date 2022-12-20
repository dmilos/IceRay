#include "./affine.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_transform;


struct GC_affine::C_intersect
 {
  bool M_hit;
 };

GC_affine::GC_affine()
 {
  ::math::linear::affine::id( M2_2world    );
  ::math::linear::affine::id( M2_2local    );
  ::math::linear::matrix::id( M2_transpose );

  F_child( nullptr );
 }

GC_affine::GC_affine
 (
   T_geometry    * P_child
 )
 {
  F_child( P_child );
  F_2world( ::math::linear::affine::id( T_affine{} ) );
 }

GC_affine::GC_affine
 (
   T_geometry          * P_child
  ,T_matrix       const& P_linear
  ,T_coord        const& P_center
 )
 {
  F_child( P_child );

  M2_2world.matrix() =  P_linear;

  ::math::linear::matrix::transform( M2_2world.vector(), P_linear, P_center );
  ::math::linear::vector::negate( M2_2world.vector() );
  ::math::linear::vector::addition( M2_2world.vector(), P_center );

  F_2world( M2_2world );
 }

GC_affine::GC_affine
 (
   T_geometry    * P_child
  ,T_affine const& P_2world
 )
 {
  F_child( P_child );
  F_2world( P_2world );
 }

GC_affine::~GC_affine()
 {
  // empty
 }

void GC_affine::Fv_reset( T_state &P_intersect )const
 {
  C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  T_state        I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  I_head.M_hit = false;

  M2_geometry.M2__base->Fv_reset( I_tail );
 }

GC_affine::T_size  GC_affine::Fv_weight()const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_geometry.M2__base->Fv_weight();

  return Ir_weigh;
 }

GC_affine::T_size const& GC_affine::Fv_id( T_state const& P_intersect )const
 {
  return M2_geometry.M2__base->Fv_id( P_intersect );
 }

GC_affine::T_size const&    GC_affine::Fv_quantity()const
 {
  static T_size Irs_quantity = 1;
  return Irs_quantity;
 }

GC_affine::T__base*         GC_affine::Fv_base( T_size const& P_index )const
 {
  return M2_geometry.M2__base;
 }

bool             GC_affine::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
 {
  C_intersect const& I_head = P_state.F_content<C_intersect>();

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
bool GC_affine::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const
 {
  C_intersect &I_head = P_state.F_content<C_intersect>();
  T_state      I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_ray I_ray;

  ::math::linear::affine::transform( I_ray.M_origin, F_2local(), P_ray.M_origin );

  ::math::linear::matrix::transform( I_ray.M_direction, F_2local().matrix(), P_ray.M_direction ); // on the right side

  T_scalar I_length = ::math::linear::vector::length( I_ray.M_direction );

  I_length = T_scalar( 1 )/I_length;

  ::math::linear::vector::scale( I_ray.M_direction, I_length );

  T_scalar I_lambda = P_lambda / I_length;
  if( false == M2_geometry.M2_intersect->Fv_intersect( I_lambda, I_tail, I_ray ) )
   {
    return I_head.M_hit = false;
   }

  P_lambda = I_lambda * I_length;

  return I_head.M_hit = true;
 }

void GC_affine::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );

  T_coord I_normal;
  M2_geometry.M2_normal->Fv_normal( I_normal, I_point, P_intersect );

  ::math::linear::matrix::transform( P_normal, M2_transpose, I_normal );

  ::math::linear::vector::length( P_normal, T_scalar(1) );
 }

GC_affine::T_location GC_affine::Fv_inside( T_coord const& P_point/*, T_state const&P_intersect*/ )const
 {
  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );

  return M2_geometry.M2_inside->Fv_inside( I_point/*, P_intersect */ );
 }

GC_affine::T_scalar GC_affine::Fv_distance( T_coord const& P_point )const
 { // TODO
  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );
  auto I_scale = ::math::linear::vector::distance( I_point, P_point );
  auto I_distance = M2_geometry.M2_distance->Fv_distance( I_point );
  return    I_distance * I_scale;
 }

bool GC_affine::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const & P_intersect )const
 {
  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );
  return M2_geometry.M2_uvw->Fv_uvw( P_uvw, I_point, P_intersect );
 }

GC_affine::T_affine const&  GC_affine::Fv_2world( T_state const&P_state )const
 {
  return M2_2world;
 }

GC_affine::T_affine const&  GC_affine::Fv_2local( T_state const&P_state )const
{
  return M2_2local;
}

bool GC_affine::F_2world( T_affine const& P_2world )
 {
  M2_2world = P_2world;
  ::math::linear::affine::invert( M2_2local, M2_2world );

  ::math::linear::matrix::transpose( M2_transpose, F_2local().matrix() );

  T_interval I_box;
  ::math::geometry::interval::transform( I_box, F_2world(), M2_geometry.M2__base->F_box() );
  F1_box( I_box );
  return true;
 }

bool   GC_affine::F_2local( T_affine const& P_2local )
 {
  ::math::linear::affine::invert( M2_2world, P_2local );
  return F_2world( M2_2world );
 }

bool GC_affine::F_child( T_geometry * P_child )
 {
  M2_geometry.M2__base = ( ( nullptr == P_child ) ? &Fs_vacuum() : P_child );

  M2_geometry.M2_intersect = dynamic_cast<T2_intersect*>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_intersect) M2_geometry.M2_intersect = & Fs_vacuum();
  M2_geometry.M2_normal    = dynamic_cast<T2_normal   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_normal   ) M2_geometry.M2_normal    = & Fs_vacuum();
  M2_geometry.M2_inside    = dynamic_cast<T2_inside   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_inside   ) M2_geometry.M2_inside    = & Fs_vacuum();
  M2_geometry.M2_distance  = dynamic_cast<T2_distance *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_distance ) M2_geometry.M2_distance  = & Fs_vacuum();
  M2_geometry.M2_uvw       = dynamic_cast<T2_uvw      *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_uvw      ) M2_geometry.M2_uvw       = & Fs_vacuum();

  return F_2world( M2_2world );
 }

GC_affine::T_vacuum & GC_affine::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }

