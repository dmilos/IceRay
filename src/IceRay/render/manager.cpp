#include "manager.hpp"

using namespace GS_DDMRM::S_IceRay::S_render;

GC_manager::GC_manager()
 {
  M2_image    = NULL;
  M2_pixel    = NULL;
  M2_beam     = NULL;
  M2_ray      = NULL;
  M2_camera   = NULL;
  M2_geometry = NULL;
 }

GC_manager::~GC_manager()
 {

 }

void GC_manager::F_do( T_picture & P_image )
 {
  if( NULL == M2_image ) return;
  if( NULL == M2_pixel ) return;
  if( NULL == M2_beam ) return;
  if( NULL == M2_ray ) return;
 // moze i bez ovoga
 //if( NULL == M2_geometry ) return; 

  M2_pixel->Fv_prepare();
  M2_image->Fv_render( P_image );
 }

bool 
GC_manager::F_work()
 {
  if( NULL == F_image() ) return false;
  return M2_image->F_work();
 }


void 
GC_manager::F_image   (T_image   * P_image    )
 {
  if( true == F_work() ) return;
  M2_image = P_image;
  if( NULL == M2_image ) return;
  M2_image->Fv_pixel( M2_pixel );
 }

void 
GC_manager::F_pixel   (T_pixel   * P_pixel    )
 {
  if( true == F_work() ) return;
  M2_pixel = P_pixel;
  F_image( M2_image );
  if( NULL == M2_pixel ) return;
  M2_pixel->Fv_camera( M2_camera );
  M2_pixel->Fv_beam( M2_beam );
 }

void 
GC_manager::F_beam    (T_beam    * P_beam     )
 {
  if( true == F_work() ) return;
  M2_beam = P_beam;
  F_pixel( M2_pixel );
  if( NULL == M2_beam ) return;
  M2_beam->Fv_ray( M2_ray );
 }

void 
GC_manager::F_ray     (T_ray     * P_ray      )
 {
  if( true == F_work() ) return;
  M2_ray = P_ray;
  F_beam( M2_beam );
  if( NULL == M2_ray ) return;
  M2_ray->Fv_geometry( M2_geometry );
 }

void GC_manager::F_camera  (T_camera  * P_camera   )
 {
  if( true == F_work() ) return;
  M2_camera = P_camera;
  F_pixel( M2_pixel );
 }

void GC_manager::F_geometry(T_geometry* P_geometry )
 {
  if( true == F_work() ) return;
  M2_geometry = P_geometry;
  F_ray( M2_ray );
 }

