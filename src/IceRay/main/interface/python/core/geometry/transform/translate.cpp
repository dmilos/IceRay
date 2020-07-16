
#include "./transform.hpp"

#include "IceRay/geometry/transform/translate.hpp"
#include "IceRay/geometry/transform/identity.hpp"


void expose_IceRay_geometry_transform_identity()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_identity         Tf_identity;

//typedef  GTs__base const& (Tf_identity::*Tf_getChild )(void) const;
  typedef  bool (Tf_identity::*Tf_setChild  )( GTs__base * );
//Tf_getChild I_getChild = &Tf_identity::F_child;
  Tf_setChild I_setChild = &Tf_identity::F_child;

  boost::python::class_< Tf_identity, boost::python::bases<GTs__base> >( "GeometryTransformIdentity" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__base *>() )
  //.def( "child", I_getChild, boost::python::return_internal_reference<>() )
    .def( "child", I_setChild      )
  ;

 }

void expose_IceRay_geometry_transform_translate()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_transform::GC_translate         Tf_translate;

  typedef  GTs_coord3D const& (Tf_translate::*Tf_getMove  )(void) const;
  typedef  bool (Tf_translate::*Tf_setMove  )(GTs_coord3D const&);
  Tf_getMove I_getMove = &Tf_translate::F_2world;
  Tf_setMove I_setMove = &Tf_translate::F_2world;

//typedef  GTs__base const& (Tf_translate::*Tf_getChild )(void) const;
  typedef  bool (Tf_translate::*Tf_setChild  )( GTs__base * );
//Tf_getChild I_getChild = &Tf_translate::F_child;
  Tf_setChild I_setChild = &Tf_translate::F_child;

  boost::python::class_< Tf_translate, boost::python::bases<GTs__base> >( "GeometryTransformTranslate" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__base *, GTs_coord3D>() )
  //.def( "move",  I_getMove, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "move",  I_setMove )
  //.def( "child", I_getChild, boost::python::return_internal_reference<>() )
    .def( "child", I_setChild      )
  ;

 }
