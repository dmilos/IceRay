
#include "../../def_submodule.hpp"

#include "./camera.hpp"

void expose_IceRay_camera_cone()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  typedef  GTs_size const& (GTs_cone::*Tf_getSize )(void) const;
  typedef  bool (GTs_cone::*Tf_setSize  )(GTs_size const&);

  Tf_getSize I_getSample = &GTs_cone::F_size;
  Tf_setSize I_setSample = &GTs_cone::Fv_size;

  typedef  GTs_scalar const& (GTs_cone::*Tf_getScalar)(void) const;
  typedef  bool (GTs_cone::*Tf_setScalar  )(GTs_scalar const&);  
  
  Tf_getScalar I_getGauss = &GTs_cone::F_gauss;
  Tf_setScalar I_setGauss = &GTs_cone::F_gauss;

  Tf_getScalar I_getAperture = &GTs_cone::F_aperture;
  Tf_setScalar I_setAperture = &GTs_cone::F_aperture;

  boost::python::class_<GTs_cone, boost::python::bases<GTs__parent> >( "CameraCone" )
    //.def( "load",     &load3<Tf_scalar3D::T_value >, boost::python::return_value_policy<boost::python::reference_existing_object>() )
    .def( "aperture", I_getAperture, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "aperture", I_setAperture )
    .def( "gauss",  I_getGauss , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "gauss",  I_setGauss )
    .def( "sample",  I_getSample, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "sample",  I_setSample)
  ;

 }