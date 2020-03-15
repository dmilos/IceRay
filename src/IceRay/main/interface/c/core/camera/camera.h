#ifndef d9bc24244e734ac8b0a6a9b49357594b
#define d9bc24244e734ac8b0a6a9b49357594b

#include "../../system/system.h"
#include "../../type/scalar.h"
#include "../../type/interval.h"
#include "../../type/size.h"

typedef  void * IceRayC_Camera;

// TODO typedef struct IceRayC_Camera {} *IceRayC_Camera;

IceRayC__EXPORT IceRayC__DECLSPEC void IceRayC_Camera_Release( IceRayC_Camera P_this );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraFlatPerspective0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraFlatPerspective1( IceRayC_TypeScalar P_aspect );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraFlatPerspective2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_height );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraFlatSuper0( );

IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraFlatPerspective_Width(  IceRayC_Camera P_this, IceRayC_TypeScalar P_width );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraFlatPerspective_Height( IceRayC_Camera P_this, IceRayC_TypeScalar P_height );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraFlatPerspective_Aspect( IceRayC_Camera P_this, IceRayC_TypeScalar P_aspect );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraFlatOrthogonal0( );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraFlatOrthogonal_Width(  IceRayC_Camera P_this, IceRayC_TypeScalar P_width );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraFlatOrthogonal_Height( IceRayC_Camera P_this, IceRayC_TypeScalar P_height );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraFlatOrthogonal_Aspect( IceRayC_Camera P_this, IceRayC_TypeScalar P_aspect );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraCylinderHorizontal0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraCylinderHorizontal1( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraCylinderHorizontal2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraCylinderHorizontal_Width( IceRayC_Camera P_this,IceRayC_TypeScalar P_width );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraCylinderHorizontal_Theta( IceRayC_Camera P_this,IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraCylinderHorizontal_Radius( IceRayC_Camera P_this,IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraCylinderVertical( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraCylinderVertical1( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraCylinderVertical2( IceRayC_TypeScalar P_width, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraCylinderVertical_Phi( IceRayC_Camera P_this,IceRayC_TypeScalar P_phi);
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraCylinderVertical_Height( IceRayC_Camera P_this,IceRayC_TypeScalar P_height);
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraCylinderVertical_Radius( IceRayC_Camera P_this,IceRayC_TypeScalar P_radius);
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSphereVetical0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSphereVetical1( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSphereVetical2( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereVetical_Theta( IceRayC_Camera P_this, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereVetical_Phi(IceRayC_Camera P_this, IceRayC_TypeScalar P_width );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereVetical_Radius( IceRayC_Camera P_this, IceRayC_TypeScalar P_height );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSphereHorizontal0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSphereHorizontal1( IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereHorizontal_Phi(IceRayC_Camera P_this, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_phi );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereHorizontal_Theta( IceRayC_Camera P_this, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereHorizontal_Radius( IceRayC_Camera P_this, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSphereFisheye0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSphereFisheye1( IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSphereFisheye2( IceRayC_TypeScalar P_phi, IceRayC_TypeScalar P_theta, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereFisheye_Phi( IceRayC_Camera P_this, IceRayC_TypeScalar P_phi );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereFisheye_Theta( IceRayC_Camera P_this, IceRayC_TypeScalar P_theta );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraSphereFisheye_Radius( IceRayC_Camera P_this, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraSpherePackage1( IceRayC_TypeScalar P_hfov, IceRayC_TypeScalar P_vfov );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraTrasformAffine0( );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraTrasformAffine1( IceRayC_Camera P_child );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraDOFFocus0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraDOFFocus1(  IceRayC_TypeSize P_sample, IceRayC_TypeInterval1D P_aperture, IceRayC_TypeInterval1D P_focus, IceRayC_TypeScalar P_gauss );
IceRayC__EXPORT IceRayC__DECLSPEC int            IceRayC_CameraDOFFocus_Aperture( IceRayC_Camera P_this, IceRayC_TypeScalar P_focus );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraDOFFocus_Focus( IceRayC_Camera P_this, IceRayC_TypeScalar P_focus );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraDOFFocus_Gauss( IceRayC_Camera P_this, IceRayC_TypeScalar P_gauss );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraDOFCone0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraDOFCone1( IceRayC_Camera child, IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraDOFCone2( IceRayC_Camera child, IceRayC_TypeSize P_sample, IceRayC_TypeScalar P_aperture, IceRayC_TypeScalar P_gauss );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraDOFConus_Sample( IceRayC_Camera P_this, IceRayC_TypeSize P_sample );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraDOFConus_Aperture( IceRayC_Camera P_this, IceRayC_TypeScalar P_aperture );
IceRayC__EXPORT IceRayC__DECLSPEC int IceRayC_CameraDOFConus_Gauss( IceRayC_Camera P_this, IceRayC_TypeScalar P_gauss );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraTransformInvert0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Camera IceRayC_CameraTransformInvert1( IceRayC_Camera P_child );
IceRayC__EXPORT IceRayC__DECLSPEC int            IceRayC_CameraTransformInvert_Child( IceRayC_Camera P_this, IceRayC_Camera P_child );


#endif
