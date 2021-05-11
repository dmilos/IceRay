#include "./pierce.hpp"
#include "./sheaf.hpp"
#include "../camera/camera.hpp"

#include "IceRay/render/2pierce/_pure.hpp"

GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure *          c2cpp( IceRayC_Render_Pierce_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure*> ( P_that );
 }

IceRayC_Render_Pierce_Handle                       cpp2c( GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Pierce_Handle >( P_this );
 }

void IceRayC_Render_Pierce_Release( IceRayC_Render_Pierce_Handle P_that )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  auto I_this = c2cpp( P_that );
  delete I_this;
 }

IceRayC_Render_Pierce_Handle IceRayC_Render_Pierce_UV0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pierce::GC_UV{};
  return cpp2c( I_pure );
 }

IceRayC_Render_Pierce_Handle IceRayC_Render_Pierce_Projector0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector{};
  return cpp2c( I_pure );
 }

int  IceRayC_Render_Pierce_Projector_Camera( IceRayC_Render_Pierce_Handle P_this, IceRayC_Camera_Handle P_camera )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector Tf_projector;

  auto I_this = dynamic_cast< Tf_projector *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf_camera;

  I_this->Fv_camera( c2cpp ( P_camera ) );
  return 1;
 }

int  IceRayC_Render_Pierce_Projector_Sheaf( IceRayC_Render_Pierce_Handle P_this, IceRayC_Render_Sheaf_Handle P_sheaf )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector Tf_projector;

  auto I_this = dynamic_cast< Tf_projector *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf_sheaf;

  I_this->Fv_sheaf( c2cpp( P_sheaf ) );
  return 1;
 }
