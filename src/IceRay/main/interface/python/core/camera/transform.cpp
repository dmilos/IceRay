
#include "../../def_submodule.hpp"

#include "./camera.hpp"
namespace {
using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

// typedef GS_DDMRM::S_IceRay::S_camera::GC__pure       GTs__pure;
// typedef GS_DDMRM::S_IceRay::S_camera::GC__parent     GTs__parent;

typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine       GTs_affine;


bool GFs_doTranslate( GTs_affine & P_affine, GTs_coord3D const& P_move )
 {
  GTs_affine::T_affine I_transform;

  ::math::linear::affine::id( I_transform );
  I_transform.vector() = P_move;

  GTs_affine::T_affine I_2world;
  ::math::linear::affine::compose( I_2world, I_transform, P_affine.F_2world() );

  P_affine.F_2world( I_2world );
  return true;
 }

bool GFs_doScale0( GTs_affine &P_affine, GTs_coord3D const& P_scale )
 {
  GTs_affine::T_affine I_transform;

  ::math::linear::affine::id( I_transform );
  I_transform.matrix()[0][0] = P_scale[0];
  I_transform.matrix()[1][1] = P_scale[1];
  I_transform.matrix()[2][2] = P_scale[2];

  GTs_affine::T_affine I_2world;
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

bool GFs_doRotate( GTs_affine & P_affine, GTs_coord3D const& P_pivot, GTs_coord3D const& P_direction, GTs_scalar const& P_angle )
 {
  GTs_affine::T_affine I_rotate;  ::math::linear::affine::rotate( I_rotate, P_pivot, P_direction, P_angle  );

  GTs_affine::T_affine I_2world; ::math::linear::affine::compose( I_2world, I_rotate, P_affine.F_2world()  );

  P_affine.F_2world( I_2world );

  return true;
 }

bool GFs_doSkewX( GTs_affine & P_affine, GTs_coord3D const& P_pivot, GTs_coord3D const& P_angle )
 {
   return true;
 }
}

void expose_IceRay_camera_transform_affine()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure                 Ts__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::GC__parent               Ts__parent;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_affine   Ts_affine;

  typedef  GTs_affine3D const& (Ts_affine::*Tf_getAffine3D)(void) const;
  typedef  bool (Ts_affine::*Tf_setAffine3D  )(GTs_affine3D const& );  
  
  Tf_getAffine3D I_getWorld = &Ts_affine::F_2world;
  Tf_setAffine3D I_setWorld = &Ts_affine::F_2world;
  Tf_getAffine3D I_getLocal = &Ts_affine::F_2local;
  Tf_setAffine3D I_setLocal = &Ts_affine::F_2local;

  boost::python::class_<Ts_affine, boost::python::bases<Ts__parent> >( "CameraTransformAffine" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Ts__pure*>() )
    .def( "world",  I_getWorld , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "world",  I_setWorld )
    .def( "local",  I_getLocal , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "local",  I_setLocal )
    .def("translate",  &GFs_doTranslate )
    .def("scale",      &GFs_doScaleX )
    .def("rotate",     &GFs_doRotate )
    .def("skew",       &GFs_doSkewX )
  ;

 }