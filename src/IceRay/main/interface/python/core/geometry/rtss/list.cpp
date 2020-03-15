
#include "../../../def_submodule.hpp"

#include "../../../../../../geometry/rtss/list.hpp"


typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base    GTs__base;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure     GTs__rtss;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_list      GTs_list;

void expose_IceRay_geometry_RTSS_list()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( rtss );

  // just empty class, might be ::type()
  // But not insert/add/push/size
  boost::python::class_< GTs_list, boost::python::bases<GTs__rtss> >( "GeometryRTSSList" )
    .def( boost::python::init<>() )
  ;

 }
