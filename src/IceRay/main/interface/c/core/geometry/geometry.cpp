
#include "./geometry.h"
#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "../../type/affine.hpp"

#include "IceRay/geometry/geometry.hpp"

void IceRayC_Geometry_Release( IceRayC_Geometry_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto I_this = reinterpret_cast<Tf__base*> ( P_this );
  delete I_this;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Sphere0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_sphere{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Sphere1( IceRayC_TypeCoord3D P_center, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_sphere{ c2cpp( P_center), P_radius } ;
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
int IceRayC_Geometry_Sphere_Center( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( P_center) );
  return 1;
 }
int IceRayC_Geometry_Sphere_Radius( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere Tf_sphere;
  auto I_this = dynamic_cast< Tf_sphere *>( reinterpret_cast<Tf__base*> ( P_this ) );
  I_this->F_radius( P_radius );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Box0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;
  auto Ir_result = new Tf_box{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Box1( IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;
  auto Ir_result = new Tf_box{ c2cpp( P_lo ), c2cpp( P_hi ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

int IceRayC_Geometry_Box_Lo( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_lo )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;

  auto I_this = dynamic_cast< Tf_box *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_lo( c2cpp( P_lo ) );
  return 1;
 }

int IceRayC_Geometry_Box_Hi( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;

  auto I_this = dynamic_cast< Tf_box *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hi( c2cpp( P_hi ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Torus0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto Ir_result = new Tf_torus{};
  return reinterpret_cast<IceRayC_Geometry_Handle>(dynamic_cast< Tf__base *> ( Ir_result ) );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Torus1( IceRayC_TypeScalar P_minor )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto Ir_result = new Tf_torus{ P_minor };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}
int IceRayC_Geometry_Torus_Minor( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_minor )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus Tf_torus;
  auto I_this = dynamic_cast< Tf_torus *>( reinterpret_cast<Tf__base*> ( P_this ) );
  I_this->F_minor( P_minor );
  return 1;
}

IceRayC_Geometry_Handle IceRayC_Geometry_Triangle0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;
  auto Ir_result = new Tf_triangle{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Triangle1( IceRayC_TypeCoord3D P_e0, IceRayC_TypeCoord3D P_ex, IceRayC_TypeCoord3D P_ey )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;
  auto Ir_result = new Tf_triangle{ c2cpp( P_e0 ), c2cpp( P_ex ), c2cpp( P_ey ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}
int IceRayC_Geometry_Triangle_Origin( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_origin )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_origin( c2cpp( P_origin ) );
  return 1;
 }

int IceRayC_Geometry_Triangle_eX( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_eX )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_eX( c2cpp( P_eX ) );
  return 1;
 }
int IceRayC_Geometry_Triangle_eY( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_eY )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle Tf_triangle;

  auto I_this = dynamic_cast< Tf_triangle *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_eY( c2cpp( P_eY ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke Tf_smoke;
  auto Ir_result = new Tf_smoke{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Smoke1(  IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke Tf_smoke;
  auto Ir_result = new Tf_smoke{ c2cpp( P_lo ), c2cpp( P_hi ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

 int IceRayC_Geometry_Volumetric_Smoke_Hull( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect Tf_hull;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke Tf_smoke;

  auto I_this = dynamic_cast< Tf_smoke *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hull( dynamic_cast< Tf_hull *>( reinterpret_cast<Tf__base*> ( P_this ) ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_MotionBlur()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_mblur Tf_mblur;
  auto Ir_result = new Tf_mblur{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Plane0( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;
  auto Ir_result = new Tf_plane{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Plane1( IceRayC_TypeCoord3D P_origin, IceRayC_TypeCoord3D P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_geometry::GC_plane{ c2cpp( P_origin ), c2cpp( P_normal ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
int IceRayC_Geometry_Plane_Origin( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_pivot )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;

  auto I_this = dynamic_cast< Tf_plane *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_pivot( c2cpp( P_pivot ) );
 }
int IceRayC_Geometry_Plane_Normal( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane Tf_plane;

  auto I_this = dynamic_cast< Tf_plane *>( reinterpret_cast<Tf__base*> ( P_this ) );
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
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Disc0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Disc1( IceRayC_TypeCoord3D P_center, IceRayC_TypeCoord3D P_normal, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{ c2cpp( P_center ), c2cpp( P_normal ), P_radius };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
int IceRayC_Geometry_Disc_Center(IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_center( c2cpp( P_center ) );
}

int IceRayC_Geometry_Disc_Normal(IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__base*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__base*> ( P_this ) );
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
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

int IceRayC_Geometry_Cylinder_Radius( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_cylinder Tf_cylinder;

  auto I_this = dynamic_cast< Tf_cylinder *>( reinterpret_cast<Tf__base*> ( P_this ) );
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
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Paraboloid0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_paraboloid Tf_paraboloid;
  auto Ir_result = new Tf_paraboloid{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid0()
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;
  auto Ir_result = new Tf_hyperboloid{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid1(  IceRayC_TypeScalar P_core )
{
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;
  auto Ir_result = new Tf_hyperboloid{ P_core };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}
int IceRayC_Geometry_Hyperboloid_Core( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_core )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid Tf_hyperboloid;

  auto I_this = dynamic_cast< Tf_hyperboloid *>( reinterpret_cast<Tf__base*> ( P_this ) );
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
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}

IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;
  auto Ir_result = new Tf_intersect{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect1( IceRayC_Geometry_Handle P_left, IceRayC_Geometry_Handle P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;
  auto Ir_result = new Tf_intersect{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }



int IceRayC_Geometry_Complex_Intersect_Left0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_left( reinterpret_cast<Tf__base*> ( P_left ) );
 }

int IceRayC_Geometry_Complex_Intersect_Left1( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_left, int location )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside::T_location    Tf_location;
  return I_this->F_left( reinterpret_cast<Tf__base*> ( P_left ), Tf_location( location ) );
 }

int IceRayC_Geometry_Complex_Intersect_Right0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_right( reinterpret_cast<Tf__base*> ( P_right ) );
 }

int IceRayC_Geometry_Complex_Intersect_Right1( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_right, int location )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside::T_location    Tf_location;
  return I_this->F_right( reinterpret_cast<Tf__base*> ( P_right ), Tf_location( location ) );
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Identica0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_identity;
  auto Ir_result = new Tf_identity{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Identity1( IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_identity;
  auto Ir_result = new Tf_identity{ reinterpret_cast<Tf__base*> ( P_child ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
int IceRayC_Geometry_Identity_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity Tf_identity;

  auto I_this = dynamic_cast< Tf_identity *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( reinterpret_cast<Tf__base*>( P_child ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_affine;
  auto Ir_result = new Tf_affine{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Transform_Affine1( IceRayC_Geometry_Handle P_child, IceRayC_TypeAffine3D P_affine )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_affine;
  auto Ir_result = new Tf_affine{ reinterpret_cast<Tf__base*> ( P_child ), c2cpp( P_affine ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

int IceRayC_Geometry_Transform_Affine_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_identity;

  auto I_this = dynamic_cast< Tf_identity *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( reinterpret_cast<Tf__base*>( P_child ) );
  return 1;
 }

int IceRayC_Geometry_Transform_Affine_Affine( IceRayC_Geometry_Handle P_this, IceRayC_TypeAffine3D P_affine )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine Tf_identity;

  auto I_this = dynamic_cast< Tf_identity *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_2world( c2cpp( P_affine ) );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Translate0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
}
IceRayC_Geometry_Handle IceRayC_Geometry_Translate1( IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{ reinterpret_cast<Tf__base*> ( P_child ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Translate2( IceRayC_Geometry_Handle P_child, IceRayC_TypeCoord3D P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;
  auto Ir_result = new Tf_translate{ reinterpret_cast<Tf__base*> ( P_child ), c2cpp( P_move ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
int IceRayC_Geometry_Translate_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;

  auto I_this = dynamic_cast< Tf_translate *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( reinterpret_cast<Tf__base*> ( P_this  ) );
  return 1;
 }
int IceRayC_Geometry_Translate_Move( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_move )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate Tf_translate;

  auto I_this = dynamic_cast< Tf_translate *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_move( c2cpp( P_move ) );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum0( )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum1( IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{ c2cpp( P_lo), c2cpp( P_hi ) };
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

int IceRayC_Geometry_Volumetric_Vacuum_Lo( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_lo )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_box( c2cpp( P_lo ), I_this->F_box()[1] );
  return 1;
 }

int IceRayC_Geometry_Volumetric_Vacuum_Hi( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_box( I_this->F_box()[0], c2cpp( P_hi ) );
  return 1;
 }

int IceRayC_Geometry_Volumetric_Vacuum_Lo( IceRayC_Geometry_Handle P_this, IceRayC_TypeInterval3D P_box )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;

  auto I_this = dynamic_cast< Tf_vacuum *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( c2cpp( P_box ) );
  return 1;
 }


IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_Object0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object Tf_object;
  auto Ir_result = new Tf_object{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

int IceRayC_Geometry_RTSS_Object_Rtss0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object Tf_object;

  auto I_this = dynamic_cast< Tf_object *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure Tf_child;
  auto I_child = dynamic_cast< Tf_child *>( reinterpret_cast<Tf__base*> ( P_child ) );
  if( nullptr == I_child )
   {
    return 0;
   }

  I_this->F_push( I_child );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_List0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_list Tf_list;
  auto Ir_result = new Tf_list{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_Uniform0(  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_uniform Tf_uniform;
  auto Ir_result = new Tf_uniform{};
  return reinterpret_cast<IceRayC_Geometry_Handle>( dynamic_cast< Tf__base *> ( Ir_result ) );
 }

int IceRayC_Geometry_RTSS_Uniform_Size( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordSize3D P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_uniform Tf_uniform;

  auto I_this = dynamic_cast< Tf_uniform *>( reinterpret_cast<Tf__base*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }

  I_this->F_dimension( c2cpp( P_size ) );
  return 1;
 }
