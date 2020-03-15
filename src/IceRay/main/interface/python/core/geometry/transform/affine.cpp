
#include "./transform.hpp"

#include "IceRay/geometry/transform/affine.hpp"

typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_affine      GTs_affine;

bool GFs_doTranslate( GTs_affine & P_affine, GTs_coord3D const& P_move )
 {
  GTs_affine3D I_transform;

  ::math::linear::affine::id( I_transform );
  I_transform.vector() = P_move;

  GTs_affine3D I_2world;
  ::math::linear::affine::compose( I_2world, I_transform, P_affine.F_2world() );

  P_affine.F_2world( I_2world );
  return true;
 }

bool GFs_doScale0( GTs_affine &P_affine, GTs_coord3D const& P_scale )
 {
  GTs_affine3D I_transform;

  ::math::linear::affine::id( I_transform );
  I_transform.matrix()[0][0] = P_scale[0];
  I_transform.matrix()[1][1] = P_scale[1];
  I_transform.matrix()[2][2] = P_scale[2];

  GTs_affine3D I_2world;
  ::math::linear::affine::compose( I_2world, I_transform, P_affine.F_2world() );

  P_affine.F_2world( I_2world );
  return true;
 }

bool GFs_doScaleX( GTs_affine & P_affine, GTs_coord3D const& P_pivot, GTs_coord3D const& P_scale )
 {
  using namespace ::math::linear::vector;
  GFs_doTranslate( P_affine, -P_pivot );
  GFs_doScale0( P_affine, P_scale );
  GFs_doTranslate( P_affine, P_pivot );

  return true;
 }

bool GFs_doRotate( GTs_affine * P_affine, GTs_coord3D const& P_pivot, GTs_coord3D const& P_direction, GTs_scalar const& P_angle )
 {
  GTs_affine::T_affine I_rotate;  ::math::linear::affine::rotate( I_rotate, P_pivot, P_direction, P_angle  );

  GTs_affine::T_affine I_2world; ::math::linear::affine::compose( I_2world, I_rotate, P_affine->F_2world()  );

  P_affine->F_2world( I_2world );

  return true;
 }

bool GFs_doSkewX( GTs_affine * P_affine, GTs_coord3D const& P_pivot, GTs_coord3D const& P_angle )
 {
   return true;
 }

void expose_IceRay_geometry_transform_affine()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

   boost::python::class_< GTs_affine, boost::python::bases<GTs__base> >( "GeometryTransformAffine" )
     .def( boost::python::init<>() )
      .def( boost::python::init<GTs__base *>() )
      .def( boost::python::init<GTs__base *, GTs_affine3D>() )
      .def( boost::python::init<GTs__base *, GTs_matrix3D, GTs_coord3D>() )
      .def("translate",  &GFs_doTranslate )
      .def("scale",      &GFs_doScaleX )
      .def("rotate",     &GFs_doRotate )
      .def("skew",       &GFs_doSkewX )
  ;

 }
