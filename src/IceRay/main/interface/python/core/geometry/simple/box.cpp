
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/box.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_box            GTs_box;

void expose_IceRay_geometry_box()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );


  typedef  GTs_coord3D const& (GTs_box::*Tf_getLo  )(void) const;
  Tf_getLo I_getLo = &GTs_box::F_lo;

  typedef  bool (GTs_box::*Tf_setLo  )(GTs_coord3D const&);
  Tf_setLo I_setLo = &GTs_box::F_lo;

  typedef  GTs_coord3D const& (GTs_box::*Tf_getHi)(void) const;
  Tf_getHi I_getHi = &GTs_box::F_hi;

  typedef  bool (GTs_box::*Tf_setHi  )(GTs_coord3D const&);
  Tf_setHi I_setHi = &GTs_box::F_hi;

  typedef  bool (GTs_box::*Tf_setBoxI  )(GTs_box::T_box const&);
  Tf_setBoxI I_setBoxI = &GTs_box::F_load;

  typedef  bool (GTs_box::*Tf_setBoxVV  )(GTs_coord3D const&,GTs_coord3D const&);
  Tf_setBoxVV I_setBoxVV = &GTs_box::F_load;

  boost::python::class_< GTs_box, boost::python::bases<GTs__base> >( "GeometrySimpleBox" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D, GTs_coord3D>() )
    .def("lo",  I_getLo, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("lo",  I_setLo )
    .def("hi",  I_getHi, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("hi",  I_setHi )
    .def("load", I_setBoxI )
    .def("load", I_setBoxVV )
  ;

 }
