

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/reflector.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_reflector      GTs_reflector;


void expose_IceRay_light_Reflector()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef  GTs_scalar const& (GTs_reflector::*Tf_getScalar  )(void) const;
  typedef  bool (GTs_reflector::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getInner = &GTs_reflector::F_innner;
  Tf_setScalar I_setInner = &GTs_reflector::F_innner;

  Tf_getScalar I_getOutter = &GTs_reflector::F_outter;
  Tf_setScalar I_setOutter = &GTs_reflector::F_outter;

  typedef  GTs_spot const& (GTs_reflector::*Tf_getSpot  )(void) const;
  typedef  bool (GTs_reflector::*Tf_setSpot  )(GTs_spot const&);

  Tf_getSpot I_getSpot = &GTs_reflector::F_spot;
  Tf_setSpot I_setSpot = &GTs_reflector::F_spot;

  typedef  GTs_coord3D const& (GTs_reflector::*Tf_getCoord  )(void) const;
  typedef  bool (GTs_reflector::*Tf_setCoord  )(GTs_coord3D const&);

  Tf_getCoord I_getDirection = &GTs_reflector::F_direction;
  Tf_setCoord I_setDirection = &GTs_reflector::F_direction;

  Tf_getCoord I_getPosition = &GTs_reflector::F_position;
  Tf_setCoord I_setPosition = &GTs_reflector::F_position;

  boost::python::class_<GTs_reflector, boost::python::bases<GTs__pure> >( "LightReflector" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D, GTs_coord3D >() )
    .def( boost::python::init<GTs_coord3D, GTs_coord3D, GTs_scalar, GTs_scalar>() )
    .def( boost::python::init<GTs_spot, GTs_coord3D>() )
    .def( boost::python::init<GTs_spot, GTs_coord3D, GTs_scalar, GTs_scalar>() )
    .def("spot",     I_getSpot, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("spot",     I_setSpot      )
    .def("position",   I_getPosition, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("position",   I_setPosition      )
    .def("direction",  I_getDirection, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("direction",  I_setDirection      )
    .def("inner",     I_getInner, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("inner",     I_setInner  )
    .def("outer",     I_getOutter, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("outer",     I_setOutter )
  ;

 }
