
#include "./affine.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_blobby;



struct GC_affine::C_intersect
 {
  enum Ee_hit{ En_undefined, En_enter, En_exit, En_miss, En_2far, En_behind, En_hit };
  Ee_hit M_hit;
 };

GC_affine::GC_affine()
 :GC_affine( &Fs_vacuum(), ::math::linear::affine::id<T_scalar,3>( ) )
 {
 }

GC_affine::GC_affine( T__element *P_child )
 :GC_affine( P_child, ::math::linear::affine::id<T_scalar,3>() )
 {
 }

GC_affine::GC_affine
 (
   T__element    * P_child
  ,T_affine const& P_2world
 )
 {
  M2_child =  &Fs_vacuum();
  M2_2world = ::math::linear::affine::id<T_scalar,3>( );
  M2_2local = ::math::linear::affine::id<T_scalar,3>( );
  F_child( P_child );
  F_2world( P_2world );
 }

GC_affine::GC_affine
 (
   T__element          * P_child
  ,T_matrix       const& P_linear
  ,T_coord        const& P_center
 )
 {
  M2_child =  &Fs_vacuum();
  M2_2world = ::math::linear::affine::id<T_scalar,3>();
  M2_2local = ::math::linear::affine::id<T_scalar,3>();

  F_child( P_child );

  M2_2world.matrix() =  P_linear;

  ::math::linear::matrix::transform( M2_2world.vector(), P_linear, P_center );
  ::math::linear::vector::negate( M2_2world.vector() );
  ::math::linear::vector::addition( M2_2world.vector(), P_center );

  F_2world( M2_2world );
 }

GC_affine::~GC_affine( )
 {
 }

void GC_affine::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_head = P_intersect.F_content<C_intersect>();

  I_head.M_hit = C_intersect::En_undefined;

  T_state        I_tail ; P_intersect.F_tail<C_intersect>(I_tail);
  M2_child->Fv_reset( I_tail );

  return;
 }

GC_affine::T_size GC_affine::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_child->Fv_weight();

  return Ir_weigh;
 }

GC_affine::T_size const& GC_affine::Fv_id( T_state const& P_intersect )const
 {
  C_intersect  const &I_head = P_intersect.F_content<C_intersect>();
  T_state            I_tail; P_intersect.F_tail<C_intersect>(I_tail);

  return M2_child->Fv_id( I_tail );
 }

bool GC_affine::Fv_intersect( T_scalar     & P_lambda, T_state      & P_intersect, T_ray   const& P_ray )const
 {
  C_intersect       &I_head = P_intersect.F_content<C_intersect>();
  T_state            I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_ray I_ray;

  ::math::linear::affine::transform( I_ray.M_origin,    F_2local(),          P_ray.M_origin );

  ::math::linear::matrix::transform( I_ray.M_direction, F_2local().matrix(), P_ray.M_direction ); // on the right side

  T_scalar I_length = ::math::linear::vector::length( I_ray.M_direction );

  I_length = T_scalar( 1 )/I_length;

  ::math::linear::vector::scale( I_ray.M_direction, I_length );

  T_scalar I_lambda = P_lambda / I_length;
  if( false == M2_child->Fv_intersect( I_lambda, I_tail, I_ray ) )
   {
    I_head.M_hit = C_intersect::En_miss;
    return false;
   }

  I_head.M_hit = C_intersect::En_hit;
  P_lambda = I_lambda * I_length;

  return true;
 }

void GC_affine::Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
  C_intersect  const &I_head = P_intersect.F_content<C_intersect>();
  T_state            I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );

  T_coord I_normal;
  M2_child->Fv_normal( I_normal, I_point, I_tail );

  ::math::linear::matrix::transform( P_normal, M2_transpose, I_normal );
 }

GC_affine::T_location GC_affine::Fv_inside( T_coord const& P_point/*, T_state const&P_intersect*/ )const
 {
  //C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  //T_state        I_tail = P_intersect.F_tail<C_intersect>();

  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );

  return M2_child->Fv_inside( I_point /*,P_intersect*/ );
 }

bool GC_affine::Fv_coefficient
 (
   T_coefficient::T_typedef & P_coefficient
  ,T_state             const& P_intersect
  ,T_ray               const& P_ray
 )const
 {
  C_intersect  const &I_head = P_intersect.F_content<C_intersect>();
  T_state             I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_ray I_ray = P_ray;
  ::math::linear::affine::transform( I_ray.M_origin,    F_2local(),          P_ray.M_origin    );
  ::math::linear::matrix::transform( I_ray.M_direction, F_2local().matrix(), P_ray.M_direction );

  // Bad Idea: ::math::linear::vector::length( I_ray.M_direction, T_scalar(1) );

  return M2_child->Fv_coefficient( P_coefficient, I_tail, I_ray );
 }

GC_affine::T_scalar GC_affine::Fv_intensity( T_coord const& P_point )const
 {
  T_coord I_point;
  ::math::linear::affine::transform( I_point, F_2local(), P_point );

  return M2_child->Fv_intensity( I_point );
 }

bool               GC_affine::F_2world( T_affine const& P_2world )
 {
  M2_2world = P_2world;
  ::math::linear::affine::invert( M2_2local, M2_2world );

  T_interval I_box;
  ::math::geometry::interval::transform( I_box, F_2world(), M2_child->F_box() );

  ::math::linear::matrix::transpose( M2_transpose, F_2local().matrix() );

  F1_box( I_box );
  return true;
 }

bool              GC_affine:: F_2local( T_affine const& P_2local )
 {
  ::math::linear::affine::invert( M2_2world, P_2local );
  return F_2world( M2_2world );
 }

bool GC_affine::F_child( T__element * P_child )
 {
  M2_child = P_child;

  F_2world( M2_2world );
  return true;
 }

GC_affine::T_vacuum & GC_affine::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }

