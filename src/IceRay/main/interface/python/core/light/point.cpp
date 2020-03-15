

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/point.hpp"


typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_point          GTs_point;

void expose_IceRay_light_Point()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pierce );

  typedef  GTs_spot const& (GTs_point::*Tf_getSpot  )(void) const;
  typedef  bool (GTs_point::*Tf_setSpot  )(GTs_spot const&);
  
  typedef  GTs_coord3D const& (GTs_point::*Tf_getCoord3D  )(void) const;
  typedef  bool (GTs_point::*Tf_setCoord3D  )(GTs_coord3D const&);

  Tf_getCoord3D   I_getCenter = &GTs_point::F_center;
  Tf_setCoord3D   I_setCenter = &GTs_point::F_center;

  Tf_getSpot I_getSpot = &GTs_point::F_spot;
  Tf_setSpot I_setSpot = &GTs_point::F_spot;

  boost::python::class_<GTs_point, boost::python::bases<GTs__pure> >( "LightPoint" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D>() )
    .def( boost::python::init<GTs_coord3D,GTs_color,GTs_color,GTs_color>() )
    .def( boost::python::init<GTs_spot>() )
    .def( "spot",     I_getSpot,    boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "spot",     I_setSpot     )
    .def( "center",   I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "center",   I_setCenter  )
  ;

 }
