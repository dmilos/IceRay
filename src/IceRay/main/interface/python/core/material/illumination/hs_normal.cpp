
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/hs_normal.hpp"



void expose_IceRay_material_illumination_hs_normal()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                                      GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::S_HeidrichSeidel::GC_normal  GTs_hsp;
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_hsp::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_hsp::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_hsp::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_hsp::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_hsp::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_hsp::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_hsp, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationHSNormal")
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size>() )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_hsp::Ee_input>( "Input" )
    .value( "Groove",         GTs_hsp::En_inCoord_Groove     )
    .value( "normal",         GTs_hsp::En_inCoord_Normal     )
    .export_values()
   ;

  boost::python::enum_<GTs_hsp::Ee_output>( "Output" )
    .value( "result",     GTs_hsp::En_outCoord_result   )
  ;
 }
