
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "../../../../../../geometry/_pure/_base.hpp"
#include "../../../../../../geometry/complex/intersect.hpp"



void expose_IceRay_geometry_complex_intersect()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  Tf_coord3D;

  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base                  Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect     Tf_intersect;

  typedef  bool  (Tf_intersect::*Tf_setSmall)( Tf__base * P_right );
  typedef  bool  (Tf_intersect::*Tf_setFull )( Tf__base * P_right, Tf_intersect::T_location const& P_orientation );

  Tf_setSmall I_setSmallLeft  = &Tf_intersect::F_left;
  Tf_setFull  I_setFullLeft   = &Tf_intersect::F_left;
  Tf_setSmall I_setSmallRight = &Tf_intersect::F_right;
  Tf_setFull  I_setFullRight  = &Tf_intersect::F_right;

  boost::python::class_< Tf_intersect, boost::python::bases<Tf__base> >( "GeometryComplexIntersect" )
    .def( boost::python::init<>() )
    .def("left",  I_setSmallLeft   )
    .def("left",  I_setFullLeft    )
    .def("right", I_setSmallRight  )
    .def("right", I_setFullRight   )
  ;

 }
