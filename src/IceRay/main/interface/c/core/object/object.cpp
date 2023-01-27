#include "./object.h"

#include "../material/pigment/pigment.hpp"
#include "../material/medium/medium.hpp"
#include "../geometry/handle.hpp"


#include "IceRay/object/object.hpp"

IceRayC_Object_Handle cpp2c( GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure * P_this )
 {
  return reinterpret_cast<IceRayC_Object_Handle>( P_this );
 }

GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure * c2cpp(  IceRayC_Object_Handle P_this )
 {
  return reinterpret_cast<GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure *>( P_this );
 }

int IceRayC_Object_Release( IceRayC_Object_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
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
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure     Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap               Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   Tf__geometry;

  auto Ir_result = new Tf_wrap{ c2cpp( P_geometry ) } ;

  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle      IceRayC_Object_Cast2Geometry( IceRayC_Object_Handle P_this )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure     Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap               Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   Tf__geometry;

  auto I_this = dynamic_cast< Tf_wrap *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return cpp2c( dynamic_cast< Tf__geometry *>( I_this ) );
}

int IceRayC_Object_Geometry_Set( IceRayC_Object_Handle P_this, IceRayC_Geometry_Handle  P_gemetry )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap             Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   Tf__geometry;

  auto I_this = dynamic_cast< Tf_wrap *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_geometry( c2cpp( P_gemetry ) );
  return 1;
}

IceRayC_Geometry_Handle IceRayC_Object_Geometry_Get( IceRayC_Object_Handle P_this )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap             Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__geometry;

  auto I_this = c2cpp( P_this );

  return cpp2c( &I_this->F_geometry( ) );
}

int IceRayC_Object_Pigment( IceRayC_Object_Handle P_this, IceRayC_Material_PigmentHandle  P_pigment )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure      Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap                Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure  Tf__pigment;

  auto I_this = dynamic_cast< Tf_wrap *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_pigment( c2cpp( P_pigment ) );
  return 1;
 }

int IceRayC_Object_Medium( IceRayC_Object_Handle P_this, IceRayC_Material_MediumHandle  P_medium )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure     Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap               Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure  Tf__medium;

  auto I_this = dynamic_cast< Tf_wrap *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_medium( c2cpp( P_medium ) );
  return 1;
 }
