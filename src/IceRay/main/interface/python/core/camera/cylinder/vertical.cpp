#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "./camera.hpp"

void expose_IceRay_camera_cylinder_vertical()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef GS_DDMRM::S_IceRay::S_camera::S_cylinder::GC_vertical           GTs_cylinderVertical;


  typedef  GTs_scalar const& (GTs_cylinderVertical::*Tf_getScalar)(void) const;
  typedef  bool (GTs_cylinderVertical::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getPhi = &GTs_cylinderVertical::F_phi;
  Tf_setScalar I_setPhi = &GTs_cylinderVertical::F_phi;

  Tf_getScalar I_getHeight = &GTs_cylinderVertical::F_height;
  Tf_setScalar I_setHeight = &GTs_cylinderVertical::F_height;

  Tf_getScalar I_getRadius = &GTs_cylinderVertical::F_radius;
  Tf_setScalar I_setRadius = &GTs_cylinderVertical::F_radius;

  boost::python::class_<GTs_cylinderVertical, boost::python::bases<GTs__pure> >("CameraCylinderVertical" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar,GTs_scalar>() )
    .def( boost::python::init<GTs_scalar,GTs_scalar,GTs_scalar>() )
    .def( "height",  I_getHeight , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "height",  I_setHeight )
    .def( "phi",     I_getPhi , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "phi",     I_setPhi )
    .def( "radius",  I_getRadius , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "radius",  I_setRadius )
  ;

 }
