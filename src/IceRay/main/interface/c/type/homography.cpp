#include "./homography.h"
#include "./homography.hpp"
#include "./coord.hpp"

#include "IceRay/type/math/homography.hpp"

int   IceRayC_Type_Math_Homography_Core1D( IceRayC_Type_Math_Homography1D *P_result, IceRayC_TypeScalar P_A, IceRayC_TypeScalar P_B )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_result;

  ::math::linear::homography::construct( I_result, P_A, P_B );

  *P_result = cpp2c( I_result );

  return 1;
 }


int   IceRayC_Type_Math_Homography_Core2D( IceRayC_Type_Math_Homography2D *P_result, IceRayC_TypeCoordScalar2D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_result;

  ::math::linear::homography::construct( I_result, c2cpp( *P_point ) );

  *P_result = cpp2c( I_result );
  return 1;
 }


int   IceRayC_Type_Math_Homography_Core3D( IceRayC_Type_Math_Homography3D *P_result, IceRayC_TypeCoordScalar3D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_result;

  ::math::linear::homography::construct( I_result, c2cpp( *P_point ) );

  *P_result = cpp2c( I_result );
  return 1;
 }

#define C3D IceRayC_TypeCoordScalar3D
int IceRayC_Type_Math_Homography_Construct3D
 ( IceRayC_Type_Math_Homography3D *P_result
    ,C3D *P_tO, C3D *P_tX, C3D* P_tY, C3D * P_tZ, C3D * P_tT
    ,C3D *P_sO, C3D *P_sX, C3D* P_sY, C3D * P_sZ, C3D * P_sT
  )
 {
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_result;

   ::math::linear::homography::construct( I_result
      ,{ c2cpp( *P_tO ), c2cpp( *P_tX ), c2cpp( *P_tY ), c2cpp( *P_tZ ), c2cpp( *P_tT ) }
      ,{ c2cpp( *P_sO ), c2cpp( *P_sX ), c2cpp( *P_sY ), c2cpp( *P_sZ ), c2cpp( *P_sT ) }
   );

  *P_result = cpp2c( I_result );
  return 1;
 }
#undef C3D

int  IceRayC_Type_Math_Homography_Transform1D( IceRayC_TypeCoordScalar1D *P_result, IceRayC_Type_Math_Homography1D *P_matrix, IceRayC_TypeCoordScalar1D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D I_result;
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D I_matrix = c2cpp( *P_matrix );
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D I_point  = c2cpp( *P_point );

  ::math::linear::homography::transform( I_result, I_matrix, I_point );

  *P_result = cpp2c( I_result );

  return 1;
 }

int  IceRayC_Type_Math_Homography_Transform2D( IceRayC_TypeCoordScalar2D *P_result, IceRayC_Type_Math_Homography2D *P_matrix, IceRayC_TypeCoordScalar2D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_result;
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D I_matrix = c2cpp( * P_matrix );
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_point  = c2cpp( *P_point );

  ::math::linear::homography::transform( I_result, I_matrix, I_point );

  *P_result = cpp2c( I_result );

  return 1;
 }

int  IceRayC_Type_Math_Homography_Transform3D( IceRayC_TypeCoordScalar3D *P_result, IceRayC_Type_Math_Homography3D *P_matrix, IceRayC_TypeCoordScalar3D *P_point )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_result;
  GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D I_matrix = c2cpp( * P_matrix );
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_point  = c2cpp( *P_point );

  ::math::linear::homography::transform( I_result, I_matrix, I_point );

  *P_result = cpp2c( I_result );

  return 1;
 }

int  IceRayC_Type_Math_Homography_System1D( IceRayC_Type_Math_Homography1D *P_result, IceRayC_TypeScalar P_pivot, IceRayC_TypeScalar P_X, IceRayC_TypeScalar P_T )
 {
  // TODO GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar1D I_result;
  // TODO ::math::linear::homography::construct( I_result, P_pivot, P_X, P_T );
  // TODO *P_result = cpp2c( I_result );

  return 1;
 }

int  IceRayC_Type_Math_Homography_System2D( IceRayC_Type_Math_Homography2D *P_result, IceRayC_TypeCoordScalar2D *P_pivot, IceRayC_TypeCoordScalar2D *P_X, IceRayC_TypeCoordScalar2D* P_Y, IceRayC_TypeCoordScalar2D * P_T )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar2D I_result;

  ::math::linear::homography::construct( I_result, c2cpp( *P_pivot ), c2cpp( *P_X ), c2cpp( *P_Y ), c2cpp( *P_T ) );

  *P_result = cpp2c( I_result );

  return 1;
 }

int  IceRayC_Type_Math_Homography_System3D( IceRayC_Type_Math_Homography3D *P_result, IceRayC_TypeCoordScalar3D *P_pivot, IceRayC_TypeCoordScalar3D *P_X, IceRayC_TypeCoordScalar3D* P_Y, IceRayC_TypeCoordScalar3D * P_Z, IceRayC_TypeCoordScalar3D * P_T )
 {
  GS_DDMRM::S_IceRay::S_type::S_homography::GT_scalar3D I_result;

  ::math::linear::homography::construct( I_result, c2cpp( *P_pivot ), c2cpp( *P_X ), c2cpp( *P_Y ), c2cpp( *P_Z ), c2cpp( *P_T ) );
  *P_result = cpp2c( I_result );

  return 1;
 }


