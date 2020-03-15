

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/blocked.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure             GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_blocked           GTs_blocked;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_geometry;

bool set_barrier( GTs_blocked & P_light,  GTs_geometry * P_geometry )
 {
  typedef  GTs_blocked::T_barrier Tf_barrier;

  auto I_ptr = dynamic_cast< Tf_barrier * >( P_geometry );

  //if( nullptr == I_ptr )
  // {
  //  return false;
  // }

  return P_light.F_barrier( I_ptr );
 }

void expose_IceRay_light_Blocked()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef  bool (GTs_blocked::*Tf_setLight        )( GTs__pure       * );
  Tf_setLight     I_setLight    =  &GTs_blocked::F_light;

  boost::python::class_<GTs_blocked, boost::python::bases<GTs__pure> >( "LightBlocked" )
    .def( boost::python::init<>() )
    .def("light",     I_setLight   )
    .def("barrier",   set_barrier  )
  ;

 }
