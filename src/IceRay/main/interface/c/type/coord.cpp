#include "./coord.h"

#include "IceRay/type/math/coord.hpp"



GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D c2cpp( IceRayC_TypeCoord1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D Ir_result;
  Ir_result[0] = P_that.value[0];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_coord:: GT_scalar2D c2cpp( IceRayC_TypeCoord2D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  return Ir_result;
 }
 
GS_DDMRM::S_IceRay::S_type::S_coord:: GT_scalar3D c2cpp( IceRayC_TypeCoord3D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_coord:: GT_scalar4D c2cpp( IceRayC_TypeCoord4D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  Ir_result[3] = P_that.value[3];
  return Ir_result;
 }


