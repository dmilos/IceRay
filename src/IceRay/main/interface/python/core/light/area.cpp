

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/area.hpp"

typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_size GTs_size;

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_area           GTs_area;


void expose_IceRay_light_Area()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef  GTs_spot const& (GTs_area::*Tf_getSpot  )(void) const;
  Tf_getSpot I_getSpot = &GTs_area::F_spot;
  typedef  bool (GTs_area::*Tf_setSpot  )(GTs_spot const&);
  Tf_setSpot I_setSpot = &GTs_area::F_spot;

  typedef  GTs_coord3D const& (GTs_area::*Tf_getCoord  )(void) const;
  typedef  bool (GTs_area::*Tf_setCoord  )(GTs_coord3D const&);

  Tf_getCoord I_getOrigin = &GTs_area::F_origin;
  Tf_setCoord I_setOrigin = &GTs_area::F_origin;
  Tf_getCoord I_getX = &GTs_area::F_x;
  Tf_setCoord I_setX = &GTs_area::F_x;
  Tf_getCoord I_getY = &GTs_area::F_y;
  Tf_setCoord I_setY = &GTs_area::F_y;

  typedef  GTs_size const& (GTs_area::*Tf_getSize )(void) const;
  typedef  bool (GTs_area::*Tf_setSize  )(GTs_size const&);
  Tf_getSize I_getSample = &GTs_area::F_sample;
  Tf_setSize I_setSample = &GTs_area::F_sample;

  boost::python::class_<GTs_area, boost::python::bases<GTs__pure> >( "LightArea" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_spot,GTs_coord3D,GTs_coord3D>() )
    .def( boost::python::init<GTs_spot,GTs_coord3D,GTs_coord3D,GTs_size>() )
    .def("origin",   I_getOrigin, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("origin",   I_setOrigin    )

    .def("spot",   I_getSpot, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("spot",   I_setSpot    )
    .def("x",      I_getX, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("x",      I_setX      )
    .def("y",      I_getY, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("y",      I_setY      )
    .def("sample",  I_getSample, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("sample",  I_setSample      )
    ;

 }
