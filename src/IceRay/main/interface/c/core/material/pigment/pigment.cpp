#include "./pigment.h"

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

void IceRayC_Material_Pigment_Release( IceRayC_Material_PigmentHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Material_PigmentHandle IceRayC_Material_Pigment_Surface0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface  Tf_surface;

  auto Ir_result = new Tf_surface{};
  return reinterpret_cast<IceRayC_Material_PigmentHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_Material_Pigment_Surface_Append( IceRayC_Material_PigmentHandle P_this, IceRayC_Material_Pigment_InstructionHandle P_instruction )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction    Tf__instruction;
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure          Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_append( reinterpret_cast<Tf__instruction*> ( P_instruction ) );
  return 1;
 }


IceRayC_Material_PigmentHandle IceRayC_Material_Pigment_Default0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC_default Tf_default;

  auto Ir_result = new Tf_default{};
  return reinterpret_cast<IceRayC_Material_PigmentHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }


#include "./instruction.cpp"