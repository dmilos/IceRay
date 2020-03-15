

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/sun.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_sun            GTs_sun;


void expose_IceRay_light_Sun()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef  bool (GTs_sun::*Tf_setChild  )( GTs__pure * );
  Tf_setChild I_setChild = &GTs_sun::F_child;

  boost::python::class_< GTs_sun, boost::python::bases<GTs__pure> >( "LightSun" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__pure *>() )
    .def( "child", I_setChild      )
   ;
 }
