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
