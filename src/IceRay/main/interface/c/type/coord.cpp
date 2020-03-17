#include "./coord.h"

#include "IceRay/type/math/coord.hpp"



GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D c2cpp( IceRayC_TypeCoordScalar1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D Ir_result;
  Ir_result[0] = P_that.value[0];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_coord:: GT_scalar2D c2cpp( IceRayC_TypeCoordScalar2D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  return Ir_result;
 }
 
GS_DDMRM::S_IceRay::S_type::S_coord:: GT_scalar3D c2cpp( IceRayC_TypeCoordScalar3D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_coord:: GT_scalar4D c2cpp( IceRayC_TypeCoordScalar4D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  Ir_result[3] = P_that.value[3];
  return Ir_result;
 }



GS_DDMRM::S_IceRay::S_type::S_coord::GT_size1D c2cpp( IceRayC_TypeCoordSize1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_size1D Ir_result;
  Ir_result[0] = P_that.value[0];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_coord:: GT_size2D c2cpp( IceRayC_TypeCoordSize2D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  return Ir_result;
 }
 
GS_DDMRM::S_IceRay::S_type::S_coord:: GT_size3D c2cpp( IceRayC_TypeCoordSize3D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_coord:: GT_size4D c2cpp( IceRayC_TypeCoordSize4D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  Ir_result[3] = P_that.value[3];
  return Ir_result;
 }


