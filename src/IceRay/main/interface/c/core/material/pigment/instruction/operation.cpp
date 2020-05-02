#include "./operation.hpp"

#include "../../../../type/coord.hpp"
#include "../../../../type/affine.hpp"
// TODO #include "../../../../type/homography.hpp"


#include "IceRay/material/compute/operation/operation.hpp"

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Size0(     IceRayC_TypeSize P_result, IceRayC_TypeSize P_input, IceRayC_TypeSize P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_size    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Scalar0(   IceRayC_TypeSize P_result, IceRayC_TypeSize P_input, IceRayC_TypeSize P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_scalar    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Color0(    IceRayC_TypeSize P_result, IceRayC_TypeSize P_input, IceRayC_TypeSize P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_color    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Coord2D0(  IceRayC_TypeSize P_result, IceRayC_TypeSize P_input, IceRayC_TypeSize P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_coord2D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_Coord3D0(  IceRayC_TypeSize P_result, IceRayC_TypeSize P_input, IceRayC_TypeSize P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_coord3D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Ramp0(      IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_ramp    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Saw0(       IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_saw    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Wave0(      IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_wave    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Sinkhole0(  IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_sinkhole    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_Relu0(      IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_relu    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


H F(Identity0            )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_identity    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2Cylindric0 )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2cylindric    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2Package0   )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2package    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2Spherical0 )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2spherical    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2Torus0     )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2torus    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2Tablecloth0)( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2tablecloth    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2WoodX0     )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2woodX    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2WoodY0     )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2woodY    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2WoodZ0     )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2woodZ    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cylindric2Cartesian0 )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cylindric2cartesian    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 };
H F(Cylindric2Spherical0 )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cylindric2spherical    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Spherical2Cartesian0 )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_spherical2cartesian    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Spherical2Cylindric0 )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_spherical2cylindric    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Euclid2Max0          )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_euclid2max    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Max2Euclid0          )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_max2euclid    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Cartesian2Fisheye0   )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_cartesian2fisheye    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }

H F(Translate0   )( IceRayC_Type_Coord_Scalar3D * P_translate, S P_result, S P_left )
 {
  // typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_translate    Tf_this;
  // auto Ir_result = new Tf_this{ c2cpp(*P_translate), P_result, P_left };
  //return cpp2c( nullptr );
  return nullptr;
 }
H F(Affine0   )( IceRayC_Type_Math_Affine3D *P_affine,              S P_result, S P_left )
 {
  // typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_affine    Tf_this;
  // auto Ir_result = new Tf_this{ c2cpp(*P_affine), P_result, P_left };
  //return cpp2c( nullptr );
  return nullptr;
 }
// TODO H F(Homography0   )( IceRayC_Type_Math_Homography3D *P_homography,      S P_result, S P_left )
// TODO  {
// TODO   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_homography    Tf_this;
// TODO   auto Ir_result = new Tf_this{ c2cpp(*P_homography), P_result, P_left };
// TODO   //return cpp2c( nullptr );
// TODO   return nullptr;
// TODO  }


#undef H
#undef S
#undef F
#undef P
