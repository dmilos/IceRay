
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/hs_lambert.hpp"


void expose_IceRay_material_illumination_hs_lambert()
 {
  typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
  typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
  typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                               GTs_instruction;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_HeidrichSeidel::GC_Lambert GTs_HeidrichSeidelLambert;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_HeidrichSeidelLambert::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_HeidrichSeidelLambert::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_HeidrichSeidelLambert::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_HeidrichSeidelLambert::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_HeidrichSeidelLambert::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_HeidrichSeidelLambert::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_HeidrichSeidelLambert, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationHSLambert")
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_HeidrichSeidelLambert::Ee_input>("Input")
    .value( "SpotBegin",      GTs_HeidrichSeidelLambert::En_inSize_SpotBegin   )
    .value( "SpotEnd",        GTs_HeidrichSeidelLambert::En_inSize_SpotEnd     )
    .value( "Diffuse",        GTs_HeidrichSeidelLambert::En_inColor_Diffuse      )
    .value( "Normal",         GTs_HeidrichSeidelLambert::En_inCoord_Normal       )
    .value( "Groove",         GTs_HeidrichSeidelLambert::En_inCoord_Groove       )
    .export_values()
   ;

  boost::python::enum_<GTs_HeidrichSeidelLambert::Ee_output>("Output")
    .value( "result",     GTs_HeidrichSeidelLambert::En_outColor_result   )
    .export_values()
   ;

 }


