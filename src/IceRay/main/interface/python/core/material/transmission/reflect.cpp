
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/transmission/reflect/one.hpp"
#include "IceRay/material/compute/transmission/reflect/schlick.hpp"


typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction   GTs_instruction;


void expose_IceRay_material_transmission_reflect_one()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_reflect::GC_one   GTs_one;

  typedef  bool                (GTs_one::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_one::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_one::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_one::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_one::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_one::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_one, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialTransmissionReflectOne", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_one::Ee_input>( "Input" )
    .value( "point",          GTs_one::En_inCoord_Point    )
    .value( "normal",         GTs_one::En_inCoord_Normal   )
    .value( "albedo",         GTs_one::En_inColor_Albedo   )
    .export_values()
   ;

 }

void expose_IceRay_material_transmission_reflect_schlick()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_reflect::GC_schlick   GTs_schlick;

  typedef  bool                (GTs_schlick::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_schlick::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_schlick::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_schlick::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_schlick::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_schlick::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_schlick, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialTransmissionReflectSchlick", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

  //boost::python::enum_<GTs_schlick::Ee_input>( "Input" )
  //  .value( "point",          GTs_schlick::En_inCoord_Point    )
  //  .value( "normal",         GTs_schlick::En_inCoord_Normal   )
  //  .export_values()
  // ;

  //boost::python::enum_<GTs_schlick::Ee_output>( "Output" )
  //  .value( "count",     GTs_schlick::En_outSize_RayCount )
  //  .value( "count",     GTs_schlick::En_outRay_Reflected )
  //  .export_values()
   ;
 }

