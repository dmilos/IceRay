
#include "./light.h"
#include "../../type/coord.hpp"
#include "../../type/affine.hpp"

#include "IceRay/light/transform/transform.hpp"

#include "./light.hpp"



IceRayC_Light_Handle IceRayC_Light_Transform_Identity0()
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_identity Tf_identity;
  auto Ir_result = new Tf_identity{};
  return cpp2c( Ir_result );
 }
IceRayC_Light_Handle IceRayC_Light_Transform_Identity1( IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_identity Tf_identity;
  auto Ir_result = new Tf_identity{ c2cpp( P_child ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Transform_Identity_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_identity Tf_identity;

  auto I_this = dynamic_cast< Tf_identity *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  // TODO I_this->F_child( c2cpp( P_child ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Transform_Affine0()
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_affine Tf_affine;
  auto Ir_result = new Tf_affine{};
  return cpp2c( Ir_result );
}
//TODO IceRayC_Light_Handle IceRayC_Light_Transform_Affine1( IceRayC_Light_Handle P_child, IceRayC_Type_Math_Affine3D* P_affine )
//TODO  {
//TODO   typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
//TODO   typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_affine Tf_affine;
//TODO   auto Ir_result = new Tf_affine{ c2cpp( P_child ), c2cpp( *P_affine ) };
//TODO   return cpp2c( Ir_result );
//TODO  }

int IceRayC_Light_Transform_Affine_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_affine Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_child( c2cpp( P_child ) );
  return 1;
 }

int IceRayC_Light_Transform_Affine_2World( IceRayC_Light_Handle P_this, IceRayC_Type_Math_Affine3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_affine Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  //I_this->F_2world( c2cpp( *P_2world ) );
  return 1;
 }


IceRayC_Light_Handle IceRayC_Light_Transform_Translate0()
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_translate Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
}
IceRayC_Light_Handle IceRayC_Light_Transform_Translate1( IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_translate Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ) };
  return cpp2c( Ir_result );
 }
IceRayC_Light_Handle IceRayC_Light_Transform_Translate2( IceRayC_Light_Handle P_child, IceRayC_TypeCoordScalar3D* P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_translate Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ), c2cpp( *P_move ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Transform_Translate_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_translate Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_child( c2cpp( P_child ) );
  return 1;
 }
int IceRayC_Light_Transform_Translate_Move( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__base;
  typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC_translate Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_move( c2cpp( *P_move ) );
  return 1;
 }

