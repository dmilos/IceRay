
#include "../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"

#include "IceRay/material/compute/operation/unary.hpp"
#include "IceRay/material/compute/operation/binary.hpp"
#include "IceRay/material/compute/operation/ternary.hpp"
#include "IceRay/material/compute/operation/switch.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction       GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory            GTs_memory;


typedef GTs_instruction::T_size GTs_size;

void expose_IceRay_material_instruction()
 {
  //aaaaa();
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );


  typedef void            (GTs_instruction::*Tf_setInput )( GTs_instruction::T_component const&, GTs_size const&, GTs_size const& );
  typedef GTs_size const& (GTs_instruction::*Tf_getInput )( GTs_instruction::T_component const&, GTs_size const& )const;

  typedef void            (GTs_instruction::*Tf_setOutput)( GTs_instruction::T_component const&, GTs_size const&, GTs_size const& );
  typedef GTs_size const& (GTs_instruction::*Tf_getOutput)( GTs_instruction::T_component const&, GTs_size const& )const;

  Tf_setInput  I_setInput  = &GTs_instruction::F_input;
  Tf_getInput  I_getInput  = &GTs_instruction::F_input;

  Tf_setOutput I_setOutput = &GTs_instruction::F_output;
  Tf_getOutput I_getOutput = &GTs_instruction::F_output;

  boost::python::class_<GTs_instruction, boost::noncopyable >( "MaterialSurface_Instruction", boost::python::no_init )
    .def( "input",  I_getInput, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "input",  I_setInput  )
    .def( "output", I_getOutput, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "output", I_setOutput )
  ;

  boost::python::enum_<GTs_instruction::T_component>( "Component" )
    .value( "ray",       GTs_memory::En_ray      )
    .value( "bool",      GTs_memory::En_bool     )
    .value( "uint8",     GTs_memory::En_uint8    )
    .value( "size",      GTs_memory::En_size     )
    .value( "scalar",    GTs_memory::En_scalar   )
    .value( "coord2D",   GTs_memory::En_coord2D  )
    .value( "coord3D",   GTs_memory::En_coord3D  )
    .value( "coord",     GTs_memory::En_coord    )
    .value( "coord4D",   GTs_memory::En_coord4D  )
    .value( "color",     GTs_memory::En_color    )
    .value( "spot",      GTs_memory::En_spot     )
    .export_values()
   ;

  //boost::python::enum_<GTs_instruction::Ee_constantBool>( "ConstantBool" )
  //  .value( "valid",   GTs_instruction::En_inValid )
  //  .export_values()
  // ;
  //
  //boost::python::enum_<GTs_instruction::Ee_constantSize>( "ConstantSize" )
  //  .value( "spot",   GTs_instruction::En_LightCount )
  //  .export_values()
  // ;
  //
  //boost::python::enum_<GTs_instruction::Ee_constantScalar>( "ConstantScalar" )
  //  .value( "zero",   GTs_instruction::En_inZero )
  //  .value( "one",    GTs_instruction::En_inOne  )
  //  .value( "pi",     GTs_instruction::En_inPi   )
  //  .value( "gold",   GTs_instruction::En_inGold )
  //  .export_values()
  //  ;
  //
  //boost::python::enum_<GTs_instruction::Ee_constantColor>( "ConstantColor" )
  //  .value( "result",   GTs_instruction::En_result )
  //  .value( "black",    GTs_instruction::En_black  )
  //  .value( "white",    GTs_instruction::En_white  )
  //  .export_values()
  // ;
  //
  //boost::python::enum_<GTs_instruction::Ee_constantCoord>( "ConstantCoord" )
  //  .value( "point",         GTs_instruction::En_coordPoint  )
  //  .value( "normal",        GTs_instruction::En_coordNormal )
  //  .value( "bump",          GTs_instruction::En_coordBump   )
  //  .export_values()
  // ;
 }

void expose_IceRay_material_operation_binary()
 {


 }
