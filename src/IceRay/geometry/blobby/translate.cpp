#include "./translate.hpp"
#include "./system.hpp"


using namespace GS_DDMRM::S_IceRay::S_geometry::S_blobby;


struct GC_translate::C_intersect
 {
  enum Ee_hit{ En_undefined, En_enter, En_exit, En_miss, En_2far, En_behind, En_hit };
  Ee_hit M_hit;
 };

GC_translate::GC_translate()
:GC_translate( nullptr, ::math::linear::vector::fill( T_coord{}, 0 ) )
 {
 }

GC_translate::GC_translate( T_coord const& P_move )
 :GC_translate( nullptr, P_move )
 {
 }

GC_translate::GC_translate(  T__element *P_child )
 :GC_translate( P_child, ::math::linear::vector::fill( T_coord{}, 0 ) )
 {
 }

GC_translate::GC_translate( T__element *P_child, T_coord const& P_move )
 : M2_2local( ::math::linear::vector::fill( T_coord{}, 0 ) )
 , M2_2world( ::math::linear::vector::fill( T_coord{}, 0 ) )
 , M2_child( nullptr )
 {
  M2_2world =  P_move;
  ::math::linear::vector::negate( M2_2local, P_move );

  F_child( P_child );
 }

GC_translate::~GC_translate( )
 {
 }

void GC_translate::Fv_reset( T_state &P_intersect )const
 {
  C_intersect   &I_head = P_intersect.F_content<C_intersect>();

  I_head.M_hit = C_intersect::En_undefined;

  T_state        I_tail ; P_intersect.F_tail<C_intersect>(I_tail);
  M2_child->Fv_reset( I_tail );

  return;
 }

GC_translate::T_size GC_translate::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_child->Fv_weight();

  return Ir_weigh;
 }

GC_translate::T_size const& GC_translate::Fv_id( T_state const&P_intersect )const
 {
  C_intersect   const&I_head = P_intersect.F_content<C_intersect>();
  T_state             I_tail; P_intersect.F_tail<C_intersect>(I_tail);

  return M2_child->Fv_id( I_tail );
 }

bool GC_translate::Fv_intersect
 (
   T_scalar     & P_lambda
  ,T_state      & P_intersect
  ,T_ray   const& P_ray
 )const
 {
  C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  T_state        I_tail;  P_intersect.F_tail<C_intersect>(I_tail);

  T_ray I_ray( P_ray );
  ::math::linear::vector::addition( I_ray.M_origin, M2_2local );
  return M2_child->Fv_intersect( P_lambda, I_tail, I_ray );
 }

void GC_translate::Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
  C_intersect   const&I_head = P_intersect.F_content<C_intersect>();
  T_state             I_tail ; P_intersect.F_tail<C_intersect>(I_tail);
  T_coord I_point;
  ::math::linear::vector::addition( I_point, P_point, M2_2local );

  M2_child->Fv_normal( P_normal, I_point, I_tail );
 }

GC_translate::T_location GC_translate::Fv_inside( T_coord const& P_point/*, T_intersect const&P_intersect*/ )const
 {
  //C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  //T_state        I_tail = P_intersect.F_tail<C_intersect>();

  T_coord I_point;
  ::math::linear::vector::addition( I_point, P_point, M2_2local );
  return M2_child->Fv_inside( I_point /*,P_intersect*/ );
 }

bool GC_translate::Fv_coefficient
 (
   T_coefficient::T_typedef & P_coefficient
  ,T_state             const& P_intersect
  ,T_ray               const& P_ray
 )const
 {
  C_intersect   const&I_head = P_intersect.F_content<C_intersect>();
  T_state             I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_ray I_ray =  P_ray;
  ::math::linear::vector::addition( I_ray.M_origin, M2_2local );
  return M2_child->Fv_coefficient( P_coefficient, I_tail, I_ray );
 }

GC_translate::T_scalar GC_translate::Fv_intensity( T_coord const& P_point )const
 {
  T_coord I_point;
  ::math::linear::vector::addition( I_point, P_point, M2_2local );

  return M2_child->Fv_intensity( I_point );
 }

void GC_translate::F_child( T__element *P_child )
 {
  M2_child = P_child;
  T_box I_box = M2_child->F_box();
  ::math::geometry::interval::translate( I_box, M2_2world );
  Fv_box( I_box );
 }

bool GC_translate::F_move( T_coord const& P_move )
{
  M2_2world = P_move;
  ::math::linear::vector::negate( M2_2local, P_move );
  T_box I_box = M2_child->F_box();
  ::math::geometry::interval::translate( I_box, M2_2world );
  Fv_box( I_box );
  return bool( true );
}
