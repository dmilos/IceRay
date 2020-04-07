#include "./homography.h"
#include "./homography.hpp"

#include "IceRay/type/math/matrix.hpp"



GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D c2cpp( IceRayC_Type_Math_Homography1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D Ir_result;
  for(int i=0; i< 1; ++i)
   for(int j=0; j< 1; ++j)
    Ir_result[i][j] = P_that.value[i][j];
 return Ir_result;
 }

IceRayC_Type_Math_Homography1D cpp2c( GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D const& P_this )
 {
  IceRayC_Type_Math_Homography1D I_that;
  for(int i=0; i< 1; ++i)
   for(int j=0; j< 1; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_homography:: GT_scalar2D c2cpp( IceRayC_Type_Math_Homography2D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D Ir_result;
  for(int i=0; i< 2; ++i)
   for(int j=0; j< 2; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

IceRayC_Type_Math_Homography2D cpp2c( GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D const& P_this )
 {
  IceRayC_Type_Math_Homography2D I_that;
  for(int i=0; i< 2; ++i)
   for(int j=0; j< 2; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_homography:: GT_scalar3D c2cpp( IceRayC_Type_Math_Homography3D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D I_this;
  for(int i=0; i< 3; ++i)
   for(int j=0; j< 3; ++j)
    I_this[i][j] = P_that.value[i][j];
  return I_this;
 }

IceRayC_Type_Math_Homography3D cpp2c( GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D const& P_this )
 {
  IceRayC_Type_Math_Homography3D I_that;
  for(int i=0; i< 3; ++i)
   for(int j=0; j< 3; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_homography:: GT_scalar4D c2cpp( IceRayC_Type_Math_Homography4D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D Ir_result;
  for(int i=0; i< 4; ++i)
   for(int j=0; i< 4; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

IceRayC_Type_Math_Homography4D cpp2c( GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar4D const& P_this )
 {
  IceRayC_Type_Math_Homography4D I_that;
  for(int i=0; i< 4; ++i)
   for(int j=0; j< 4; ++j)
    I_that.value[i][j] = P_this[i][j];
  return  I_that;
 }

int   IceRayC_Type_Math_Homography2D_ID( IceRayC_Type_Math_Homography2D *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D I_id;
  ::math::linear::matrix::id(I_id);
  *P_that = cpp2c( I_id );
  return 1;
 }
int   IceRayC_Type_Math_Homography3D_ID( IceRayC_Type_Math_Homography3D *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D I_id;
  ::math::linear::matrix::id(I_id);
  *P_that = cpp2c( I_id );
  return 1;
 }

int   IceRayC_Type_Math_Homography3D_Zero( IceRayC_Type_Math_Homography3D *P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D I_zero;
  ::math::linear::matrix::zero(I_zero);
  *P_that = cpp2c( I_zero );
  return 1;
 }

int  IceRayC_Type_Math_Homography1D_ID( IceRayC_Type_Math_Homography1D *P_that )
 { // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography2D_ID( IceRayC_Type_Math_Homography2D *P_that )
 { // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography3D_ID( IceRayC_Type_Math_Homography3D *P_that )
 { // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography4D_ID( IceRayC_Type_Math_Homography4D *P_that )
 { // TODO
  return 0;
 }

int  IceRayC_Type_Math_Homography1D_Zero( IceRayC_Type_Math_Homography1D *P_that )
 { // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography2D_Zero( IceRayC_Type_Math_Homography2D *P_that )
 { // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography3D_Zero( IceRayC_Type_Math_Homography3D *P_that )
 { // TODO
  return 0;
 }
int  IceRayC_Type_Math_Homography4D_Zero( IceRayC_Type_Math_Homography4D *P_that )
 { // TODO
  return 0;
 }
