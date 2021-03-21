#include "./transmission.hpp"

#include "IceRay/material/compute/transmission/transmission.hpp"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Transmission_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Grid0)(    S P_normal, S P_leader, S P_count, S P_angle, S P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_grid    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count, P_angle, P_gauss };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Hexagon0)( S P_normal, S P_leader, S P_count, S P_angle, S P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_hexagon    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count, P_angle, P_gauss };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_Random0)(  S P_normal, S P_leader, S P_count, S P_angle, S P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_random    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count, P_angle, P_gauss };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Blossom_VDC0)(     S P_normal, S P_leader, S P_count, S P_angle, S P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_vdc    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_leader, P_count, P_angle, P_gauss };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Jitter_Random0)(     S P_normal, S P_begin, S P_end, S P_angle )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_jitter::GC_random    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_begin, P_end, P_angle };
  return cpp2c( Ir_result );
 }
IceRayC__EXPORT IceRayC__DECLSPEC  H F( Jitter_VDC0)(     S P_normal, S P_begin, S P_end, S P_angle )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_jitter::GC_vdc    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_begin, P_end, P_angle };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Corrector0)( S P_normal, S P_bump, S P_begin, S P_end )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::GC_corrector    Tf_this;
  auto Ir_result = new Tf_this{ P_normal, P_bump, P_begin, P_end };
  return cpp2c( Ir_result );
 }


IceRayC__EXPORT IceRayC__DECLSPEC  H F( Reflect_One0)( S P_point, S P_normal, S P_albedo )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_reflect::GC_one    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_albedo };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Reflect_Schlick0)( S P_point, S P_normal, S P_ior )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_reflect::GC_schlick    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_ior };
  return cpp2c( Ir_result );
 }


IceRayC__EXPORT IceRayC__DECLSPEC  H F( Refract_Snell0)(     S P_point, S P_normal, S P_ior, S P_attenuation  )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_snell    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_ior, P_attenuation };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Refract_Arbitrary0)( S P_point, S P_normal, S P_ior, S P_albedo, S P_attenuation )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_arbitrary    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_ior, P_albedo, P_attenuation };
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

#undef D
#undef E
#undef H
#undef S
#undef P
#undef F
