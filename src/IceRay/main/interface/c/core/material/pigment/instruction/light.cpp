#include "./light.hpp"
#include "../../../light/light.hpp"
#include "../../../geometry/handle.hpp"

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Light_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle

H F(Generator0)( IceRayC_Light_Handle P_light, S P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_generator    Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_light ), P_result };
  return cpp2c( Ir_result );
 }

H F(SwarmA0)(                 S P_outSpot_Count, S P_inSpot_Begin, S P_inLight_Light, S P_inCoord_Point )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_swarmA    Tf_this;
  auto Ir_result = new Tf_this{ P_outSpot_Count,   P_inSpot_Begin,   P_inLight_Light,   P_inCoord_Point };
  return cpp2c( Ir_result );
 }
H F(SwarmB0)(                 S P_outSpot_Count, S P_inSpot_Begin, S P_inLight_Light, S P_inCoord_Point, S P_inCoord_Normal,  S P_inBool_Cull )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_swarmB    Tf_this;
  auto Ir_result = new Tf_this{ P_outSpot_Count,   P_inSpot_Begin,   P_inLight_Light,   P_inCoord_Point,   P_inCoord_Normal,    P_inBool_Cull };
  return cpp2c( Ir_result );
 }
H F(SwarmC0)                ( IceRayC_Light_Handle P_light, S P_outSpot_Count, S P_inSpot_Begin,                    S P_inCoord_Point, S P_inCoord_Normal )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_swarmC    Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_light ), P_outSpot_Count,   P_inSpot_Begin,                      P_inCoord_Point,   P_inCoord_Normal };
  return cpp2c( Ir_result );
 }

#undef F
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Spot_##D_P

H F(Cull0)( S P_point, S P_normal, S P_inSize_SpotBegin, S P_inSize_SpotEnd )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_spot::GC_cull    Tf_this;
  auto Ir_result = new Tf_this{ P_point, P_normal, P_inSize_SpotBegin, P_inSize_SpotEnd };
  return cpp2c( Ir_result );
 }

H F(UWV0)  ( S P_out, S P_point, S P_normal, S P_spotIndex )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_spot::GC_UVW    Tf_this;
  auto Ir_result = new Tf_this{ P_out, P_point, P_normal, P_spotIndex };
  return cpp2c( Ir_result );
 }

H F(Confine0)( IceRayC_Geometry_Handle P_geometry, S P_outSize_SpotEnd, S P_inSize_SpotBegin, S P_inSize_SpotEnd )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_spot::GC_confine    Tf_this;
  auto I_geometry = c2cpp( P_geometry );
  //auto Ir_result = new Tf_this{ I_geometry, P_outSize_SpotEnd, P_inSize_SpotBegin, P_inSize_SpotEnd };
  return nullptr; // cpp2c( Ir_result );
 }

H F(Obstruct0)  ( IceRayC_Geometry_Handle P_geometry, S P_outSize_SpotEnd, S P_inSize_SpotBegin, S P_inSize_SpotEnd )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_spot::GC_obstruct    Tf_this;
  auto I_geometry = c2cpp( P_geometry );
  auto Ir_result = new Tf_this{ c2cpp( P_geometry ), P_outSize_SpotEnd, P_inSize_SpotBegin, P_inSize_SpotEnd };
  return cpp2c( Ir_result );
 }

#undef H
#undef S
#undef F
#undef P
