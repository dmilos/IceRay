
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"


#include "IceRay/geometry/simple/quadric.hpp"


#include "./simple.hpp"


typedef GS_DDMRM::S_IceRay::S_geometry::GC_quadric   GTs_quadric;

void expose_IceRay_geometry_simple_quadric()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              Tf_scalar;
  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     Tf_coord;
  typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D  Tf_matrix;

  typedef  Tf_matrix const& (GTs_quadric::*Tf_getMatrix  )(void) const;
  typedef  bool (GTs_quadric::*Tf_setMatrix  )(Tf_matrix const&);

  typedef  Tf_coord const& (GTs_quadric::*Tf_getCoord  )(void) const;
  typedef  bool (GTs_quadric::*Tf_setCoord  )(Tf_coord const&);

  typedef  Tf_scalar const& (GTs_quadric::*Tf_getScalar  )(void) const;
  typedef  bool (GTs_quadric::*Tf_setScalar  )(Tf_scalar const&);

  Tf_getMatrix  I_getMatrix = &GTs_quadric::F_matrix;
  Tf_setMatrix  I_setMatrix = &GTs_quadric::F_matrix;
  Tf_getCoord   I_getCoord  = &GTs_quadric::F_coord;
  Tf_setCoord   I_setCoord  = &GTs_quadric::F_coord;
  Tf_getScalar  I_getScalar = &GTs_quadric::F_scalar;
  Tf_setScalar  I_setScalar = &GTs_quadric::F_scalar;

  boost::python::class_< GTs_quadric, boost::python::bases<GTs__base> >( "GeometrySimpleQuadric" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Tf_matrix, Tf_coord, Tf_scalar>() )
    .def("matrix",  I_getMatrix, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("matrix",  I_setMatrix )
    .def("coord",   I_getCoord,  boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("coord",   I_setCoord  )
    .def("scalar",  I_getScalar, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def("scalar",  I_setScalar )
    ;

 }
