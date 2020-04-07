#include "./object.h"
#include "../geometry/geometry.hpp"

#include "IceRay/object/object.hpp"

IceRayC_Object_Handle cpp2c( GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure * P_this )
 {
  return reinterpret_cast<IceRayC_Object_Handle>( P_this );
 }

GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure * c2cpp(  IceRayC_Object_Handle P_that )
 {
  return reinterpret_cast<GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure *>( P_that );
 }

void IceRayC_Object_Release( IceRayC_Object_Handle P_that )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure Tf__pure;
  auto I_this = c2cpp( P_that );
  delete I_this;
}

IceRayC_Object_Handle  IceRayC_Object0()
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap Tf_wrap;

  auto Ir_result = new Tf_wrap{};

  return cpp2c( Ir_result );
 }

IceRayC_Object_Handle  IceRayC_Object1( IceRayC_Geometry_Handle P_geometry )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap             Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__geometry;

  auto Ir_result = new Tf_wrap{ c2cpp( P_geometry ) } ;

  return cpp2c( Ir_result );
 }

int IceRayC_Object_GeometrySet( IceRayC_Object_Handle P_that, IceRayC_Geometry_Handle  P_gemetry )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap             Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__geometry;

  auto I_this = dynamic_cast< Tf_wrap *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_geometry( c2cpp( P_gemetry ) );
  return 1;
}

IceRayC_Geometry_Handle IceRayC_Object_GeometryGet( IceRayC_Object_Handle P_that )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap             Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__geometry;

  auto I_this = c2cpp( P_that );

  return cpp2c( &I_this->F_geometry( ) );
}

int IceRayC_Object_Pigment( IceRayC_Object_Handle P_that, IceRayC_Material_PigmentHandle  P_pigment )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap                Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure  Tf__pigment;

  auto I_this = dynamic_cast< Tf_wrap *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_pigment( reinterpret_cast<Tf__pigment*> ( P_pigment ) );
  return 1;
 }

int IceRayC_Object_Medium( IceRayC_Object_Handle P_that, IceRayC_Material_MediumHandle  P_medium )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure     Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap               Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure  Tf__medium;

  auto I_this = dynamic_cast< Tf_wrap *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_medium( reinterpret_cast<Tf__medium*> ( P_medium ) );
  return 1;
 }

