
#include "../../def_submodule.hpp"

#include "./camera.hpp"

void expose_IceRay_camera__parent()
 {
  using namespace GS_DDMRM::S_IceRay::S_main::S_interface::S_python;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( camera );


  typedef  GTs__pure const& (GTs__parent::*Tf_getChild )(void) const;
  typedef  bool (GTs__parent::*Tf_setChild  )( GTs__pure * );
  Tf_getChild I_getChild = &GTs__parent::F_child;
  Tf_setChild I_setChild = &GTs__parent::F_child;


  boost::python::class_<GTs__parent, boost::python::bases<GTs__pure> >("Camera_parent" )
    .def( "child",     I_getChild, boost::python::return_internal_reference<>() )
    .def( "child",     I_setChild      )
  ;

 }
