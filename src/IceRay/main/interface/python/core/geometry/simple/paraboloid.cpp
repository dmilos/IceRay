
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/paraboloid.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_paraboloid         GTs_paraboloid;

void expose_IceRay_geometry_simple_paraboloid()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  boost::python::class_< GTs_paraboloid, boost::python::bases<GTs__base> >( "GeometrySimpleParaboloid" )
    .def( boost::python::init<>() )
  ;

 }
