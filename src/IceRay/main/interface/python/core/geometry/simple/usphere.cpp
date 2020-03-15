
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "IceRay/geometry/simple/usphere.hpp"


#include "./simple.hpp"


void expose_IceRay_geometry_simple_usphere()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_usphere        GTs_usphere;


  boost::python::class_< GTs_usphere, boost::python::bases<GTs__base> >( "GeometrySimpleUSphere" )
    .def( boost::python::init<>() )
  ;

 }
