#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/geometry/uvw.hpp"



void expose_IceRay_material_geometry_UVW()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction         GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GC_UVW      GTs_UVW;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( geometry );

  typedef boost::python::class_<GTs_UVW, boost::python::bases< GTs_instruction  > > Tf_this;

  boost::python::object I_this = Tf_this( "MateriaGeometryUVW" )
    .def( boost::python::init<>() )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_UVW::Ee_input>( "Input" )
    .value( "geometry",  GTs_UVW::En_inGeometryUVW_This      )
    .value( "point",     GTs_UVW::En_inCoord_Point )
    .value( "state",     GTs_UVW::En_inState_State )
    .export_values()
   ;

  boost::python::enum_<GTs_UVW::Ee_output>( "Output" )
    .value( "UVW",     GTs_UVW::En_outCoord_UVW  )
    .value( "valid",   GTs_UVW::En_outBool_Valid  )
    .export_values()
   ;
 }