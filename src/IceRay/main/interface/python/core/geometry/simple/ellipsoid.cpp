
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "IceRay/geometry/simple/ellipsoid.hpp"


#include "./simple.hpp"


void expose_IceRay_geometry_simple_ellipsoid()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::GC_ellipsoid        GTs_ellipsoid;

  typedef  bool (GTs_ellipsoid::*Tf_setCenter  )(GTs_coord3D const&);
  Tf_setCenter I_setCenter = &GTs_ellipsoid::F_center;

  boost::python::class_< GTs_ellipsoid, boost::python::bases<GTs__base> >( "GeometrySimpleEllipsoid" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D, GTs_coord3D>() )
    .def( boost::python::init<GTs_coord3D, GTs_coord3D, GTs_coord3D, GTs_coord3D>() )
    .def("center",  I_setCenter )
    ;

 }
