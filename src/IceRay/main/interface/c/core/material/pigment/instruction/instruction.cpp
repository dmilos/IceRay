#include "./instruction.hpp"

#include "IceRay/material/compute/compute.hpp"

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_NOP0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_nop    Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
 }

#include "./constant.cpp"
#include "./handle.cpp"
#include "./light.cpp"
#include "./pattern.cpp"
#include "./operation.cpp"
#include "./illumination.cpp"
#include "./transmission.cpp"
#include "./convert.cpp"



/*

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Geometry_Cluster( TODO )
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Geometry_Distance( TODO )
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Geometry_Intersect( )
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Geometry_Normal( )
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Geometry_Uvw( )


IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Pattern_Uvw( )

IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Processor( )
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Program( )
IceRayC_Material_Pigment_Surfcace_Instruction_Handle IceRayC_Material_Pigment_Surface_Instruction_Surface( )

*/