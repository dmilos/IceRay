#include "./_pure.hpp"



using namespace GS_DDMRM::S_IceRay::S_render::S_pixel;


GC__pure::T2_UV GC__pure::M2s_pierce;

GC__pure::GC__pure()
 :M2_pierce( &M2s_pierce )
 //,M2_resolution( 1 )
 {

 }
GC__pure::~GC__pure()
 {

 }

void GC__pure::F_resolution( T_cell const& P_resolution )
 {
  M2_resolution = P_resolution;
  M2_scale[0] = T1_scalar(1)/M2_resolution[0];
  M2_scale[1] = T1_scalar(1)/M2_resolution[1];
 }

void GC__pure::F1_2uv( T1_uv & P_uv, T_cell const& P_cell )
 {
  P_uv[0] = P_cell[0] * M2_scale[0];
  P_uv[1] = P_cell[1] * M2_scale[1];
 }

void GC__pure::F_pierce( T_pierce * P_pierce )
 {
  M2_pierce = P_pierce;
 }
