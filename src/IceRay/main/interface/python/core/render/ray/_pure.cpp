



#include "../../../def_submodule.hpp"

#include "../../../../../../render/4ray/_pure.hpp"

typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure  GTs__pure;


void expose_IceRay_render_ray__pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( ray );

  boost::python::class_<GTs__pure, boost::noncopyable>( "CoreRenderRay_pure", boost::python::no_init )
   ;

 }
