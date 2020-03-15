
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "IceRay/geometry/_pure/_base.hpp"
#include "IceRay/geometry/volumetric/vacuum.hpp"


typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar    GTs_scalar;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs__base;
typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum         GTs_vacuum;

void expose_IceRay_geometry_vacuum()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_coord3D const& (GTs_vacuum::*Tf_getCoord)(void) const;
  typedef  bool (GTs_vacuum::*Tf_setCoord  )(GTs_coord3D const&);

  //typedef  GTs_box const& (GTs_vacuum::*Tf_getCoord)(void) const;
  //typedef  bool (GTs_vacuum::*Tf_setCoord  )(GTs_box const&);

  //Tf_getCoord I_getLo = &GTs_vacuum::F_lo;
  //Tf_setCoord I_setLo = &GTs_vacuum::F_lo;
  //Tf_getCoord I_getHi = &GTs_vacuum::F_hi;
  //Tf_setCoord I_setHi = &GTs_vacuum::F_hi;

  boost::python::class_< GTs_vacuum, boost::python::bases<GTs__base> >( "GeometryVolumetricVacuum" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D, GTs_coord3D>() )
    //.def("lo",  I_getLo, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    //.def("lo",  I_setLo )
    //.def("hi",  I_getHi, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    //.def("hi",  I_setHi      )
    ;

 }
