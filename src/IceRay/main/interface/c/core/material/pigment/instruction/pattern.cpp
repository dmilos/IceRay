
#include "IceRay/material/compute/compute.hpp"

#include "../../../type/size.h"
#include "../../../type/coord.hpp"
#include "../../../type/color.hpp"

#include "../../pattern/pattern.hpp"


#include "./handle.hpp"


IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Pattern_Size0(           IceRayC_Material_Pattern_Handle P_pattern, IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_size    Tf_this;
  auto Ir_result = new Tf_this{ dynamic_cast<Tf_this::T_pattern*>( c2cpp( P_pattern ) ), P_result, P_input };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Pattern_Scalar0(         IceRayC_Material_Pattern_Handle P_pattern, IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_scalar    Tf_this;
  auto Ir_result = new Tf_this{ dynamic_cast<Tf_this::T_pattern*>( c2cpp( P_pattern ) ), P_result, P_input };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Pattern_Color0(          IceRayC_Material_Pattern_Handle P_pattern, IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_color    Tf_this;
  auto Ir_result = new Tf_this{ dynamic_cast<Tf_this::T_pattern*>( c2cpp( P_pattern ) ), P_result, P_input };
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Size2D0( IceRayC_Material_Pattern_Handle P_pattern, IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_size2D    Tf_this;
  auto Ir_result = new Tf_this{ dynamic_cast<Tf_this::T_pattern*>( c2cpp( P_pattern ) ), P_result, P_input };
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Size3D0( IceRayC_Material_Pattern_Handle P_pattern, IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_size3D    Tf_this;
  auto Ir_result = new Tf_this{ dynamic_cast<Tf_this::T_pattern*>( c2cpp( P_pattern ) ), P_result, P_input };
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Scalar2D0( IceRayC_Material_Pattern_Handle P_pattern, IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_coord2D    Tf_this;
  auto Ir_result = new Tf_this{ dynamic_cast<Tf_this::T_pattern*>( c2cpp( P_pattern ) ), P_result, P_input };
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Pattern_Coord_Scalar3D0( IceRayC_Material_Pattern_Handle P_pattern, IceRayC_TypeSize P_result, IceRayC_TypeSize P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_coord3D    Tf_this;
  auto Ir_result = new Tf_this{ dynamic_cast<Tf_this::T_pattern*>( c2cpp( P_pattern ) ), P_result, P_input };
  return cpp2c( Ir_result );
 }
