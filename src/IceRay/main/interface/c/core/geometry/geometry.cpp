

#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "../../type/affine.hpp"

#include "IceRay/geometry/simple/simple.hpp"

#include "./handle.hpp"

#include "./simple.h"
#include "./simple.hpp"


IceRayC_Geometry_Handle IceRayC_Geometry_Torus0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto Ir_result = new Tf_torus{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Torus1( IceRayC_TypeScalar P_minor )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto Ir_result = new Tf_torus{ P_minor };
  return cpp2c( Ir_result );
 }
IceRayC_Type_Bool IceRayC_Geometry_Torus_Minor( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_minor )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto I_this = dynamic_cast< Tf_torus *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_minor( P_minor );
  return 1;
 }


// TODO #include "./base.cpp"
// TODO #include "./blobby.cpp"
// TODO #include "./complex.cpp"
// TODO #include "./flat.cpp"
// TODO #include "./geometry.cpp"
// TODO #include "./handle.cpp"
// TODO #include "./hfield.cpp"
// TODO #include "./rtss.cpp"
// TODO #include "./simple.cpp"
// TODO #include "./transform.cpp"
// TODO #include "./volumetric.cpp"

