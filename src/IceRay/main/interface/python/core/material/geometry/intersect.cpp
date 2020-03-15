#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/geometry/intersect.hpp"


void expose_IceRay_material_geometry_intersect()
 {

  typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
  typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
  typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction          GTs_instruction;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GC_intersect   GTs_intersect;

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( geometry );

  typedef boost::python::class_<GTs_intersect, boost::python::bases< GTs_instruction  > > Tf_this;

  boost::python::object I_this = Tf_this( "MateriaGeometryIntersect" )
    .def( boost::python::init<>() )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_intersect::Ee_input>( "Input" )
    .value( "geometry",  GTs_intersect::En_inGeometryIntersect_This   )
    .value( "ray",       GTs_intersect::En_inRay_Incoming    )
    .value( "state",     GTs_intersect::En_inState_State  )
    .export_values()
        ;

  boost::python::enum_<GTs_intersect::Ee_output>( "Output" )
    .value( "lambda",    GTs_intersect::En_outScalar_Lambda  )
    .value( "valid",     GTs_intersect::En_outBool_valid  )
    .value( "point",     GTs_intersect::En_outCoord_Point  )
    .value( "state",     GTs_intersect::En_outState_State  )
    .export_values()
   ;
 }
