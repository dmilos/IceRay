#include "./object.h"

#include "IceRay/object/object.hpp"

void IceRayC_Object_Release( IceRayC_ObjectHandle P_this )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
}

IceRayC_ObjectHandle  IceRayC_Object0()
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap Tf_wrap;

  auto Ir_result = new Tf_wrap{} ;

  return reinterpret_cast<IceRayC_ObjectHandle>( dynamic_cast< Tf__pure *>( new Tf_wrap ) );
 }

IceRayC_ObjectHandle  IceRayC_Object1( IceRayC_GeometryHandle P_geometry )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;

  auto Ir_result = new Tf_wrap{ /* TODO reinterpret_cast<Tf__base>( P_geometry )*/ } ;

  return reinterpret_cast<IceRayC_ObjectHandle>( dynamic_cast< Tf__pure *>( new Tf_wrap ) );
 }

int IceRayC_Object_Pigment(  IceRayC_ObjectHandle P_this, IceRayC_Material_PigmentHandle  P_pigment )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap Tf_wrap;
//typedef GS_DDMRM::S_IceRay::TODO Tf__pigment;

  auto I_this = dynamic_cast< Tf_wrap *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
  {
    return 1;
  }
  // TODO P_this->F_pigment( reinterpret_cast<Tf__pigment*> ( P_this ) );
  return 0;
 }

int IceRayC_Object_Medium(   IceRayC_ObjectHandle P_this, IceRayC_Material_MediumHandle   P_medium  )
 {
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap Tf_wrap;
  //typedef GS_DDMRM::S_IceRay::TODO Tf__medium;

  auto I_this = dynamic_cast< Tf_wrap *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
  {
    return 1;
  }
  //I_this->F_medium( reinterpret_cast<Tf__medium*> ( P_medium ) );
  return 0;
 }

int IceRayC_Object_Geometry( IceRayC_ObjectHandle P_this, IceRayC_GeometryHandle  P_gemetry )
{
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_object::GC_wrap            Tf_wrap;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__geometry;

  auto I_this = dynamic_cast< Tf_wrap *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_geometry( reinterpret_cast<Tf__geometry*> ( P_this ) );
  return 0;
}
