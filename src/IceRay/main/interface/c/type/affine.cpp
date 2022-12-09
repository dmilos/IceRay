#include "./affine.h"
#include "./affine.hpp"
#include "./coord.hpp"

#include "IceRay/type/math/affine.hpp"



GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar1D c2cpp( IceRayC_Type_Math_Affine1D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar1D Ir_result;
  for(int i=0; i< 2; ++i)
   for(int j=0; j< 1; ++j)
    Ir_result[i][j] = P_that.value[i][j];
 return Ir_result;
 }

IceRayC_Type_Math_Affine1D cpp2c( GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar1D const& P_this )
 {
  IceRayC_Type_Math_Affine1D I_that;
  for(int i=0; i< 2; ++i)
   for(int j=0; j< 1; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_affine:: GT_scalar2D c2cpp( IceRayC_Type_Math_Affine2D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar2D Ir_result;
  for(int i=0; i< 3; ++i)
   for(int j=0; j< 2; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

IceRayC_Type_Math_Affine2D cpp2c( GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar2D const& P_this )
 {
  IceRayC_Type_Math_Affine2D I_that;
  for(int i=0; i< 3; ++i)
   for(int j=0; j< 2; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_affine:: GT_scalar3D c2cpp( IceRayC_Type_Math_Affine3D  const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_this;
  for(int i=0; i< 4; ++i)
   for(int j=0; j< 3; ++j)
    I_this[i][j] = P_that.value[i][j];
  return I_this;
 }

IceRayC_Type_Math_Affine3D cpp2c( GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D const& P_this )
 {
  IceRayC_Type_Math_Affine3D I_that;
  for(int i=0; i< 4; ++i)
   for(int j=0; j< 3; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_affine:: GT_scalar4D c2cpp( IceRayC_Type_Math_Affine4D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar4D Ir_result;
  for(int i=0; i< 5; ++i)
   for(int j=0; i< 4; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

IceRayC_Type_Math_Affine4D cpp2c( GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar4D const& P_this )
 {
  IceRayC_Type_Math_Affine4D I_that;
  for(int i=0; i< 5; ++i)
   for(int j=0; j< 4; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

int   IceRayC_Type_Math_Affine3D_ID( IceRayC_Type_Math_Affine3D *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_id;
  ::math::linear::affine::id(I_id);
  *P_that = cpp2c( I_id );
  return 1;
 }

int   IceRayC_Type_Math_Affine3D_Zero( IceRayC_Type_Math_Affine3D *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_zero;
  ::math::linear::affine::zero(I_zero);
  *P_that = cpp2c( I_zero );
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_Move( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_move )
 {
  IceRayC_Type_Math_Affine3D_ID( P_that );
  P_that->value[3][0] = P_move->value[0];
  P_that->value[3][1] = P_move->value[1];
  P_that->value[3][2] = P_move->value[2];
  return 0;
 }

int    IceRayC_Type_Math_Affine3D_ScaleS( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_scale )
 {
  IceRayC_Type_Math_Affine3D_ID( P_that );
  P_that->value[0][0] = P_scale;
  P_that->value[1][1] = P_scale;
  P_that->value[2][2] = P_scale;
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_ScaleV( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D * P_scale )
 {
  IceRayC_Type_Math_Affine3D_ID( P_that );
  P_that->value[0][0] = P_scale->value[0];
  P_that->value[1][1] = P_scale->value[1];
  P_that->value[2][2] = P_scale->value[2];
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_RotateX( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::matrix::rotateX(I_result.matrix(),P_alpha);
  ::math::linear::vector::fill(I_result.vector(),0);
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_RotateY( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::matrix::rotateY( I_result.matrix(), P_alpha );
  ::math::linear::vector::fill(    I_result.vector(), 0 );
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_RotateZ( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::matrix::rotateZ( I_result.matrix(),P_alpha);
  ::math::linear::vector::fill(    I_result.vector(), 0 );
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_RotateA( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D *P_direction, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::matrix::rotate( I_result.matrix(), c2cpp(*P_direction), P_alpha );
  ::math::linear::vector::fill(    I_result.vector(), 0 );
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_RotateD( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_pivot, IceRayC_TypeCoordScalar3D* P_direction, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_rotate;    ::math::linear::vector::fill( I_rotate.vector(), 0 );
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_2center;   ::math::linear::affine::id( I_2center );
  I_2center.vector() = c2cpp( * P_pivot );  ::math::linear::vector::negate( I_2center.vector() );

  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_2back; ::math::linear::affine::id( I_2back );
  I_2back.vector() = c2cpp( * P_pivot );

  ::math::linear::matrix::rotate( I_rotate.matrix(), c2cpp(*P_direction), P_alpha );
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_tmp; 
  ::math::linear::affine::compose( I_tmp, I_rotate, I_2center );

  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_LookAt( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D * P_eye, IceRayC_TypeCoordScalar3D * P_view, IceRayC_TypeCoordScalar3D * P_up )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_2world;

  ::math::linear::affine::look_at( I_2world, c2cpp(*P_eye), c2cpp(*P_view), c2cpp( *P_up ) );

  *P_that = cpp2c( I_2world );
  return 1;
 }

int    IceRayC_Type_Math_Affine3D_Compose( IceRayC_Type_Math_Affine3D *P_that, IceRayC_Type_Math_Affine3D * P_left, IceRayC_Type_Math_Affine3D * P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::affine::compose( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_that = cpp2c( I_result );
  return 1;
 }
