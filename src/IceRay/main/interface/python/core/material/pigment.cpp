
#include "../../def_submodule.hpp"

#include "../../../../../material/_pure.hpp"
#include "../../../../../material/medium/_pure.hpp"


typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_material::S_pigment::GC__pure    GTs_pigment;
typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure     GTs_medium;
typedef GS_DDMRM::S_IceRay::S_material::GC__pure               GTs__pure;


void expose_IceRay_material_pigment()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );

  typedef boost::python::class_<GTs_pigment, boost::noncopyable > Tf_this;

  Tf_this I_this = Tf_this( "MaterialSurfacePigment", boost::python::no_init )
  ;

 }
