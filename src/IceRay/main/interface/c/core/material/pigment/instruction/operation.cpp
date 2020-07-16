#include "./operation.hpp"

#include "../../../../type/coord.hpp"
#include "../../../../type/affine.hpp"
#include "../../../../type/matrix.hpp"
#include "../../../../type/homography.hpp"


#include "IceRay/material/compute/operation/operation.hpp"


#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Switch_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


H F( Size0 )(     S P_result, S P_input, S P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_size    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }
H F( Scalar0 )(   S P_result, S P_input, S P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_scalar    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }
H F( Color0 )(    S P_result, S P_input, S P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_color    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }
H F( Coord2D0 )(  S P_result, S P_input, S P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_coord2D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }
H F( Coord3D0 )(  S P_result, S P_input, S P_candidate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GT_coord3D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input, P_candidate };
  return cpp2c( Ir_result );
 }

#undef F
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Clamp_##D_P

H F( Ramp0 )(      S P_result, S P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_ramp    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }
H F( Saw0 )(       S P_result, S P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_saw    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }
H F( Wave0 )(      S P_result, S P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_wave    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }
H F( Sinkhole0 )(  S P_result, S P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_sinkhole    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }
H F( Relu0 )(      S P_result, S P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_relu    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_input };
  return cpp2c( Ir_result );
 }

H F( Color_Divide0 )(      S P_result, S P_left, S P_right )
 {
  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_divides    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left, P_right };
  return cpp2c( Ir_result );
 }


#undef H
#undef S
#undef F
#undef P

#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Mapping_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


H F(Identity3D0            )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_identity3D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }

H F(Translate3D0            )(S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_translate3D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Translate3D1            )(IceRayC_Type_Coord_Scalar3D   * P_translate, S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_translate3D    Tf_this;
  auto Ir_result = new Tf_this{ Tf_this::T_operation( c2cpp(*P_translate) ), P_result, P_left };
  return cpp2c( Ir_result );
 }
int F(Translate3D_Move            )( H P_that, IceRayC_Type_Coord_Scalar3D   * P_translate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_translate3D    Tf_this;
  auto I_this= dynamic_cast<Tf_this* >( c2cpp( P_that ) );
  if( nullptr == I_this ) return 0;
  // TODO I_this->F_structure( c2cpp( * P_translate ) )
  return 0; // TODO
 }

H F(Affine3D0            )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_affine3D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Affine3D1            )(IceRayC_Type_Math_Affine3D    * P_affine, S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_affine3D    Tf_this;
  auto Ir_result = new Tf_this{ Tf_this::T_operation( c2cpp(*P_affine) ), P_result, P_left };
  return cpp2c( Ir_result );
 }
int F(Affine3D_Structure            )( H P_that, IceRayC_Type_Math_Affine3D   * P_translate )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_affine3D    Tf_this;
  auto I_this= dynamic_cast<Tf_this* >( c2cpp( P_that ) );
  if( nullptr == I_this ) return 0;
  // TODO I_this->F_structure( c2cpp( * P_translate ) )
  return 0; // TODO
 }

H F(Homography3D0        )( S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_homography3D    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left };
  return cpp2c( Ir_result );
 }
H F(Homography3D1        )(IceRayC_Type_Math_Homography3D     * P_homography, S P_result, S P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_homography3D    Tf_this;
  auto Ir_result = new Tf_this{  Tf_this::T_operation( c2cpp(*P_homography) ),  P_result, P_left };
  return cpp2c( Ir_result );
 }
int F(Homography3D_Structure            )( H P_that, IceRayC_Type_Math_Homography3D  * P_structure )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_mapping::GT_homography3D    Tf_this;
  auto I_this= dynamic_cast<Tf_this* >( c2cpp( P_that ) );
  if( nullptr == I_this ) return 0;
  // TODO I_this->F_structure( c2cpp( * P_translate ) )
  return 0; // TODO
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

#undef H
#undef S
#undef F
#undef P
