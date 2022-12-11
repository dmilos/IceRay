#include "./transmission.hpp"

#include "IceRay/material/compute/transmission/transmission.hpp"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Transmission_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


IceRayC__EXPORT IceRayC__DECLSPEC  H F(Blossom_Grid0)(      S P_normal, S P_leader, S P_side, S P_angle, S P_gauss, S P_total, S P_start )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_grid    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_side, P_angle, P_gauss, P_total, P_start };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F(Blossom_Hexagon0)(   S P_normal, S P_leader, S P_radius, S P_angle, S P_gauss, S P_total, S P_start )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_hexagon    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_radius, P_angle, P_gauss, P_total, P_start };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F(Blossom_Pinwheel0)(  S P_normal, S P_leader, S P_radius, S P_angle, S P_gauss, S P_start )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_pinwheel    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_radius, P_angle, P_gauss, P_start };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F(Blossom_Random0)(    S P_normal, S P_leader, S P_count, S P_angle, S P_gauss, S P_start )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_random    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count, P_angle, P_gauss, P_start };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F(Blossom_Triangle0)(  S P_normal, S P_leader, S P_radius, S P_angle, S P_gauss, S P_total, S P_start )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_triangle    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_radius, P_angle, P_gauss, P_total, P_start };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F(Blossom_VDC0)(       S P_normal, S P_leader, S P_count, S P_angle, S P_gauss, S P_start )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_vdc    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count, P_angle, P_gauss, P_start };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F(Correct_Cone0)( S P_normal, S P_bump, S P_angleIn, S P_angleOut )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_correct::GC_cone    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_bump, P_angleIn, P_angleOut };
  return cpp2c( Ir_result );
 }
IceRayC__EXPORT IceRayC__DECLSPEC  H F(Correct_Claim0)( S P_normal, S P_leader, S P_count )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_correct::GC_claim    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count };
  return cpp2c( Ir_result );
 }
IceRayC__EXPORT IceRayC__DECLSPEC  H F(Correct_Leader0)( S P_normal, S P_angle, S P_leaderS, S P_leaderT )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_correct::GC_leader    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_angle, P_leaderS, P_leaderT };
  return cpp2c( Ir_result );
 }
IceRayC__EXPORT IceRayC__DECLSPEC  H F(Correct_Trim0)( S P_normal, S P_leader, S P_count )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_correct::GC_trim    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F(Jitter_Random0)(  S P_normal, S P_leader, S P_count, S P_angle )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_jitter::GC_random    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count, P_angle };
  return cpp2c( Ir_result );
 }
IceRayC__EXPORT IceRayC__DECLSPEC  H F(Jitter_VDC0)(     S P_normal, S P_leader, S P_count, S P_angle )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_jitter::GC_vdc    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count, P_angle };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Reflect_One0)( S P_point, S P_normal, S P_albedo, S P_index )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_reflect::GC_one    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_albedo, P_index };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Reflect_Schlick0)( S P_point, S P_normal, S P_ior )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_reflect::GC_schlick    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_ior };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Refract_Fresnel0)( S P_point, S P_normal, S P_ior, S P_albedo )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_fresnel    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_ior, P_albedo };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Refract_Schlick0)( S P_point, S P_normal, S P_ior, S P_albedo )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_schlick   Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_ior, P_albedo };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Refract_Snell0)(     S P_point, S P_normal, S P_ior, S P_albedo, S P_transparency  )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_snell    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_ior, P_albedo, P_transparency };
  return cpp2c( Ir_result );
 }


#undef D
#undef E
#undef H
#undef S
#undef P
#undef F
