#include "./coord.h"
#include "./interval.h"
#include "./coord.hpp"

#include "IceRay/type/math/interval.hpp"



GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D c2cpp( IceRayC_TypeInterval1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D Ir_result;
  Ir_result[0] = P_that.value[0].value[0]; //!< TODO
  Ir_result[1] = P_that.value[1].value[0]; //!< TODO
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_interval:: GT_scalar2D c2cpp( IceRayC_TypeInterval2D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar2D Ir_result;
  Ir_result[0] = c2cpp( P_that.value[0] );
  Ir_result[1] = c2cpp( P_that.value[1] );
  return Ir_result;
 }
 
GS_DDMRM::S_IceRay::S_type::S_interval:: GT_scalar3D c2cpp( IceRayC_TypeInterval3D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar3D Ir_result;
  Ir_result[0] = c2cpp( P_that.value[0] );
  Ir_result[1] = c2cpp( P_that.value[1] );
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_interval:: GT_scalar4D c2cpp( IceRayC_TypeInterval4D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar4D Ir_result;
  Ir_result[0] = c2cpp( P_that.value[0] );
  Ir_result[1] = c2cpp( P_that.value[1] );
  return Ir_result;
 }
