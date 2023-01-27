
#include "./geometry.h"
#include "../../type/coord.hpp"
#include "../../type/matrix.hpp"
#include "../../type/affine.hpp"

#include "IceRay/geometry/transform/transform.hpp"

#include "./geometry.hpp"
#include "./handle.hpp"


IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Identity0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Identity1( IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Transform_Identity_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine1( IceRayC_Geometry_Handle P_child, IceRayC_Type_Math_Affine3D* P_affine )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ), c2cpp( *P_affine ) };
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine2( IceRayC_Geometry_Handle P_child, IceRayC_Type_Math_Matrix3D *P_matrix, IceRayC_TypeCoordScalar3D* P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ), c2cpp( *P_matrix ), c2cpp( *P_move ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Transform_Affine_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }

int IceRayC_Geometry_Transform_Affine_2Local_Get( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D* P_2local )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  *P_2local = cpp2c( I_this->F_2local( ) );
  return 1;
 }

int IceRayC_Geometry_Transform_Affine_2Local_Set( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D* P_2local )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_2local( c2cpp( *P_2local ) );
  return 1;
 }

int IceRayC_Geometry_Transform_Affine_2World_Get( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  *P_2world = cpp2c( I_this->F_2world( ) );
  return 1;
 }

int IceRayC_Geometry_Transform_Affine_2World_Set( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Affine3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_2world( c2cpp( *P_2world ) );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate1( IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ) };
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate2( IceRayC_Geometry_Handle P_child, IceRayC_TypeCoordScalar3D* P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ), c2cpp( *P_move ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Transform_Translate_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){ return 0; }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }

int IceRayC_Geometry_Transform_Translate_2Local_Get( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_2local )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){ return 0; }
  *P_2local = cpp2c( I_this->F_2local() );
  return 1;
 }
int IceRayC_Geometry_Transform_Translate_2Local_Set( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_2local )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){ return 0; }
  I_this->F_2local( c2cpp( *P_2local ) );
  return 1;
 }
int IceRayC_Geometry_Transform_Translate_2World_Get( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){ return 0; }
  *P_2world = cpp2c( I_this->F_2world( ) );
  return 1;
 }
int IceRayC_Geometry_Transform_Translate_2World_Set( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){return 0; }
  I_this->F_2world( c2cpp( *P_2world ) );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Homography0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_homography Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Homography1( IceRayC_Geometry_Handle P_child, IceRayC_Type_Math_Homography3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_homography Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ), c2cpp( *P_2world  ) };
  return cpp2c( Ir_result );
 }

int                     IceRayC_Geometry_Transform_Homography_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_homography Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){return 0; }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }
int                     IceRayC_Geometry_Transform_Homography_2Local_Get( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Homography3D* P_2local )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_homography Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){ return 0; }
  *P_2local =  cpp2c( I_this->F_2local() );
  return 1;
 }
int                     IceRayC_Geometry_Transform_Homography_2Local_Set( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Homography3D* P_2local )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_homography Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){ return 0; }
  I_this->F_2local( c2cpp( *P_2local ) );
  return 1;
 }
int                     IceRayC_Geometry_Transform_Homography_2World_Get( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Homography3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_homography Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){ return 0; }
  *P_2world =  cpp2c( I_this->F_2world() );
  return 1;
 }
int                     IceRayC_Geometry_Transform_Homography_2World_Set( IceRayC_Geometry_Handle P_that, IceRayC_Type_Math_Homography3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_homography Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this ){ return 0; }
  I_this->F_2world( c2cpp( *P_2world ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Transform_MotionBlur0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_mblur Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Transform_MotionBlur1( IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_mblur Tf_this;
  auto Ir_result = new Tf_this{  };
  Ir_result->F_child( c2cpp( P_child ) );
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Transform_MotionBlur2( IceRayC_Geometry_Handle P_child, IceRayC_TypeCoordScalar3D* P_direction )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_mblur Tf_this;
  auto Ir_result = new Tf_this{ c2cpp( P_child ), c2cpp( *P_direction ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Transform_MotionBlur_Child( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_mblur Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }

int IceRayC_Geometry_Transform_MotionBlur_Direction( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_direction )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_mblur Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_direction( c2cpp( *P_direction ) );
  return 1;
 }
