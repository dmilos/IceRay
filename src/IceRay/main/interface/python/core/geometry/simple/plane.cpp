
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/flat/plane.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_plane            GTs_plane;

void expose_IceRay_geometry_plane()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_coord3D const& (GTs_plane::*Tf_getPivot  )(void) const;
  Tf_getPivot I_getPivot = &GTs_plane::F_pivot;

  typedef  bool (GTs_plane::*Tf_setPivot  )(GTs_coord3D const&);
  Tf_setPivot I_setPivot = &GTs_plane::F_pivot;

  typedef  GTs_coord3D const& (GTs_plane::*Tf_getNormal)(void) const;
  Tf_getNormal I_getNormal = &GTs_plane::F_normal;

  typedef  bool (GTs_plane::*Tf_setNormal  )(GTs_coord3D const&);
  Tf_setNormal I_setNormal = &GTs_plane::F_normal;


  boost::python::class_< GTs_plane, boost::python::bases<GTs__base> >( "GeometrySimplePlane" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D, GTs_coord3D>() )
    .def("pivot",  I_getPivot, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("pivot",  I_setPivot )
    .def("normal",  I_getNormal, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("normal",  I_setNormal )
  ;

 }


