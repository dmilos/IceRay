
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/sphere.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_sphere         GTs_sphere;

void expose_IceRay_geometry_sphere()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_coord3D const& (GTs_sphere::*Tf_getCenter  )(void) const;
  Tf_getCenter I_getCenter = &GTs_sphere::F_center;

  typedef  bool (GTs_sphere::*Tf_setCenter  )(GTs_coord3D const&);
  Tf_setCenter I_setCenter = &GTs_sphere::F_center;

  typedef  GTs_scalar const& (GTs_sphere::*Tf_getRadius)(void) const;
  Tf_getRadius I_getRadius = &GTs_sphere::F_radius;

  typedef  bool (GTs_sphere::*Tf_setRadius  )(GTs_scalar const&);
  Tf_setRadius I_setRadius = &GTs_sphere::F_radius;

  boost::python::class_< GTs_sphere, boost::python::bases<GTs__base> >( "GeometrySimpleSphere" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D>() )
    .def( boost::python::init<GTs_coord3D, GTs_scalar>() )
    .add_property("center", boost::python::make_function( I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>() ), I_setCenter )
    .add_property("radius", boost::python::make_function( I_getRadius, boost::python::return_value_policy<boost::python::copy_const_reference>() ), I_setRadius )
    //.def("center",  I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    //.def("center",  I_setCenter )
    //.def("radius",  I_getRadius, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    //.def("radius",  I_setRadius      )
  ;

 }
