
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/saddle.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_saddle         GTs_saddle;

void expose_IceRay_geometry_simple_saddle()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  boost::python::class_< GTs_saddle, boost::python::bases<GTs__base> >( "GeometrySimpleSaddle" )
    .def( boost::python::init<>() )
  ;

 }
