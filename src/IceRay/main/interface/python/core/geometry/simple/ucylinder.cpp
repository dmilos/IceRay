
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "IceRay/geometry/simple/ucylinder.hpp"


#include "./simple.hpp"


void expose_IceRay_geometry_simple_ucylinder()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

typedef GS_DDMRM::S_IceRay::S_geometry::GC_ucylinder       GTs_ucylinder;


  boost::python::class_< GTs_ucylinder, boost::python::bases<GTs__base> >( "GeometrySimpleUCylinder" )
    .def( boost::python::init<>() )
  ;

 }
