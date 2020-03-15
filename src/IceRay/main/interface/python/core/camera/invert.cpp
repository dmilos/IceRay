
#include "../../def_submodule.hpp"

#include "./camera.hpp"

void expose_IceRay_camera_transform_invert()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );


  typedef GS_DDMRM::S_IceRay::S_camera::GC__pure                 Ts__pure;
  typedef GS_DDMRM::S_IceRay::S_camera::GC__parent               Ts__parent;
  typedef GS_DDMRM::S_IceRay::S_camera::S_transform::GC_invert   Ts_invert;

  boost::python::class_<Ts_invert, boost::python::bases<Ts__parent> >("CameraTransformInvert" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Ts__pure*>() )

  ;

 }
