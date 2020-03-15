#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "./camera.hpp"

void expose_IceRay_camera_cylinder_horizontal()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_horizontal           GTs_cylinderHorizontal;

  typedef  GTs_scalar const& (GTs_cylinderHorizontal::*Tf_getScalar)(void) const;
  typedef  bool (GTs_cylinderHorizontal::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getTheta = &GTs_cylinderHorizontal::F_theta;
  Tf_setScalar I_setTheta = &GTs_cylinderHorizontal::F_theta;

  Tf_getScalar I_getWidth = &GTs_cylinderHorizontal::F_width;
  Tf_setScalar I_setWidth = &GTs_cylinderHorizontal::F_width;

  Tf_getScalar I_getRadius = &GTs_cylinderHorizontal::F_radius;
  Tf_setScalar I_setRadius = &GTs_cylinderHorizontal::F_radius;

  boost::python::class_<GTs_cylinderHorizontal, boost::python::bases<GTs__pure> >("CameraCylinderHorizontal" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar,GTs_scalar>() )
    .def( boost::python::init<GTs_scalar,GTs_scalar,GTs_scalar>() )
    .def( "theta",  I_getTheta , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "theta",  I_setTheta )
    .def( "width",  I_getWidth , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "width",  I_setWidth )
    .def( "radius", I_getRadius , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "radius", I_setRadius )
  ;

 }
