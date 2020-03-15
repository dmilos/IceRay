
#include "../../../def_submodule.hpp"

#include "../../../../../../geometry/rtss/uniform.hpp"


typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D    GTs_cell3D;


typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base    GTs__base;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC__pure     GTs__rtss;
typedef GS_DDMRM::S_IceRay::S_geometry::S_RTSS::GC_uniform   GTs_uniform;

void expose_IceRay_geometry_RTSS_uniform()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );
  MAKE_SUBMODULE( rtss );

  typedef  GTs_cell3D const& (GTs_uniform::*Tf_getSize)(void) const;
  typedef  bool (GTs_uniform::*Tf_setSize  )(GTs_cell3D const& );  
  
  Tf_getSize I_getDimesion = &GTs_uniform::F_dimension;
  Tf_setSize I_setDimesion = &GTs_uniform::F_dimension;

  boost::python::class_< GTs_uniform, boost::python::bases<GTs__rtss> >( "GeometryRTSSUniform" )
    .def( "dimension",  I_getDimesion , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "dimension",  I_setDimesion )
  ;

 }
