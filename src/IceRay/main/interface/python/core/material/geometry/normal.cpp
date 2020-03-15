#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/geometry/normal.hpp"



void expose_IceRay_material_geometry_normal()
 {
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction         GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GC_normal   GTs_normal;
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( geometry );

  typedef boost::python::class_<GTs_normal, boost::python::bases< GTs_instruction  > > Tf_this;

  boost::python::object I_this = Tf_this( "MateriaGeometryNormal" )
    .def( boost::python::init<>() )
  ;

  boost::python::scope I_scope = I_this;

// TODO  boost::python::enum_<GTs_normal::Ee_input>( "Input" )
// TODO    .value( "geometry",  GTs_normal::En_inGeometryNormal_This  )
// TODO    .value( "point",     GTs_normal::En_inCoord_Point )
// TODO    .value( "state",     GTs_normal::En_inState_State  )
// TODO    .export_values()
// TODO   ;
// TODO
// TODO  boost::python::enum_<GTs_normal::Ee_output>( "Output" )
// TODO    .value( "count",     GTs_normal::En_outCoord_Normal  )
// TODO    .export_values()
// TODO   ;

 }