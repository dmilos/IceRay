#include "IceRay/material/compute/compute.hpp"

#include "../../../type/size.h"
#include "../../../type/color.hpp"
#include "../../../type/coord.hpp"

#include "./handle.hpp"

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Size0(    IceRayC_Type_Size     P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_size    Tf_this;
  auto Ir_result = new Tf_this{ P_value, P_result };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Scalar0(  IceRayC_Type_Scalar   P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_scalar    Tf_this;
  auto Ir_result = new Tf_this{ P_value, P_result };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Color0(   IceRayC_TypeColorRGB* P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_color    Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( *P_value ), P_result };
  return cpp2c( Ir_result );
 }

//IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Size1D(IceRayC_Type_Coord_Size1D* P_value,  IceRayC_TypeSize P_result )
// {
//  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_size1D    Tf_this;
//  auto Ir_result = new Tf_this{ P_result, c2cpp( *P_value) };
//  return cpp2c( Ir_result );
// }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Size2D0( IceRayC_Type_Coord_Size2D* P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_size2D    Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( *P_value ), P_result };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Size3D0( IceRayC_Type_Coord_Size3D* P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_size3D    Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( *P_value ), P_result };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Size4D0( IceRayC_Type_Coord_Size4D* P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_size4D    Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( *P_value ), P_result };
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Scalar2D0( IceRayC_Type_Coord_Scalar2D*   P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_coord2D    Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( *P_value ), P_result };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Scalar3D0( IceRayC_Type_Coord_Scalar3D*   P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_coord3D    Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( *P_value ), P_result };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Constant_Coord_Scalar4D0( IceRayC_Type_Coord_Scalar4D* P_value, IceRayC_TypeSize P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_coord4D   Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( *P_value ), P_result };
  return cpp2c( Ir_result );
 }
