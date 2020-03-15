
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"

#include "IceRay/material/compute/transmission/refract/refract.hpp"

#include "IceRay/material/compute/transmission/blossom/blossom.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction   GTs_instruction;

void expose_IceRay_material_transmission_blossom()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );


  //typedef  bool                (GTs_blossom::*Tf_setScalar   )( GTs_scalar const& );
  //typedef  GTs_scalar const&   (GTs_blossom::*Tf_getScalar   )( void ) const;
  //typedef  bool                (GTs_blossom::*Tf_setColor    )( GTs_color const& );
  //typedef  GTs_color const&    (GTs_blossom::*Tf_getColor    )( void ) const;
  //typedef  bool                (GTs_blossom::*Tf_setCoord3D  )( GTs_coord3D const& );
  //typedef  GTs_coord3D const&  (GTs_blossom::*Tf_getCoord3D  )( void ) const;


  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_grid   GTs_grid;
  typedef boost::python::class_<GTs_grid, boost::python::bases< GTs_instruction > > Tf_grid;
  boost::python::object I_grid = Tf_grid( "MaterialTransmissionBlossomGrid", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_random   GTs_random;
  typedef boost::python::class_<GTs_random, boost::python::bases< GTs_instruction > > Tf_random;
  boost::python::object I_random = Tf_random( "MaterialTransmissionBlossomRandom", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_hexagon   GTs_hexagon;
  typedef boost::python::class_<GTs_hexagon, boost::python::bases< GTs_instruction > > Tf_hexagon;
  boost::python::object I_hexagon = Tf_hexagon( "MaterialTransmissionBlossomHexagon", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
    ;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_blossom::GC_vdc   GTs_vdc;
  typedef boost::python::class_<GTs_vdc, boost::python::bases< GTs_instruction > > Tf_vdc;
  boost::python::object I_vdc = Tf_vdc( "MaterialTransmissionBlossomVDC", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  //boost::python::scope I_scope = I_this;

  //boost::python::enum_<GTs_blossom::Ee_input>( "Input" )
  //  .value( "normal",         GTs_blossom::En_inCoord_Normal   )
  //  .value( "transparency",   GTs_blossom::En_inColor_Transparency  )
  //  .export_values()
  // ;

  //boost::python::enum_<GTs_one::Ee_output>( "Output" )
  //  .value( "count",     GTs_blossom::En_outSize_RayCount )
  //  .value( "count",     GTs_blossom::En_outRay_Refracted )
  //  .export_values()
  // ;
 }



void expose_IceRay_material_transmission_refract_one()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_one   GTs_one;

  typedef  bool                (GTs_one::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_one::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_one::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_one::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_one::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_one::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_one, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialTransmissionRefractOne", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_one::Ee_input>( "Input" )
    .value( "point",          GTs_one::En_inCoord_Point    )
    .value( "normal",         GTs_one::En_inCoord_Normal   )
    .value( "transmittance",   GTs_one::En_inColor_Transmittance  )
    .export_values()
   ;

  //boost::python::enum_<GTs_one::Ee_output>( "Output" )
  //  .value( "count",     GTs_split::En_outSize_RayCount )
  //  .value( "count",     GTs_split::En_outRay_Refracted )
  //  .export_values()
  // ;
 }

void expose_IceRay_material_transmission_refract_multi()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_multi   GTs_multi;

  typedef  bool                (GTs_multi::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_multi::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_multi::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_multi::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_multi::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_multi::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_multi, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialTransmissionRefractMulti", boost::python::no_init )
    .def( boost::python::init<>() )
  //.def( boost::python::init< GTs_size,...>() )
  ;

  boost::python::scope I_scope = I_this;

 // boost::python::enum_<GTs_multi::Ee_input>( "Input" )
 //   .value( "point",          GTs_multi::En_inCoord_Point    )
 //   .value( "normal",         GTs_multi::En_inCoord_Normal   )
 //   .value( "transparency",   GTs_multi::En_inColor_Transparency   )
 //   .value( "angle",          GTs_multi::En_inScalar_Angle   )
 //   .value( "count",          GTs_multi::En_inSize_RayCount  )
 //   .export_values()
 //  ;

 }

void expose_IceRay_material_transmission_refract_fresnel()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_fresnel   GTs_fresnel;

  typedef  bool                (GTs_fresnel::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_fresnel::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_fresnel::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_fresnel::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_fresnel::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_fresnel::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_fresnel, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialTransmissionRefractFresnel", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

 // boost::python::enum_<GTs_fresnel::Ee_input>( "Input" )
 //   .value( "point",          GTs_fresnel::En_inCoord_Point    )
 //   .value( "normal",         GTs_fresnel::En_inCoord_Normal   )
 //   .value( "absorbtion",   GTs_fresnel::En_inColor_Absorbtion  )
 //   .export_values()
 //  ;

  //boost::python::enum_<GTs_fresnel::Ee_output>( "Output" )
  //  .value( "count",     GTs_fresnel::En_outSize_RayCount )
  //  .value( "count",     GTs_fresnel::En_outRay_Refracted )
  //  .export_values()
   ;
 }

void expose_IceRay_material_transmission_refract_schlick()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_schlick   GTs_schlick;

  typedef  bool                (GTs_schlick::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_schlick::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_schlick::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_schlick::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_schlick::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_schlick::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_schlick, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialTransmissionRefractSchlick", boost::python::no_init )
    .def( boost::python::init<>() )
   .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size >() )
  ;

  boost::python::scope I_scope = I_this;

 // boost::python::enum_<GTs_schlick::Ee_input>( "Input" )
 //   .value( "point",          GTs_schlick::En_inCoord_Point    )
 //   .value( "normal",         GTs_schlick::En_inCoord_Normal   )
 //   .value( "absorbtion",   GTs_schlick::En_inColor_Absorbtion )
 //   .export_values()
 //  ;

  //boost::python::enum_<GTs_schlick::Ee_output>( "Output" )
  //  .value( "count",     GTs_schlick::En_outSize_RayCount )
  //  .value( "count",     GTs_schlick::En_outRay_Refracted )
  //  .export_values()
   ;
 }

void expose_IceRay_material_transmission_refract_arbitrary()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::S_refract::GC_arbitrary   GTs_arbitrary;

  typedef  bool                (GTs_arbitrary::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_arbitrary::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_arbitrary::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_arbitrary::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_arbitrary::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_arbitrary::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_arbitrary, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialTransmissionRefractArbitrary", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

 // boost::python::enum_<GTs_arbitrary::Ee_input>( "Input" )
 //   .value( "point",          GTs_arbitrary::En_inCoord_Point    )
 //   .value( "normal",         GTs_arbitrary::En_inCoord_Normal   )
 //   .value( "absorbtion",   GTs_arbitrary::En_inColor_Absorbtion  )
 //   .export_values()
 //  ;

  //boost::python::enum_<GTs_arbitrary::Ee_output>( "Output" )
  //  .value( "count",     GTs_arbitrary::En_outSize_RayCount )
  //  .value( "count",     GTs_arbitrary::En_outRay_Refracted )
  //  .export_values()
   ;
 }
