
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/on_f29.hpp"



void expose_IceRay_material_illumination_on_f29()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                      GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_OrenNayar::GC_f29   GTs_on_f29;
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_on_f29::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_on_f29::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_on_f29::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_on_f29::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_on_f29::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_on_f29::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_on_f29, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationONf29")
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
    //.def( "interval", &GTs_on_f29::F_get, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //.def( "interval", &GTs_on_f29::F_set )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_on_f29::Ee_input>( "Input" )
    .value( "SpotBegin",      GTs_on_f29::En_inSize_SpotBegin   )
    .value( "SpotEnd",        GTs_on_f29::En_inSize_SpotEnd     )
    .value( "A",              GTs_on_f29::En_inColor_rho        )
    .value( "B",              GTs_on_f29::En_inColor_sigma      )
    .value( "point",          GTs_on_f29::En_inCoord_Point      )
    .value( "normal",         GTs_on_f29::En_inCoord_Normal     )
    .export_values()
        ;

  boost::python::enum_<GTs_on_f29::Ee_output>( "Output" )
    .value( "result",     GTs_on_f29::En_outColor_result   )
    .export_values()
  ;

 }
