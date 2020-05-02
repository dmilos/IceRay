#include "./homography.h"
#include "./homography.hpp"

#include "IceRay/type/math/homography.hpp"



GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D c2cpp( IceRayC_Type_Math_Homography1D_Struct P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D Ir_result;
  for(int i=0; i< 1; ++i)
   for(int j=0; j< 1; ++j)
    Ir_result[i][j] = P_that.value[i][j];
 return Ir_result;
 }

//IceRayC_Type_Math_Homography1D_Struct                 cpp2c( GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D  const& P_this )
// {
//  IceRayC_Type_Math_Homography1D I_that;
//  for(int i=0; i< 1; ++i)
//   for(int j=0; j< 1; ++j)
//    I_that.value[i][j] = P_this[i][j];
//  return  I_that;
// }

GS_DDMRM::S_IceRay::S_type::S_homography:: GT_scalar2D c2cpp( IceRayC_Type_Math_Homography2D_Struct P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D Ir_result;
  for(int i=0; i< 2; ++i)
   for(int j=0; j< 2; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

//IceRayC_Type_Math_Homography2D_Struct cpp2c( GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D const& P_this )
// {
//  IceRayC_Type_Math_Homography2D I_that;
//  for(int i=0; i< 2; ++i)
//   for(int j=0; j< 2; ++j)
//    I_that.value[i][j] = P_this[i][j];
//  return  I_that;
// }

GS_DDMRM::S_IceRay::S_type::S_homography:: GT_scalar3D c2cpp( IceRayC_Type_Math_Homography3D_Struct P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D I_this;
  for(int i=0; i< 3; ++i)
   for(int j=0; j< 3; ++j)
    I_this[i][j] = P_that.value[i][j];
  return I_this;
 }

//IceRayC_Type_Math_Homography3D_Struct cpp2c( GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D const& P_this )
// {
//  IceRayC_Type_Math_Homography3D I_that;
//  for(int i=0; i< 3; ++i)
//   for(int j=0; j< 3; ++j)
//    I_that.value[i][j] = P_this[i][j];
//  return  I_that;
// }

GS_DDMRM::S_IceRay::S_type::S_homography:: GT_scalar4D c2cpp( IceRayC_Type_Math_Homography4D_Struct P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D Ir_result;
  for(int i=0; i< 4; ++i)
   for(int j=0; i< 4; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

//IceRayC_Type_Math_Homography4D_Struct cpp2c( GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D const& P_this )
// {
//  IceRayC_Type_Math_Homography4D I_that;
//  for(int i=0; i< 4; ++i)
//   for(int j=0; j< 4; ++j)
//    I_that.value[i][j] = P_this[i][j];
//  return  I_that;
// }



int  IceRayC_Type_Math_Homography1D_ID( IceRayC_Type_Math_Homography1D_Struct *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D I_this;
  ::math::linear::matrix::id(I_this);
  // TODO *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Homography2D_ID( IceRayC_Type_Math_Homography2D_Struct *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D I_this;
  ::math::linear::matrix::id( I_this );
  // TODO *P_that = cpp2c( I_id );
  return 1;
 }
int  IceRayC_Type_Math_Homography3D_ID( IceRayC_Type_Math_Homography3D_Struct *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D I_this;
  ::math::linear::matrix::id( I_this );
  // TODO *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Homography4D_ID( IceRayC_Type_Math_Homography4D_Struct *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D I_this;
  ::math::linear::matrix::id( I_this );
  // TODO *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Homography1D_Zero( IceRayC_Type_Math_Homography1D_Struct *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D I_this;
  ::math::linear::matrix::zero(I_this);
  // TODO *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Homography2D_Zero( IceRayC_Type_Math_Homography2D_Struct *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D I_this;
  ::math::linear::matrix::zero(I_this);
  // TODO *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Homography3D_Zero( IceRayC_Type_Math_Homography3D_Struct *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D I_this;
  ::math::linear::matrix::zero( I_this );
  // TODO *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Homography4D_Zero( IceRayC_Type_Math_Homography4D_Struct *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D I_this;
  ::math::linear::matrix::zero( I_this );
  // TODO *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Homography1D_Convert( IceRayC_Type_Math_Homography1D_Struct *P_that, IceRayC_Type_Math_Affine1D  * P_source )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D I_this;
  // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography2D_Convert( IceRayC_Type_Math_Homography2D_Struct *P_that, IceRayC_Type_Math_Affine2D  * P_source )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D I_this;
  // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography3D_Convert( IceRayC_Type_Math_Homography3D_Struct *P_that, IceRayC_Type_Math_Affine3D  * P_source )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D I_this;
  // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography4D_Convert( IceRayC_Type_Math_Homography4D_Struct *P_that, IceRayC_Type_Math_Affine4D  * P_source )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D I_this;
  // TODO
  return 0;
 }

