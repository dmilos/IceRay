#include "./medium.h"
#include "../../../type/type.h"
#include "../../type/color.hpp"

#include "IceRay/material/medium/medium.hpp"

void IceRayC_Material_MediumRelease( IceRayC_Material_MediumHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Constant0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_constant{};
  return reinterpret_cast<IceRayC_Material_MediumHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Constant1(   IceRayC_TypeColorRGB P_value, IceRayC_TypeColorRGB P_deplete)
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_constant{ c2cpp( P_value), c2cpp(P_deplete) };
  return reinterpret_cast<IceRayC_Material_MediumHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Linear0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_linear{};
  return reinterpret_cast<IceRayC_Material_MediumHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Linear1( IceRayC_TypeColorRGB  P_value, IceRayC_TypeScalar P_c0, IceRayC_TypeScalar  P_c1 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_linear{ c2cpp( P_value ), P_c0, P_c1 };
  return reinterpret_cast<IceRayC_Material_MediumHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Quadratic0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic{};
  return reinterpret_cast<IceRayC_Material_MediumHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Quadratic1( IceRayC_TypeColorRGB P_value, IceRayC_TypeScalar P_c0, IceRayC_TypeScalar P_c1, IceRayC_TypeScalar P_c2 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic{ c2cpp( P_value ), P_c0, P_c1 , P_c2 };
  return reinterpret_cast<IceRayC_Material_MediumHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Exponential0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_exponential{};
  return reinterpret_cast<IceRayC_Material_MediumHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Exponential1( IceRayC_TypeColorRGB P_value, IceRayC_TypeScalar P_half )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_exponential{ c2cpp( P_value ), P_half };
  return reinterpret_cast<IceRayC_Material_MediumHandle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
