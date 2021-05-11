#include "./medium.h"
#include "../../../type/type.h"
#include "../../../type/color.hpp"

#include "IceRay/material/medium/medium.hpp"

IceRayC_Material_MediumHandle cpp2c( GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure * P_this )
 {
  return reinterpret_cast<IceRayC_Material_MediumHandle>( P_this );
 }

GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure * c2cpp(  IceRayC_Material_MediumHandle P_that )
 {
  return reinterpret_cast<GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure *>( P_that );
 }

void IceRayC_Material_Medium_Release( IceRayC_Material_MediumHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Transparent0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_transparent{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Solid0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_solid{};
  return cpp2c( Ir_result );
 }

IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Constant0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_constant{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Constant1(   IceRayC_TypeColorRGB P_value, IceRayC_TypeColorRGB P_deplete)
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_constant{ c2cpp( P_value), c2cpp(P_deplete) };
  return cpp2c( Ir_result );
 }

int  IceRayC_Material_Medium_Constant_Value(   IceRayC_Material_MediumHandle P_that, IceRayC_TypeColorRGB* P_value   )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_constant Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_value( c2cpp( *P_value ) );
  return 1;
 }

int  IceRayC_Material_Medium_Constant_Deplete( IceRayC_Material_MediumHandle P_that, IceRayC_TypeColorRGB* P_deplete )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_constant Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_deplete( c2cpp( *P_deplete ) );
  return 1;
 }


IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Linear0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_linear{};
  return cpp2c( Ir_result );
 }


IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Linear1( IceRayC_TypeColorRGB  P_value, IceRayC_TypeScalar P_c0, IceRayC_TypeScalar  P_c1 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_linear{ c2cpp( P_value ), P_c0, P_c1 };
  return cpp2c( Ir_result );
 }

int                            IceRayC_Material_Medium_Linear_Value( IceRayC_Material_MediumHandle P_that, IceRayC_TypeColorRGB* P_value )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_linear Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_value( c2cpp( *P_value ) );
  return 1;
 }

int                            IceRayC_Material_Medium_Linear_A( IceRayC_Material_MediumHandle P_that, IceRayC_Type_Scalar P_A )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_linear Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_a( P_A );
  return 1;
 }

int                            IceRayC_Material_Medium_Linear_B( IceRayC_Material_MediumHandle P_that, IceRayC_Type_Scalar P_B )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_linear Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_b(  P_B );
  return 1;
 }


IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Quadratic0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Quadratic1( IceRayC_TypeColorRGB P_value, IceRayC_TypeScalar P_c0, IceRayC_TypeScalar P_c1, IceRayC_TypeScalar P_c2 )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic{ c2cpp( P_value ), P_c0, P_c1 , P_c2 };
  return cpp2c( Ir_result );
 }
int                            IceRayC_Material_Medium_Quadratic_Value(      IceRayC_Material_MediumHandle P_that, IceRayC_TypeColorRGB* P_value )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_value( c2cpp( *P_value ) );
  return 1;
 }

int                            IceRayC_Material_Medium_Quadratic_A(      IceRayC_Material_MediumHandle P_that, IceRayC_Type_Scalar P_A )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_a( P_A );
  return 1;
 }
int                            IceRayC_Material_Medium_Quadratic_B(      IceRayC_Material_MediumHandle P_that, IceRayC_Type_Scalar P_B )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_b( P_B );
  return 1;
 }
int                            IceRayC_Material_Medium_Quadratic_C(      IceRayC_Material_MediumHandle P_that, IceRayC_Type_Scalar P_C )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_c( P_C );
  return 1;
 }


IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Exponential0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_exponential{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_MediumHandle  IceRayC_Material_Medium_Exponential1( IceRayC_TypeColorRGB P_value, IceRayC_TypeScalar P_half )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_medium::GC_exponential{ c2cpp( P_value ), P_half };
  return cpp2c( Ir_result );
 }

int                            IceRayC_Material_Medium_Exponential_Value(   IceRayC_Material_MediumHandle P_that, IceRayC_TypeColorRGB* P_value   )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_exponential Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_value( c2cpp( *P_value ) );
  return 1;
 }

int                            IceRayC_Material_Medium_Exponential_Half(    IceRayC_Material_MediumHandle P_that, IceRayC_TypeScalar P_half )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_exponential Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_half( P_half );
  return 1;
 }
