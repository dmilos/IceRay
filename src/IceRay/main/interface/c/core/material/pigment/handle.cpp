#include "./pigment.h"
#include "./pigment.hpp"

#include "IceRay/material/pigment/pigment.hpp"
#include "IceRay/material/compute/surface.hpp"



IceRayC_Material_PigmentHandle cpp2c( GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure * P_this )
 {
  return reinterpret_cast<IceRayC_Material_PigmentHandle>( P_this );
 }

GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure * c2cpp(  IceRayC_Material_PigmentHandle P_that )
 {
  return reinterpret_cast<GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure *>( P_that );
 }

int IceRayC_Material_Pigment_Release( IceRayC_Material_PigmentHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }

IceRayC_Material_PigmentHandle IceRayC_Material_Pigment_Constant0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC_constant Tf_default;

  auto Ir_result = new Tf_default{};
  return cpp2c( Ir_result );
 }
