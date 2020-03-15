#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "./camera.hpp"

void expose_IceRay_camera_sphere_package()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_package           GTs_SpherePackage;


  typedef  GTs_scalar const& (GTs_SpherePackage::*Tf_getScalar)(void) const;
  typedef  bool (GTs_SpherePackage::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getPhi = &GTs_SpherePackage::F_horizontal;
  Tf_setScalar I_setPhi = &GTs_SpherePackage::F_horizontal;
  
  Tf_getScalar I_getTheta = &GTs_SpherePackage::F_vertical;
  Tf_setScalar I_setTheta = &GTs_SpherePackage::F_vertical;

  boost::python::class_<GTs_SpherePackage, boost::python::bases<GTs__pure> >("CameraSpherePackage" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar,GTs_scalar>() )
    // TODO .def( "hfov",  I_getPhi , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    // TODO .def( "hfov",  I_setPhi )
    // TODO .def( "vfov",  I_getTheta , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    // TODO .def( "vfov",  I_setTheta )
  ;

 }

void expose_IceRay_camera_sphere_fisheye()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_fisheye           GTs_SphereFisheye;


  typedef  GTs_scalar const& (GTs_SphereFisheye::*Tf_getScalar)(void) const;
  typedef  bool (GTs_SphereFisheye::*Tf_setScalar  )(GTs_scalar const&);

  // TODO Tf_getScalar I_getPhi = &GTs_SphereFisheye::F_horizontal;
  // TODO Tf_setScalar I_setPhi = &GTs_SphereFisheye::F_horizontal;
  
  // TODO Tf_getScalar I_getTheta = &GTs_SphereFisheye::F_vertical;
  // TODO Tf_setScalar I_setTheta = &GTs_SphereFisheye::F_vertical;

  boost::python::class_<GTs_SphereFisheye, boost::python::bases<GTs__pure> >("CameraSphereFisheye" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar,GTs_scalar>() )
    // TODO .def( "hfov",  I_getPhi , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    // TODO .def( "hfov",  I_setPhi )
    // TODO .def( "vfov",  I_getTheta , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    // TODO .def( "vfov",  I_setTheta )
  ;

 }
