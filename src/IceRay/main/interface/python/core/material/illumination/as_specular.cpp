
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/as_specular.hpp"


void expose_IceRay_material_illumination_AshikhminShirley_specular()
 {
  typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
  typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
  typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                                    GTs_instruction;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_AshikhminShirley::GC_specular   GTs_specular;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_specular::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_specular::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_specular::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_specular::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_specular::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_specular::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_specular, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationAshikhminShirleySpecular")
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

  //boost::python::enum_<GTs_specular::Ee_input>( "Input" )
  //  .value( "Specular",       GTs_specular::En_inColor_Specular   )
  //  .value( "Shininess",      GTs_specular::En_inColor_Shininess  )
  //  .value( "LightCount",     GTs_specular::En_inSize_LightCount  )
  //  .export_values()
  // ;
  //
  //boost::python::enum_<GTs_specular::Ee_output>( "Output" )
  //  .value( "result",     GTs_specular::En_outColor_result   )
  //  .export_values()
  // ;

 }
