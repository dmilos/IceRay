
#include "../../../def_submodule.hpp"

#include "../../../../../../geometry/rtss/_pure.hpp"




typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base    GTs__base;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure     GTs__rtss;


void expose_IceRay_geometry_RTSS__pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( rtss );

  //typedef  GTs_size (GTs__rtss::*Tf_size )( GTs__base * );
  //Tf_size I_size = &GTs__rtss::Fv_size;

  boost::python::class_<GTs__rtss, boost::noncopyable>( "GeometryRTSS_pure", boost::python::no_init )
    //.def( "size", I_size, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "done",  &GTs__rtss::Fv_optimize )

  ;
  
 }
