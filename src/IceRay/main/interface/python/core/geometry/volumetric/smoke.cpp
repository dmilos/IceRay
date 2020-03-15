
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "IceRay/geometry/_pure/_base.hpp"
#include "IceRay/geometry/volumetric/smoke.hpp"


typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar    GTs_scalar;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs__base;
typedef GS_DDMRM::S_IceRay::S_geometry::GC_smoke          GTs_smoke;

void expose_IceRay_geometry_smoke()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_coord3D const& (GTs_smoke::*Tf_getCoord)(void) const;
  typedef  bool (GTs_smoke::*Tf_setCoord  )(GTs_coord3D const&);

  typedef  GTs_scalar const& (GTs_smoke::*Tf_getScalar)(void) const;
  typedef  bool (GTs_smoke::*Tf_setScalar  )(GTs_scalar const&);

  // TODO Tf_getCoord I_getLo = &GTs_smoke::F_lo;
  // TODO Tf_setCoord I_setLo = &GTs_smoke::F_lo;
  // TODO Tf_getCoord I_getHi = &GTs_smoke::F_hi;
  // TODO Tf_setCoord I_setHi = &GTs_smoke::F_hi;

  Tf_getScalar I_getPrecision = & GTs_smoke::F_precision;
  Tf_setScalar I_setPrecision = & GTs_smoke::F_precision;

  //Tf_getScalar I_getensity = & GTs_smoke::F_density;
  //Tf_setScalar I_setensity = & GTs_smoke::F_density;

  boost::python::class_< GTs_smoke, boost::python::bases<GTs__base> >( "GeometryVolumetricSmoke" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D, GTs_coord3D>() )
    // TODO .def("lo",  I_getLo, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    // TODO .def("lo",  I_setLo )
    // TODO .def("hi",  I_getHi, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    // TODO .def("hi",  I_setHi )

    //.def("precision",  I_getPrecision, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    //.def("precision",  I_setPrecision )

  ;

 }
