#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "../camera.hpp"

void expose_IceRay_camera_flat_perspective()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef  GTs_scalar const& (GTs_perspective::*Tf_getScalar)(void) const;
  typedef  bool (GTs_perspective::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getAspect = &GTs_perspective::F_aspect;
  Tf_setScalar I_setAspect = &GTs_perspective::F_aspect;

  Tf_getScalar I_getWidth = &GTs_perspective::F_width;
  Tf_setScalar I_setWidth = &GTs_perspective::F_width;

  Tf_getScalar I_getHeight = &GTs_perspective::F_height;
  Tf_setScalar I_setHeight = &GTs_perspective::F_height;

  //TODO Tf_getScalar I_getHFov = &GTs_perspective::F_HFov;
  //TODO Tf_setScalar I_setHFov = &GTs_perspective::F_HFov;
  //TODO Tf_getScalar I_getVFov = &GTs_perspective::F_VFov;
  //TODO Tf_setScalar I_setVFov = &GTs_perspective::F_VFov;
  //TODO Tf_getScalar I_getDFov = &GTs_perspective::F_VDov;
  //TODO Tf_setScalar I_setDFov = &GTs_perspective::F_VDov;


  typedef boost::python::class_<GTs_perspective, boost::python::bases<GTs__pure> > Tf_this;

  boost::python::object  I_this = Tf_this( "CameraFlatPerspective" )
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


void expose_IceRay_camera_flat_super()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D      Ts_coord2D;
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super        Ts_super;

  typedef  Ts_coord2D const& (Ts_super::*Tf_getCoord2D)(void) const;
  typedef  bool              (Ts_super::*Tf_setCoord2D )(Ts_coord2D const&);

  typedef boost::python::class_<Ts_super, boost::python::bases<GTs__pure> > Tf_this;

  boost::python::object  I_this = Tf_this( "CameraFlatSuper" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Ts_coord2D,Ts_coord2D>() )
  ;
 }
