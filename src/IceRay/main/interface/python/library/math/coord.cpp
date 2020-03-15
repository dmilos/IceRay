
#include "../../def_submodule.hpp"

#include "../../../../../type/math/coord.hpp"


using namespace ::math::linear::vector;

#include <boost/python.hpp>

typedef GS_DDMRM::S_IceRay::S_type::GT_int               GTs_int;
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
//typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_int2D    GTs_cell2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_int3D    GTs_cell3D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_int4D    GTs_cell4D;

typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D    GTs_size2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D    GTs_size3D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D    GTs_size4D;


typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  GTs_coord2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D  GTs_coord4D;

namespace
 {

  template < typename N_number, unsigned N_dimension>
   N_number get( typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, N_dimension>::T_typedef const&v, int P_index )
    {
     if( P_index >= 0 && P_index < v.size() )
      {
       return v.at( P_index );
      }

     PyErr_SetString( PyExc_IndexError, "index out of range" );
     return 0;
    }

   template < typename N_scalar, typename N_number, unsigned N_dimension>
    void set( typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_scalar, N_dimension>::T_typedef & v, int P_index, N_number value )
     {
      if(P_index >= 0 && P_index < v.size())
       {
        v.at( P_index ) = value;
        return;
       }

       PyErr_SetString(PyExc_IndexError, "index out of range" );
       return;
     }

   template < typename N_number >
    typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< N_number, 2 >::T_typedef &
    load2( typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, 2 >::T_typedef & v, N_number x, N_number y )
     {
      v[0] = x;
      v[1] = y;
      return v;
     }
   template < typename N_number >
    typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< N_number, 3 >::T_typedef &
    load3( typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, 3 >::T_typedef & v, N_number x, N_number y, N_number z )
     {
      v[0] = x;
      v[1] = y;
      v[2] = z;
      return v;
     }

   template < typename N_number >
    typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< N_number, 4 >::T_typedef &
    load4( typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, 4 >::T_typedef & v, N_number x, N_number y, N_number z, N_number t )
     {
      v[0] = x;
      v[1] = y;
      v[2] = z;
      v[3] = t;
      return v;
     }

   template < typename N_number, unsigned dimension_number >
    typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< N_number, dimension_number >::T_typedef &
    fill( typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, dimension_number >::T_typedef & v, N_number x )
     {
      ::math::linear::vector::fill( v, x );
      return v;
     }


    template < typename N_number >
     typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model< N_number, 3 >::T_typedef
      GFs_cross
       (
         typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, 3 >::T_typedef const& P_left
        ,typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, 3 >::T_typedef const& P_right
       )
       {
        typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, 3 >::T_typedef Ir_right;
        ::math::linear::vector::cross( Ir_right, P_left, P_right );
        return Ir_right;
       }

    template < typename N_number, unsigned N_dimension >
     N_number
     GFs_dot
      (
        typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, N_dimension >::T_typedef const& P_left
       ,typename GS_DDMRM::S_IceRay::S_type::S_coord::GC__model<N_number, N_dimension >::T_typedef const& P_right
      )
      {
       return  ::math::linear::vector::dot( P_left, P_right );
      }

  }

void expose_math_type_coord_cell()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( math   );

  boost::python::class_<GTs_cell2D>( "MathTypeCell2D" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GTs_int>() )
  //.def( boost::python::init<GTs_scalar>() )
  //.def( boost::python::init<GTs_int,GTs_int>( TODO ) )
    .def( boost::python::init<GTs_cell2D>() )

    .def("__getitem__", &get<GTs_int, 2 > )
    .def("__setitem__", &set<GTs_int, GTs_int, 2 > )
    .def("__setitem__", &set<GTs_int, GTs_scalar, 2 > )

    .def( "load",       &load2<GTs_size   >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",       &load2<GTs_scalar >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",       &fill<GTs_size,2>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )
    .def( boost::python::self * GTs_size() )
    .def( GTs_size() * boost::python::self  )
    .def( boost::python::self / GTs_int() )
    .def( boost::python::self /= GTs_int() )
    .def( boost::python::self *= GTs_int() )
    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
  ;

  boost::python::class_<GTs_cell3D>( "MathTypeCell3D" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GTs_size>() )
  //.def( boost::python::init<GTs_scalar>() )
  //.def( boost::python::init<GTs_size,GTs_size,GTs_size>( TODO ) )
   .def( boost::python::init<GTs_cell3D>() )

    .def("__getitem__", &get<GTs_int, 3 > )
    .def("__setitem__", &set<GTs_int, GTs_int, 3 > )
    .def("__setitem__", &set<GTs_int, GTs_scalar, 3 > )

    .def( "load",       &load3<GTs_int   >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",       &load3<GTs_scalar >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",       &fill<GTs_int,3>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )
    .def( boost::python::self * GTs_scalar() )
    .def( GTs_scalar() * boost::python::self  )
    .def( boost::python::self / GTs_int() )
    .def( boost::python::self /= GTs_int() )
    .def( boost::python::self *= GTs_int() )
    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
  ;

  boost::python::class_<GTs_cell4D>( "MathTypeCell4D" )
    .def( boost::python::init<>() )
    //.def( boost::python::init<GTs_int>() )
    //.def( boost::python::init<GTs_scalar>() )
    //.def( boost::python::init<GTs_int,GTs_int,GTs_int,GTs_int>( TODO ) )
    .def( boost::python::init<GTs_cell4D>() )

    .def("__getitem__", &get<GTs_int, 4 > )
    .def("__setitem__", &set<GTs_int, GTs_int, 4 > )
    .def("__setitem__", &set<GTs_int, GTs_scalar, 4 > )

    .def( "load",       &load4<GTs_int    >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",       &load4<GTs_scalar >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",       &fill<GTs_int,   4>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )
    .def( boost::python::self * GTs_scalar() )
    .def( GTs_scalar() * boost::python::self  )
    .def( boost::python::self / GTs_int() )
    .def( boost::python::self /= GTs_int() )
    .def( boost::python::self *= GTs_int() )
    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
    ;
 }

void expose_math_type_coord_size()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( math   );

  boost::python::class_<GTs_size2D>( "MathTypeSize2D" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GTs_size>() )
  //.def( boost::python::init<GTs_scalar>() )
  //.def( boost::python::init<GTs_size,GTs_size>( TODO ) )
    .def( boost::python::init<GTs_size2D>() )

    .def("__getitem__", &get<GTs_size, 2 > )
    .def("__setitem__", &set<GTs_size, GTs_size, 2 > )
    .def("__setitem__", &set<GTs_size, GTs_scalar, 2 > )

    .def( "load",       &load2<GTs_size   >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",       &load2<GTs_scalar >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",       &fill<GTs_size,2>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )
    .def( boost::python::self * GTs_size() )
    .def( GTs_size() * boost::python::self  )
    .def( boost::python::self / GTs_size() )
    .def( boost::python::self /= GTs_size() )
    .def( boost::python::self *= GTs_size() )
    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
  ;

  boost::python::class_<GTs_size3D>( "MathTypeSize3D" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GTs_size>() )
  //.def( boost::python::init<GTs_scalar>() )
  //.def( boost::python::init<GTs_size,GTs_size,GTs_size>( TODO ) )
   .def( boost::python::init<GTs_size3D>() )

    .def("__getitem__", &get<GTs_size, 3 > )
    .def("__setitem__", &set<GTs_size, GTs_size, 3 > )
    .def("__setitem__", &set<GTs_size, GTs_scalar, 3 > )

    .def( "load",       &load3<GTs_size   >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",       &load3<GTs_scalar >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",       &fill<GTs_size,3>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )
    .def( boost::python::self * GTs_scalar() )
    .def( GTs_scalar() * boost::python::self  )
    .def( boost::python::self / GTs_size() )
    .def( boost::python::self /= GTs_size() )
    .def( boost::python::self *= GTs_size() )
    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
  ;

  boost::python::class_<GTs_size4D>( "MathTypeSize4D" )
    .def( boost::python::init<>() )
    //.def( boost::python::init<GTs_size>() )
    //.def( boost::python::init<GTs_scalar>() )
    //.def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size>( TODO ) )
    .def( boost::python::init<GTs_size4D>() )

    .def("__getitem__", &get<GTs_size, 4 > )
    .def("__setitem__", &set<GTs_size, GTs_size, 4 > )
    .def("__setitem__", &set<GTs_size, GTs_scalar, 4 > )

    .def( "load",       &load4<GTs_size   >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",       &load4<GTs_scalar >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",       &fill<GTs_size,4>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )
    .def( boost::python::self * GTs_scalar() )
    .def( GTs_scalar() * boost::python::self  )
    .def( boost::python::self / GTs_size() )
    .def( boost::python::self /= GTs_size() )
    .def( boost::python::self *= GTs_size() )
    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
    ;
 }

// TODO: s * v, v * s, v / s, v+v, v-v
void expose_math_type_coord_scalar()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( math   );

  boost::python::class_<GTs_coord2D>( "MathTypeCoord2D" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GTs_scalar>() )
  //.def( boost::python::init<GTs_scalar,GTs_scalar>( TODO ) )
    .def( boost::python::init<GTs_coord2D>() )

    .def("__getitem__", &get<GTs_scalar, 2 > )
    .def("__setitem__", &set<GTs_scalar, GTs_scalar, 2 > )

    .def( "load",        &load2<GTs_scalar >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",        &fill<GTs_scalar,2>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )

    .def( boost::python::self * GTs_scalar() )
    .def( GTs_scalar() * boost::python::self  )

    .def( boost::python::self / GTs_scalar() )

    .def( boost::python::self /= GTs_scalar() )
    .def( boost::python::self *= GTs_scalar() )

    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
  ;

  boost::python::def("MathCoord2D_dot",  &GFs_dot<GTs_scalar, 2 > );

  boost::python::def("MathLinearVector2DDot",  &GFs_dot<GTs_scalar, 2 > );
  boost::python::def("MathLinearVector3DLength",  &::math::linear::vector::length<GTs_scalar,GTs_scalar, 4 > );

  boost::python::class_<GTs_coord3D>( "MathTypeCoord3D" )
    .def( boost::python::init<>() )
   //.def( boost::python::init<GTs_scalar>() )
   //.def( boost::python::init<GTs_scalar,GTs_scalar,GTs_scalar>( TODO ) )
   .def( boost::python::init<GTs_coord3D>() )

     .def( "__getitem__", &get<GTs_scalar, 3 > )
     .def( "__setitem__", &set<GTs_scalar, GTs_scalar, 3 > )
   //.def("__setitem__", &set<GTs_scalar, GTs_size, 3 > )

    .def( "load",        &load3<GTs_scalar >, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",        &fill<GTs_scalar,3>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )

    .def( boost::python::self * GTs_scalar() )
    .def( GTs_scalar() * boost::python::self  )

    .def( boost::python::self / GTs_scalar() )

    .def( boost::python::self /= GTs_scalar() )
    .def( boost::python::self *= GTs_scalar() )

    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
   ;

  boost::python::def("MathCoord3D_dot",    &GFs_dot<GTs_scalar, 3 > );
  boost::python::def("MathCoord3D_cross",  &GFs_cross<GTs_scalar > );

  boost::python::def("MathLinearVector3DDot",  &GFs_dot<GTs_scalar, 2 > );
  boost::python::def("MathLinearVector3DLength",  &::math::linear::vector::length<GTs_scalar,GTs_scalar, 3 > );


  boost::python::class_<GTs_coord4D>( "MathTypeCoord4D" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GTs_scalar>() )
  //.def( boost::python::init<GTs_scalar,GTs_scalar,GTs_scalar,GTs_scalar>() )
   .def( boost::python::init<GTs_coord4D>() )

   .def("__getitem__", &get<GTs_scalar, 4 > )
   .def("__setitem__", &set<GTs_scalar, GTs_scalar, 4 > )

    .def( "load",       &load4<GTs_scalar>, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",       &load4<GTs_size>, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",       &fill<GTs_scalar,4>, boost::python::return_value_policy<boost::python::return_by_value>() )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )
    .def( boost::python::self * GTs_scalar() )
    .def( GTs_scalar() * boost::python::self  )
    .def( boost::python::self / GTs_scalar() )
    .def( boost::python::self /= GTs_scalar() )
    .def( boost::python::self *= GTs_scalar() )
    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
   ;

  boost::python::def("MathCoord4D_dot",  &GFs_dot<GTs_scalar, 4 > );

  boost::python::def("MathLinearVector4DDot",  &GFs_dot<GTs_scalar, 2 > );
  boost::python::def("MathLinearVector4DLength",  &::math::linear::vector::length<GTs_scalar,GTs_scalar, 4 > );

 }


void expose_math_type_coord_coord()
 {
  expose_math_type_coord_cell();
  expose_math_type_coord_size();
  expose_math_type_coord_scalar();
 }