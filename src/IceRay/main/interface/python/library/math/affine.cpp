#include "../../def_submodule.hpp"

#include "../../../../../type/math/coord.hpp"
#include "../../../../../type/math/matrix.hpp"
#include "../../../../../type/math/affine.hpp"

#include <boost/python.hpp>

typedef GS_DDMRM::S_IceRay::S_type::GT_size                GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D   GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D  GTs_matrix3D;
typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D  GTs_affine3D;

namespace{

GTs_scalar const& GFs_get( GTs_affine3D & P_affine, GTs_size P_row, GTs_size const& P_column )
 {
  return P_affine.matrix()[ P_row ][ P_column ];
 }

GTs_affine3D & GFs_set( GTs_affine3D & P_affine, GTs_size P_row, GTs_size const& P_column, GTs_scalar const& P_value )
 {
  P_affine.matrix()[ P_row ][ P_column ] = P_value;
   return P_affine;
 }

GTs_coord3D GFs_rowGet( GTs_affine3D & P_affine, GTs_size P_row  )
 {
  GTs_coord3D Ir_row;
  Ir_row[0] = P_affine.matrix()[ P_row][ 0 ];
  Ir_row[1] = P_affine.matrix()[ P_row][ 1 ];
  Ir_row[2] = P_affine.matrix()[ P_row][ 2 ];

  return Ir_row;
 }

GTs_affine3D & GFs_rowSet( GTs_affine3D & P_affine, GTs_size P_row, GTs_coord3D const& P_value )
 {
  P_affine.matrix()[ P_row][ 0 ] = P_value[0];
  P_affine.matrix()[ P_row][ 1 ] = P_value[1];
  P_affine.matrix()[ P_row][ 2 ] = P_value[2];
  return P_affine;
 }

GTs_coord3D GFs_columnGet( GTs_affine3D & P_affine, GTs_size P_column  )
 {
  GTs_coord3D Ir_column;

  Ir_column[0] = P_affine.matrix()[ 0 ][ P_column ];
  Ir_column[1] = P_affine.matrix()[ 1 ][ P_column ];
  Ir_column[2] = P_affine.matrix()[ 2 ][ P_column ];
  return Ir_column;
 }

GTs_affine3D &  GFs_columnSet( GTs_affine3D & P_affine, GTs_size P_column, GTs_coord3D const& P_value )
 {
  P_affine.matrix()[ 0 ][ P_column ] = P_value[0];
  P_affine.matrix()[ 1 ][ P_column ] = P_value[1];
  P_affine.matrix()[ 2 ][ P_column ] = P_value[2];
  return P_affine;
 }

GTs_affine3D &  GFs_scale1( GTs_affine3D & P_affine, GTs_scalar const& P_value )
 {
  P_affine.matrix()[ 0 ][ 0 ] *= P_value;
  P_affine.matrix()[ 1 ][ 1 ] *= P_value;
  P_affine.matrix()[ 2 ][ 2 ] *= P_value;
  return P_affine;
 }

GTs_affine3D &  GFs_scale3( GTs_affine3D & P_affine, GTs_coord3D const& P_value )
 {
  P_affine.matrix()[ 0 ][ 0 ] *= P_value[0];
  P_affine.matrix()[ 1 ][ 1 ] *= P_value[1];
  P_affine.matrix()[ 2 ][ 2 ] *= P_value[2];
  return P_affine;
 }

GTs_affine3D &  GFs_load( GTs_affine3D & P_affine, GTs_coord3D const& P_x, GTs_coord3D const& P_y, GTs_coord3D const& P_z, GTs_coord3D const& P_move )
 {
  ::math::linear::affine::system( P_affine, P_move, P_x, P_y, P_z );

  return P_affine;
 }

 GTs_affine3D
 GFs_lookAt
  (
    GTs_coord3D const& P_eye
   ,GTs_coord3D const& P_view
   ,GTs_coord3D const& P_up
  )
  {
   GTs_affine3D Ir_world;
   ::math::linear::affine::look_at( Ir_world, P_eye, P_view, P_up );

   return Ir_world;
  }

}

void expose_math_type_affine()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( math   );

  typedef  GTs_coord3D const& (GTs_affine3D::*Tf_getCoord3D )(void) const;
  Tf_getCoord3D I_getCoord3D = &GTs_affine3D::vector;

  //typedef  GTs_affine3D     & (GTs_affine3D::*Tf_setCoord3D )( GTs_coord3D const&);
  //Tf_setCoord3D I_setCoord3D = &GTs_affine3D::vector;

  typedef  GTs_matrix3D const& (GTs_affine3D::*Tf_getMatrix3D )(void) const;
  Tf_getMatrix3D I_getMatrix3D = &GTs_affine3D::matrix;

  //typedef  GTs_affine3D     & (GTs_affine3D::*Tf_setMatrix3D )( GTs_matrix3D const&);
  //Tf_setMatrix3D I_setMatrix3D = &GTs_affine3D::matrix;

  boost::python::class_<GTs_affine3D>( "MathTypeAffine3D" )
/*    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_coord3D >() )
    .def( boost::python::init< GTs_matrix3D >() )
    .def( boost::python::init< GTs_matrix3D, GTs_coord3D >() )
    .def( "load",     &GFs_load, boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "coord",    I_getCoord3D,  boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //.def( "coord",    I_setCoord3D,  boost::python::return_value_policy<boost::python::reference_existing_object>() )
    .def( "matrix",   I_getMatrix3D, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //.def( "matrix",   I_setMatrix3D, boost::python::return_value_policy<boost::python::reference_existing_object>() )

    .def( "element", &GFs_get,       boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "element", &GFs_set,       boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "row",     &GFs_rowGet    )
    .def( "row",     &GFs_rowSet,    boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "column",  &GFs_columnGet )
    .def( "column",  &GFs_columnSet, boost::python::return_value_policy<boost::python::reference_existing_object>()  )

    .def( "scale",  &GFs_scale1, boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "scale",  &GFs_scale3, boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    //.def( "move" )
    //.def( "rotate_x" )
    //.def( "rotate_y" )
    //.def( "rotate_z" )
    //.def( "rotate_axis" )
    //.def( "load",   <GTs_matrix3D, GTs_coord3D > )

    //.def( boost::python::self + boost::python::self )
    //.def( boost::python::self - boost::python::self )
    //.def( boost::python::self * GTs_scalar3D::T_value() )
    //.def( GTs_scalar3D::T_value() * boost::python::self  )
    //.def( boost::python::self / GTs_scalar3D::T_value() )
    //.def( boost::python::self += boost::python::self )
    //.def( boost::python::self -= boost::python::self )
*/
  ;

    boost::python::def("MathAffine3D_lookAt",    GFs_lookAt );

 }
