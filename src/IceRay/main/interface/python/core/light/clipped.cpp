

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/clipped.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_clipped        GTs_clipped;


void expose_IceRay_light_Clipped()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  // TODO typedef  bool (GTs_clipped::*Tf_setLight        )( GTs__pure       * );
  // TODO typedef  bool (GTs_clipped::*Tf_setGeometry     )( GTs_geometry    * );

  // TODO Tf_setLight     I_setLight    =  &GTs_clipped::F_light;
  // TODO Tf_setGeometry  I_setGeometry =  &GTs_clipped::F_geometry;

  boost::python::class_<GTs_clipped, boost::python::bases<GTs__pure> >( "LightClipped" )
    .def( boost::python::init<>() )
  //.def("light",      &GTs_clipped::F_light     )
  // TODO .def("light",      I_setLight     )
  //.def("geometry",   &GTs_clipped::F_geometry  )
  // TODO .def("geometry",   I_setGeometry  )
  ;

 }
