#include "./sheaf.h"
#include "IceRay/render/3sheaf/sheaf.hpp"


void IceRayC_Render_Sheaf_Release( IceRayC_Render_Sheaf_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Render_Sheaf_Handle IceRayC_Render_Sheaf_ALL0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_all{};
  return reinterpret_cast< IceRayC_Render_Sheaf_Handle>( I_pure );
 }

IceRayC_Render_Sheaf_Handle IceRayC_Render_Sheaf_First0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_first{};
  return reinterpret_cast< IceRayC_Render_Sheaf_Handle>( I_pure );
 }

IceRayC_Render_Sheaf_Handle IceRayC_Render_Sheaf_Random0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_random{};
  return reinterpret_cast< IceRayC_Render_Sheaf_Handle>( I_pure );
 }
