
#include "../../def_submodule.hpp"

#include "../../../../../light/_pure.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;

void expose_IceRay_light_type_Spot()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );
  MAKE_SUBMODULE( type );

  typedef  GTs_coord3D const& (GTs_spot::*Tf_getCenter  )(void) const;
  typedef  bool (GTs_spot::*Tf_setCenter  )(GTs_coord3D const&);

  Tf_getCenter I_getCenter = &GTs_spot::F_center;
  Tf_setCenter I_setCenter = &GTs_spot::F_center;

  typedef  GTs_color const& (GTs_spot::*Tf_getColor  )(void) const;
  typedef  bool (GTs_spot::*Tf_setColor  )(GTs_color const&);

  Tf_getColor I_get0 = &GTs_spot::F_0;
  Tf_setColor I_set0 = &GTs_spot::F_0;

  Tf_getColor I_get1 = &GTs_spot::F_1;
  Tf_setColor I_set1 = &GTs_spot::F_1;

  Tf_getColor I_get2 = &GTs_spot::F_2;
  Tf_setColor I_set2 = &GTs_spot::F_2;

  boost::python::class_<GTs_spot> ( "LightTypeSpot" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D>() )
    .def( boost::python::init<GTs_coord3D,GTs_color,GTs_color,GTs_color>() )
    .def( "center",  I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "center",  I_setCenter )
    .def( "_0",      I_get0, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "_0",      I_set0 )
    .def( "_1",      I_get1, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "_1",      I_set1 )
    .def( "_2",      I_get2, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "_2",      I_set2 )
    ;
 }
