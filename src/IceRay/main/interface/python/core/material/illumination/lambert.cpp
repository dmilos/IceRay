
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/lambert.hpp"



void expose_IceRay_material_illumination_lambert()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                          GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_lambert   GTs_lambert;
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_lambert::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_lambert::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_lambert::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_lambert::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_lambert::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_lambert::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_lambert, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationLambert")
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_lambert::Ee_input>( "Input" )
    .value( "LightCount",     GTs_lambert::En_inSize_SpotCount   )
    .value( "diffuse",        GTs_lambert::En_inColor_Diffuse    )
    .value( "point",          GTs_lambert::En_inCoord_Point      )
    .value( "normal",         GTs_lambert::En_inCoord_Normal     )
    .export_values()
   ;

  boost::python::enum_<GTs_lambert::Ee_output>( "Output" )
    .value( "result",     GTs_lambert::En_outColor_result   )
    .export_values()
   ;

 }
