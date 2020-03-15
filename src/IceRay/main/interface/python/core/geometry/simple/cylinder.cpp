
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/cylinder.hpp"


#include "./simple.hpp"



typedef GS_DDMRM::S_IceRay::S_geometry::GC_cylinder       GTs_cylinder;

void expose_IceRay_geometry_cylinder()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_scalar const& (GTs_cylinder::*Tf_getRadius)(void) const;
  Tf_getRadius I_getRadius = &GTs_cylinder::F_radius;

  typedef  bool (GTs_cylinder::*Tf_setRadius  )(GTs_scalar const&);
  Tf_setRadius I_setRadius = &GTs_cylinder::F_radius;

  boost::python::class_< GTs_cylinder, boost::python::bases<GTs__base> >( "GeometrySimpleCylinder" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar>() )
    .def( boost::python::init<GTs_scalar,GTs_scalar>() )
    .def("radius",  I_getRadius, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("radius",  I_setRadius      )

  ;

 }
