



#include <boost/python.hpp>
#include "../../../def_submodule.hpp"

#include "../../../../../../render/4ray/classic2/algorithm.hpp"

typedef  GS_DDMRM::S_IceRay::S_type::GT_size      GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar     GTs_scalar;

typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure                    GTs_ray;
typedef GS_DDMRM::S_IceRay::S_render::S_ray::S_classic2::GC_algorithm    GTs_c2a;
typedef GS_DDMRM::S_IceRay::S_object::S__pure::GC__base                  GTs_object;


void expose_IceRay_render_ray_C2A()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( ray );

  typedef  GTs_scalar const& (GTs_c2a::*Tf_getScalar)(void) const;
  typedef  bool (GTs_c2a::*Tf_setScalar  )(GTs_scalar const&);

  Tf_getScalar I_getTrash = &GTs_c2a::F_trash;
  Tf_setScalar I_setTrash = &GTs_c2a::F_trash;

  typedef  GTs_size const& (GTs_c2a::*Tf_getSize)(void) const;
  typedef  bool (GTs_c2a::*Tf_setSize  )(GTs_size const&);

  Tf_getSize I_getDepth = &GTs_c2a::F_depth;
  Tf_setSize I_setDepth = &GTs_c2a::F_depth;

  typedef  bool (GTs_c2a::*Tf_setObject )(GTs_object *);
  Tf_setObject I_setObject = &GTs_c2a::F_object;

  boost::python::class_<GTs_c2a, boost::python::bases<GTs_ray> >("CoreRenderRayC2A" )
   .def( boost::python::init<>() )
    .def( "object", I_setObject    )
    .def( "trash",  I_getTrash, boost::python::return_value_policy<boost::python::copy_const_reference>()    )
    .def( "trash",  I_setTrash     )
    .def( "depth",  I_getDepth, boost::python::return_value_policy<boost::python::copy_const_reference>()    )
    .def( "depth",  I_setDepth     )
  ;

 }

