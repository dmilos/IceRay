
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/disc.hpp"


#include "./simple.hpp"



typedef GS_DDMRM::S_IceRay::S_geometry::GC_disc           GTs_disc;

void expose_IceRay_geometry_disc()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_scalar const& (GTs_disc::*Tf_getRadius)(void) const;
  Tf_getRadius I_getRadius = &GTs_disc::F_radius;

  typedef  bool (GTs_disc::*Tf_setRadius  )(GTs_scalar const&);
  Tf_setRadius I_setRadius = &GTs_disc::F_radius;

  typedef  GTs_coord3D const& (GTs_disc::*Tf_getCoord)(void) const;
  typedef  bool (GTs_disc::*Tf_setCoord)(GTs_coord3D const&);

  Tf_getCoord I_getNormal = &GTs_disc::F_center;
  Tf_setCoord I_setNormal = &GTs_disc::F_center;
  Tf_getCoord I_getCenter = &GTs_disc::F_normal;
  Tf_setCoord I_setCenter = &GTs_disc::F_normal;


  boost::python::class_< GTs_disc, boost::python::bases<GTs__base> >( "GeometrySimpleDisc" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D,GTs_coord3D,GTs_scalar>() )
    .def( "radius",  I_getRadius, boost::python::return_value_policy<boost::python::copy_const_reference>()   )
    .def( "radius",  I_setRadius )
    .def( "normal",  I_getNormal, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "normal",  I_setNormal )
    .def( "center",  I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "center",  I_setCenter )
  ;

 }
