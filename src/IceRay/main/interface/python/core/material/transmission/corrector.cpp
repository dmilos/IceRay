
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/transmission/corrector.hpp"


void expose_IceRay_material_transmission_corrector()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( transmission );

  typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction   GTs_instruction;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_transmission::GC_corrector   GTs_corrector;


  typedef boost::python::class_<GTs_corrector, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialTransmissionCorrector", boost::python::no_init )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

  //boost::python::enum_<GTs_one::Ee_input>( "Input" )
  //  .value( "point",          GTs_one::En_inCoord_Normal   )
  //  .value( "normal",         GTs_one::En_inCoord_Bump     )
  //  .value( "albedo",         GTs_one::En_inColor_Correct  )
  //  .export_values()
  // ;

 }
