
#include "../../def_submodule.hpp"

#include "./camera.hpp"

void expose_IceRay_camera__pure()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );

  //typedef  GTs_size const& (GTs__pure::*Tf_getSize )(void) const;
  //typedef  bool (GTs__pure::*Tf_setSize  )(GTs_size const&);

  //Tf_getSize I_getSample = &GTs__pure::F_size;
  //Tf_setSize I_setSample = &GTs__pure::Fv_size;

  boost::python::class_<GTs__pure, boost::noncopyable>( "Camera_pure", boost::python::no_init )
   //.def( "size",  I_getSample, boost::python::return_value_policy<boost::python::copy_const_reference>() )
   //.def( "size",  I_setSample)

  ;
 }
