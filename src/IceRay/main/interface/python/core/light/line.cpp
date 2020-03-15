

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/line.hpp"


typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_size GTs_size;

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_line          GTs_line;


void expose_IceRay_light_Line()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef  GTs_spot const& (GTs_line::*Tf_getSpot  )(void) const;
  Tf_getSpot I_getSpot = &GTs_line::F_spot;
  typedef  bool (GTs_line::*Tf_setSpot  )(GTs_spot const&);
  Tf_setSpot I_setSpot = &GTs_line::F_spot;

  typedef  GTs_coord3D const& (GTs_line::*Tf_getCoord  )(void) const;
  typedef  bool (GTs_line::*Tf_setCoord  )(GTs_coord3D const&);

  Tf_getCoord I_getEnd = &GTs_line::F_end;
  Tf_setCoord I_setEnd = &GTs_line::F_end;

  typedef  GTs_size const& (GTs_line::*Tf_getSize )(void) const;
  typedef  bool (GTs_line::*Tf_setSize  )(GTs_size const&);
  Tf_getSize I_getSample = &GTs_line::F_sample;
  Tf_setSize I_setSample = &GTs_line::F_sample;
  
  Tf_getCoord I_getStart = &GTs_line::F_start;
  Tf_setCoord I_setStart = &GTs_line::F_start;

  boost::python::class_<GTs_line, boost::python::bases<GTs__pure> >( "LightLine" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_spot, GTs_coord3D>() )
    .def( "spot",    I_getSpot, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "spot",    I_setSpot      )
    .def( "start",   I_getStart, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "start",   I_setStart      )
    .def( "end",     I_getEnd, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "end",     I_setEnd      )
    .def( "sample",  I_getSample, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "sample",  I_setSample      )
  ;

 }
