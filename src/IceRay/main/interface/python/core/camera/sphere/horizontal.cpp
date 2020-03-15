#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "./camera.hpp"

void expose_IceRay_camera_sphere_horizontal()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_horizontal           GTs_sphereHorizontal;


  typedef  GTs_scalar const& (GTs_sphereHorizontal::*Tf_getScalar)(void) const;
  typedef  bool (GTs_sphereHorizontal::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getPhi = &GTs_sphereHorizontal::F_phi;
  Tf_setScalar I_setPhi = &GTs_sphereHorizontal::F_phi;

  Tf_getScalar I_getTheta = &GTs_sphereHorizontal::F_theta;
  Tf_setScalar I_setTheta = &GTs_sphereHorizontal::F_theta;

  // TODO Tf_getScalar I_getRadius = &GTs_sphereHorizontal::F_theta;
  // TODO Tf_setScalar I_setRadius = &GTs_sphereHorizontal::F_theta;

  boost::python::class_<GTs_sphereHorizontal, boost::python::bases<GTs__pure> >("CameraSpherePolarHorizontal" )
    .def( boost::python::init<>() )
    .def( "phi",  I_getPhi , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "phi",  I_setPhi )
    .def( "theta",  I_getTheta , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "theta",  I_setTheta )
    //TODO .def( "radius",  I_getRadius , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //TODO .def( "radius",  I_setRadius )
  ;

 }
