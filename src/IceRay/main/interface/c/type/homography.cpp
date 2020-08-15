#include "./homography.h"
#include "./homography.hpp"
#include "./coord.hpp"

#include "IceRay/type/math/homography.hpp"


int   IceRayC_Type_Math_Homography_Construct2D( IceRayC_Type_Math_Matrix3D *P_result, IceRayC_TypeCoordScalar2D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;

  ::math::linear::homography::construct( I_result, c2cpp( *P_point ) );

  *P_result = cpp2c( I_result );
  return 1;
 }


int   IceRayC_Type_Math_Homography_Construct3D( IceRayC_Type_Math_Matrix4D *P_result, IceRayC_TypeCoordScalar3D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_result;

  ::math::linear::homography::construct( I_result, c2cpp( *P_point ) );

  *P_result = cpp2c( I_result );
  return 1;
 }

int  IceRayC_Type_Math_Homography_Transform1D( IceRayC_TypeCoordScalar1D *P_result, IceRayC_Type_Math_Matrix2D *P_matrix, IceRayC_TypeCoordScalar1D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D I_result;
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_matrix = c2cpp( *P_matrix );
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D I_point  = c2cpp( *P_point );

  ::math::linear::homography::transform( I_result, I_matrix, I_point );

  *P_result = cpp2c( I_result );

  return 1;
 }

int  IceRayC_Type_Math_Homography_Transform2D( IceRayC_TypeCoordScalar2D *P_result, IceRayC_Type_Math_Matrix3D *P_matrix, IceRayC_TypeCoordScalar2D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_result;
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_matrix = c2cpp( * P_matrix );
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_point  = c2cpp( *P_point );

  ::math::linear::homography::transform( I_result, I_matrix, I_point );

  *P_result = cpp2c( I_result );

  return 1;
 }

int  IceRayC_Type_Math_Homography_Transform3D( IceRayC_TypeCoordScalar3D *P_result, IceRayC_Type_Math_Matrix4D *P_matrix, IceRayC_TypeCoordScalar3D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_result;
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_matrix = c2cpp( * P_matrix );
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_point  = c2cpp( *P_point );

  ::math::linear::homography::transform( I_result, I_matrix, I_point );

  *P_result = cpp2c( I_result );

  return 1;
 }
