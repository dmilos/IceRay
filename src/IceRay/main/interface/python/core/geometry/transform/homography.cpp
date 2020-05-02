
#include "./transform.hpp"

#include "IceRay/geometry/transform/homography.hpp"


void expose_IceRay_geometry_transform_homography()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D  Tf_matrix;

  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  Tf__base;

  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_homography         Tf_homography;

  boost::python::class_< Tf_homography, boost::python::bases<Tf__base> >( "GeometryTransformHomography" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Tf__base *>() )
    .def( boost::python::init<Tf__base *, Tf_matrix>() )
   ;

 }
