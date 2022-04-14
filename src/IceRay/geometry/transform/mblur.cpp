#include "mblur.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_transform;


struct GC_mblur::C_intersect
 {
  GC_mblur::T_scalar M_t;
  bool M_hit;
  bool M_1 = false; T_affine M_2local;
  bool M_2 = false; T_affine M_2world;
 };

GC_mblur::GC_mblur()
 :GC_mblur(nullptr, ::math::linear::vector::fill( T_coord{}, 0 ) )
 {
 }

GC_mblur::GC_mblur
 (
   T_geometry *P_child
  ,T_coord const& P_direction
 )
 {
  M2_direction = P_direction;

  F_child( P_child );
 }

GC_mblur::~GC_mblur()
 {
 }

void    GC_mblur::Fv_reset( T_state &P_intersect )const
 {
  C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  T_state        I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  I_head.M_t = 0;
  I_head.M_hit = false;

  M2_geometry.M2__base->Fv_reset( I_tail );
 }

GC_mblur::T_size
GC_mblur::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_geometry.M2__base->Fv_weight();

  return Ir_weigh;
 }

GC_mblur::T_size const& GC_mblur::Fv_id( T_state const&P_state )const
 {
  return M2_geometry.M2__base->Fv_id( P_state );
 }

GC_mblur::T_size const&    GC_mblur::Fv_quantity()const
 {
  static T_size Irs_quantity = 1;
  return Irs_quantity;
 }

GC_mblur::T__base*         GC_mblur::Fv_base( T_size const& P_index )const
 {
  return M2_geometry.M2__base;
 }

bool             GC_mblur::Fv_fragment( T_fragment & P_fragment, T_state const& P_state )const
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
bool GC_mblur::Fv_intersect( T_scalar &P_lambda, T_state &P_intersect, T_ray const& P_ray )const
 {
  C_intersect &I_head = P_intersect.F_content<C_intersect>();
  T_state      I_tail;  P_intersect.F_tail<C_intersect>(I_tail);

  T_ray I_ray;
  I_ray.M_direction = P_ray.M_direction;

   I_head.M_t = M2_randSobol1D.next(); // Winner
  //I_head.M_t = M2_randVDC.next();
  //I_head.M_t = M2_randStandard1D();

  ::math::linear::vector::combine( I_ray.M_origin, P_ray.M_origin, -I_head.M_t, F_direction() );

  //if( false == I_head.M_hit )
  // {
  //  M2_intersect->Fv_reset( I_tail );
  // }

  I_head.M_hit = M2_geometry.M2_intersect->Fv_intersect( P_lambda, I_tail, I_ray );

  return I_head.M_hit;
 }

void GC_mblur::Fv_normal( T_coord &P_normal, T_coord const& P_point, T_state const& P_state )const
 {
  C_intersect const& I_head = P_state.F_content<C_intersect>();
  T_state            I_tail;  P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point( P_point);
  using namespace ::math::linear::vector;
  I_point  -= I_head.M_t * F_direction();

  return M2_geometry.M2_normal->Fv_normal( P_normal, I_point, I_tail );
 }

GC_mblur::T_location GC_mblur::Fv_inside( T_coord const& P_point/*, T_state &P_state*/ )const
 {
  //C_intersect const &I_head = P_intersect.F_content<C_intersect>();
  //T_state              I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_coord I_point( P_point);

  // TODO ::math::linear::vector::combine( I_point, I_point, -I_head.M_t, M2_direction );

  return M2_geometry.M2_inside->Fv_inside( P_point/*,I_tail*/ );
 }

GC_mblur::T_scalar
GC_mblur::Fv_distance( T_coord const& P_point/*, T_state &P_state*/ )const
 {    // TODO
  T_coord I_point( P_point );
  //I_point  -= M2_re;
  return M2_geometry.M2_distance->Fv_distance( I_point );
 }

bool
GC_mblur::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const & P_state )const
 {
  C_intersect const &I_head = P_state.F_content<C_intersect>();
  T_state            I_tail ; P_state.F_tail<C_intersect>(I_tail);

  T_coord I_point( P_point);
  using namespace ::math::linear::vector;
  I_point  -= I_head.M_t * F_direction();

  return M2_geometry.M2_uvw->Fv_uvw( P_uvw,  I_point, I_tail );
 }


GC_mblur::T_affine const&  GC_mblur::Fv_2world( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();
  T_state           I_mainHit;    P_state.F_tail<C_intersect>( I_mainHit );

  return I_intersect.M_2world;
 }

GC_mblur::T_affine const&  GC_mblur::Fv_2local( T_state const&P_state )const
 {
  C_intersect const&I_intersect = P_state.F_content<C_intersect>();

  return I_intersect.M_2local;
}

bool GC_mblur::F_child( T_geometry * P_child )
 {
  M2_geometry.M2__base = ( ( nullptr == P_child ) ? &Fs_vacuum() : P_child );

  M2_geometry.M2_intersect = dynamic_cast<T2_intersect*>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_intersect) M2_geometry.M2_intersect = & Fs_vacuum();
  M2_geometry.M2_normal    = dynamic_cast<T2_normal   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_normal   ) M2_geometry.M2_normal    = & Fs_vacuum();
  M2_geometry.M2_inside    = dynamic_cast<T2_inside   *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_inside   ) M2_geometry.M2_inside    = & Fs_vacuum();
  M2_geometry.M2_distance  = dynamic_cast<T2_distance *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_distance ) M2_geometry.M2_distance  = & Fs_vacuum();
  M2_geometry.M2_uvw       = dynamic_cast<T2_uvw      *>( M2_geometry.M2__base ); if( nullptr == M2_geometry.M2_uvw      ) M2_geometry.M2_uvw       = & Fs_vacuum();

  F_direction( M2_direction );
  return true;
 }


bool GC_mblur::F_direction( T_coord const& P_direction )
 {
  auto I_boxA = M2_geometry.M2__base->F_box();

  auto I_boxB = M2_geometry.M2__base->F_box();
  ::math::linear::vector::addition( I_boxB[0], M2_direction );
  ::math::linear::vector::addition( I_boxB[1], M2_direction );

  ::math::geometry::interval::extend( I_boxA, I_boxB );

  F1_box( I_boxA );
  return true;
 }

GC_mblur::T_vacuum & GC_mblur::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }
