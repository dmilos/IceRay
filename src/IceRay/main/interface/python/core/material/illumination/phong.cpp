
#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"
#include "IceRay/material/compute/illumination/phong.hpp"


void expose_IceRay_material_illumination_phong()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                        GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_illumination::GC_phong   GTs_phong;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( illumination );

  typedef  bool                (GTs_phong::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_phong::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_phong::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_phong::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_phong::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_phong::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_phong, boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialIlluminationPhong")
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size>() )
    //.def( "interval", &GTs_phong::F_get, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //.def( "interval", &GTs_phong::F_set )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_phong::Ee_input>( "Input" )
    .value( "Specular",       GTs_phong::En_inColor_Specular   )
    .value( "Shininess",      GTs_phong::En_inColor_Shininess  )
    .value( "LightCount",     GTs_phong::En_inSize_SpotCount  )
    .export_values()
   ;

  boost::python::enum_<GTs_phong::Ee_output>( "Output" )
    .value( "result",     GTs_phong::En_outColor_result   )
    .export_values()
   ;

 }
