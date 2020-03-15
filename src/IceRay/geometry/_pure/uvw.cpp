#include "./uvw.hpp"
#include "math/function/function.hpp"


using namespace GS_DDMRM::S_IceRay::S_geometry::S__pure;


GC_uvw::GC_uvw()
 {
 }

GC_uvw::~GC_uvw()
 {
 }

bool GC_uvw::Fv_uvw( T_coord & P_uvw, T_coord const& P_point, T_state const& P_state  )const
 {
  P_uvw[0] = ::math::function::to_one( P_point[0], F_box()[0][0], F_box()[1][0] );
  P_uvw[1] = ::math::function::to_one( P_point[1], F_box()[0][1], F_box()[1][1] );
  P_uvw[2] = ::math::function::to_one( P_point[2], F_box()[0][2], F_box()[1][2] );
  return true;
 }
