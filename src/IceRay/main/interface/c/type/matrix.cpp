#include "./matrix.h"
#include "./matrix.hpp"
#include "./coord.hpp"

#include "IceRay/type/math/matrix.hpp"



GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D c2cpp( IceRayC_Type_Math_Matrix1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D Ir_result;
  for(int i=0; i< 1; ++i)
   for(int j=0; j< 1; ++j)
    Ir_result[i][j] = P_that.value[i][j];
 return Ir_result;
 }

IceRayC_Type_Math_Matrix1D cpp2c( GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D const& P_this )
 {
  IceRayC_Type_Math_Matrix1D I_that;
  for(int i=0; i< 1; ++i)
   for(int j=0; j< 1; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_matrix:: GT_scalar2D c2cpp( IceRayC_Type_Math_Matrix2D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D Ir_result;
  for(int i=0; i< 2; ++i)
   for(int j=0; j< 2; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

IceRayC_Type_Math_Matrix2D cpp2c( GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D const& P_this )
 {
  IceRayC_Type_Math_Matrix2D I_that;
  for(int i=0; i< 2; ++i)
   for(int j=0; j< 2; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_matrix:: GT_scalar3D c2cpp( IceRayC_Type_Math_Matrix3D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_this;
  for(int i=0; i< 3; ++i)
   for(int j=0; j< 3; ++j)
    I_this[i][j] = P_that.value[i][j];
  return I_this;
 }

IceRayC_Type_Math_Matrix3D cpp2c( GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D const& P_this )
 {
  IceRayC_Type_Math_Matrix3D I_that;
  for(int i=0; i< 3; ++i)
   for(int j=0; j< 3; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_matrix:: GT_scalar4D c2cpp( IceRayC_Type_Math_Matrix4D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D Ir_result;
  for(int i=0; i< 4; ++i)
   for(int j=0; j< 4; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

IceRayC_Type_Math_Matrix4D cpp2c( GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D const& P_this )
 {
  IceRayC_Type_Math_Matrix4D I_that;
  for(int i=0; i< 4; ++i)
   for(int j=0; j< 4; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

int   IceRayC_Type_Math_Matrix1D_ID( IceRayC_Type_Math_Matrix1D *P_this )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D I_id;
  ::math::linear::matrix::id(I_id);
  *P_this = cpp2c( I_id );
  return 1;
 }

int   IceRayC_Type_Math_Matrix2D_ID( IceRayC_Type_Math_Matrix2D *P_this )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_id;
  ::math::linear::matrix::id(I_id);
  *P_this = cpp2c( I_id );
  return 1;
 }

int   IceRayC_Type_Math_Matrix3D_ID( IceRayC_Type_Math_Matrix3D *P_this )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_id;
  ::math::linear::matrix::id(I_id);
  *P_this = cpp2c( I_id );
  return 1;
 }

int   IceRayC_Type_Math_Matrix4D_ID( IceRayC_Type_Math_Matrix4D *P_this )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_id;
  ::math::linear::matrix::id(I_id);
  *P_this = cpp2c( I_id );
  return 1;
 }

int   IceRayC_Type_Math_Matrix1D_Zero( IceRayC_Type_Math_Matrix1D *P_this )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D I_zero;
  ::math::linear::matrix::zero(I_zero);
  *P_this = cpp2c( I_zero );
  return 1;
 }

int   IceRayC_Type_Math_Matrix2D_Zero( IceRayC_Type_Math_Matrix2D *P_this )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_zero;
  ::math::linear::matrix::zero(I_zero);
  *P_this = cpp2c( I_zero );
  return 1;
 }

int   IceRayC_Type_Math_Matrix3D_Zero( IceRayC_Type_Math_Matrix3D *P_this )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_zero;
  ::math::linear::matrix::zero(I_zero);
  *P_this = cpp2c( I_zero );
  return 1;
 }

int   IceRayC_Type_Math_Matrix4D_Zero( IceRayC_Type_Math_Matrix4D *P_this )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_zero;
  ::math::linear::matrix::zero(I_zero);
  *P_this = cpp2c( I_zero );
  return 1;
 }

int    IceRayC_Type_Math_Matrix3D_ScaleS( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_scale )
 {
  IceRayC_Type_Math_Matrix3D_ID( P_that );
  P_that->value[3][0] = P_scale;
  P_that->value[3][1] = P_scale;
  P_that->value[3][2] = P_scale;
  return 1;
 }

int    IceRayC_Type_Math_Matrix3D_ScaleV( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeCoordScalar3D* P_scale )
 {
  IceRayC_Type_Math_Matrix3D_ID( P_that );
  P_that->value[3][0] = P_scale->value[0];
  P_that->value[3][1] = P_scale->value[1];
  P_that->value[3][2] = P_scale->value[2];
  return 1;
 }

int    IceRayC_Type_Math_Matrix3D_RotateX( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;
  ::math::linear::matrix::rotateX(I_result,P_alpha);
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Matrix3D_RotateY( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;
  ::math::linear::matrix::rotateY( I_result, P_alpha );
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Matrix3D_RotateZ( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;
  ::math::linear::matrix::rotateZ( I_result, P_alpha );
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Matrix3D_RotateA( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeCoordScalar3D* P_direction, IceRayC_TypeScalar P_alpha )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;
  ::math::linear::matrix::rotate( I_result, c2cpp(*P_direction), P_alpha);
  *P_that = cpp2c( I_result );
  return 1;
 }

int    IceRayC_Type_Math_Matrix1D_Multiply( IceRayC_Type_Math_Matrix1D *P_that, IceRayC_Type_Math_Matrix1D* P_left, IceRayC_Type_Math_Matrix1D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D I_result;
  ::math::linear::matrix::multiply( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_that = cpp2c( I_result );
  return 1;
 }
int    IceRayC_Type_Math_Matrix2D_Multiply( IceRayC_Type_Math_Matrix2D *P_that, IceRayC_Type_Math_Matrix2D* P_left, IceRayC_Type_Math_Matrix2D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_result;
  ::math::linear::matrix::multiply( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_that = cpp2c( I_result );
  return 1;
 }
int    IceRayC_Type_Math_Matrix3D_Multiply( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_Type_Math_Matrix3D* P_left, IceRayC_Type_Math_Matrix3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;
  ::math::linear::matrix::multiply( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_that = cpp2c( I_result );
  return 1;
 }
int    IceRayC_Type_Math_Matrix4D_Multiply( IceRayC_Type_Math_Matrix4D *P_result, IceRayC_Type_Math_Matrix4D* P_left, IceRayC_Type_Math_Matrix4D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_result;
  ::math::linear::matrix::multiply( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Matrix1D_Addition(    IceRayC_Type_Math_Matrix1D *P_result, IceRayC_Type_Math_Matrix1D* P_left, IceRayC_Type_Math_Matrix1D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D I_result;
  ::math::linear::matrix::subtraction( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }
int  IceRayC_Type_Math_Matrix2D_Addition(    IceRayC_Type_Math_Matrix2D *P_result, IceRayC_Type_Math_Matrix2D* P_left, IceRayC_Type_Math_Matrix2D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_result;
  ::math::linear::matrix::subtraction( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }
int  IceRayC_Type_Math_Matrix3D_Addition(    IceRayC_Type_Math_Matrix3D *P_result, IceRayC_Type_Math_Matrix3D* P_left, IceRayC_Type_Math_Matrix3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;
  ::math::linear::matrix::subtraction( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }
int  IceRayC_Type_Math_Matrix4D_Addition(    IceRayC_Type_Math_Matrix4D *P_result, IceRayC_Type_Math_Matrix4D* P_left, IceRayC_Type_Math_Matrix4D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_result;
  ::math::linear::matrix::subtraction( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Matrix1D_Subtraction( IceRayC_Type_Math_Matrix1D *P_result, IceRayC_Type_Math_Matrix1D* P_left, IceRayC_Type_Math_Matrix1D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D I_result;
  ::math::linear::matrix::subtraction( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }
int  IceRayC_Type_Math_Matrix2D_Subtraction( IceRayC_Type_Math_Matrix2D *P_result, IceRayC_Type_Math_Matrix2D* P_left, IceRayC_Type_Math_Matrix2D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_result;
  ::math::linear::matrix::subtraction( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }
int  IceRayC_Type_Math_Matrix3D_Subtraction( IceRayC_Type_Math_Matrix3D *P_result, IceRayC_Type_Math_Matrix3D* P_left, IceRayC_Type_Math_Matrix3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;
  ::math::linear::matrix::subtraction( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }
int  IceRayC_Type_Math_Matrix4D_Subtraction( IceRayC_Type_Math_Matrix4D *P_result, IceRayC_Type_Math_Matrix4D* P_left, IceRayC_Type_Math_Matrix4D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_result;
  ::math::linear::matrix::subtraction( I_result, c2cpp(*P_left), c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Matrix1D_Scale( IceRayC_Type_Math_Matrix1D *P_that, IceRayC_TypeScalar P_scalar, IceRayC_Type_Math_Matrix1D* P_right );
int  IceRayC_Type_Math_Matrix2D_Scale( IceRayC_Type_Math_Matrix2D *P_that, IceRayC_TypeScalar P_scalar, IceRayC_Type_Math_Matrix2D* P_right );
int  IceRayC_Type_Math_Matrix3D_Scale( IceRayC_Type_Math_Matrix3D *P_that, IceRayC_TypeScalar P_scalar, IceRayC_Type_Math_Matrix3D* P_right );
int  IceRayC_Type_Math_Matrix4D_Scale( IceRayC_Type_Math_Matrix4D *P_that, IceRayC_TypeScalar P_scalar, IceRayC_Type_Math_Matrix4D* P_right );



int  IceRayC_Type_Math_Matrix1D_Invert( IceRayC_Type_Math_Matrix1D *P_result, IceRayC_Type_Math_Matrix1D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar1D I_result;
  ::math::linear::matrix::invert( I_result, c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Matrix2D_Invert( IceRayC_Type_Math_Matrix2D *P_result, IceRayC_Type_Math_Matrix2D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_result;
  ::math::linear::matrix::invert( I_result, c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Matrix3D_Invert( IceRayC_Type_Math_Matrix3D *P_result, IceRayC_Type_Math_Matrix3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;
  ::math::linear::matrix::invert( I_result, c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Matrix4D_Invert( IceRayC_Type_Math_Matrix4D *P_result, IceRayC_Type_Math_Matrix4D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_result;
  ::math::linear::matrix::invert( I_result, c2cpp(*P_right) );
  *P_result = cpp2c( I_result );
  return 1;
 }

