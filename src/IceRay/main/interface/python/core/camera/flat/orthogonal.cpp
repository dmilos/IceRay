#include <boost/python.hpp>

#include "./camera.hpp"

void expose_IceRay_camera_flat_orthogonal()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef  GTs_scalar const& (GTs_orthogonal::*Tf_getScalar)(void) const;
  typedef  bool (GTs_orthogonal::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getAspect = &GTs_orthogonal::F_aspect;
  Tf_setScalar I_setAspect = &GTs_orthogonal::F_aspect;

  Tf_getScalar I_getWidth  = &GTs_orthogonal::F_width;
  Tf_setScalar I_setWidth  = &GTs_orthogonal::F_width;;

  Tf_getScalar I_getHeight = &GTs_orthogonal::F_height;
  Tf_setScalar I_setHeight = &GTs_orthogonal::F_height;

  boost::python::class_<GTs_orthogonal, boost::python::bases<GTs__pure> >( "CameraFlatOrthogonal" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar>() )
    .def( boost::python::init<GTs_scalar,GTs_scalar>() )
    .def("aspect",  I_getAspect, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("aspect",  I_setAspect  )
    .def("width",    I_getWidth, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("width",    I_setWidth  )
    .def("height",   I_getHeight, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("height",   I_setHeight  )
  ;
 }
