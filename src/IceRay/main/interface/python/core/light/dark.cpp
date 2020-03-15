

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/dark.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_dark          GTs_dark;


void expose_IceRay_light_Dark()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  boost::python::class_<GTs_dark, boost::python::bases<GTs__pure> >( "LightDark" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GT_coord>() )
   //.def("size",    &GTs_dark::F_do        )
   //.def("get",     &GTs_dark::F_work      )
   //.def("set",     &GTs_dark::F_stop      )
  ;

 }
