#include "./setup.hpp"

#include "IceRay/material/compute/setup/setup.hpp"


#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Setup_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


H F( ToViewer0      )( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_setup::GC_2viewer   Tf_this;
  auto Ir_result = new Tf_this{  };
  return cpp2c( Ir_result );
 }
H F( PlaneIncident0 )( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_setup::GC_PlaneIncident   Tf_this;
  auto Ir_result = new Tf_this{  };
  return cpp2c( Ir_result );
 }
H F( PlaneSurface0  )( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_setup::GC_PlaneSurface   Tf_this;
  auto Ir_result = new Tf_this{  };
  return cpp2c( Ir_result );
 }
H F( PlaneReflect0  )( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_setup::GC_PlaneReflect   Tf_this;
  auto Ir_result = new Tf_this{  };
  return cpp2c( Ir_result );
 }
H F( Reflect0       )( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_setup::GC_reflect   Tf_this;
  auto Ir_result = new Tf_this{  };
  return cpp2c( Ir_result );
 }


#undef H
#undef S
#undef F
#undef P
