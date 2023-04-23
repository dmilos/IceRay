#include "./color.h"

#include "IceRay/type/color.hpp"

GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar c2cpp( IceRayC_Type_Color_Gray const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar Ir_result;
  Ir_result[0] = P_that.value;
  return Ir_result;
 }

IceRayC_Type_Color_Gray cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar const& P_that )
 {
  IceRayC_Type_Color_Gray Ir_result;
  Ir_result.value = P_that[0];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar c2cpp( IceRayC_TypeColorRGB const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  return Ir_result;
 }

IceRayC_TypeColorRGB                           cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar const& P_this )
 {
  IceRayC_TypeColorRGB I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  I_that.value[2] = P_this[2];
  return I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_color::S_HSL::GT_scalar c2cpp( IceRayC_TypeColorHSL const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_color::S_HSL::GT_scalar Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  return Ir_result;
 }

IceRayC_TypeColorHSL                           cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::S_HSL::GT_scalar const& P_this )
 {
  IceRayC_TypeColorHSL I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  I_that.value[2] = P_this[2];
  return I_that;
 }


//GS_DDMRM::S_IceRay::S_type::S_color::GT_size4D c2cpp( IceRayC_Type_Color_RGBA const&  );
//IceRayC_Type_Color_RGBA cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D const& );


int  IceRayC_Type_Color_HSL2RGB( IceRayC_TypeColorRGB *P_left, IceRayC_TypeColorHSL* P_right )
 {

  *P_left = cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar( c2cpp( *P_right ) ) );
  return 1;
 }

int  IceRayC_Type_Color_RGB2HSL( IceRayC_TypeColorHSL *P_left, IceRayC_TypeColorRGB* P_right )
 {
  *P_left = cpp2c( GS_DDMRM::S_IceRay::S_type::S_color::S_HSL::GT_scalar( c2cpp( *P_right ) ) );
  return 1;
 }

