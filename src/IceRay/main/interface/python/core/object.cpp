
#include <memory>

#include "../def_submodule.hpp"

#include "../../../../object/wrap.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar              GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D   GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar  GTs_box;


typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure         GTs_pigment;
typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure     GTs_medium;
typedef GS_DDMRM::S_IceRay::S_material::GC__pure               GTs_material;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   GTs_geometry;

typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__pure     GTs__pure;
typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base     GTs__base;

typedef GS_DDMRM::S_IceRay::S_object::GC_wrap               GTs_wrap;


void expose_IceRay_object__pure()
 {
  typedef boost::python::class_< GTs__pure, boost::python::bases< GTs_geometry >, boost::noncopyable > Tf_this;
  Tf_this ( "ObjectPure", boost::python::no_init )
    ;
 }

void expose_IceRay_object__base()
 {
  typedef boost::python::class_< GTs__base, boost::python::bases< GTs__pure >,  boost::noncopyable > Tf_this;
  Tf_this ( "ObjectBase", boost::python::no_init )
    ;
 }

void expose_IceRay_core_object()
 {
  expose_IceRay_object__pure();
  expose_IceRay_object__base();

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( core );

  typedef boost::python::class_< GTs_wrap, boost::python::bases< GTs__base > > Tf_this;

  typedef  bool (GTs_wrap::*Tf_setPigment      )( GTs_pigment  * );
  typedef  bool (GTs_wrap::*Tf_setMedium       )( GTs_medium   * );
  typedef  bool (GTs_wrap::*Tf_setGeometry     )( GTs_geometry * );

  typedef  GTs_box const& (GTs_wrap::*Tf_getBox     )( )const;

  Tf_getBox I_getBox = &GTs__pure::F_box;


  Tf_setPigment       I_setPigment      = &GTs_wrap::F_pigment;
  Tf_setMedium        I_setMedium       = &GTs_wrap::F_medium;
  Tf_setGeometry      I_setGeometry     = &GTs_wrap::F_geometry;

  Tf_this ( "CoreObject" )
  //.def( "geometry", &GTs__pure::F_geometry, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "geometry", I_setGeometry )
  //.def( "surface", &GTs__pure::F_box, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "surface", I_setPigment )
  //.def( "medium", , boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "medium", I_setMedium )
  ;
 }
