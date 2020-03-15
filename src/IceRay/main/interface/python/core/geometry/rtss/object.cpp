

#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "../../../../../../geometry/rtss/object.hpp"


typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base    GTs__base;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure     GTs__rtss;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_object    GTs_object;


void expose_IceRay_geometry_RTSS_object()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( rtss );

  typedef  GTs_size const& (GTs_object::*Tf_getSize )( )const;
  Tf_getSize I_getSize = &GTs_object::Fv_quantity;

  typedef  bool ( GTs_object::*Tf_setRtss )( GTs__rtss * );
  Tf_setRtss I_setRtss = &GTs_object::F_rtss;
  
  typedef  GTs_size (GTs_object::*Tf_insert )( GTs__base * );
  Tf_insert I_push = &GTs_object::F_push;

  boost::python::class_< GTs_object, boost::python::bases<GTs__base> >( "GeometryRTSSGeometry" )
    .def( boost::python::init<>() )
    .def( "quantity",  I_getSize, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "rtss",  I_setRtss )
    .def( "push",  I_push )
    .def( "optimize",  &GTs_object::F_optimize )
    .def( "clear",  &GTs_object::F_clear )
  //.def( "erase",  &GTs_object::F_erase )
  ;

 }
