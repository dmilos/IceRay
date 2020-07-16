#include "./coord.h"
#include "./interval.h"
#include "./coord.hpp"

#include "IceRay/type/math/interval.hpp"



GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D c2cpp( IceRayC_TypeInterval1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D Ir_result;
  Ir_result[0] = P_that.value[0].value[0];
  Ir_result[1] = P_that.value[1].value[0];
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


GS_DDMRM::S_IceRay::S_type::S_interval::GT_size1D c2cpp( IceRayC_Type_Interval_Size1D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_size1D Ir_result;
  Ir_result[0] = P_that.value[0].value[0];
  Ir_result[1] = P_that.value[1].value[0];
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_interval:: GT_size2D c2cpp( IceRayC_Type_Interval_Size2D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_size2D Ir_result;
  Ir_result[0] = c2cpp( P_that.value[0] );
  Ir_result[1] = c2cpp( P_that.value[1] );
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_interval:: GT_size3D c2cpp( IceRayC_Type_Interval_Size3D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_size3D Ir_result;
  Ir_result[0] = c2cpp( P_that.value[0] );
  Ir_result[1] = c2cpp( P_that.value[1] );
  return Ir_result;
 }

GS_DDMRM::S_IceRay::S_type::S_interval:: GT_size4D c2cpp( IceRayC_Type_Interval_Size4D P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_interval::GT_size4D Ir_result;
  Ir_result[0] = c2cpp( P_that.value[0] );
  Ir_result[1] = c2cpp( P_that.value[1] );
  return Ir_result;
 }



int IceRayC_Type_Math_Interval3D_Center(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Confine(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Correct(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Extend(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_In(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Inflate(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Intersect(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Interval(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Load(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Out(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Size(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Structure(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Transform(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Translate(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Unit(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Valid(   )
 {
  return 0;
 }

int IceRayC_Type_Math_Interval3D_Volume(   )
 {
  return 0;
 }

