

#include <boost/python.hpp>
#include "../../../def_submodule.hpp"

#include "../../../../../../render/4ray/distance.hpp"

typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure       GTs_ray;
typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC_distance    GTs_distance;

void expose_IceRay_render_ray_distance()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( ray );

  //typedef void (GTs_distance::*T_setCamera )( GTs_camera *  );

  //T_setCamera  I_setCamera = &GTs_distance::Fv_camera;
  //T_setRay     I_setRay    = &GTs_distance::Fv_ray;
  
  boost::python::class_<GTs_distance, boost::python::bases<GTs_ray> >("CoreRenderRayDistance" )
   .def( boost::python::init<>() )
   //.def("camera",    I_setCamera  )
   //.def("geometry",  I_setGeometry    )
  ;

 }
