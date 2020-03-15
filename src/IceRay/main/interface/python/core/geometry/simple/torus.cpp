
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/torus.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_torus          GTs_torus;

void expose_IceRay_geometry_torus()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  //typedef  GTs_coord3D const& (GTs_torus::*Tf_getCenter  )(void) const;
  //Tf_getCenter I_getCenter = &GTs_torus::F_center;

  //typedef  bool (GTs_torus::*Tf_setCenter  )(GTs_coord3D const&);
  //Tf_setCenter I_setCenter = &GTs_torus::F_center;

  typedef  GTs_scalar const& (GTs_torus::*Tf_getMinor  )(void) const;
  Tf_getMinor I_getMinor = &GTs_torus::F_minor;

  typedef  bool (GTs_torus::*Tf_setMinor  )(GTs_scalar const&);
  Tf_setMinor I_setMinor = &GTs_torus::F_minor;

  boost::python::class_< GTs_torus, boost::python::bases<GTs__base> >( "GeometrySimpleTorus" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar>() )
    .def("minor",  I_getMinor, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("minor",  I_setMinor )
  //.def("center",  I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
  //.def("center",  I_setCenter )
  ;

 }
