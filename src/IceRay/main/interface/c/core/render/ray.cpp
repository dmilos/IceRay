#include "./ray.h"

#include "IceRay/render/4ray/ray.hpp"
#include "IceRay/render/4ray/classic2/algorithm.hpp"

#include "../../type/interval.hpp"
#include "../../core/geometry/geometry.hpp"
#include "../../core/object/object.hpp"


IceRayC_Render_Ray_Handle cpp2c( GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Ray_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure * c2cpp( IceRayC_Render_Ray_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure*> ( P_that );
 }

void IceRayC_Render_Ray_Release( IceRayC_Render_Ray_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
 }

IceRayC_Render_Ray_Handle   IceRayC_Render_Ray_Direction0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC_direction  Tf_direction;
  Tf__pure* I_this = new Tf_direction{};
  return cpp2c( I_this );
 }

IceRayC_Render_Ray_Handle   IceRayC_Render_Ray_Distance0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC_distance  Tf_distance;
  Tf__pure* I_this = new Tf_distance{};
  return cpp2c( I_this );
 }
IceRayC_Render_Ray_Handle   IceRayC_Render_Ray_Distance1( IceRayC_Geometry_Handle P_geometry )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC_distance  Tf_distance;

  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  Tf_geometry;

  Tf__pure* I_this = new Tf_distance{ c2cpp( P_geometry ) };
  return cpp2c( I_this );
 }
int   IceRayC_Render_Ray_Distance_Geometry( IceRayC_Render_Ray_Handle P_this, IceRayC_Geometry_Handle P_geometry )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC_distance  Tf_distance;

  auto I_this = dynamic_cast< Tf_distance *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  Tf_geometry;

  I_this->F_geometry( c2cpp( P_geometry ) );
  return 1;
 }

int                         IceRayC_Render_Ray_Distance_Clip( IceRayC_Render_Ray_Handle P_this, IceRayC_TypeInterval1D P_clip )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC_distance  Tf_distance;

  auto I_this = dynamic_cast< Tf_distance *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_clip( c2cpp ( P_clip ) );
  return 1;
 }


IceRayC_Render_Ray_Handle   IceRayC_Render_Ray_Trace0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm  Tf_algorithm;
  Tf__pure* I_this = new Tf_algorithm{};
  return cpp2c( I_this );
 }

int   IceRayC_Render_Ray_Trace_Object( IceRayC_Render_Ray_Handle P_this, IceRayC_Object_Handle P_object )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm  Tf_algorithm;

  auto I_this = dynamic_cast< Tf_algorithm *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure Tf_object;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm::T_object  Tf_wrap;

  I_this->F_object( dynamic_cast<Tf_wrap*>( c2cpp( P_object ) ) );
  return 1;
 }

int   IceRayC_Render_Ray_Trace_Depth( IceRayC_Render_Ray_Handle P_this, IceRayC_TypeSize P_depth )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm  Tf_algorithm;

  auto I_this = dynamic_cast< Tf_algorithm *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_depth( P_depth );
  return 1;
 }

int   IceRayC_Render_Ray_Trace_Trash( IceRayC_Render_Ray_Handle P_this, IceRayC_TypeScalar P_trash )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm  Tf_algorithm;

  auto I_this = dynamic_cast< Tf_algorithm *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_trash( P_trash );
  return 1;
 }

