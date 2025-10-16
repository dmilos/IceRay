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

int   IceRayC_Type_Math_Affine_ID3D( IceRayC_Type_Math_Affine3D *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_id;
  ::math::linear::affine::id(I_id);
  *P_that = cpp2c( I_id );
  return 1;
 }

int   IceRayC_Type_Math_Affine_Zero3D( IceRayC_Type_Math_Affine3D *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_zero;
  ::math::linear::affine::zero(I_zero);
  *P_that = cpp2c( I_zero );
  return 1;
 }
#define C3D IceRayC_TypeCoordScalar3D
int IceRayC_Type_Math_Affine_Construct3D
  ( 
    IceRayC_Type_Math_Affine3D *P_result
   ,C3D *P_tO, C3D *P_tX, C3D* P_tY, C3D * P_tZ 
   ,C3D *P_sO, C3D *P_sX, C3D* P_sY, C3D * P_sZ
  )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::affine::construct( I_result
      ,{ c2cpp( *P_tO ), c2cpp( *P_tX ), c2cpp( *P_tY ), c2cpp( *P_tZ ) }
      ,{ c2cpp( *P_sO ), c2cpp( *P_sX ), c2cpp( *P_sY ), c2cpp( *P_sZ ) }
    );

  *P_result = cpp2c( I_result );
 return 1;
  }

#undef C3D

int  IceRayC_Type_Math_Affine_System3D( IceRayC_Type_Math_Affine3D *P_this, IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_X, IceRayC_TypeCoordScalar3D* P_Y, IceRayC_TypeCoordScalar3D* P_Z )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_this;
  ::math::linear::affine::system( I_this, c2cpp( *P_origin ), c2cpp( *P_X ), c2cpp( *P_Y ), c2cpp( *P_Z ) );

  *P_this = cpp2c(  I_this );
  return 1;
 }

int  IceRayC_Type_Math_Affine_SystemZ3D( IceRayC_Type_Math_Affine3D *P_this, IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_Z )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_x, I_y,I_z{ c2cpp( *P_Z )};

  switch( ::math::linear::vector::dominant( c2cpp( *P_Z ) ).first )
   {
    case( 0 ): I_y[0] = 0; I_y[1] = 0; I_y[2] = 1; break;
    case( 1 ): I_y[0] = 1; I_y[1] = 0; I_y[2] = 0; break;
    case( 2 ): I_y[0] = 0; I_y[1] = 1; I_y[2] = 0; break;
   }

  ::math::linear::vector::cross( I_x, I_y, I_z ); ::math::linear::vector::length<IceRayC_TypeScalar>( I_x, 1 );
  ::math::linear::vector::cross( I_y, I_z, I_x ); ::math::linear::vector::length<IceRayC_TypeScalar>( I_y, 1 );

  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_this;
  ::math::linear::affine::system( I_this, c2cpp( *P_origin ), I_x, I_y, I_z );

  *P_this = cpp2c( I_this );
  return 1;
 }

int    IceRayC_Type_Math_Affine_Move3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D* P_move )
 {
  IceRayC_Type_Math_Affine_ID3D( P_that );
  P_that->value[3][0] = P_move->value[0];
  P_that->value[3][1] = P_move->value[1];
  P_that->value[3][2] = P_move->value[2];
  return 0;
 }

int    IceRayC_Type_Math_Affine_ScaleS3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeScalar P_scale )
 {
  IceRayC_Type_Math_Affine_ID3D( P_that );
  P_that->value[0][0] = P_scale;
  P_that->value[1][1] = P_scale;
  P_that->value[2][2] = P_scale;
  return 1;
 }

int    IceRayC_Type_Math_Affine_ScaleV3D( IceRayC_Type_Math_Affine3D *P_that, IceRayC_TypeCoordScalar3D * P_scale )
 {
  IceRayC_Type_Math_Affine_ID3D( P_that );
  P_that->value[0][0] = P_scale->value[0];
  P_that->value[1][1] = P_scale->value[1];
  P_that->value[2][2] = P_scale->value[2];
  return 1;
 }

int    IceRayC_Type_Math_Affine_RotateX3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::matrix::rotateX(I_result.matrix(),P_alpha);
  ::math::linear::vector::fill( I_result.vector(), 0 );
  *P_result = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine_RotateY3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::matrix::rotateY( I_result.matrix(), P_alpha );
  ::math::linear::vector::fill(    I_result.vector(), 0 );
  *P_result = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine_RotateZ3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::matrix::rotateZ( I_result.matrix(),P_alpha);
  ::math::linear::vector::fill(    I_result.vector(), 0 );
  *P_result = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine_RotateA3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_TypeCoordScalar3D *P_direction, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::matrix::rotate( I_result.matrix(), c2cpp(*P_direction), P_alpha );
  ::math::linear::vector::fill(    I_result.vector(), 0 );
  *P_result = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine_RotateD3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_TypeCoordScalar3D* P_pivot, IceRayC_TypeCoordScalar3D* P_direction, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_rotate;    ::math::linear::vector::fill( I_rotate.vector(), 0 );
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_2center;   ::math::linear::affine::id( I_2center );
  I_2center.vector() = c2cpp( * P_pivot );  ::math::linear::vector::negate( I_2center.vector() );

  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_2back; ::math::linear::affine::id( I_2back );
  I_2back.vector() = c2cpp( * P_pivot );

  ::math::linear::matrix::rotate( I_rotate.matrix(), c2cpp(*P_direction), P_alpha );
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::affine::compose( I_result, I_rotate, I_2center );

  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Affine_Invert3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_Type_Math_Affine3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  if( false ==::math::linear::affine::invert( I_result, c2cpp( *P_right ) ) )
   {
    return 0;
   }
  *P_result = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Affine_LookAt3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_TypeCoordScalar3D * P_eye, IceRayC_TypeCoordScalar3D * P_view, IceRayC_TypeCoordScalar3D * P_up )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_2world;

  ::math::linear::affine::look_at( I_2world, c2cpp(*P_eye), c2cpp(*P_view), c2cpp( *P_up ) );

  *P_result = cpp2c( I_2world );
  return 1;
 }

int    IceRayC_Type_Math_Affine_Compose3D( IceRayC_Type_Math_Affine3D *P_result, IceRayC_Type_Math_Affine3D * P_left, IceRayC_Type_Math_Affine3D * P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D I_result;
  ::math::linear::affine::compose( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Affine_Transform3D( IceRayC_TypeCoordScalar3D *P_result, IceRayC_Type_Math_Affine3D* P_affine, IceRayC_TypeCoordScalar3D* P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_result;
  ::math::linear::affine::transform( I_result, c2cpp(*P_affine), c2cpp(*P_point) );
  *P_result = cpp2c( I_result );
  return 1;
 }
