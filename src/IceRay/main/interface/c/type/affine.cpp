#include "./affine.h"

#include "IceRay/type/math/affine.hpp"



GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar1D c2cpp( IceRayC_TypeAffine1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar1D Ir_result;
  for(int i=0; i< 1; ++i) 
   for(int j=0; i< j; ++j)
    Ir_result[i][j] = P_that.value[i][j];
 return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_affine:: GT_scalar2D c2cpp( IceRayC_TypeAffine2D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar2D Ir_result;
  for(int i=0; i< 2; ++i) 
   for(int j=0; i< 2; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }
 
GS_DDMRM::S_IceRay::S_type::S_affine:: GT_scalar3D c2cpp( IceRayC_TypeAffine3D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D Ir_result;
  for(int i=0; i< 3; ++i) 
   for(int j=0; i< 3; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_affine:: GT_scalar4D c2cpp( IceRayC_TypeAffine4D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar4D Ir_result;
  for(int i=0; i< 4; ++i) 
   for(int j=0; i< 4; ++j)
    Ir_result[i][j] = P_that.value[i][j];
  return Ir_result;
 }
