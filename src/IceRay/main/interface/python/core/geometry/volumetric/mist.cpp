
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "IceRay/geometry/_pure/_base.hpp"
#include "IceRay/geometry/volumetric/mist.hpp"



void expose_IceRay_geometry_mist()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
  typedef GS_DDMRM::S_IceRay::S_type::GT_scalar    Tf_scalar;

  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base        GTs__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_volumetric::GC_mist         Tf_mist;

  typedef  Tf_scalar const& (Tf_mist::*Tf_getScalar)(void) const;
  typedef  bool (Tf_mist::*Tf_setScalar  )(Tf_scalar const&);

  //typedef  GTs__base const& (Tf_mist::*Tf_getHull )(void) const;
  typedef  bool (Tf_mist::*Tf_setHull  )( GTs__base * );

  Tf_getScalar I_getPrecision = & Tf_mist::F_precision;
  Tf_setScalar I_setPrecision = & Tf_mist::F_precision;

  Tf_getScalar I_getDensity = & Tf_mist::F_density;
  Tf_setScalar I_setDensity = & Tf_mist::F_density;

//Tf_getHull I_getHull = &Tf_mist::F_hull;
  Tf_setHull I_setHull = &Tf_mist::F_hull;

  boost::python::class_< Tf_mist, boost::python::bases<GTs__base> >( "GeometryVolumetricMist" )
    .def( boost::python::init<>() )
    .def("precision",  I_getPrecision, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("precision",  I_setPrecision )
    .def("density",    I_getDensity, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def("density",    I_setDensity )
  //.def( "hull", I_getHull, boost::python::return_internal_reference<>() )
    .def( "hull", I_setHull      )
    ;

 }
