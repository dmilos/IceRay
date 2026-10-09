#include "./enclose.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_blobby;



struct GC_enclose::C_intersect
 {
  enum Ee_hit{ En_undefined, En_enter, En_exit, En_miss, En_2far, En_behind, En_hit };
  Ee_hit M_hit;
 };

GC_enclose::GC_enclose()
 :GC_enclose( &Fs_vacuum(), &Fs_vacuum() )
 {
 }

GC_enclose::GC_enclose
 (
   T__element    * P_child
  ,T_geometry   * P_hull
 )
 {
  M2_child =  &Fs_vacuum();
  M2_hull  =  &Fs_vacuum();
 }

GC_enclose::~GC_enclose( )
 {
 }

void GC_enclose::Fv_reset( T_state &P_intersect )const
 {
  C_intersect &I_head = P_intersect.F_content<C_intersect>();

  I_head.M_hit = C_intersect::En_undefined;

  T_state        I_tail ; P_intersect.F_tail<C_intersect>(I_tail);
  M2_child->Fv_reset( I_tail );

  return;
 }

GC_enclose::T_size GC_enclose::Fv_weight( )const
 {
  T_size Ir_weigh = 0;

  Ir_weigh += sizeof( C_intersect );
  Ir_weigh += M2_child->Fv_weight();

  return Ir_weigh;
 }

GC_enclose::T_size const& GC_enclose::Fv_id( T_state const& P_intersect )const
 {
  C_intersect  const &I_head = P_intersect.F_content<C_intersect>();
  T_state            I_tail; P_intersect.F_tail<C_intersect>(I_tail);

  return M2_child->Fv_id( I_tail );
 }

bool GC_enclose::Fv_intersect( T_scalar     & P_lambda, T_state      & P_intersect, T_ray   const& P_ray )const
 {
  C_intersect       &I_head = P_intersect.F_content<C_intersect>();
  T_state            I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_ray I_ray;

  
  return true;
 }

void GC_enclose::Fv_normal   ( T_coord &P_normal, T_coord const& P_point, T_state const& P_intersect )const
 {
  C_intersect  const &I_head = P_intersect.F_content<C_intersect>();
  T_state            I_tail ; P_intersect.F_tail<C_intersect>(I_tail);
  // TODO
 }

GC_enclose::T_location GC_enclose::Fv_inside( T_coord const& P_point/*, T_state const&P_intersect*/ )const
 {
  //C_intersect   &I_head = P_intersect.F_content<C_intersect>();
  //T_state        I_tail = P_intersect.F_tail<C_intersect>();

  // TODO

  return M2_child->Fv_inside( P_point /*,P_intersect*/ );
 }

bool GC_enclose::Fv_coefficient
 (
   T_coefficient::T_typedef & P_coefficient
  ,T_state             const& P_intersect
  ,T_ray               const& P_ray
 )const
 {
  C_intersect  const &I_head = P_intersect.F_content<C_intersect>();
  T_state             I_tail ; P_intersect.F_tail<C_intersect>(I_tail);

  T_ray I_ray = P_ray;
  return M2_child->Fv_coefficient( P_coefficient, I_tail, I_ray );
 }

GC_enclose::T_scalar GC_enclose::Fv_intensity( T_coord const& P_point )const
 {
  T_coord I_point;

  return M2_child->Fv_intensity( I_point );
 }

bool GC_enclose::F_child( T__element * P_child )
 {
  M2_child = P_child;
  // TODO
  return true;
 }

 bool GC_enclose::F_hull( T_geometry * P_hull )
 {
  M2_hull = P_hull;
  // TODO
  return true;
 }

GC_enclose::T_vacuum & GC_enclose::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }
