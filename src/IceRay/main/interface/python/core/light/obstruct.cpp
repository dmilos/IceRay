

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/obstruct.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure             GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_obstruct          GTs_obstruct;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_geometry;

bool set_barrier( GTs_obstruct & P_light,  GTs_geometry * P_geometry )
 {
  typedef  GTs_obstruct::T_barrier Tf_barrier;

  auto I_ptr = dynamic_cast< Tf_barrier * >( P_geometry );

  //if( nullptr == I_ptr )
  // {
  //  return false;
  // }

  return P_light.F_barrier( I_ptr );
 }

void expose_IceRay_light_Obstruct()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef  bool (GTs_obstruct::*Tf_setLight        )( GTs__pure       * );
  Tf_setLight     I_setLight    =  &GTs_obstruct::F_child;

  boost::python::class_<GTs_obstruct, boost::python::bases<GTs__pure> >( "LightObstruct" )
    .def( boost::python::init<>() )
    .def("light",     I_setLight   )
    .def("barrier",   set_barrier  )
  ;

 }
