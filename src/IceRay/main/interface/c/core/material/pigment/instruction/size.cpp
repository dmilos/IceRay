#include "./operation.hpp"

#include "../../../../type/size.h"

#include "IceRay/material/compute/operation/operation.hpp"


#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_Size_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


IceRayC__EXPORT IceRayC__DECLSPEC  H F( Addition0     )( S P_result, S P_left,   S P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_size::GT_addition    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left, P_right };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Multiply0     )( S P_result, S P_left,   S P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_size::GT_multiply    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left, P_right };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Subtraction0  )( S P_result, S P_left,   S P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_size::GT_subtraction    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left, P_right };
  return cpp2c( Ir_result );
 }

IceRayC__EXPORT IceRayC__DECLSPEC  H F( Divide0  )( S P_result, S P_left,   S P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_size::GT_divide    Tf_this;
  auto Ir_result = new Tf_this{ P_result, P_left, P_right };
  return cpp2c( Ir_result );
 }

#undef H
#undef S
#undef F
#undef P
