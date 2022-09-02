#include "./sheaf.h"
#include "./sheaf.hpp"
#include "IceRay/render/3sheaf/sheaf.hpp"

GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure *          c2cpp( IceRayC_Render_Sheaf_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure*> ( P_that );
 }

IceRayC_Render_Sheaf_Handle                       cpp2c( GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Sheaf_Handle >( P_this );
 }



IceRayC_Type_Bool IceRayC_Render_Sheaf_Release( IceRayC_Render_Sheaf_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }

IceRayC_Render_Sheaf_Handle IceRayC_Render_Sheaf_ALL0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_all{};
  return cpp2c( I_pure );
 }

IceRayC_Render_Sheaf_Handle IceRayC_Render_Sheaf_First0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_first{};
  return cpp2c( I_pure );
 }

IceRayC_Render_Sheaf_Handle IceRayC_Render_Sheaf_Random0()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure  Tf__pure;
  Tf__pure *I_pure = new GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_random{};
  return cpp2c( I_pure );
 }
