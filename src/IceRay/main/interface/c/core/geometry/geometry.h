#ifndef a4ff2885f266411bb260d2e1749a7b7e
#define a4ff2885f266411bb260d2e1749a7b7e

#include "../../system/system.h"
#include "../../type/type.h"


struct  IceRayC_Geometry_Struct {};
typedef IceRayC_Geometry_Struct* IceRayC_Geometry_Handle;


IceRayC__EXPORT IceRayC__DECLSPEC  void IceRayC_Geometry__Release( IceRayC_Geometry_Handle );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Sphere0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Sphere1( IceRayC_TypeCoord3D center, IceRayC_TypeScalar radius );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Sphere_Center( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Sphere_Radius( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar radius );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_USphere();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Box0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Box1( IceRayC_TypeCoord3D lo, IceRayC_TypeCoord3D hi );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Torus0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Torus1( IceRayC_TypeScalar P_minor );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Torus_Minor( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_minor );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Triangle0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Triangle1( IceRayC_TypeCoord3D e0, IceRayC_TypeCoord3D ex, IceRayC_TypeCoord3D ey );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Smoke0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Smoke1( IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi, IceRayC_TypeScalar P_density );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_MotionBlur0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_MotionBlur_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Plane0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Plane( IceRayC_TypeCoord3D P_origin, IceRayC_TypeCoord3D P_normal );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_HField();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Disc0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Disc1(  IceRayC_TypeCoord3D P_center, IceRayC_TypeCoord3D P_normal, IceRayC_TypeScalar P_radius );

IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Center( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_center );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Normal( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_normal );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Disc_Radius( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_radius );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Cylinder0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Cone0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Paraboloid0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Hyperboloid1( IceRayC_TypeScalar P_core );
IceRayC__EXPORT IceRayC__DECLSPEC  int              IceRayC_Geometry_Hyperboloid_Core( IceRayC_Geometry_Handle P_this, IceRayC_TypeScalar P_core );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Saddle0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect1( IceRayC_Geometry_Handle P_left, IceRayC_Geometry_Handle P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Left0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_left );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Left1( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_left, int location );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Right0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_right );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Complex_Intersect_Right1( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_right, int location );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Identity0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Identity1(      IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Identity_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Affine0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Affine1( IceRayC_Geometry_Handle child, IceRayC_TypeAffine3D P_affine );
//IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Affine2( IceRayC_Geometry_Handle child, IceRayC_TypeMatric3D P_affine, IceRayC_TypeCoord3D P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Affine_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Affine_Affine( IceRayC_Geometry_Handle P_this, IceRayC_TypeAffine3D P_affine );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Affine_Scale( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_origin, IceRayC_TypeCoord3D P_scale );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Affine_Translate( IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D P_move );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Translate0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Translate1(      IceRayC_Geometry_Handle P_child, IceRayC_TypeCoord3D translation );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Translate_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle child );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_Translate_Move(  IceRayC_Geometry_Handle P_this, IceRayC_TypeCoord3D translation );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum0();
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Volumetric_Vacuum1( IceRayC_TypeCoord3D P_lo, IceRayC_TypeCoord3D P_hi );


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_System0( );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_System_RTSS( IceRayC_Geometry_Handle  P_system, IceRayC_Geometry_Handle* P_rtss );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_System_Add( IceRayC_Geometry_Handle  P_system, IceRayC_Geometry_Handle* P_element );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_Sphere0( IceRayC_TypeCoord3D P_center, IceRayC_TypeScalar P_influence, IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_USphere0( IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_UCylinderZ0( IceRayC_TypeScalar P_radius );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_UWaterZ0( IceRayC_TypeScalar P_level );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_Translate0( IceRayC_Geometry_Handle P_element, IceRayC_TypeCoord3D P_translate );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_Blobby_Affine0( IceRayC_Geometry_Handle P_element, IceRayC_TypeAffine3D P_affine );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_Object0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_RTSS_Object_Rtss0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_List0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_RTSS_Uniform0(  );
IceRayC__EXPORT IceRayC__DECLSPEC  int                     IceRayC_Geometry_RTSS_Uniform_Size( IceRayC_Geometry_Handle P_this, IceRayC_TypeSize3D P_size );



#endif
