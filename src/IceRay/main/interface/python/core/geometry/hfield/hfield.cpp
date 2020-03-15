
#include <boost/python.hpp>

#include "../../../def_submodule.hpp"

#include "IceRay/geometry/hfield/hfield.hpp"

void expose_IceRay_geometry_hfield_generator__base()
{
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure      Ts__base;

  boost::python::class_<Ts__base, boost::noncopyable>( "GeometryHFieldGenerator_Pure", boost::python::no_init )
    ;
}


void expose_IceRay_geometry_hfield_generator_theone()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure      Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_theone     Ts_theone;

  boost::python::class_< Ts_theone, boost::python::bases<Ts__base> >( "GeometryHFieldGeneratorTheOne" )
    .def( boost::python::init<>() )
  ;
 }

void expose_IceRay_geometry_hfield_generator_table()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure      Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table      Ts_table;

  boost::python::class_< Ts_table, boost::python::bases<Ts__base> >( "GeometryHFieldGeneratorTable" )
    .def( boost::python::init<>() )
  ;
 }

void expose_IceRay_geometry_hfield_generator_function()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure      Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_function   Ts_function;

  boost::python::class_< Ts_function, boost::python::bases<Ts__base> >( "GeometryHFieldGeneratorFunction" )
    .def( boost::python::init<>() )
  ;
 }

void expose_IceRay_geometry_hfield_generator_generator()
 {
  expose_IceRay_geometry_hfield_generator__base();
  expose_IceRay_geometry_hfield_generator_theone();
  expose_IceRay_geometry_hfield_generator_table();
  expose_IceRay_geometry_hfield_generator_function();
 }

void expose_IceRay_geometry_hfield_object__base()
{
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure      Ts__base;

  boost::python::class_<Ts__base, boost::noncopyable>( "GeometryHFieldObject_Pure", boost::python::no_init )
    ;
}

void expose_IceRay_geometry_hfield_object_b3()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure      Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_b3         Ts_b3;

  boost::python::class_< Ts_b3, boost::python::bases<Ts__base> >( "GeometryHFieldObjectB3" )
    .def( boost::python::init<>() )
  ;
 }

void expose_IceRay_geometry_hfield_object_trg()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure      Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_trg       Ts_trg;

  boost::python::class_< Ts_trg, boost::python::bases<Ts__base> >( "GeometryHFieldObjectTriangle" )
    .def( boost::python::init<>() )
  ;
 }

void expose_IceRay_geometry_hfield_object_vacuum()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure      Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_vacuum     Ts_vacuum;

  boost::python::class_< Ts_vacuum, boost::python::bases<Ts__base> >( "GeometryHFieldObjectVacuum" )
    .def( boost::python::init<>() )
  ;
 }

void expose_IceRay_geometry_hfield_object_quad()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure      Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_quad       Ts_quad;

  boost::python::class_< Ts_quad, boost::python::bases<Ts__base> >( "GeometryHFieldObjectQuad" )
    .def( boost::python::init<>() )
  ;
 }
 
void expose_IceRay_geometry_hfield_object_flat()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure      Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_flat       Ts_flat;

  boost::python::class_< Ts_flat, boost::python::bases<Ts__base> >( "GeometryHFieldObjectFlat" )
    .def( boost::python::init<>() )
  ;
 }

void expose_IceRay_geometry_hfield_object_object()
 {
  expose_IceRay_geometry_hfield_object__base();
  expose_IceRay_geometry_hfield_object_b3();
  expose_IceRay_geometry_hfield_object_trg();
  expose_IceRay_geometry_hfield_object_vacuum();
  expose_IceRay_geometry_hfield_object_quad();
  expose_IceRay_geometry_hfield_object_flat();
 }

void expose_IceRay_geometry_hfield_system()
 {
   expose_IceRay_geometry_hfield_object_object();
   expose_IceRay_geometry_hfield_generator_generator();

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base       Ts__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system     Ts_system;

  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure      Ts_object;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure   Ts_generator;

  //typedef  Ts_generator * (GTs_smoke::*Tf_getGenerator )(void) const;
  typedef  bool (Ts_system::*Tf_setGenerator  )(Ts_generator *);

  //typedef  Ts_object * (GTs_smoke::*Tf_getObject )(void) const;
  typedef  bool (Ts_system::*Tf_setObject  )(Ts_object *);

  Tf_setGenerator I_setGenerator = & Ts_system::F_generator;
  Tf_setObject    I_setObject    = & Ts_system::F_object;

  boost::python::class_< Ts_system, boost::python::bases<Ts__base> >( "GeometryHFieldSystem" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Ts_generator*,Ts_object*>() )
    .def("object",      I_setObject )
    .def("generator",   I_setGenerator )

  ;

 }
