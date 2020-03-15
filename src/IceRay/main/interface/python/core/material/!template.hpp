
#include "../../def_submodule.hpp"

#include "../../../../../../material/compute/instruction.hpp"
#include "../../../../../../material/$[![type]!] $[![kind]!].hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

 
typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction                             GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pigment::S_$[![type]!]::GC_$[![kind]!]   GTs_$[![kind]!];


void expose_IceRay_material_$[![type]!]_$[![kind]!]()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( $[![type]!] );
  

  typedef  bool                (GTs_$[![kind]!]::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_$[![kind]!]::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_$[![kind]!]::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_$[![kind]!]::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_$[![kind]!]::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_$[![kind]!]::*Tf_getCoord3D  )( void ) const;
  
  
  typedef boost::python::class_<GTs_$[![kind]!], boost::python::bases< GTs_instruction > > Tf_this;

  boost::python::object I_this = Tf_this( "Material$[![TypeX]!] $[![KindX]!]", boost::python::no_init )
    //.def( "interval", &GTs_$[![kind]!]::F_get, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    //.def( "interval", &GTs_$[![kind]!]::F_set )
  ;

  boost::python::scope I_scope = I_this;

  //boost::python::enum_<GTs_$[![kind]!]::Ee_input>("input")
  //       .value( "nowhere",     GTs_$[![kind]!]::En_nowhere     )
  //       .value( "in",          GTs_$[![kind]!]::En_in          )
  //       .value( "out",         GTs_$[![kind]!]::En_out         )
  //       .export_values()
  //      ;

  boost::python::enum_<GTs_$[![kind]!]::Ee_output>("output")
    .value( "result",     GTs_$[![kind]!]::En_outColor_result   )
    .value( "valid",      GTs_$[![kind]!]::En_outBool_valid     )
    .export_values()
    ;

  $[![]!]
 }
