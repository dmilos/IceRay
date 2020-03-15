
#include <boost/python.hpp>

#include "../../def_submodule.hpp"

#include "../../../../../material/_pure.hpp"
#include "../../../../../material/compute/surface.hpp"


typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure         GTs_pigment;
typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure     GTs_medium;
typedef GS_DDMRM::S_IceRay::S_material::GC__pure               GTs__pure;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface  GTs_surface;

void expose_IceRay_material_surface()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );

  //typedef  GTs_scalar const& (GTs_surface::*Tf_getRadius)(void) const;
  //typedef  bool (GTs_surface::*Tf_setRadius  )(GTs_scalar const&);

  typedef boost::python::class_< GTs_surface, boost::python::bases< GTs_pigment > > Tf_this;

  Tf_this( "MaterialSurface" )
    .def( boost::python::init<>() )
    .def("insert",  &GTs_surface::F_insert )
    .def("set",     &GTs_surface::F_set    )
    .def("append",  &GTs_surface::F_append )
  ;

 }
