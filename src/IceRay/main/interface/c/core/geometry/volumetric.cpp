
#include "./geometry.h"
#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "./geometry.hpp"
#include "./handle.hpp"

#include "IceRay/geometry/volumetric/volumetric.hpp"

IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;
  auto Ir_result = new Tf_mist{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist1( IceRayC_TypeScalar P_density )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;
  auto Ir_result = new Tf_mist{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist2( IceRayC_TypeScalar P_density, IceRayC_TypeScalar P_precision )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;
  auto Ir_result = new Tf_mist{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist3( IceRayC_Geometry_Handle P_hull )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;
  auto Ir_result = new Tf_mist{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist4( IceRayC_Geometry_Handle P_hull, IceRayC_TypeScalar P_density )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;
  auto Ir_result = new Tf_mist{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Mist5( IceRayC_Geometry_Handle P_hull, IceRayC_TypeScalar P_density, IceRayC_TypeScalar P_precision )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;
  auto Ir_result = new Tf_mist{};
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Volumetric_Mist_Seed( IceRayC_Geometry_Handle P_this, IceRayC_TypeSize P_seed )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base     Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect Tf_hull;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;

  auto I_this = dynamic_cast< Tf_mist *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_seed( P_seed );
  return 1;
 }
 
int IceRayC_Geometry_Volumetric_Mist_Density( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_density )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect Tf_hull;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;

  auto I_this = dynamic_cast< Tf_mist *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_density( P_density );
  return 1;
 }
int IceRayC_Geometry_Volumetric_Mist_Precision( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_precision )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect Tf_hull;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;

  auto I_this = dynamic_cast< Tf_mist *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_precision( P_precision );
  return 1;
 }
int IceRayC_Geometry_Volumetric_Mist_Hull( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect Tf_hull;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist Tf_mist;

  auto I_this = dynamic_cast< Tf_mist *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hull( dynamic_cast< Tf_hull *>( c2cpp( P_hull ) ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_smoke Tf_smoke;
  auto Ir_result = new Tf_smoke{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke2( IceRayC_Geometry_Handle P_hull )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_smoke Tf_smoke;
  auto Ir_result = new Tf_smoke{ /*dynamic_cast<Tf_smoke::T_hull*>( c2cpp( P_hull ) )*/ };
  return cpp2c( Ir_result );
}
int IceRayC_Geometry_Volumetric_Smoke_Hull( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect Tf_hull;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_smoke Tf_smoke;

  auto I_this = dynamic_cast< Tf_smoke *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hull( dynamic_cast< Tf_hull *>( c2cpp( P_hull ) ) );
  return 1;
 }

int                     IceRayC_Geometry_Volumetric_Smoke_Expression( IceRayC_Geometry_Handle P_this, char *P_expression )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_smoke Tf_smoke;

  auto I_this = dynamic_cast< Tf_smoke *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_expression( P_expression );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum0( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum1( IceRayC_TypeCoordScalar3D* P_lo, IceRayC_TypeCoordScalar3D* P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{ c2cpp( *P_lo ), c2cpp( *P_hi ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Volumetric_Vacuum_Lo( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_lo )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( Tf_vacuum::T_box{ c2cpp( *P_lo ), I_this->F_box()[1] } );
  return 1;
 }
int IceRayC_Geometry_Volumetric_Vacuum_Hi( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( Tf_vacuum::T_box{ I_this->F_box()[0], c2cpp( *P_hi ) } );
  return 1;
 }
int IceRayC_Geometry_Volumetric_Vacuum_Box( IceRayC_Geometry_Handle P_this, IceRayC_TypeInterval3D* P_box )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( c2cpp( *P_box ) );
  return 1;
 }
