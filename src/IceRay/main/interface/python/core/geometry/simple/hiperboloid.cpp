
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/hyperboloid.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_hyperboloid         GTs_hyperboloid;

void expose_IceRay_geometry_simple_hyperboloid()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_scalar const& (GTs_hyperboloid::*Tf_getCore)(void) const;
  Tf_getCore I_getCore = &GTs_hyperboloid::F_core;

  typedef  bool (GTs_hyperboloid::*Tf_setCore  )(GTs_scalar const&);
  Tf_setCore I_setCore = &GTs_hyperboloid::F_core;

  boost::python::class_< GTs_hyperboloid, boost::python::bases<GTs__base> >( "GeometrySimpleHyperboloid" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar>() )
    .def("core",  I_getCore, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("core",  I_setCore      )
  ;
 }
