#include "./camera.h"
#include "./camera.hpp"
#include "IceRay/camera/camera.hpp"
#include "../../type/type.hpp"



IceRayC_Camera_Handle cpp2c( GS_DDMRM::S_IceRay::S_camera::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Camera_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_camera::GC__pure * c2cpp( IceRayC_Camera_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_camera::GC__pure*> ( P_that );
 }

void IceRayC_Camera_Release( IceRayC_Camera_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
 }

IceRayC_Camera_Handle IceRayC_Camera_Flat_Perspective0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective{};
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Flat_Perspective1( IceRayC_TypeScalar P_aspect )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective{ P_aspect };
  return cpp2c( Ir_result );
 }


IceRayC_Camera_Handle IceRayC_Camera_Flat_Perspective2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_height )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective{ P_width, P_height };
  return cpp2c( Ir_result );
 }

int IceRayC_Camera_Flat_Perspective_Width(  IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_width )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_width( P_width );
  return 1;
 }

int IceRayC_Camera_Flat_Perspective_Height( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_height )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_height( P_height );
  return 1;
 }

int IceRayC_Camera_Flat_Perspective_Aspect( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_aspect )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aspect( P_aspect );
  return 1;
 }

IceRayC_Camera_Handle IceRayC_Camera_Flat_Super0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super{};
  return cpp2c( Ir_result );
 }

int                   IceRayC_Camera_Flat_Super_Eye(        IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_eye )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_eye( c2cpp( *P_eye ) );
  return 1;
 }
int                   IceRayC_Camera_Flat_Super_Ocular(     IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_ocular )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_ocular( c2cpp( *P_ocular ) );
  return 1;
 }

int                   IceRayC_Camera_Flat_Super_View(       IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_view )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_view( c2cpp( *P_view ) );
  return 1;
 }

int                   IceRayC_Camera_Flat_Super_Objective(  IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_objective )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_objective( c2cpp( *P_objective ) );
  return 1;
 }

int                   IceRayC_Camera_Flat_Super_Focus(  IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_focus )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_focus( c2cpp( *P_focus ) );
  return 1;
 }


IceRayC_Camera_Handle IceRayC_Camera_Flat_Orthogonal0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal{  };
  return cpp2c( Ir_result );
 }


int IceRayC_Camera_Flat_Orthogonal_Width(  IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_width )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_width( P_width );
  return 1;
 }

int IceRayC_Camera_Flat_Orthogonal_Height( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_height )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_height( P_height );
  return 1;
 }

int IceRayC_Camera_Flat_Orthogonal_Aspect( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_aspect )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aspect( P_aspect );
  return 1;
 }

IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Horizontal0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal{};
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Horizontal1( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal{ P_width, P_theta };
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Horizontal2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal{ P_width, P_theta, P_radius };
  return cpp2c( Ir_result );
 }

int IceRayC_Camera_Cylinder_Horizontal_Width( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_width )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal Tf_horizontal;

  auto I_this = dynamic_cast< Tf_horizontal *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_width( P_width );
  return 1;
 }

int IceRayC_Camera_Cylinder_Horizontal_Theta( IceRayC_Camera_Handle P_that,IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal Tf_horizontal;

  auto I_this = dynamic_cast< Tf_horizontal *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_theta( P_theta );
  return 1;
 }

int IceRayC_Camera_Cylinder_Horizontal_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal Tf_horizontal;

  auto I_this = dynamic_cast< Tf_horizontal *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 1;
 }


IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Vertical0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical{};
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Vertical1( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical{ P_width, P_theta };
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Vertical2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical{ P_width, P_theta, P_radius };
  return cpp2c( Ir_result );
 }

int IceRayC_Camera_Cylinder_Vertical_Phi( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_phi( P_phi );
  return 1;
 }

int IceRayC_Camera_Cylinder_Vertical_Height( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_height )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_height( P_height );
  return 1;
 }

int IceRayC_Camera_Cylinder_Vertical_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 1;
 }

IceRayC_Camera_Handle IceRayC_Camera_Sphere_Vertical0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical{};
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Sphere_Vertical1( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical{P_theta, P_phi};
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Sphere_Vertical2( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical{P_theta, P_phi, P_radius};
  return cpp2c( Ir_result );
 }

int IceRayC_Camera_Sphere_Vertical_Theta( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_theta( P_theta );
  return 1;
 }

int IceRayC_Camera_Sphere_Vertical_Phi( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_phi( P_phi );
  return 0;
 }

int IceRayC_Camera_Sphere_Vertical_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 0;
 }


IceRayC_Camera_Handle IceRayC_Camera_Sphere_Horizontal0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_horizontal{  };
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Sphere_Horizontal1( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_horizontal{ P_theta, P_phi, P_radius };
  return cpp2c( Ir_result );
 }

int IceRayC_Camera_Sphere_Horizontal_Phi( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_phi( P_phi );
  return 0;
 }

int IceRayC_Camera_Sphere_Horizontal_Theta( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_theta( P_theta );
  return 0;
 }

int IceRayC_Camera_Sphere_Horizontal_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 0;
 }

IceRayC_Camera_Handle IceRayC_Camera_Sphere_Fisheye0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_fisheye{  };
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Sphere_Fisheye1( IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_fisheye{ P_phi, P_theta };
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Sphere_Fisheye2( IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_fisheye{ P_phi, P_theta, P_radius };
  return cpp2c( Ir_result );
 }

int IceRayC_Camera_Sphere_Fisheye_Phi( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_phi( P_phi );
  return 0;
 }

int IceRayC_Camera_Sphere_Fisheye_Theta( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_theta( P_theta );
  return 0;
 }

int IceRayC_Camera_Sphere_Fisheye_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 0;
 }

//IceRayC_Camera_Handle IceRayC_Camera_Sphere_Package1( IceRayC_TypeScalar P_hfov, IceRayC_TypeScalar P_vfov )
// {
//  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
//  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_package{  };
//   return cpp2c( Ir_result );
// }

IceRayC_Camera_Handle      IceRayC_Camera_Transform_Affine0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto I_result = new GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine{  };
  return  cpp2c( I_result );
 }
IceRayC_Camera_Handle      IceRayC_Camera_Transform_Affine1( IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine Tf_affine;
  auto Ir_result = new Tf_affine{ c2cpp( P_child ) };
  return cpp2c( Ir_result );
 }
IceRayC_Camera_Handle      IceRayC_Camera_Transform_Affine2( IceRayC_Camera_Handle P_child, IceRayC_Type_Math_Affine3D * P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine Tf_affine;
  auto aaa = c2cpp( *P_2world );
  auto Ir_result = new Tf_affine{ c2cpp( P_child )  };
  return cpp2c( Ir_result );
 }
int                        IceRayC_Camera_Transform_Affine_Child( IceRayC_Camera_Handle P_that, IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine Tf_affine;

  auto I_this = dynamic_cast<Tf_affine*>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }
int                        IceRayC_Camera_Transform_Affine_2World_Get( IceRayC_Camera_Handle P_that, IceRayC_Type_Math_Affine3D * P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine Tf_affine;

  auto I_this = dynamic_cast<Tf_affine*>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    IceRayC_Type_Math_Affine3D_ID( P_2world );
    return 0;
   }
  *P_2world = cpp2c( I_this->F_2world() );
  return 1;
 }
int                        IceRayC_Camera_Transform_Affine_2World_Set( IceRayC_Camera_Handle P_that, IceRayC_Type_Math_Affine3D * P_2world )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine Tf_affine;

  auto I_this = dynamic_cast<Tf_affine*>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_2world( c2cpp( *P_2world ) );
  return 1;
 }
int IceRayC_Camera_Transform_Affine_2Local_Get( IceRayC_Camera_Handle P_that, IceRayC_Type_Math_Affine3D *P_2local )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine Tf_affine;

  auto I_this = dynamic_cast<Tf_affine*>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    IceRayC_Type_Math_Affine3D_ID( P_2local );
    return 0;
   }
  *P_2local = cpp2c( I_this->F_2local() );
  return 1;
 }
int                        IceRayC_Camera_Transform_Affine_2Local_Set( IceRayC_Camera_Handle P_that, IceRayC_Type_Math_Affine3D * P_2local )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine Tf_affine;

  auto I_this = dynamic_cast<Tf_affine*>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_2local( c2cpp( *P_2local ) );
  return 1;
 }

IceRayC_Camera_Handle IceRayC_Camera_DOF_Focus0()
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus{};
  return cpp2c( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_Camera_DOF_Focus1( IceRayC_TypeSize P_sample, IceRayC_TypeInterval1D P_aperture, IceRayC_TypeInterval1D P_focus, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus{ P_sample, c2cpp( P_aperture ), c2cpp(P_focus), P_gauss };
  return cpp2c( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_Camera_DOF_Focus2( IceRayC_Camera_Handle P_child, IceRayC_TypeSize P_sample, IceRayC_TypeInterval1D P_aperture, IceRayC_TypeInterval1D P_focus, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus{ c2cpp( P_child ), P_sample, c2cpp( P_aperture ), c2cpp(P_focus), P_gauss };
  return cpp2c( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int            IceRayC_Camera_DOF_Focus_Aperture( IceRayC_Camera_Handle P_that, IceRayC_TypeInterval1D P_aperture )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus Tf_focus;

  auto I_this = dynamic_cast< Tf_focus *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aperture( c2cpp( P_aperture ) );
  return 1;
 }

int IceRayC_Camera_DOF_Focus_Focus( IceRayC_Camera_Handle P_that, IceRayC_TypeInterval1D P_focus )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus Tf_focus;

  auto I_this = dynamic_cast< Tf_focus *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_focus( c2cpp( P_focus ) );
  return 1;
 }

int IceRayC_Camera_DOF_Focus_Gauss( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus Tf_focus;

  auto I_this = dynamic_cast< Tf_focus *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_gauss( P_gauss );
  return 1;
 }

int IceRayC_Camera_DOF_Focus_Child( IceRayC_Camera_Handle P_that, IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus Tf_focus;

  auto I_this = dynamic_cast< Tf_focus *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }


IceRayC_Camera_Handle IceRayC_Camera_DOF_Cone0()
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone{  };
  return cpp2c( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_Camera_DOF_Cone1( IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture )
{
    typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
    auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone{ P_sample, P_aperture };
    return cpp2c( Ir_result );
}

IceRayC_Camera_Handle IceRayC_Camera_DOF_Cone2( IceRayC_Camera_Handle P_child, IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone{ c2cpp( P_child ), P_sample, P_aperture };
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_DOF_Cone3( IceRayC_Camera_Handle P_child, IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone{ c2cpp( P_child ), P_sample, P_aperture, P_gauss };
  return cpp2c( Ir_result );
 }

int IceRayC_Camera_DOF_Conus_Sample( IceRayC_Camera_Handle P_that, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone Tf_conus;

  auto I_this = dynamic_cast< Tf_conus *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sample( P_sample );
  return 1;
 }

int IceRayC_Camera_DOF_Conus_Aperture( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_aperture )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone Tf_conus;

  auto I_this = dynamic_cast< Tf_conus *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aperture( P_aperture );
  return 1;
 }

int IceRayC_Camera_DOF_Conus_Gauss( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone Tf_conus;

  auto I_this = dynamic_cast< Tf_conus *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aperture( P_gauss );
  return 1;
 }

int IceRayC_Camera_DOF_Conus_Child( IceRayC_Camera_Handle P_that, IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone Tf_conus;

  auto I_this = dynamic_cast< Tf_conus *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }


IceRayC_Camera_Handle IceRayC_Camera_Transform_Invert0()
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_transform::GC_invert{};
  return cpp2c( Ir_result );
 }

IceRayC_Camera_Handle IceRayC_Camera_Transform_Invert1( IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_transform::GC_invert{ c2cpp( P_child ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Camera_Transform_Invert_Child( IceRayC_Camera_Handle P_that, IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_invert Tf_invert;

  auto I_this = dynamic_cast< Tf_invert *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }
