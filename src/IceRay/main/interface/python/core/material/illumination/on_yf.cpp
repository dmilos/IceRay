
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/on_yf.hpp"



void expose_IceRay_material_illumination_on_YF()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                      GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_OrenNayar::GC_YasuhiroFujii   GTs_onYF;
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_onYF::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_onYF::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_onYF::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_onYF::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_onYF::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_onYF::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_onYF, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationONYF")
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
    //.def( "interval", &GTs_onYF::F_get, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //.def( "interval", &GTs_onYF::F_set )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_onYF::Ee_input>( "Input" )
    .value( "SpotBegin",      GTs_onYF::En_inSize_SpotBegin )
    .value( "SpotEnd",        GTs_onYF::En_inSize_SpotEnd )
    .value( "A",              GTs_onYF::En_inColor_A          )
    .value( "B",              GTs_onYF::En_inColor_B          )
    .value( "point",          GTs_onYF::En_inCoord_Point      )
    .value( "normal",         GTs_onYF::En_inCoord_Normal     )
    .export_values()
        ;

  boost::python::enum_<GTs_onYF::Ee_output>( "Output" )
    .value( "result",     GTs_onYF::En_outColor_result   )
    .export_values()
  ;

 }
