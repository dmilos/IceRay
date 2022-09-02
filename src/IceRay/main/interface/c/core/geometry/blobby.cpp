#include "./rtss.h"
#include "./blobby.hpp"
#include "../../type/coord.hpp"
#include "../../type/affine.hpp"

#include "./geometry.hpp"
#include "IceRay/geometry/blobby/blobby.hpp"


IceRayC_Geometry_Blobby_Element_Handle cpp2c( GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element* P_this )
 {
  return reinterpret_cast< IceRayC_Geometry_Blobby_Element_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element * c2cpp( IceRayC_Geometry_Blobby_Element_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element*> ( P_that );
 }

int IceRayC_Geometry_Blobby_Element_Release( IceRayC_Geometry_Blobby_Element_Handle P_that )
 {
  auto I_this = c2cpp( P_that );
  delete I_this;
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_System0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_system{  } ;
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_System_RTSS( IceRayC_Geometry_Handle  P_system, IceRayC_Geometry_RTSS_Handle* P_rtss )
 {
  return 0;
 }

int IceRayC_Geometry_Blobby_System_Push( IceRayC_Geometry_Blobby_Element_Handle  P_system, IceRayC_Geometry_Blobby_Element_Handle* P_element )
 {
  return 0;
 }


IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Sphere0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere{ } ;
  return cpp2c(  Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Sphere1( IceRayC_TypeCoordScalar3D *P_center, IceRayC_TypeScalar P_core, IceRayC_TypeScalar P_radius )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere{ c2cpp( *P_center ), P_core, P_radius };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_Sphere_Core(   IceRayC_Geometry_Blobby_Element_Handle P_that, IceRayC_TypeScalar P_core )
 {
  return 0;
 }
int IceRayC_Geometry_Blobby_Sphere_Radius( IceRayC_Geometry_Blobby_Element_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  return 0;
 }
int IceRayC_Geometry_Blobby_Sphere_Center( IceRayC_Geometry_Blobby_Element_Handle P_that, IceRayC_TypeCoordScalar3D* P_center )
 {
  return 0;
 }


IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_USphere0()
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_usphere{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_USphere1( IceRayC_TypeScalar P_core )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_usphere{ P_core };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Blobby_USphere_Core( IceRayC_Geometry_Blobby_Element_Handle P_that,IceRayC_TypeScalar P_core )
 {
  return 0;
 }


IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_UCylinderZ0()
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_UCylinderZ1( IceRayC_TypeScalar P_core )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ{ P_core };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_UCylinderZ_Core( IceRayC_Geometry_Blobby_Element_Handle P_that,IceRayC_TypeScalar P_core )
 {
  return 0;
 }


IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_UWaterZ0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_uwaterZ{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_UWaterZ1( IceRayC_TypeScalar P_level )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_uwaterZ{};
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_UWaterZ_Level( IceRayC_Geometry_Blobby_Element_Handle P_that,IceRayC_TypeScalar P_level )
 {
  return 0;
 }


IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Translate0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_translate{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Translate1( IceRayC_Geometry_Blobby_Element_Handle P_element, IceRayC_TypeCoordScalar3D* P_translate )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_translate{ c2cpp( P_element ), c2cpp( *P_translate ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_Translate_Move( IceRayC_Geometry_Blobby_Element_Handle P_that,  IceRayC_TypeCoordScalar3D* P_translate )
 {
  return 0;
 }
int IceRayC_Geometry_Blobby_Translate_Child( IceRayC_Geometry_Blobby_Element_Handle P_that, IceRayC_Geometry_Blobby_Element_Handle P_child )
 {
  return 0;
 }


IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Affine0(  )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_affine{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Affine1(    IceRayC_Geometry_Blobby_Element_Handle P_element, IceRayC_Type_Math_Affine3D P_affine )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_affine{ c2cpp( P_element), c2cpp( P_affine ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_Affine_2World_Get( IceRayC_Geometry_Blobby_Element_Handle P_that,  IceRayC_Type_Math_Affine3D P_2world )
 {
  // TODO
  return 0;
 }
int IceRayC_Geometry_Blobby_Affine_Child( IceRayC_Geometry_Blobby_Element_Handle P_that, IceRayC_Geometry_Blobby_Element_Handle P_child )
 {
  // TODO
  return 0;
 }

