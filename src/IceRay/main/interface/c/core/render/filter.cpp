#include "./filter.h"
#include "./filter.hpp"

#include "IceRay/render/1pixel/filter/filter.hpp"


GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure *          c2cpp( IceRayC_Render_Pixel_Filter_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure*> ( P_that );
 }

IceRayC_Render_Pixel_Filter_Handle                       cpp2c( GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Render_Pixel_Filter_Handle >( P_this );
 }

IceRayC_Type_Bool IceRayC_Render_Pixel_Filter_Release( IceRayC_Render_Pixel_Filter_Handle P_this )
{
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure  Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
}
