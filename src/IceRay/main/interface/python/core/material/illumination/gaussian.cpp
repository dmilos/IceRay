
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/gaussian.hpp"



void expose_IceRay_material_illumination_gaussian()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_gaussian   GTs_gaussian;
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_gaussian::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_gaussian::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_gaussian::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_gaussian::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_gaussian::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_gaussian::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_gaussian, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationGaussian")
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
    //.def( "interval", &GTs_gaussian::F_get, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //.def( "interval", &GTs_gaussian::F_set )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_gaussian::Ee_input>( "Input" )
    .value( "SpotBegin",      GTs_gaussian::En_inSize_SpotBegin     )
    .value( "SpotEnd",        GTs_gaussian::En_inSize_SpotEnd       )
    .value( "Specular",       GTs_gaussian::En_inColor_Specular     )
    .value( "Smoothness",     GTs_gaussian::En_inColor_Smoothness   )
    .value( "point",          GTs_gaussian::En_inCoord_Point        )
    .value( "normal",         GTs_gaussian::En_inCoord_Normal       )
    .export_values()
   ;

  boost::python::enum_<GTs_gaussian::Ee_output>( "Output" )
    .value( "result",     GTs_gaussian::En_outColor_result   )
    .export_values()
   ;
 }
