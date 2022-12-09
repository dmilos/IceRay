#include "./coord.h"
#include "./coord.hpp"

#include "IceRay/type/math/coord.hpp"



GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D c2cpp( IceRayC_TypeCoordScalar1D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D Ir_result;
  Ir_result[0] = P_that.value[0];
  return Ir_result;
 }
GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D c2cpp( IceRayC_TypeCoordScalar2D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  return Ir_result;
 }
GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D c2cpp( IceRayC_TypeCoordScalar3D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  return Ir_result;
 }
GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D c2cpp( IceRayC_TypeCoordScalar4D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  Ir_result[3] = P_that.value[3];
  return Ir_result;
 }

IceRayC_TypeCoordScalar1D                        cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D const& P_this )
 {
  IceRayC_TypeCoordScalar1D I_that;
  I_that.value[0] = P_this[0];
  return I_that;
 }
IceRayC_TypeCoordScalar2D                        cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D const& P_this )
 {
  IceRayC_TypeCoordScalar2D I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  return I_that;
 }
IceRayC_TypeCoordScalar3D                        cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D const& P_this )
 {
  IceRayC_TypeCoordScalar3D I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  I_that.value[2] = P_this[2];
  return I_that;
 }
IceRayC_TypeCoordScalar4D                        cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D const& P_this )
 {
  IceRayC_TypeCoordScalar4D I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  I_that.value[2] = P_this[2];
  I_that.value[3] = P_this[3];
  return I_that;
 }

GS_DDMRM::S_IceRay::S_type::S_coord::GT_size1D c2cpp( IceRayC_TypeCoordSize1D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_size1D Ir_result;
  Ir_result[0] = P_that.value[0];
  return Ir_result;
 }
GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D c2cpp( IceRayC_TypeCoordSize2D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  return Ir_result;
 }
GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D c2cpp( IceRayC_TypeCoordSize3D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  return Ir_result;
 }
GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D c2cpp( IceRayC_TypeCoordSize4D const& P_that )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D Ir_result;
  Ir_result[0] = P_that.value[0];
  Ir_result[1] = P_that.value[1];
  Ir_result[2] = P_that.value[2];
  Ir_result[3] = P_that.value[3];
  return Ir_result;
 }

IceRayC_TypeCoordSize1D cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_size1D const& P_this )
 {
  IceRayC_TypeCoordSize1D I_that;
  I_that.value[0] = P_this[0];
  return I_that;
 }
IceRayC_TypeCoordSize2D cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D const& P_this )
 {
  IceRayC_TypeCoordSize2D I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  return I_that;
 }
IceRayC_TypeCoordSize3D cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D const& P_this )
 {
  IceRayC_TypeCoordSize3D I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  I_that.value[2] = P_this[2];
  return I_that;
 }
IceRayC_TypeCoordSize4D cpp2c( GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D const& P_this )
 {
  IceRayC_TypeCoordSize4D I_that;
  I_that.value[0] = P_this[0];
  I_that.value[1] = P_this[1];
  I_that.value[2] = P_this[2];
  I_that.value[3] = P_this[3];
  return I_that;
 }

int  IceRayC_Type_Math_Coord1D_Fill( IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeScalar P_x )
 {
  P_that->value[0] = P_x;
  return 0;
 }
int  IceRayC_Type_Math_Coord2D_Fill( IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeScalar P_scalar)
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_this;
  ::math::linear::vector::fill( I_this, P_scalar );
  *P_that = cpp2c( I_this );
  return 0;
 }
int  IceRayC_Type_Math_Coord3D_Fill( IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeScalar P_scalar)
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_this;
  ::math::linear::vector::fill( I_this, P_scalar );
  *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Coord4D_Fill( IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeScalar P_scalar)
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D I_this;
  ::math::linear::vector::fill( I_this, P_scalar );
  *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Coord1D_Load( IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeScalar P_x)
 {
  P_that->value[0] = P_x;
  return 0;
 }
int  IceRayC_Type_Math_Coord2D_Load( IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeScalar P_x, IceRayC_TypeScalar P_y )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_this;
  ::math::linear::vector::load( I_this, P_x, P_y );
  *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Coord3D_Load( IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeScalar P_x, IceRayC_TypeScalar P_y,  IceRayC_TypeScalar P_z )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_this;
  ::math::linear::vector::load( I_this, P_x, P_y, P_z );
  *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Coord4D_Load( IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeScalar P_x, IceRayC_TypeScalar P_y,  IceRayC_TypeScalar P_z, IceRayC_TypeScalar P_t )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D I_this;
  ::math::linear::vector::load( I_this, P_x, P_y, P_z, P_t );
  *P_that = cpp2c( I_this );
  return 1;
 }

IceRayC_TypeScalar  IceRayC_Type_Math_Coord1D_Length( IceRayC_TypeCoordScalar1D *P_that )
 {
  return ::math::linear::vector::length( c2cpp( *P_that ) );
 }
IceRayC_TypeScalar  IceRayC_Type_Math_Coord2D_Length( IceRayC_TypeCoordScalar2D *P_that )
 {
  return ::math::linear::vector::length( c2cpp( *P_that ) );
 }
IceRayC_TypeScalar  IceRayC_Type_Math_Coord3D_Length( IceRayC_TypeCoordScalar3D *P_that )
 {
  return ::math::linear::vector::length( c2cpp( *P_that ) );
 }
IceRayC_TypeScalar  IceRayC_Type_Math_Coord4D_Length( IceRayC_TypeCoordScalar4D *P_that )
 {
  return ::math::linear::vector::length( c2cpp( *P_that ) );
 }

IceRayC_TypeScalar  IceRayC_Type_Math_Coord1D_Distance( IceRayC_TypeCoordScalar1D* P_left, IceRayC_TypeCoordScalar1D* P_right )
 {
  return ::math::linear::vector::distance( c2cpp( *P_left ), c2cpp( *P_right ) );
 }
IceRayC_TypeScalar  IceRayC_Type_Math_Coord2D_Distance( IceRayC_TypeCoordScalar2D* P_left, IceRayC_TypeCoordScalar2D* P_right )
 {
  return ::math::linear::vector::distance( c2cpp( *P_left ), c2cpp( *P_right ) );
 }
IceRayC_TypeScalar  IceRayC_Type_Math_Coord3D_Distance( IceRayC_TypeCoordScalar3D* P_left, IceRayC_TypeCoordScalar3D* P_right )
 {
  return ::math::linear::vector::distance( c2cpp( *P_left ), c2cpp( *P_right ) );
 }
IceRayC_TypeScalar  IceRayC_Type_Math_Coord4D_Distance( IceRayC_TypeCoordScalar4D* P_left, IceRayC_TypeCoordScalar4D* P_right )
 {
  return ::math::linear::vector::distance( c2cpp( *P_left ), c2cpp( *P_right ) );
 }


int  IceRayC_Type_Math_Coord3D_Cross(    IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeCoordScalar3D* P_left, IceRayC_TypeCoordScalar3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_this;
  ::math::linear::vector::cross( I_this, c2cpp( *P_left ), c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Coord1D_Addition(    IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeCoordScalar1D* P_left, IceRayC_TypeCoordScalar1D* P_right )
 {
  P_that->value[0] = P_left->value[0] + P_right->value[0];
  return 1;
 }
int  IceRayC_Type_Math_Coord2D_Addition(    IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeCoordScalar2D* P_left, IceRayC_TypeCoordScalar2D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_this;
  ::math::linear::vector::addition( I_this, c2cpp( *P_left ), c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Coord3D_Addition(    IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeCoordScalar3D* P_left, IceRayC_TypeCoordScalar3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_this;
  ::math::linear::vector::addition( I_this, c2cpp( *P_left ), c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Coord4D_Addition(    IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeCoordScalar4D* P_left, IceRayC_TypeCoordScalar4D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D I_this;
  ::math::linear::vector::addition( I_this, c2cpp( *P_left ), c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Coord1D_Subtraction( IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeCoordScalar1D* P_left, IceRayC_TypeCoordScalar1D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D I_this;
  ::math::linear::vector::subtraction( I_this, c2cpp( *P_left ), c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Coord2D_Subtraction( IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeCoordScalar2D* P_left, IceRayC_TypeCoordScalar2D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_this;
  ::math::linear::vector::addition( I_this, c2cpp( *P_left ), c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Coord3D_Subtraction( IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeCoordScalar3D* P_left, IceRayC_TypeCoordScalar3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_this;
  ::math::linear::vector::addition( I_this, c2cpp( *P_left ), c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }
int  IceRayC_Type_Math_Coord4D_Subtraction( IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeCoordScalar4D* P_left, IceRayC_TypeCoordScalar4D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D I_this;
  ::math::linear::vector::addition( I_this, c2cpp( *P_left ), c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Coord1D_Scale(    IceRayC_TypeCoordScalar1D *P_that, IceRayC_TypeScalar P_left, IceRayC_TypeCoordScalar1D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar1D I_this;
  ::math::linear::vector::scale( I_this, P_left, c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Coord2D_Scale(    IceRayC_TypeCoordScalar2D *P_that, IceRayC_TypeScalar P_left, IceRayC_TypeCoordScalar2D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D I_this;
  ::math::linear::vector::scale( I_this, P_left, c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Coord3D_Scale(    IceRayC_TypeCoordScalar3D *P_that, IceRayC_TypeScalar P_left, IceRayC_TypeCoordScalar3D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D I_this;
  ::math::linear::vector::scale( I_this, P_left, c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }

int  IceRayC_Type_Math_Coord4D_Scale(    IceRayC_TypeCoordScalar4D *P_that, IceRayC_TypeScalar P_left, IceRayC_TypeCoordScalar4D* P_right )
 {
  GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D I_this;
  ::math::linear::vector::scale( I_this, P_left, c2cpp( *P_right ) );
  *P_that = cpp2c( I_this );
  return 1;
 }


