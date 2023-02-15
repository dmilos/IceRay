#include "./rtss.h"
#include "./blobby.hpp"
#include "../../type/coord.hpp"
#include "../../type/affine.hpp"

#include "./geometry.hpp"
#include "IceRay/geometry/blobby/blobby.hpp"
#include "./handle.hpp"


IceRayC_Geometry_Blobby_Element_Handle cpp2c( GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element* P_this )
 {
  return reinterpret_cast< IceRayC_Geometry_Blobby_Element_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element * c2cpp( IceRayC_Geometry_Blobby_Element_Handle P_this )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element*> ( P_this );
 }

int IceRayC_Geometry_Blobby_Element_Release( IceRayC_Geometry_Blobby_Element_Handle P_this )
 {
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_System0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_system{  } ;
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_System_RTSS( IceRayC_Geometry_Handle  P_this, IceRayC_Geometry_RTSS_Handle P_rtss )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_system Tf_system;

  auto I_this = dynamic_cast< Tf_system *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_rtss( c2cpp( P_rtss ) );
 }

int IceRayC_Geometry_Blobby_System_Push( IceRayC_Geometry_Handle  P_this, IceRayC_Geometry_Blobby_Element_Handle P_element )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_system Tf_system;

  auto I_this = dynamic_cast< Tf_system *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_push( c2cpp( P_element ) ); 
 }


IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Sphere0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere{ } ;
  return cpp2c(  Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Sphere1( IceRayC_TypeCoordScalar3D *P_center, IceRayC_TypeScalar P_radius, IceRayC_TypeScalar P_influence )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere{ c2cpp( *P_center ), P_radius, P_influence };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_Element_Sphere_Influence(   IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_TypeScalar P_core )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_influence( P_core ); 
 }
int IceRayC_Geometry_Blobby_Element_Sphere_Radius( IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_radius( P_radius ); 
 }
int IceRayC_Geometry_Blobby_Element_Sphere_Center( IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_center( c2cpp(*P_center) ); 
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_USphere0()
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_usphere{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_USphere1( IceRayC_TypeScalar P_core )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_usphere{ P_core };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Blobby_Element_USphere_Core( IceRayC_Geometry_Blobby_Element_Handle P_this,IceRayC_TypeScalar P_core )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_usphere Tf_usphere;

  auto I_this = dynamic_cast< Tf_usphere *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_core( P_core ); 
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_UCylinderZ0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ Tf_ucylinderZ;

  auto Ir_result = new Tf_ucylinderZ{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_UCylinderZ1( IceRayC_TypeScalar P_core )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ Tf_ucylinderZ;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ{ P_core };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_Element_UCylinderZ_Core( IceRayC_Geometry_Blobby_Element_Handle P_this,IceRayC_TypeScalar P_core )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ Tf_ucylinderZ;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_usphere Tf_usphere;

  auto I_this = dynamic_cast< Tf_usphere *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_core( P_core ); 
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_UWaterZ0( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ GC_uwaterZ;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_uwaterZ{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_UWaterZ1( IceRayC_TypeScalar P_level )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ GC_uwaterZ;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_uwaterZ{};
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_Element_UWaterZ_Level( IceRayC_Geometry_Blobby_Element_Handle P_this,IceRayC_TypeScalar P_level )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_uwaterZ T_uwaterZ;

  auto I_this = dynamic_cast< T_uwaterZ *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_level( P_level ); 
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Translate0( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Translate1( IceRayC_Geometry_Blobby_Element_Handle P_element, IceRayC_TypeCoordScalar3D* P_translate )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{ c2cpp( P_element ), c2cpp( *P_translate ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Blobby_Element_Translate_Move( IceRayC_Geometry_Blobby_Element_Handle P_this,  IceRayC_TypeCoordScalar3D* P_translate )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_translate Tf_translate;

  auto I_this = dynamic_cast< Tf_translate *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_move( c2cpp( *P_translate ) ); 
 }
int IceRayC_Geometry_Blobby_Element_Translate_Child( IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_Geometry_Blobby_Element_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_translate Tf_translate;

  auto I_this = dynamic_cast< Tf_translate *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_child( c2cpp( P_child ) ); 
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Affine0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_affine Tf_affine;
  auto Ir_result = new Tf_affine{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Blobby_Element_Handle IceRayC_Geometry_Blobby_Element_Affine1(    IceRayC_Geometry_Blobby_Element_Handle P_element, IceRayC_Type_Math_Affine3D* P_affine )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_affine Tf_affine;
  // TODO auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_affine{ c2cpp( P_element), c2cpp( *P_affine ) };
  // TODO return cpp2c( Ir_result );
  return nullptr;
 }

int IceRayC_Geometry_Blobby_Element_Affine_2World_Get( IceRayC_Geometry_Blobby_Element_Handle P_this,  IceRayC_Type_Math_Affine3D* P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_affine Tf_affine;

  auto I_this = dynamic_cast< Tf_affine *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  // TODO
  return 0;
 }
int IceRayC_Geometry_Blobby_Element_Affine_Child( IceRayC_Geometry_Blobby_Element_Handle P_this, IceRayC_Geometry_Blobby_Element_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_affine Tf_affine;

  auto I_this = dynamic_cast< Tf_affine *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  // TODO
  return 0;
 }

