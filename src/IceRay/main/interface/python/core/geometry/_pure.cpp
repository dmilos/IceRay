
#include "../../def_submodule.hpp"

#include "../../../../../geometry/_pure/_base.hpp"

typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar3D            GTs_box;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base              GTs__base;


void expose_IceRay_geometry__pure()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_box const& (GTs__base::*Tf_getBox  )(void) const;

  Tf_getBox I_getBox = &GTs__base::F_box;

  boost::python::class_<GTs__base, boost::noncopyable>( "Geometry_base", boost::python::no_init )
    .def( "interval", I_getBox, boost::python::return_value_policy<boost::python::copy_const_reference>() )
  ;

 }
