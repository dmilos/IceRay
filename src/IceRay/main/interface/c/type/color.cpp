#include "./color.h"

#include "IceRay/type/color.hpp"


GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar c2cpp( IceRayC_TypeColorRGB P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  return Ir_result;
 }

IceRayC_TypeColorRGB                           cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar P_this )
 {
  IceRayC_TypeColorRGB I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  I_that.value[2] = P_this[2];
  return I_that;
 }
