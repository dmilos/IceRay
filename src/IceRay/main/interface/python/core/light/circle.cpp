

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/circle.hpp"

typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_size GTs_size;

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_circle         GTs_circle;


void expose_IceRay_light_Circle()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef  GTs_spot const& (GTs_circle::*Tf_getSpot  )(void) const;
  Tf_getSpot I_getSpot = &GTs_circle::F_spot;
  typedef  bool (GTs_circle::*Tf_setSpot  )(GTs_spot const&);
  Tf_setSpot I_setSpot = &GTs_circle::F_spot;

  typedef  GTs_coord3D const& (GTs_circle::*Tf_getCoord  )(void) const;
  typedef  bool (GTs_circle::*Tf_setCoord  )(GTs_coord3D const&);

  Tf_getCoord I_getX = &GTs_circle::F_x;
  Tf_setCoord I_setX = &GTs_circle::F_x;
  Tf_getCoord I_getY = &GTs_circle::F_y;
  Tf_setCoord I_setY = &GTs_circle::F_y;
  
  typedef  GTs_size const& (GTs_circle::*Tf_getSize )(void) const;
  typedef  bool (GTs_circle::*Tf_setSize  )(GTs_size const&);
  Tf_getSize I_getSample = &GTs_circle::F_sample;
  Tf_setSize I_setSample = &GTs_circle::F_sample;

  Tf_getCoord I_getPosition = &GTs_circle::F_center;
  Tf_setCoord I_setPosition = &GTs_circle::F_center;

  boost::python::class_<GTs_circle, boost::python::bases<GTs__pure> >( "LightCircle" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_spot, GTs_coord3D, GTs_coord3D, GTs_size >() )
    .def("spot",   I_getSpot, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("spot",   I_setSpot    )
    .def("center",   I_getPosition, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("center",   I_setPosition      )
    .def("x",      I_getX, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("x",      I_setX      )
    .def("y",      I_getY, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("y",      I_setY      )
    .def("sample",  I_getSample, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("sample",  I_setSample      )
   ;

 }
