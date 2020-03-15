
#include "./transform.hpp"

#include "IceRay/geometry/transform/mblur.hpp"

typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_mblur         GTs_mblur;

void expose_IceRay_geometry_transform_mblur()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_coord3D const& (GTs_mblur::*Tf_getMove  )(void) const;
  typedef  bool (GTs_mblur::*Tf_setMove  )(GTs_coord3D const&);
 //Tf_getMove I_getMove = &GTs_mblur::F_move;
  Tf_setMove I_setMove = &GTs_mblur::F_move;

//typedef  GTs__base const& (GTs_mblur::*Tf_getChild )(void) const;
  typedef  bool (GTs_mblur::*Tf_setChild  )( GTs__base * );
//Tf_getChild I_getChild = &GTs_mblur::F_child;
  Tf_setChild I_setChild = &GTs_mblur::F_child;

  boost::python::class_< GTs_mblur, boost::python::bases<GTs__base> >( "GeometryTransformMBlur" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__base *, GTs_coord3D>() )
  //.def( "move",  I_getMove, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "move",  I_setMove )
  //.def( "child", I_getChild, boost::python::return_internal_reference<>() )
  .def( "child", I_setChild      )
  ;

 }
