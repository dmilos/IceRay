
#include "../../def_submodule.hpp"

#include "../../../../../render/2pierce/_pure.hpp"
#include "../../../../../render/2pierce/uv.hpp"
#include "../../../../../render/2pierce/projector.hpp"




void expose_IceRay_render_pierce__pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pierce );

  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;

  boost::python::class_<Tf__pure, boost::noncopyable>( "RenderPierce_pure", boost::python::no_init );
 }

void expose_IceRay_render_pierce_UV()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pierce );

  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_UV  Tf_UV;

  boost::python::class_<Tf_UV, boost::python::bases<Tf__pure> >("RenderPierceUV" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GT_coord>() )
   //.def("size",     &TF_engine::F_do        )
   //.def("get",     &TF_engine::F_work      )
   //.def("set",     &TF_engine::F_stop      )
  ;

 }


typedef GS_DDMRM::S_IceRay::S_camera::GC__pure           GTs_camera;
typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure    GTs_ray;

void expose_IceRay_render_pierce_Projector()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pierce );

  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_projector  Tf_projector;

  typedef void (Tf_projector::*T_setCamera )( GTs_camera *  );
  typedef void (Tf_projector::*T_setRay    )( GTs_ray    *  );

  T_setCamera  I_setCamera = &Tf_projector::Fv_camera;
  T_setRay     I_setRay    = &Tf_projector::Fv_ray;

  boost::python::class_<Tf_projector, boost::python::bases<Tf__pure> >("RenderPierceProjector" )
    .def( boost::python::init<>() )
  //.def( boost::python::init<GT_coord>() )
   .def("camera",  I_setCamera  )
 //.def("camera",  &Tf__projector::F_camera   )
   .def("ray",     I_setRay     )
 //.def("ray",     &Tf__projector::F_ray      )
  ;

 }


