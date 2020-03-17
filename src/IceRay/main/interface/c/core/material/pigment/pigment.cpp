#include "./pigment.h"

#include "IceRay/material/pigment/pigment.hpp"
#include "IceRay/material/compute/surface.hpp"


void IceRayC_Material_PigmentRelease( IceRayC_Material_PigmentHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Material_PigmentHandle IceRayC_Material_PigmentSurface0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface  Tf_surface;

  auto Ir_result = new Tf_surface{};
  return reinterpret_cast<IceRayC_Material_PigmentHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }



IceRayC_Material_PigmentHandle IceRayC_Material_PigmentSimple0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC_simple Tf_simple;

  auto Ir_result = new Tf_simple{};
  return reinterpret_cast<IceRayC_Material_PigmentHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

#include "./instruction.cpp"