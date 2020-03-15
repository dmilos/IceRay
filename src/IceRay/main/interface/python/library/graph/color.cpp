#include <initializer_list>
#include "../../def_submodule.hpp"

#include "IceRay/type/color.hpp"

#include <boost/python.hpp>

typedef GS_DDMRM::S_IceRay::S_type::S_color::S__internal::GT_scalar                GTs_Scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar       GTs_ColorScalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar   GTs_ColorGrayScalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_char         GTs_ColorChar;


template < typename N_number>
 N_number getGray( GTs_ColorGrayScalar const& P_color, int P_index )
  {
   if( P_index >= 0 && P_index < P_color.size() )
    {
     return P_color[ P_index ];
    }
  
   PyErr_SetString( PyExc_IndexError, "index out of range" );
   return 0;
  }

template < typename N_number, typename N_component >
 N_number getRGB( ::color::rgb<N_component> const& P_color, int P_index )
  {
   if( P_index >= 0 && P_index < P_color.size() )
    {
     return P_color[ P_index ];
    }
 
   PyErr_SetString( PyExc_IndexError, "index out of range" );
   return 0;
  }

template < typename N_number >
void setGray( GTs_ColorGrayScalar & P_color, int P_index, N_number P_value )
 {
  if( P_index >= 0 && P_index < P_color.size())
   {
    P_color.set( P_index, P_value );
    return;
   }

   PyErr_SetString(PyExc_IndexError, "index out of range");
   return;
}

template < typename N_number >
void setRGB( GTs_ColorScalar & P_color, int P_index, N_number P_value )
 {
  if( P_index >= 0 && P_index < P_color.size())
   {
    P_color.set( P_index, P_value );
    return;
   }

   PyErr_SetString(PyExc_IndexError, "index out of range");
   return;
}


GTs_ColorScalar &
GFs_fillRGB( GTs_ColorScalar & v, GTs_Scalar x )
{
  v.set( 0, x );
  v.set( 1, x );
  v.set( 2, x );
  return v;
}

GTs_ColorGrayScalar &
GFs_fillGray( GTs_ColorGrayScalar & v, GTs_Scalar x )
{
  v.set( 0, x );
  return v;
}
GTs_ColorGrayScalar &
GFs_load1( GTs_ColorGrayScalar & v, GTs_Scalar x )
 {
  v.set( 0, x );
  return v;
 }

GTs_ColorScalar &
GFs_load3( GTs_ColorScalar & v, GTs_Scalar x, GTs_Scalar y, GTs_Scalar z )
 {
  v.set( 0, x );
  v.set( 1, y );
  v.set( 2, z );
  return v;
 }

GTs_ColorScalar &
GFs_load4( GTs_ColorScalar & v, GTs_Scalar x, GTs_Scalar y, GTs_Scalar z, GTs_Scalar t )
 {
  v.set( 0, x );
  v.set( 1, y );
  v.set( 2, z );
  v.set( 3, z );
  return v;
 }

//template < typename N_number>    mul   ( GTs_ColorScalar const& P_color ){ }
//template < typename N_number>    rmul  ( GTs_ColorScalar const& P_color ){ }
//template < typename N_number>    div   ( GTs_ColorScalar const& P_color ){ }
//template < typename N_number>    eq    ( GTs_ColorScalar const& P_color ){ }
//template < typename N_number>    ne    ( GTs_ColorScalar const& P_color ){ }
//template < typename N_number>    invert( GTs_ColorScalar const& P_color ){ }

// TODO: s * c, c * s, c / s, v+v, v-v
// Clamp color
void expose_graph_type_color()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( color  );


  boost::python::class_<GTs_ColorScalar>( "GraphTypeColorRGB" )
   .def( boost::python::init<>() )
    //.def( boost::python::init<GTs_Scalar>() )
    .def( boost::python::init<GTs_ColorScalar>() )

    .def( "fill",        &GFs_fillRGB, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",        &GFs_load3,   boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "load",        &GFs_load4,   boost::python::return_value_policy<boost::python::return_by_value>() )
    
    .def("__getitem__"  , &getRGB<GTs_Scalar,GTs_Scalar > )
    .def("__setitem__"  , &setRGB<GTs_Scalar > )
    
    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )
    
    .def( boost::python::self * GTs_Scalar() )
    .def( GTs_Scalar() * boost::python::self  )
    
    .def( boost::python::self / GTs_Scalar() )
    
    .def( boost::python::self /= GTs_Scalar() )
    .def( boost::python::self *= GTs_Scalar() )
    
    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )

    //.def("__eq__"       , &eq    <GTs_Scalar::T_value > )
    //.def("__ne__"       , &ne    <GTs_Scalar::T_value > )
    //.def("__invert__"   , &invert<TF_scalar::T_value > )   
  ;

  boost::python::class_<GTs_ColorGrayScalar>( "GraphTypeColorGray" )
    .def( boost::python::init<>() )
   //.def( boost::python::init<GTs_Scalar>() )
    .def( boost::python::init<GTs_ColorGrayScalar>() )
 
    .def( "load",        &GFs_load1, boost::python::return_value_policy<boost::python::return_by_value>() )
    .def( "fill",        &GFs_fillGray,  boost::python::return_value_policy<boost::python::return_by_value>() )

    .def("__getitem__"  , &getGray<GTs_Scalar > )
    .def("__setitem__"  , &setGray<GTs_Scalar > )

    .def( boost::python::self + boost::python::self )
    .def( boost::python::self - boost::python::self )

    .def( boost::python::self * GTs_Scalar() )
    .def( GTs_Scalar() * boost::python::self  )

    .def( boost::python::self / GTs_Scalar() )

    .def( boost::python::self /= GTs_Scalar() )
    .def( boost::python::self *= GTs_Scalar() )

    .def( boost::python::self += boost::python::self )
    .def( boost::python::self -= boost::python::self )
 /*
    //.def("__eq__"       , &eq    <TF_scalar::T_value > )
    //.def("__ne__"       , &ne    <TF_scalar::T_value > )
    //.def("__invert__"   , &invert<TF_scalar::T_value > )   */
  ;


    //boost::python::def( "GraphTypeColor_RGB2HLS",  &GFs_);
    //boost::python::def( "GraphTypeColor_RGB2HSV",  &GFs_);
    //boost::python::def( "GraphTypeColor_RGB2CMY",  &GFs_);

    //boost::python::def( "GraphTypeColor_HSV2RGB",  &GFs_);
    //boost::python::def( "GraphTypeColor_HSV2HLS",  &GFs_);

    //boost::python::def( "GraphTypeColor_HLS2RGB",  &GFs_);
    //boost::python::def( "GraphTypeColor_HLS2HSV",  &GFs_);

    //boost::python::def( "GraphTypeColor_clamp",  &GFs_clamp);



 }
