#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/geometry/distance.hpp"

void expose_IceRay_material_geometry_distance()
 {
  typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
  typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
  typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction          GTs_instruction;
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_geometry::GC_distance  GTs_distance;


  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( geometry );

  typedef boost::python::class_<GTs_distance, boost::python::bases< GTs_instruction  > > Tf_this;

  boost::python::object I_this = Tf_this( "MateriaGeometryDistance" )
    .def( boost::python::init<>() )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_distance::Ee_input>( "Input" )
    .value( "geometry",  GTs_distance::En_inGeometryDistance_This )
    .value( "point",     GTs_distance::En_inCoord_Point )
    .export_values()
   ;

  boost::python::enum_<GTs_distance::Ee_output>( "Output" )
    .value( "distance",     GTs_distance::En_outScalar_Distance  )
    .export_values()
   ;

 }