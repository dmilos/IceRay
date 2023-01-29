

#include "../../type/coord.hpp"

#include "IceRay/geometry/flat/flat.hpp"

#include "./handle.hpp"

#include "./flat.h"
#include "./flat.hpp"

IceRayC_Geometry_Handle IceRayC_Geometry_Box0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;
  auto Ir_result = new Tf_box{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Box1( IceRayC_TypeCoordScalar3D* P_lo, IceRayC_TypeCoordScalar3D* P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;
  auto Ir_result = new Tf_box{ c2cpp( *P_lo ), c2cpp( *P_hi ) };
  return cpp2c( Ir_result );
}

int IceRayC_Geometry_Box_Lo( IceRayC_Geometry_Handle P_that, IceRayC_TypeCoordScalar3D* P_lo )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;

  auto I_this = dynamic_cast< Tf_box *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_lo( c2cpp( *P_lo ) );
  return 1;
 }

int IceRayC_Geometry_Box_Hi( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_box Tf_box;

  auto I_this = dynamic_cast< Tf_box *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hi( c2cpp( *P_hi ) );
  return 1;
 }

IceRayC_Geometry_Handle IceRayC_Geometry_TriangleU0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangleU Tf_triangleU;
  auto Ir_result = new Tf_triangleU{};
  return cpp2c( Ir_result );
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

IceRayC_Geometry_Handle IceRayC_Geometry_Disc0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Disc1( IceRayC_TypeCoordScalar3D* P_center, IceRayC_TypeCoordScalar3D* P_normal, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{ c2cpp( *P_center ), c2cpp( *P_normal ), P_radius };
  return cpp2c( Ir_result );
 }
int IceRayC_Geometry_Disc_Center(IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_center( c2cpp( *P_center ) );
}

int IceRayC_Geometry_Disc_Normal(IceRayC_Geometry_Handle P_this, IceRayC_TypeCoordScalar3D* P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_normal( c2cpp( *P_normal ) );
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

IceRayC_Geometry_Handle IceRayC_Geometry_UDisc0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_udisc Tf_udisc;
  auto Ir_result = new Tf_udisc{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_UDisc1( IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_udisc Tf_udisc;
  auto Ir_result = new Tf_udisc{ P_radius };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_UDisc_Radius(IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_udisc Tf_udisc;

  auto I_this = dynamic_cast< Tf_udisc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_radius( P_radius );
 }

