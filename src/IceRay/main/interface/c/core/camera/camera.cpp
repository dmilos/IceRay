#include "./camera.h"
#include "IceRay/camera/camera.hpp"
#include "../../type/type.hpp"


void IceRayC_Camera_Release( IceRayC_Camera_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Camera_Handle IceRayC_CameraFlatPerspective0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective{};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraFlatPerspective1( IceRayC_TypeScalar P_aspect )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective{ P_aspect };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }


IceRayC_Camera_Handle IceRayC_CameraFlatPerspective2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_height )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective{ P_width, P_height };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_CameraFlatPerspective_Width(  IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_width )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_width( P_width );
  return 1;
 }

int IceRayC_CameraFlatPerspective_Height( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_height )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_height( P_height );
  return 1;
 }

int IceRayC_CameraFlatPerspective_Aspect( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_aspect )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aspect( P_aspect );
  return 1;
 }

IceRayC_Camera_Handle IceRayC_CameraFlatSuper0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super{};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraFlatOrthogonal0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal{  };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }


int IceRayC_CameraFlatOrthogonal_Width(  IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_width )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_width( P_width );
  return 1;
 }

int IceRayC_CameraFlatOrthogonal_Height( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_height )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_height( P_height );
  return 1;
 }

int IceRayC_CameraFlatOrthogonal_Aspect( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_aspect )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aspect( P_aspect );
  return 1;
 }

IceRayC_Camera_Handle IceRayC_CameraCylinderHorizontal0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal{};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraCylinderHorizontal1( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal{ P_width, P_theta };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraCylinderHorizontal2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal{ P_width, P_theta, P_radius };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_CameraCylinderHorizontal_Width( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_width )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal Tf_horizontal;

  auto I_this = dynamic_cast< Tf_horizontal *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_width( P_width );
  return 1;
 }

int IceRayC_CameraCylinderHorizontal_Theta( IceRayC_Camera_Handle P_this,IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal Tf_horizontal;

  auto I_this = dynamic_cast< Tf_horizontal *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_theta( P_theta );
  return 1;
 }

int IceRayC_CameraCylinderHorizontal_Radius( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal Tf_horizontal;

  auto I_this = dynamic_cast< Tf_horizontal *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 1;
 }


IceRayC_Camera_Handle IceRayC_CameraCylinderVertical( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical{};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraCylinderVertical1( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical{ P_width, P_theta };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraCylinderVertical2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical{ P_width, P_theta, P_radius };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_CameraCylinderVertical_Phi( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_phi( P_phi );
  return 1;
 }

int IceRayC_CameraCylinderVertical_Height( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_height )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_height( P_height );
  return 1;
 }

int IceRayC_CameraCylinderVertical_Radius( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 1;
 }

IceRayC_Camera_Handle IceRayC_CameraSphereVetical0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical{};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraSphereVetical1( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical{P_theta, P_phi};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraSphereVetical2( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical{P_theta, P_phi, P_radius};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_CameraSphereVetical_Theta( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_theta( P_theta );
  return 1;
 }

int IceRayC_CameraSphereVetical_Phi( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_phi( P_phi );
  return 0;
 }

int IceRayC_CameraSphereVetical_Radius( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 0;
 }


IceRayC_Camera_Handle IceRayC_CameraSphereHorizontal0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_horizontal{  };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraSphereHorizontal1( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_horizontal{ P_theta, P_phi, P_radius };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
}

int IceRayC_CameraSphereHorizontal_Phi( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_phi( P_phi );
  return 0;
 }

int IceRayC_CameraSphereHorizontal_Theta( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_theta( P_theta );
  return 0;
 }

int IceRayC_CameraSphereHorizontal_Radius( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 0;
 }

IceRayC_Camera_Handle IceRayC_CameraSphereFisheye0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_fisheye{  };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraSphereFisheye1( IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_fisheye{ P_phi, P_theta };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraSphereFisheye2( IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_fisheye{ P_phi, P_theta, P_radius };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_CameraSphereFisheye_Phi( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_phi )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_phi( P_phi );
  return 0;
 }

int IceRayC_CameraSphereFisheye_Theta( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_theta )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_theta( P_theta );
  return 0;
 }

int IceRayC_CameraSphereFisheye_Radius( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical Tf_vertical;

  auto I_this = dynamic_cast< Tf_vertical *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 0;
 }

IceRayC_Camera_Handle IceRayC_CameraSpherePackage1( IceRayC_TypeScalar P_hfov, IceRayC_TypeScalar P_vfov )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_package{  };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraTrasformAffine0( )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine{  };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraTrasformAffine1( IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine{ reinterpret_cast<Tf__pure*> ( P_child ) };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_CameraTrasformAffine_Child( IceRayC_Camera_Handle P_this, IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine Tf_affine;

  auto I_this = dynamic_cast< Tf_affine *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( reinterpret_cast<Tf__pure*> ( P_child ) );
  return 1;
 }


IceRayC_Camera_Handle IceRayC_CameraDOFFocus0()
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus{};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraDOFFocus1( IceRayC_TypeSize P_sample, IceRayC_TypeInterval1D P_aperture, IceRayC_TypeInterval1D P_focus, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus{ P_sample, c2cpp( P_aperture ), c2cpp(P_focus), P_gauss };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraDOFFocus2( IceRayC_Camera_Handle P_child, IceRayC_TypeSize P_sample, IceRayC_TypeInterval1D P_aperture, IceRayC_TypeInterval1D P_focus, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus{ reinterpret_cast<Tf__pure*> ( P_child ), P_sample, c2cpp( P_aperture ), c2cpp(P_focus), P_gauss };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int            IceRayC_CameraDOFFocus_Aperture( IceRayC_Camera_Handle P_this, IceRayC_TypeInterval1D P_aperture )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus Tf_focus;

  auto I_this = dynamic_cast< Tf_focus *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aperture( c2cpp( P_aperture ) );
  return 1;
 }

int IceRayC_CameraDOFFocus_Focus( IceRayC_Camera_Handle P_this, IceRayC_TypeInterval1D P_focus )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus Tf_focus;

  auto I_this = dynamic_cast< Tf_focus *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_focus( c2cpp( P_focus ) );
  return 1;
 }

int IceRayC_CameraDOFFocus_Gauss( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_focus Tf_focus;

  auto I_this = dynamic_cast< Tf_focus *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_gauss( P_gauss );
  return 1;
 }

IceRayC_Camera_Handle IceRayC_CameraDOFCone0()
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone{  };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraDOFCone1( IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture )
{
    typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
    auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone{ P_sample, P_aperture };
    return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
}

IceRayC_Camera_Handle IceRayC_CameraDOFCone2( IceRayC_Camera_Handle P_child, IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone{ reinterpret_cast<Tf__pure*> ( P_child ), P_sample, P_aperture };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraDOFCone3( IceRayC_Camera_Handle P_child, IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone{ reinterpret_cast<Tf__pure*> ( P_child ), P_sample, P_aperture, P_gauss };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_CameraDOFConus_Sample( IceRayC_Camera_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone Tf_conus;

  auto I_this = dynamic_cast< Tf_conus *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sample( P_sample );
  return 1;
 }

int IceRayC_CameraDOFConus_Aperture( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_aperture )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone Tf_conus;

  auto I_this = dynamic_cast< Tf_conus *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aperture( P_aperture );
  return 1;
 }

int IceRayC_CameraDOFConus_Gauss( IceRayC_Camera_Handle P_this, IceRayC_TypeScalar P_gauss )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_dof::GC_cone Tf_conus;

  auto I_this = dynamic_cast< Tf_conus *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_aperture( P_gauss );
  return 1;
 }


IceRayC_Camera_Handle IceRayC_CameraTransformInvert0()
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_transform::GC_invert{};
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

IceRayC_Camera_Handle IceRayC_CameraTransformInvert1( IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_camera::S_transform::GC_invert{ reinterpret_cast<Tf__pure*> ( P_child ) };
  return reinterpret_cast<IceRayC_Camera_Handle>( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_CameraTransformInvert_Child( IceRayC_Camera_Handle P_this, IceRayC_Camera_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_invert Tf_invert;

  auto I_this = dynamic_cast< Tf_invert *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( reinterpret_cast<Tf__pure*> ( P_child ) );
  return 1;
 }
