

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/spline.hpp"

typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_size GTs_size;

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_spline         GTs_spline;


void expose_IceRay_light_Spline()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef  GTs_spot const& (GTs_spline::*Tf_getSpot  )(void) const;
  typedef  bool (GTs_spline::*Tf_setSpot  )(GTs_spot const&);
  Tf_getSpot I_getSpot = &GTs_spline::F_spot;
  Tf_setSpot I_setSpot = &GTs_spline::F_spot;

  typedef  GTs_size const& (GTs_spline::*Tf_getSize )(void) const;
  typedef  bool (GTs_spline::*Tf_setSize  )(GTs_size const&);
  Tf_getSize I_getSample = &GTs_spline::F_sample;
  Tf_setSize I_setSample = &GTs_spline::F_sample;
  
  typedef  GTs_coord3D const& (GTs_spline::*Tf_getCoord  )( GTs_size const& ) const;
  typedef  bool (GTs_spline::*Tf_setCoord  )(GTs_size const&, GTs_coord3D const&);
  Tf_getCoord I_getCP = &GTs_spline::F_cp;
  Tf_setCoord I_setCP = &GTs_spline::F_cp;

  boost::python::class_< GTs_spline, boost::python::bases<GTs__pure> >( "LightSpline" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GTs_size>() )
  //.def( boost::python::init<GT_coord>() )
    .def( "spot",    I_getSpot, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "spot",    I_setSpot      )
    .def( "sample", I_getSample, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "sample", I_setSample      )
    .def( "cp"    , I_getCP, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "cp"    , I_setCP      )
  ;

 }
