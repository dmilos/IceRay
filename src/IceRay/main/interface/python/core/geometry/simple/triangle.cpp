
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/flat/triangle.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_triangle       GTs_triangle;

void expose_IceRay_geometry_triangle()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_coord3D const& (GTs_triangle::*Tf_getCoord )(void) const;
  Tf_getCoord I_getOrigin = &GTs_triangle::F_origin;
  Tf_getCoord I_getEX = &GTs_triangle::F_eX;
  Tf_getCoord I_getEY = &GTs_triangle::F_eY;

  typedef  bool (GTs_triangle::*Tf_setCoord  )(GTs_coord3D const&);
  Tf_setCoord I_setOrigin = &GTs_triangle::F_origin;
  Tf_setCoord I_setEX     = &GTs_triangle::F_eX;
  Tf_setCoord I_setEY     = &GTs_triangle::F_eY;

  boost::python::class_< GTs_triangle, boost::python::bases<GTs__base> >( "GeometrySimpleTriangle" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D,GTs_coord3D,GTs_coord3D>() )
    .def("origin",  I_getOrigin, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("origin",  I_setOrigin )
    .def("eX",  I_getEX, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("eX",  I_setEX )
    .def("eY",  I_getEY, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("eY",  I_setEY )
  ;

 }
