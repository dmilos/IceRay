#include "./rtss.h"
#include "./geometry.hpp"
#include "../../type/coord.hpp"

#include "IceRay/geometry/rtss/rtss.hpp"


IceRayC_Geometry_RTSS_Handle cpp2c( GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Geometry_RTSS_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure * c2cpp( IceRayC_Geometry_RTSS_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure*> ( P_that );
 }


void IceRayC_Geometry_RTSS_Release( IceRayC_Geometry_RTSS_Handle P_that )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure Tf__base;
  auto I_this = c2cpp( P_that );
  delete I_this;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_Object0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object Tf_object;
  auto Ir_result = new Tf_object{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_Object1( IceRayC_Geometry_RTSS_Handle P_rtss )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object Tf_object;
  auto Ir_result = new Tf_object{ c2cpp( P_rtss )};
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_RTSS_Object_Rtss( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_RTSS_Handle P_rtss )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object Tf_object;

  auto I_this = dynamic_cast< Tf_object *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure Tf_child;
  auto I_child = c2cpp( P_rtss );
  if( nullptr == I_child )
   {
    return 0;
   }

  I_this->F_rtss( I_child );
  return 1;
 }

int                     IceRayC_Geometry_RTSS_Object_Push( IceRayC_Geometry_Handle P_that, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object Tf_object;

  auto I_this = dynamic_cast< Tf_object *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure Tf_child;
  auto I_child = c2cpp( P_child );
  if( nullptr == I_child )
   {
    return 0;
   }

  I_this->F_push( I_child );
  return 1;
 }




IceRayC_Geometry_RTSS_Handle IceRayC_Geometry_RTSS_List0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_list Tf_list;
  auto Ir_result = new Tf_list{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_RTSS_Handle IceRayC_Geometry_RTSS_Uniform0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_uniform Tf_uniform;
  auto Ir_result = new Tf_uniform{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_RTSS_Handle IceRayC_Geometry_RTSS_Uniform1( IceRayC_TypeCoordSize3D P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_uniform Tf_uniform;
  auto Ir_result = new Tf_uniform{ c2cpp( P_size ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_RTSS_Uniform_Dimension( IceRayC_Geometry_RTSS_Handle P_that, IceRayC_TypeCoordSize3D P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_uniform Tf_uniform;

  auto I_this = dynamic_cast< Tf_uniform *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_dimension( c2cpp( P_size ) );
  return 1;
 }
