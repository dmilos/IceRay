
#include "../../def_submodule.hpp"

#include "../../../../../material/_pure.hpp"
#include "../../../../../material/compute/instruction.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure          GTs_medium;
typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure         GTs_pigment;
typedef GS_DDMRM::S_IceRay::S_material::GC__pure                    GTs__pure;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction   GTs_instruction;


void expose_IceRay_material_material()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );

  typedef boost::python::class_<GTs__pure, boost::noncopyable>  Tf_this;

  //typedef  GTs_medium * (GTs__pure::*Tf_getMedium)(void) const;
  //typedef  bool (GTs__pure::*Tf_setMedium  )(GTs_medium * );

  //typedef  GTs_pigment * (GTs__pure::*Tf_getSurface  )(void) const;
  //typedef  bool (GTs__pure::*Tf_setSurface  )(GTs_pigment * );

  //Tf_getSurface I_getSurface = &GTs__pure::F_surface;
  //Tf_setSurface I_setSurface = &GTs__pure::F_surface;
  //Tf_getMedium I_getMedium = &GTs__pure::F_medium;
  //Tf_setMedium I_setMedium = &GTs__pure::F_medium;

  Tf_this( "MaterialMaterial_pure", boost::python::no_init );
    //.def("surface",  I_getSurface, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    //.def("surface",  I_setSurface )
    //.def("medium",   I_getMedium, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    //.def("medium",   I_setMedium      )
  ;

 }
