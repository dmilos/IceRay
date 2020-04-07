#include "./pierce.h"
#include "IceRay/render/2pierce/pierce.hpp"


void IceRayC_Render_Pierce_Release( IceRayC_Render_Pierce_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_Pierce_Handle IceRayC_Render_Pierce_UV0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pierce::GC_UV{};
  return reinterpret_cast< IceRayC_Render_Pierce_Handle >( nullptr );
 }

IceRayC_Render_Pierce_Handle IceRayC_Render_Pierce_Projector0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector{};
  return reinterpret_cast< IceRayC_Render_Pierce_Handle >( I_pure );
 }

int  IceRayC_Render_Pierce_Projector_Camera( IceRayC_Render_Pierce_Handle P_this, IceRayC_Camera_Handle P_camera )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector Tf_projector;

  auto I_this = dynamic_cast< Tf_projector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf_camera;

  I_this->Fv_camera( reinterpret_cast<Tf_camera*> ( P_camera ) );
  return 1;
 }

int  IceRayC_Render_Pierce_Projector_Sheaf( IceRayC_Render_Pierce_Handle P_this, IceRayC_Render_Sheaf_Handle P_sheaf )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector Tf_projector;

  auto I_this = dynamic_cast< Tf_projector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf_sheaf;

  I_this->Fv_sheaf( reinterpret_cast<Tf_sheaf*> ( P_sheaf ) );
  return 1;
 }
