#include "./instruction.h"

#include "IceRay/material/compute/compute.hpp"

#include "../../../../type/size.h"
#include "../../../../type/color.hpp"
#include "../../../../type/coord.hpp"
// TODO #include "../../../../utility/internal.hpp"


IceRayC_Material_Pigment_Surfcace_Instruction_Handle cpp2c( GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction * P_this )
 {
  return reinterpret_cast<IceRayC_Material_Pigment_Surfcace_Instruction_Handle>( P_this );
 }

GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction * c2cpp(  IceRayC_Material_Pigment_Surfcace_Instruction_Handle P_that )
 {
  return reinterpret_cast<GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction *>( P_that );
 }


int IceRayC_Material_Pigment_Surface_Instruction_Release( IceRayC_Material_Pigment_Surfcace_Instruction_Handle P_that )
 {
  auto I_this = c2cpp( P_that );
  delete I_this;
  return 1;
 }
