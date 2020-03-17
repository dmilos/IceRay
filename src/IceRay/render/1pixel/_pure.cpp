#include "./_pure.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_pixel;

GC__pure::GC__pure()
 :M2_resolution( { 1, 1 } )
 ,M2_scale( { 1, 1 } )
 {

 }
GC__pure::~GC__pure()
 {
 }

void GC__pure::F_resolution( T_cell const& P_resolution )
 {
  M2_resolution = P_resolution;
  M2_scale[0] = T_scalar(1)/M2_resolution[0];
  M2_scale[1] = T_scalar(1)/M2_resolution[1];
 }

void GC__pure::F1_2uv( T_uv & P_uv, T_cell const& P_cell )
 {
  P_uv[0] = P_cell[0] * M2_scale[0];
  P_uv[1] = P_cell[1] * M2_scale[1];
 }

