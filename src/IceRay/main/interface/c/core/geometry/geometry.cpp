
#include "./geometry.h"
#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "../../type/affine.hpp"

#include "IceRay/geometry/geometry.hpp"


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

IceRayC_Geometry_Handle IceRayC_Geometry_Sphere0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_sphere{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Sphere1( IceRayC_TypeCoordScalar3D P_center, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_sphere{ c2cpp( P_center), P_radius } ;
  return cpp2c(  Ir_result );
 }
int IceRayC_Geometry_Sphere_Center( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( P_center) );
  return 1;
 }
int IceRayC_Geometry_Sphere_Radius( IceRayC_Geometry_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;
  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp( P_that ) );
  I_this->F_radius( P_radius );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Box0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;
  auto Ir_result = new Tf_box{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Box1( IceRayC_TypeCoordScalar3D P_lo, IceRayC_TypeCoordScalar3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;
  auto Ir_result = new Tf_box{ c2cpp( P_lo ), c2cpp( P_hi ) };
  return cpp2c( Ir_result );
}

int IceRayC_Geometry_Box_Lo( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D P_lo )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;

  auto I_this = dynamic_cast< Tf_box *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_lo( c2cpp( P_lo ) );
  return 1;
 }

int IceRayC_Geometry_Box_Hi( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;

  auto I_this = dynamic_cast< Tf_box *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hi( c2cpp( P_hi ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto Ir_result = new Tf_ellipsoid{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid1( IceRayC_TypeCoordScalar3D P_center, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto Ir_result = new Tf_ellipsoid{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Ellipsoid2( IceRayC_TypeCoordScalar3D P_center, IceRayC_TypeCoordScalar3D P_eX, IceRayC_TypeCoordScalar3D P_eY, IceRayC_TypeCoordScalar3D  P_eZ )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto Ir_result = new Tf_ellipsoid{};
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Ellipsoid_Center( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D P_center )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid Tf_ellipsoid;
  auto I_this = dynamic_cast< Tf_ellipsoid *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( P_center ) );
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
IceRayC_Geometry_Handle IceRayC_Geometry_Triangle1( IceRayC_TypeCoordScalar3D P_e0, IceRayC_TypeCoordScalar3D P_ex, IceRayC_TypeCoordScalar3D P_ey )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;
  auto Ir_result = new Tf_triangle{ c2cpp( P_e0 ), c2cpp( P_ex ), c2cpp( P_ey ) };
  return cpp2c( Ir_result );
}
int IceRayC_Geometry_Triangle_Origin( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_origin )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_origin( c2cpp( P_origin ) );
  return 1;
 }

int IceRayC_Geometry_Triangle_eX( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_eX )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_eX( c2cpp( P_eX ) );
  return 1;
 }
int IceRayC_Geometry_Triangle_eY( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_eY )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_eY( c2cpp( P_eY ) );
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
IceRayC_Geometry_Handle IceRayC_Geometry_Plane1( IceRayC_TypeCoordScalar3D P_origin, IceRayC_TypeCoordScalar3D P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_plane{ c2cpp( P_origin ), c2cpp( P_normal ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Plane_Origin( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_pivot )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;

  auto I_this = dynamic_cast< Tf_plane *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_pivot( c2cpp( P_pivot ) );
 }
int IceRayC_Geometry_Plane_Normal( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;

  auto I_this = dynamic_cast< Tf_plane *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_normal( c2cpp( P_normal ) );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_HField()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system Tf_hfield;
  auto Ir_result = new Tf_hfield{};
  return cpp2c( Ir_result );
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Disc0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Disc1( IceRayC_TypeCoordScalar3D P_center, IceRayC_TypeCoordScalar3D P_normal, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{ c2cpp( P_center ), c2cpp( P_normal ), P_radius };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Disc_Center(IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_center( c2cpp( P_center ) );
}

int IceRayC_Geometry_Disc_Normal(IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_normal( c2cpp( P_normal ) );
 }
int IceRayC_Geometry_Disc_Radius(IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_radius( P_radius );
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
IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid1(  IceRayC_TypeScalar P_core )
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


IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;
  auto Ir_result = new Tf_intersect{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect1( IceRayC_Geometry_Handle P_left, IceRayC_Geometry_Handle P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;
  auto Ir_result = new Tf_intersect{};
  return cpp2c( Ir_result );
 }



int IceRayC_Geometry_Complex_Intersect_Left0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_left( c2cpp( P_left ) );
 }

int IceRayC_Geometry_Complex_Intersect_Left1( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_left, int location )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside::T_location    Tf_location;
  return I_this->F_left( c2cpp( P_left ), Tf_location( location ) );
 }

int IceRayC_Geometry_Complex_Intersect_Right0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_right( c2cpp( P_right ) );
 }

int IceRayC_Geometry_Complex_Intersect_Right1( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_right, int location )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside::T_location    Tf_location;
  return I_this->F_right( c2cpp( P_right ), Tf_location( location ) );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Enclose0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_enclose Tf_enclose;
  auto Ir_result = new Tf_enclose{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Enclose1( IceRayC_Geometry_Handle P_child, IceRayC_Geometry_Handle P_hull )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_enclose Tf_enclose;
  auto Ir_result = new Tf_enclose{ c2cpp( P_child ), c2cpp( P_hull ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Complex_Enclose_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_enclose Tf_enclose;

  auto I_this = dynamic_cast< Tf_enclose *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_child( c2cpp( P_child ) );
 }

int IceRayC_Geometry_Complex_Enclose_Hull(  IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_enclose Tf_enclose;

  auto I_this = dynamic_cast< Tf_enclose *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside::T_location    Tf_location;
  return I_this->F_hull( c2cpp( P_hull ) );
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Identity0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_identity;
  auto Ir_result = new Tf_identity{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Identity1( IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_identity;
  auto Ir_result = new Tf_identity{ c2cpp( P_child ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Transform_Identity_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_identity;

  auto I_this = dynamic_cast< Tf_identity *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_affine;
  auto Ir_result = new Tf_affine{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine1( IceRayC_Geometry_Handle P_child, IceRayC_Type_Math_Affine3D P_affine )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_affine;
  auto Ir_result = new Tf_affine{ c2cpp( P_child ), c2cpp( P_affine ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Transform_Affine_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_identity;

  auto I_this = dynamic_cast< Tf_identity *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }

int IceRayC_Geometry_Transform_Affine_2World( IceRayC_Geometry_Handle P_this, IceRayC_Type_Math_Affine3D P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_identity;

  auto I_this = dynamic_cast< Tf_identity *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_2world( c2cpp( P_2world ) );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{};
  return cpp2c( Ir_result );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate1( IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{ c2cpp( P_child ) };
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Translate2( IceRayC_Geometry_Handle P_child, IceRayC_TypeCoordScalar3D P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{ c2cpp( P_child ), c2cpp( P_move ) };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Transform_Translate_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;

  auto I_this = dynamic_cast< Tf_translate *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_this  ) );
  return 1;
 }
int IceRayC_Geometry_Transform_Translate_Move( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;

  auto I_this = dynamic_cast< Tf_translate *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_move( c2cpp( P_move ) );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Transform_MotionBlur0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_mblur Tf_mblur;
  auto Ir_result = new Tf_mblur{};
  return cpp2c( Ir_result );
 }


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
  I_this->F_hull( dynamic_cast< Tf_hull *>( c2cpp( P_this ) ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke Tf_smoke;
  auto Ir_result = new Tf_smoke{};
  return cpp2c( Ir_result );
}


IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke2( IceRayC_Geometry_Handle P_hull )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke Tf_smoke;
  auto Ir_result = new Tf_smoke{ /*dynamic_cast<Tf_smoke::T_hull*>( c2cpp( P_hull ) )*/ };
  return cpp2c( Ir_result );
}


 int IceRayC_Geometry_Volumetric_Smoke_Hull( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect Tf_hull;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke Tf_smoke;

  auto I_this = dynamic_cast< Tf_smoke *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hull( dynamic_cast< Tf_hull *>( c2cpp( P_hull ) ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum0( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum1( IceRayC_TypeCoordScalar3D P_lo, IceRayC_TypeCoordScalar3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{ c2cpp( P_lo), c2cpp( P_hi ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Volumetric_Vacuum_Lo( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_lo )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( Tf_vacuum::T_box{ c2cpp( P_lo ), I_this->F_box()[1] } );
  return 1;
 }

int IceRayC_Geometry_Volumetric_Vacuum_Hi( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( Tf_vacuum::T_box{ I_this->F_box()[0], c2cpp( P_hi ) } );
  return 1;
 }

int IceRayC_Geometry_Volumetric_Vacuum_Box( IceRayC_Geometry_Handle P_this, IceRayC_TypeInterval3D P_box )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( c2cpp( P_box ) );
  return 1;
 }


