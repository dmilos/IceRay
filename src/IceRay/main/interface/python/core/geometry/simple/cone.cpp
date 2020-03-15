
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/cone.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_cone            GTs_cone;

void expose_IceRay_geometry_cone()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  boost::python::class_< GTs_cone, boost::python::bases<GTs__base> >( "GeometrySimpleCone" )
    .def( boost::python::init<>() )
  ;

 }
