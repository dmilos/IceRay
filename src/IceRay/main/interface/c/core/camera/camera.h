#ifndef d9bc24244e734ac8b0a6a9b49357594b
#define d9bc24244e734ac8b0a6a9b49357594b

#include "../../system/system.h"
#include "../../type/scalar.h"
#include "../../type/interval.h"
#include "../../type/affine.h"
#include "../../type/size.h"
#include "../../type/coord.h"

struct  IceRayC_Camera_Struct {};
typedef IceRayC_Camera_Struct* IceRayC_Camera_Handle;

IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Camera_Release( IceRayC_Camera_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Flat_Perspective0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Flat_Perspective1( IceRayC_TypeScalar P_aspect );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Flat_Perspective2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_height );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Perspective_Width(  IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_width );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Perspective_Height( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_height );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Perspective_Aspect( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_aspect );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Flat_Super0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Super_Eye(        IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_eye );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Super_Ocular(     IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_ocular );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Super_View(       IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_view );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Super_Objective(  IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_objective );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Super_Focus(      IceRayC_Camera_Handle P_that, IceRayC_Type_Coord_Scalar2D* P_focus );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Flat_Orthogonal0( );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Orthogonal_Width(  IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_width );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Orthogonal_Height( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_height );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Flat_Orthogonal_Aspect( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_aspect );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Horizontal0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Horizontal1( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Horizontal2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Cylinder_Horizontal_Width(  IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_width );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Cylinder_Horizontal_Theta(  IceRayC_Camera_Handle P_that,IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Cylinder_Horizontal_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Vertical0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Vertical1( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Cylinder_Vertical2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Cylinder_Vertical_Phi(    IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_phi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Cylinder_Vertical_Height( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_height );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Cylinder_Vertical_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Vertical0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Vertical1( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Vertical2( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Vertical_Theta(  IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Vertical_Phi(    IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_phi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Vertical_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Horizontal0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Horizontal1( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Horizontal_Phi(    IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Horizontal_Theta(  IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Horizontal_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Fisheye0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Fisheye1( IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Fisheye2( IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Fisheye_Phi(    IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_phi );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Fisheye_Theta(  IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Sphere_Fisheye_Radius( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_radius );

// IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Sphere_Package1( IceRayC_TypeScalar P_hfov, IceRayC_TypeScalar P_vfov );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle       IceRayC_Camera_Transform_Affine0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle       IceRayC_Camera_Transform_Affine1( IceRayC_Camera_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle       IceRayC_Camera_Transform_Affine2( IceRayC_Camera_Handle P_child, IceRayC_Type_Math_Affine3D *P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Camera_Transform_Affine_Child(      IceRayC_Camera_Handle P_that, IceRayC_Camera_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Camera_Transform_Affine_2World_Get( IceRayC_Camera_Handle P_that, IceRayC_Type_Math_Affine3D * P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Camera_Transform_Affine_2World_Set( IceRayC_Camera_Handle P_that, IceRayC_Type_Math_Affine3D * P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Camera_Transform_Affine_2Local_Get( IceRayC_Camera_Handle P_that, IceRayC_Type_Math_Affine3D * P_2world );
IceRayC__EXPORT IceRayC__DECLSPEC  int                         IceRayC_Camera_Transform_Affine_2Local_Set( IceRayC_Camera_Handle P_that, IceRayC_Type_Math_Affine3D * P_2local );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_DOF_Focus0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_DOF_Focus1( IceRayC_TypeSize P_sample, IceRayC_TypeInterval1D P_aperture, IceRayC_TypeInterval1D P_focus, IceRayC_TypeScalar P_gauss );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_DOF_Focus2( IceRayC_Camera_Handle P_child,IceRayC_TypeSize P_sample, IceRayC_TypeInterval1D P_aperture, IceRayC_TypeInterval1D P_focus, IceRayC_TypeScalar P_gauss );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_DOF_Focus_Aperture( IceRayC_Camera_Handle P_that, IceRayC_TypeInterval1D P_aperture );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_DOF_Focus_Focus(    IceRayC_Camera_Handle P_that, IceRayC_TypeInterval1D P_focus );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_DOF_Focus_Gauss(    IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_gauss );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_DOF_Focus_Child(    IceRayC_Camera_Handle P_that, IceRayC_Camera_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_DOF_Cone0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_DOF_Cone1( IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_DOF_Cone2( IceRayC_Camera_Handle P_child, IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_DOF_Cone3( IceRayC_Camera_Handle P_child, IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture, IceRayC_TypeScalar P_gauss );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_DOF_Conus_Sample(   IceRayC_Camera_Handle P_that, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_DOF_Conus_Aperture( IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_aperture );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_DOF_Conus_Gauss(    IceRayC_Camera_Handle P_that, IceRayC_TypeScalar P_gauss );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_DOF_Conus_Child(    IceRayC_Camera_Handle P_that, IceRayC_Camera_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Transform_Invert0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Camera_Handle IceRayC_Camera_Transform_Invert1( IceRayC_Camera_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                   IceRayC_Camera_Transform_Invert_Child( IceRayC_Camera_Handle P_that, IceRayC_Camera_Handle P_child );


#endif
