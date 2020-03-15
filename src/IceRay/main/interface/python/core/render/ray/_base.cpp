

#include <boost/python.hpp>
#include "../../../def_submodule.hpp"

#include "../../../../../../render/4ray/_base.hpp"

typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure       GTs_ray;
typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__base    GTs__base;

void expose_IceRay_render_ray__base()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( ray );

  //typedef void (GTs__base::*T_setCamera )( GTs_camera *  );

  //T_setCamera  I_setCamera = &GTs__base::Fv_camera;
  //T_setRay     I_setRay    = &GTs__base::Fv_ray;

  //boost::python::class_<GTs__base, boost::python::bases<GTs_ray> >("CoreRenderRay_base", boost::python::no_init )
   //.def("camera",    I_setCamera  )
   //.def("geometry",  I_setGeometry    )
  ;

 }
