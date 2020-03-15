
#include "../../def_submodule.hpp"

#include "../../../../../type/math/coord.hpp"
#include "../../../../../type/math/matrix.hpp"


#include <boost/python.hpp>

typedef GS_DDMRM::S_IceRay::S_type::GT_size                GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D   GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar2D  GTs_matrix2D;
typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D  GTs_matrix3D;
typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D  GTs_matrix4D;


namespace
 {
  GTs_matrix3D & GFs_set( GTs_matrix3D & P_matrix, GTs_size P_row, GTs_size const& P_column, GTs_scalar const& P_value )
   {
    P_matrix[ P_row ][ P_column ] = P_value;
     // TODO PyErr_SetString(PyExc_IndexError, "index out of range" );
     return P_matrix;
   }

  GTs_coord3D GFs_rowGet( GTs_matrix3D & P_matrix, GTs_size P_row  )
   {
    GTs_coord3D Ir_row;
    Ir_row[0] = P_matrix[ P_row ][ 0 ];
    Ir_row[1] = P_matrix[ P_row ][ 1 ];
    Ir_row[2] = P_matrix[ P_row ][ 2 ];

    return Ir_row;
   }

  GTs_matrix3D & GFs_rowSet( GTs_matrix3D & P_matrix, GTs_size P_row, GTs_coord3D const& P_value )
   {
    P_matrix[ P_row ][ 0 ] = P_value[0];
    P_matrix[ P_row ][ 1 ] = P_value[1];
    P_matrix[ P_row ][ 2 ] = P_value[2];
    return P_matrix;
   }

  GTs_coord3D GFs_columnGet( GTs_matrix3D & P_matrix, GTs_size P_column  )
   {
    GTs_coord3D Ir_column;

    Ir_column[0] = P_matrix[ 0 ][ P_column ];
    Ir_column[1] = P_matrix[ 1 ][ P_column ];
    Ir_column[2] = P_matrix[ 2 ][ P_column ];
    return Ir_column;
   }

  GTs_matrix3D &  GFs_columnSet( GTs_matrix3D & P_matrix, GTs_size P_column, GTs_coord3D const& P_value )
   {
    P_matrix[ 0 ][ P_column ] = P_value[0];
    P_matrix[ 1 ][ P_column ] = P_value[1];
    P_matrix[ 2 ][ P_column ] = P_value[2];
    return P_matrix;
   }

  GTs_matrix3D &  GFs_scale1( GTs_matrix3D & P_matrix, GTs_scalar const& P_value )
   {
    P_matrix[ 0 ][ 0 ] *= P_value;
    P_matrix[ 1 ][ 1 ] *= P_value;
    P_matrix[ 2 ][ 2 ] *= P_value;
    return P_matrix;
   }

  GTs_matrix3D &  GFs_scale3( GTs_matrix3D & P_matrix, GTs_coord3D const& P_value )
   {
    P_matrix[ 0 ][ 0 ] *= P_value[0];
    P_matrix[ 1 ][ 1 ] *= P_value[1];
    P_matrix[ 2 ][ 2 ] *= P_value[2];
    return P_matrix;
   }

  GTs_matrix3D &  GFs_load( GTs_matrix3D & P_matrix, GTs_coord3D const& P_x, GTs_coord3D const& P_y, GTs_coord3D const& P_z )
   {
    P_matrix[ 0 ][ 0 ] = P_x[0];
    P_matrix[ 1 ][ 0 ] = P_x[1];
    P_matrix[ 2 ][ 0 ] = P_x[2];

    P_matrix[ 0 ][ 1 ] = P_y[0];
    P_matrix[ 1 ][ 1 ] = P_y[1];
    P_matrix[ 2 ][ 1 ] = P_y[2];

    P_matrix[ 0 ][ 2 ] = P_z[0];
    P_matrix[ 1 ][ 2 ] = P_z[1];
    P_matrix[ 2 ][ 2 ] = P_z[2];

    return P_matrix;
   }
   
  GTs_matrix3D &  GFs_id3( GTs_matrix3D & P_matrix )
   {
    ::math::linear::matrix::id( P_matrix );
    return P_matrix;
   }

 }

void expose_math_type_matrix2D()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( math   );

  boost::python::class_<GTs_matrix2D>( "MathTypeMatrix2D" )
    .def( boost::python::init<>() );

 }

void expose_math_type_matrix3D()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( math   );

  //typedef  GTs_scalar const& (GTs_matrix3D::*Tf_getScalar )( GTs_size const& P_row, GTs_size const& P_column )const;
  //Tf_getScalar I_getScalar = &GTs_matrix3D::F_element;

  //typedef  GTs_scalar     & (GTs_matrix3D::*Tf_accessScalar )( GTs_size const& P_row, GTs_size const& P_column );
  //Tf_accessScalar I_accessScalar = &GTs_matrix3D::F_element;

  boost::python::class_<GTs_matrix3D>( "MathTypeMatrix3D" )
    .def( boost::python::init<>() )
    //.def( boost::python::init< GTs_scalar >() )
    //.def( boost::python::init< GTs_coord3D,GTs_coord3D,GTs_coord3D >() )

    .def( "load", &GFs_load, boost::python::return_value_policy<boost::python::reference_existing_object>()  )

    //.def( "element", I_getScalar,    boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "element",   &GFs_set,       boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "row",       &GFs_rowGet    )
    .def( "row",       &GFs_rowSet,    boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "column",    &GFs_columnGet )
    .def( "column",    &GFs_columnSet, boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "scale",     &GFs_scale1,    boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "scale",     &GFs_scale3,    boost::python::return_value_policy<boost::python::reference_existing_object>()  )
    .def( "identity",  &GFs_id3,       boost::python::return_value_policy<boost::python::reference_existing_object>()  )

    //.def( "rotate_z" )
    //.def( "rotate_axis" )

    //.def( boost::python::self + boost::python::self )
    //.def( boost::python::self - boost::python::self )
    //.def( boost::python::self * GTs_scalar3D::T_value() )
    //.def( GTs_scalar3D::T_value() * boost::python::self  )
    //.def( boost::python::self / GTs_scalar3D::T_value() )
    //.def( boost::python::self += boost::python::self )
    //.def( boost::python::self -= boost::python::self )
  ;
 }

void expose_math_type_matrix4D()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( math   );

  boost::python::class_<GTs_matrix4D>( "MathTypeMatrix4D" )
    .def( boost::python::init<>() );

 }


void expose_math_type_matrix()
 {
  expose_math_type_matrix2D();
  expose_math_type_matrix3D();
  expose_math_type_matrix4D();
 }
