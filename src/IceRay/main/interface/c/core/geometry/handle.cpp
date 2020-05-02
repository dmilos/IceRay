
#include "./handle.h"
#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "../../type/affine.hpp"

#include "IceRay/geometry/_pure/_pure.hpp"


IceRayC_Geometry_Handle cpp2c( GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base* P_this )
 {
  return reinterpret_cast< IceRayC_Geometry_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base * c2cpp( IceRayC_Geometry_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base*> ( P_that );
 }


void IceRayC_Geometry_Release( IceRayC_Geometry_Handle P_that )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto I_this = c2cpp( P_that );
  delete I_this;
 }
