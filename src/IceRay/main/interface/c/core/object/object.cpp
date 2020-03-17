#include "./object.h"

#include "IceRay/object/object.hpp"

void IceRayC_Object_Release( IceRayC_Object_Handle P_this )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
}

IceRayC_Object_Handle  IceRayC_Object0()
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap Tf_wrap;

  auto Ir_result = new Tf_wrap{} ;

  return reinterpret_cast<IceRayC_Object_Handle>( dynamic_cast< Tf__pure *>( new Tf_wrap ) );
 }

IceRayC_Object_Handle  IceRayC_Object1( IceRayC_Geometry_Handle P_geometry )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap             Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__geometry;

  auto Ir_result = new Tf_wrap{ reinterpret_cast<Tf__geometry*> ( P_geometry ) } ;

  return reinterpret_cast<IceRayC_Object_Handle>( dynamic_cast< Tf__pure *>( new Tf_wrap ) );
 }

int IceRayC_Object_Geometry( IceRayC_Object_Handle P_this, IceRayC_Geometry_Handle  P_gemetry )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap             Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__geometry;

  auto I_this = dynamic_cast< Tf_wrap *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_geometry( reinterpret_cast<Tf__geometry*> ( P_gemetry ) );
  return 1;
}

int IceRayC_Object_Pigment( IceRayC_Object_Handle P_this, IceRayC_Material_PigmentHandle  P_pigment )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base     Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap               Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure Tf__pigment;

  auto I_this = dynamic_cast< Tf_wrap *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_pigment( reinterpret_cast<Tf__pigment*> ( P_pigment ) );
  return 1;
 }

int IceRayC_Object_Medium( IceRayC_Object_Handle P_this, IceRayC_Material_MediumHandle  P_medium )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base    Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap              Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure Tf__medium;

  auto I_this = dynamic_cast< Tf_wrap *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_medium( reinterpret_cast<Tf__medium*> ( P_medium ) );
  return 1;
 }

