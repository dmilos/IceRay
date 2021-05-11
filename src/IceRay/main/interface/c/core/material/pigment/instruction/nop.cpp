#include "./nop.hpp"

#include "IceRay/material/compute/compute.hpp"

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_NOP0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_nop    Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
 }