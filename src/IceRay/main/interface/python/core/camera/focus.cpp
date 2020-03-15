
#include "../../def_submodule.hpp"

#include "./camera.hpp"


void expose_IceRay_camera_focus()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef  GTs_size const& (GTs_focus::*Tf_getSize )(void) const;
  typedef  bool (GTs_focus::*Tf_setSize  )(GTs_size const&);

  Tf_getSize I_getSample = &GTs_focus::F_sample;
  Tf_setSize I_setSample = &GTs_focus::F_sample;

  typedef  GTs_scalar const& (GTs_focus::*Tf_getScalar)(void) const;
  typedef  bool (GTs_focus::*Tf_setScalar  )(GTs_scalar const&);  

  Tf_getScalar I_getGauss = &GTs_focus::F_gauss;
  Tf_setScalar I_setGauss = &GTs_focus::F_gauss;

  typedef  GTs_interval1D const& (GTs_focus::*Tf_getInterval1D)(void) const;
  typedef  bool (GTs_focus::*Tf_setInterval1D  )(GTs_interval1D const& );  
  
  Tf_getInterval1D I_getAperture = &GTs_focus::F_aperture;
  Tf_setInterval1D I_setAperture = &GTs_focus::F_aperture;
  Tf_getInterval1D I_getFocus    = &GTs_focus::F_focus;
  Tf_setInterval1D I_setFocus    = &GTs_focus::F_focus;

  boost::python::class_<GTs_focus, boost::python::bases<GTs__parent> >("CameraFocus" )
    .def( "gauss",  I_getGauss , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "gauss",  I_setGauss )
    .def( "sample",  I_getSample, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "sample",  I_setSample)
    .def( "aperture",  I_getAperture, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "aperture",  I_setAperture)
    .def( "focus",  I_getFocus, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "focus",  I_setFocus)
  ;

 }