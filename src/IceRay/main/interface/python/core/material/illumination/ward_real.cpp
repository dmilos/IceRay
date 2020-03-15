
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/ward_real.hpp"


void expose_IceRay_material_illumination_ward_real()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                  GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_ward::GC_real GTs_wardReal;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_wardReal::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_wardReal::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_wardReal::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_wardReal::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_wardReal::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_wardReal::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_wardReal, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationWardReal", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
    //.def( "interval", &GTs_wardReal::F_get, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //.def( "interval", &GTs_wardReal::F_set )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_wardReal::Ee_input>( "Input" )
    .value( "LightCount",     GTs_wardReal::En_inSize_LightCount  )
    .value( "Specular",       GTs_wardReal::En_inColor_Specular   )
    .value( "AlphaX",         GTs_wardReal::En_inColor_AlphaX     )
    .value( "AlphaY",         GTs_wardReal::En_inColor_AlphaY     )
    .value( "point",          GTs_wardReal::En_inCoord_Point      )
    .value( "normal",         GTs_wardReal::En_inCoord_Normal     )
    .value( "direction",      GTs_wardReal::En_inCoord_Direction  )
    .export_values()
   ;

  boost::python::enum_<GTs_wardReal::Ee_output>( "Output" )
    .value( "result",     GTs_wardReal::En_outColor_result   )
    .export_values()
   ;


 }
