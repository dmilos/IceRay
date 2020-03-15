

#include "../../def_submodule.hpp"

#include "../../../../../light/_pure.hpp"


void expose_IceRay_light__Pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef GS_DDMRM::S_IceRay::S_light::GC__pure  Tf__pure;

  boost::python::class_<Tf__pure, boost::noncopyable>( "Light_pure", boost::python::no_init );
 }
