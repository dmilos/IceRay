

#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "../../type/affine.hpp"

#include "IceRay/geometry/simple/simple.hpp"
#include "IceRay/geometry/flat/flat.hpp"
#include "IceRay/geometry/hfield/hfield.hpp"

#include "./handle.hpp"

#include "./simple.h"
#include "./simple.hpp"

IceRayC_Geometry_Handle IceRayC_Geometry_Sphere0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_sphere{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Sphere1( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_sphere{ c2cpp( *P_center), P_radius } ;
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Sphere_Center( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( *P_center) );
  return 1;
 }
int IceRayC_Geometry_Sphere_Radius( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;
  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp( P_that ) );
  I_this->F_radius( P_radius );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto Ir_result = new Tf_ellipsoid{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid1( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto Ir_result = new Tf_ellipsoid{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid2( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeCoordScalar3D* P_eX, IceRayC_TypeCoordScalar3D* P_eY, IceRayC_TypeCoordScalar3D*  P_eZ )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto Ir_result = new Tf_ellipsoid{};
  return cpp2c( Ir_result );
 }

int                     IceRayC_Geometry_Ellipsoid_Center( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_center )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto I_this = dynamic_cast< Tf_ellipsoid *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( *P_center ) );
  return 1;
}
int                     IceRayC_Geometry_Ellipsoid_RadiusS( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto I_this = dynamic_cast< Tf_ellipsoid *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 1;
 }
int                     IceRayC_Geometry_Ellipsoid_RadiusV( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto I_this = dynamic_cast< Tf_ellipsoid *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( c2cpp( *P_radius ) );
  return 1;
 }
int                     IceRayC_Geometry_Ellipsoid_System( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_eX, IceRayC_TypeCoordScalar3D* P_eY, IceRayC_TypeCoordScalar3D * P_eZ )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto I_this = dynamic_cast< Tf_ellipsoid *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_system( c2cpp( *P_eX ),c2cpp( *P_eY ),c2cpp( *P_eZ ) );
  return 1;
 }


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
int IceRayC_Geometry_Torus_Minor( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_minor )
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

IceRayC_Geometry_Handle IceRayC_Geometry_Triangle0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;
  auto Ir_result = new Tf_triangle{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Triangle1( IceRayC_TypeCoordScalar3D* P_e0, IceRayC_TypeCoordScalar3D* P_ex, IceRayC_TypeCoordScalar3D* P_ey )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;
  auto Ir_result = new Tf_triangle{ c2cpp( *P_e0 ), c2cpp( *P_ex ), c2cpp( *P_ey ) };
  return cpp2c( Ir_result );
}
int IceRayC_Geometry_Triangle_Origin( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_origin )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_origin( c2cpp( *P_origin ) );
  return 1;
 }

int IceRayC_Geometry_Triangle_eX( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_eX )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_eX( c2cpp( *P_eX ) );
  return 1;
 }
int IceRayC_Geometry_Triangle_eY( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_eY )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_eY( c2cpp( *P_eY ) );
  return 1;
 }

IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Quadric0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_quadric Tf_quadric;
  auto Ir_result = new Tf_quadric{};
  return cpp2c( Ir_result );
}


IceRayC_Geometry_Handle IceRayC_Geometry_Plane0( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;
  auto Ir_result = new Tf_plane{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Plane1( IceRayC_TypeCoordScalar3D* P_origin, IceRayC_TypeCoordScalar3D* P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_plane{ c2cpp( *P_origin ), c2cpp( *P_normal ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Plane_Origin( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_pivot )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;

  auto I_this = dynamic_cast< Tf_plane *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_pivot( c2cpp( *P_pivot ) );
 }
int IceRayC_Geometry_Plane_Normal( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;

  auto I_this = dynamic_cast< Tf_plane *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_normal( c2cpp( *P_normal ) );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_HField()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system Tf_hfield;
  auto Ir_result = new Tf_hfield{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Cylinder0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_cylinder Tf_cylinder;
  auto Ir_result = new Tf_cylinder{};
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Cylinder_Radius( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_cylinder Tf_cylinder;

  auto I_this = dynamic_cast< Tf_cylinder *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Cone0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_cone Tf_cone;
  auto Ir_result = new Tf_cone{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Paraboloid0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_paraboloid Tf_paraboloid;
  auto Ir_result = new Tf_paraboloid{};
  return cpp2c( Ir_result );
}

IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;
  auto Ir_result = new Tf_hyperboloid{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid1( IceRayC_TypeScalar P_core )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;
  auto Ir_result = new Tf_hyperboloid{ P_core };
  return cpp2c( Ir_result );
}
int IceRayC_Geometry_Hyperboloid_Core( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_core )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;

  auto I_this = dynamic_cast< Tf_hyperboloid *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_core( P_core );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Saddle0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_saddle Tf_saddle;
  auto Ir_result = new Tf_saddle{};
  return cpp2c( Ir_result );
}

IceRayC_Geometry_Handle IceRayC_Geometry_USphere0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_usphere Tf_usphere;
  auto Ir_result = new Tf_usphere{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_UCylinder0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ucylinder Tf_cylinder;
  auto Ir_result = new Tf_cylinder{};
  return cpp2c( Ir_result );
}


