#include "./vacuum.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_volumetric;


struct GC_vacuum::C_intersect
 {
 };

GC_vacuum::GC_vacuum()
:GC_vacuum( T_box( ::math::linear::vector::fill( T_coord{}, -1 ), ::math::linear::vector::fill( T_coord{}, 1 ) ) )
 {
 }

GC_vacuum::GC_vacuum( T_coord  const& P_lo, T_coord  const& P_hi  )
 :T_geometry( T_box( P_lo, P_hi ) )
 {
 }

GC_vacuum::GC_vacuum( T_box const& P_box )
 :T_geometry( P_box )
 {
 }

GC_vacuum::~GC_vacuum( )
 {
 }

void GC_vacuum::Fv_reset( T_state &P_intersect )const
 {
  return;
 }

GC_vacuum::T_size GC_vacuum::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );

  return Ir_weigh;
 }

bool    GC_vacuum::Fv_box( T_box const& P_box )
 {
  F1_box( P_box );
  return true;
 }

bool GC_vacuum::Fv_intersect( T_scalar &P_lambda, T_state &P_state, T_ray const& P_ray )const
 {
  return false;
 }

void GC_vacuum::Fv_normal( T_coord &P_normal, T_coord const& P_point,  T_state const& P_state )const
 {
 }

GC_vacuum::T_location GC_vacuum::Fv_inside( T_coord const& P_point/*, T_state const&P_intersect*/ )const
 {
  return En_nowhere;
 }

GC_vacuum::T_scalar  GC_vacuum::Fv_distance( T_coord const& P_point )const
 {
  static T_scalar Is_infinity = 1e+16;
  return Is_infinity;
 }
