
#include "./geometry.h"
#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "./geometry.hpp"
#include "./handle.hpp"

#include "IceRay/geometry/implicit.hpp"


IceRayC_Geometry_Handle IceRayC_Geometry_Implicit0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_implicit Tf_implicit;
  auto Ir_result = new Tf_implicit{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Implicit1( IceRayC_Geometry_Handle P_hull )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_implicit Tf_implicit;
  auto Ir_result = new Tf_implicit{ /*dynamic_cast<Tf_implicit::T_hull*>( c2cpp( P_hull ) )*/ };
  return cpp2c( Ir_result );
}

int IceRayC_Geometry_Implicit_Hull( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect Tf_hull;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_implicit Tf_implicit;

  auto I_this = dynamic_cast< Tf_implicit *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  // TODO I_this->F_hull( dynamic_cast< Tf_hull *>( c2cpp( P_hull ) ) );
  return 1;
 }

int                     IceRayC_Geometry_Implicit_Expression( IceRayC_Geometry_Handle P_this, char *P_expression )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_implicit Tf_implicit;

  auto I_this = dynamic_cast< Tf_implicit *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_expression( P_expression );
  return 1;
 }

int                     IceRayC_Geometry_Implicit_Interval( IceRayC_Geometry_Handle P_this, IceRayC_TypeInterval3D *P_interval )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_implicit Tf_implicit;

  auto I_this = dynamic_cast< Tf_implicit *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_interval( c2cpp( *P_interval ) );
  return 1;
 }

int                     IceRayC_Geometry_Implicit_Delta(     IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_delta     )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_implicit Tf_implicit;

  auto I_this = dynamic_cast< Tf_implicit *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_delta( P_delta );
  return 1;
 }

int                     IceRayC_Geometry_Implicit_Sampling(  IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_sampling  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_implicit Tf_implicit;

  auto I_this = dynamic_cast< Tf_implicit *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sampling( P_sampling );
  return 1;
 }

int                     IceRayC_Geometry_Implicit_Iteration( IceRayC_Geometry_Handle P_this, IceRayC_TypeSize   P_iteration )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_implicit Tf_implicit;

  auto I_this = dynamic_cast< Tf_implicit *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_iteration( P_iteration );
  return 1;
 }


