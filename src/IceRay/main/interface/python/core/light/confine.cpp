#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/confine.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;


void expose_IceRay_light_confine()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );
  
  typedef GS_DDMRM::S_IceRay::S_light::GC_confine        Tf_confine;

  typedef  bool (Tf_confine::*Tf_setLight        )( GTs__pure       * );
  Tf_setLight     I_setLight    =  &Tf_confine::F_child;

  boost::python::class_<Tf_confine, boost::python::bases<GTs__pure> >( "LightConfine" )
    .def( boost::python::init<>() )
    .def("light",     I_setLight   )
  //.def("hull",      I_setBarrier  )
  ;

 }

