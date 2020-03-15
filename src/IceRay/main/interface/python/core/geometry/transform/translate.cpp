
#include "./transform.hpp"

#include "IceRay/geometry/transform/translate.hpp"

typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate         GTs_translate;

void expose_IceRay_geometry_transform_translate()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef  GTs_coord3D const& (GTs_translate::*Tf_getMove  )(void) const;
  typedef  bool (GTs_translate::*Tf_setMove  )(GTs_coord3D const&);
  Tf_getMove I_getMove = &GTs_translate::F_move;
  Tf_setMove I_setMove = &GTs_translate::F_move;

//typedef  GTs__base const& (GTs_translate::*Tf_getChild )(void) const;
  typedef  bool (GTs_translate::*Tf_setChild  )( GTs__base * );
//Tf_getChild I_getChild = &GTs_translate::F_child;
  Tf_setChild I_setChild = &GTs_translate::F_child;

  boost::python::class_< GTs_translate, boost::python::bases<GTs__base> >( "GeometryTransformTranslate" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__base *, GTs_coord3D>() )
  //.def( "move",  I_getMove, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "move",  I_setMove )
  //.def( "child", I_getChild, boost::python::return_internal_reference<>() )
    .def( "child", I_setChild      )
  ;

 }
