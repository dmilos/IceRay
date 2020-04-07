
#include <iostream>
#include <iomanip>

#include <boost/python.hpp>

#include "../../def_submodule.hpp"

#include "../../../../../render/engine.hpp"
#include "../../../../../type/picture/memory.hpp"

namespace
 {
  typedef GS_DDMRM::S_IceRay::S_render::GC_engine  GFs_engine;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure GTs_picture;

  bool start( GFs_engine & P_engine, GTs_picture * P_picture )
   {
    std::cout << std::endl;
    P_engine.F_do( *P_picture );
    return true;
   }

}

void expose_IceRay_render_Engine()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );

  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure   Tf_scanner;
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure     Tf_pixel;
  typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure    Tf_pierce;
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure     Tf_sheaf;
  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure       Tf_ray;

  void (GFs_engine::*I_setScanner)( Tf_scanner * ) = &GFs_engine::F_scanner;
  void (GFs_engine::*I_setPixel  )( Tf_pixel   * ) = &GFs_engine::F_pixel;
  void (GFs_engine::*I_setPierce )( Tf_pierce  * ) = &GFs_engine::F_pierce;
  void (GFs_engine::*I_setSheaf   )( Tf_sheaf   * ) = &GFs_engine::F_sheaf;
  void (GFs_engine::*I_setRay    )( Tf_ray     * ) = &GFs_engine::F_ray;

   boost::python::class_<GFs_engine>( "RenderEngine" )
      .def( boost::python::init<>() )
      .def( "start",    &start        )
      .def( "work",     &GFs_engine::F_work      )
      .def( "stop",     &GFs_engine::F_stop      )
      .def( "progress", &GFs_engine::F_progress  )
    //.def( "join",     &GFs_engine::F_join      )

      .def( "scanner",  I_setScanner )
      .def( "pixel",    I_setPixel   )
      .def( "pierce",   I_setPierce  )
      .def( "sheaf",    I_setSheaf    )
      .def( "ray",      I_setRay     )
  ;

 }
