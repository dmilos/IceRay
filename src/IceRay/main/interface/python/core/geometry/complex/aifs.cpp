
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "IceRay/geometry/complex/aifs.hpp"


void expose_IceRay_geometry_complex_aifs()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base           Tf__base;
typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_AIFS           Tf_AIFS;

  boost::python::class_< Tf_AIFS, boost::python::bases<Tf__base> >( "GeometryComplexAIFS" )
    .def( boost::python::init<>() )
  ;

 }
