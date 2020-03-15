
#include "../../../def_submodule.hpp"

#include "IceRay/geometry/blobby/uwaterZ.hpp"
#include "IceRay/geometry/blobby/usphere.hpp"
#include "IceRay/geometry/blobby/ucylinderZ.hpp"
#include "IceRay/geometry/blobby/sphere.hpp"
#include "IceRay/geometry/blobby/_element.hpp"
#include "IceRay/geometry/blobby/translate.hpp"
#include "IceRay/geometry/blobby/affine.hpp"

#include "IceRay/geometry/blobby/system.hpp"

typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D   GTs_coord3D;
//typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D  GTs_matrix3D;
typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D  GTs_affine3D;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              GTs_scalar;

typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_uwaterZ       GTs_uwaterZ;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_usphere      GTs_usphere;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_ucylinderZ   GTs_ucylinderZ;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_sphere   GTs_sphere;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_translate   GTs_translate;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_affine      GTs_affine;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base              GTs__base;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC__element GTs__element;
typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::GC_system       GTs_system;


void expose_IceRay_geometry_blobby___pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( blobby );

  boost::python::class_<GTs__element, boost::noncopyable>( "GeometryBlobby_Element", boost::python::no_init )
    // TODO .def( "interval", &Tf__base::F_box, boost::python::return_value_policy<boost::python::copy_const_reference>() )
  ;

 }


void expose_IceRay_geometry_blobby_system()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( blobby );


  boost::python::class_< GTs_system, boost::python::bases<GTs__base> >( "GeometryBlobbySystem" )
    .def( boost::python::init<>() )
    .def( "add",  &GTs_system::F_add )
    .def( "rtss", &GTs_system::F_rtss)
  ;

 }

void expose_IceRay_geometry_blobby_sphere()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( blobby );

  typedef  GTs_coord3D const& (GTs_sphere::*Tf_getCenter  )(void) const;
  Tf_getCenter I_getCenter = &GTs_sphere::F_center;

  typedef  bool (GTs_sphere::*Tf_setCenter  )(GTs_coord3D const&);
  Tf_setCenter I_setCenter = &GTs_sphere::F_center;

  typedef  GTs_scalar const& (GTs_sphere::*Tf_getScalar)(void) const;
  typedef  bool (GTs_sphere::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getRadius = &GTs_sphere::F_radius;
  Tf_setScalar I_setRadius = &GTs_sphere::F_radius;

  Tf_getScalar I_getInfluence = &GTs_sphere::F_influence;
  Tf_setScalar I_setInfluence = &GTs_sphere::F_influence;

  boost::python::class_< GTs_sphere, boost::python::bases<GTs__element> >( "GeometryBlobbySphere" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D >() )
    .def( boost::python::init<GTs_coord3D, GTs_scalar, GTs_scalar>() )
    .def( "center",  I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "center",  I_setCenter )
    .def( "radius",  I_getRadius, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "radius",  I_setRadius )
    .def( "influence",  I_getInfluence, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "influence",  I_setInfluence )
  ;

 }

void expose_IceRay_geometry_blobby_ucylinderZ()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( blobby );

  typedef  GTs_scalar const& (GTs_ucylinderZ::*Tf_getScalar)(void) const;
  typedef  bool (GTs_ucylinderZ::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getRadius = &GTs_ucylinderZ::F_radius;
  Tf_setScalar I_setRadius = &GTs_ucylinderZ::F_radius;

  boost::python::class_< GTs_ucylinderZ, boost::python::bases<GTs__element> >( "GeometryBlobbyUCylinderZ" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar>() )
    .def( "radius",  I_getRadius, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "radius",  I_setRadius )
  ;

 }

void expose_IceRay_geometry_blobby_usphere()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( blobby );

  typedef  GTs_scalar const& (GTs_usphere::*Tf_getScalar)(void) const;
  typedef  bool (GTs_usphere::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getRadius = &GTs_usphere::F_radius;
  Tf_setScalar I_setRadius = &GTs_usphere::F_radius;

  boost::python::class_< GTs_usphere, boost::python::bases<GTs__element> >( "GeometryBlobbyUSphere" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar>() )
    .def( "radius",  I_getRadius, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "radius",  I_setRadius )
  ;

 }

void expose_IceRay_geometry_blobby_uwaterZ()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( blobby );

  typedef  GTs_scalar const& (GTs_uwaterZ::*Tf_getScalar)(void) const;
  typedef  bool (GTs_uwaterZ::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getLevel = &GTs_uwaterZ::F_level;
  Tf_setScalar I_setLevel = &GTs_uwaterZ::F_level;

  boost::python::class_< GTs_uwaterZ, boost::python::bases<GTs__element> >( "GeometryBlobbyUWaterZ" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar>() )
    .def( "level",  I_getLevel, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "level",  I_setLevel )
  ;

 }

void expose_IceRay_geometry_blobby_translate()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( blobby );

  typedef  GTs_coord3D const& (GTs_translate::*Tf_getMove  )(void) const;
  Tf_getMove I_getMove = &GTs_translate::F_move;

  typedef  bool (GTs_translate::*Tf_setMove  )(GTs_coord3D const&);
  Tf_setMove I_setMove = &GTs_translate::F_move;

  boost::python::class_< GTs_translate, boost::python::bases<GTs__element> >( "GeometryBlobbyTranslate" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__element*>() )
    .def( boost::python::init<GTs__element*, GTs_coord3D>() )
    .def( "move",  I_getMove, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "move",  I_setMove )
  ;

 }
 namespace {
bool GFs_doTranslate( GTs_affine & P_affine, GTs_coord3D const& P_move )
 {
  GTs_affine3D I_transform;

  ::math::linear::affine::id( I_transform );
  I_transform.vector() = P_move;

  GTs_affine3D I_2world;
  ::math::linear::affine::compose( I_2world, I_transform, P_affine.F_2world() );

  P_affine.F_2world( I_2world );
  return true;
 }

bool GFs_doScale0( GTs_affine &P_affine, GTs_coord3D const& P_scale )
 {
  GTs_affine3D I_transform;

  ::math::linear::affine::id( I_transform );
  I_transform.matrix()[0][0] = P_scale[0];
  I_transform.matrix()[1][1] = P_scale[1];
  I_transform.matrix()[2][2] = P_scale[2];

  GTs_affine3D I_2world;
  ::math::linear::affine::compose( I_2world, I_transform, P_affine.F_2world() );

  P_affine.F_2world( I_2world );
  return true;
 }

bool GFs_doScaleX( GTs_affine & P_affine, GTs_coord3D const& P_pivot, GTs_coord3D const& P_scale )
 {
  using namespace ::math::linear::vector;
  GFs_doTranslate( P_affine, -P_pivot );
  GFs_doScale0( P_affine, P_scale );
  GFs_doTranslate( P_affine, P_pivot );

  return true;
 }

bool GFs_doRotate( GTs_affine * P_affine, GTs_coord3D const& P_pivot, GTs_coord3D const& P_direction, GTs_scalar const& P_angle )
 {
  GTs_affine::T_affine I_rotate;  ::math::linear::affine::rotate( I_rotate, P_pivot, P_direction, P_angle  );

  GTs_affine::T_affine I_2world; ::math::linear::affine::compose( I_2world, I_rotate, P_affine->F_2world()  );

  P_affine->F_2world( I_2world );

  return true;
 }

 }
void expose_IceRay_geometry_blobby_affine()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( blobby );

  boost::python::class_< GTs_affine, boost::python::bases<GTs__element> >( "GeometryBlobbyAffine" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__element *>() )
    .def( boost::python::init<GTs__element *, GTs_affine3D>() )
  //def( boost::python::init<GTs__element *, GTs_matrix3D, GTs_coord3D>() )
    .def("translate",  &GFs_doTranslate )
    .def("scale",      &GFs_doScaleX )
    .def("rotate",     &GFs_doRotate )
    //.def("skew",       &GFs_doSkewX )
  ;

 }
