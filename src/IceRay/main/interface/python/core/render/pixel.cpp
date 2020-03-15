
#include "../../def_submodule.hpp"

#include "IceRay/render/1pixel/pixel.hpp"
#include "IceRay/render/1pixel/strategy/strategy.hpp"


void expose_IceRay_render_pixel__pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pixel  );

  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure Tf__pure;

  boost::python::class_<Tf__pure, boost::noncopyable>( "RenderPixel_pure", boost::python::no_init );
 }

void expose_IceRay_render_pixel_filter()
{
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pixel  );
  MAKE_SUBMODULE( filter  );

  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure Tf__pure;

  boost::python::class_<Tf__pure, boost::noncopyable>( "RenderPixelFilter_pure", boost::python::no_init );
}

void expose_IceRay_render_pixel_strategy()
{
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pixel  );
  MAKE_SUBMODULE( strategy  );

  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure Tf__pure;

  boost::python::class_<Tf__pure, boost::noncopyable>( "RenderPixelStrategy_pure", boost::python::no_init );

  {
    typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_center Tf_center;

    boost::python::class_<Tf_center, boost::python::bases<Tf__pure> >( "RenderPixelStrategyCenter" )
      .def( boost::python::init<>() )
    ;
  }

  {
   typedef GS_DDMRM::S_IceRay::S_type::GT_size                   GTs_size;
   typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_grid Tf_grid;

   bool (Tf_grid::*I_setSize  )( GTs_size const& ) = &Tf_grid::F_size;


    boost::python::class_<Tf_grid, boost::python::bases<Tf__pure> >( "RenderPixelStrategyGrid" )
      .def( boost::python::init<>() )
      .def( boost::python::init<GTs_size>() )
      .def("size",   I_setSize      )
    ;
  }

}
void expose_IceRay_render_pixel_Base()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pixel  );

  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure TF__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base TF_base;

  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure    Tf_filterPure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure  Tf_strategyPure;

  void (TF_base::*I_setFilter  )( Tf_filterPure   * ) = &TF_base::F_filter;
  void (TF_base::*I_setStrategy)( Tf_strategyPure * ) = &TF_base::F_strategy;

    boost::python::class_<TF_base, boost::python::bases<TF__pure> >( "RenderPixelBasic" )
      .def( boost::python::init<>() )
      .def("filter",     I_setFilter        )
      .def("strategy",   I_setStrategy      )
    ;
 }

void expose_IceRay_render_pixel_UV()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pixel );

  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC_UV  Tf_UV;

  boost::python::class_<Tf_UV, boost::python::bases<Tf__pure> >("RenderPixelUV" )
    .def( boost::python::init<>() )
    //.def( boost::python::init<GT_coord>() )
    //.def("size",     &TF_engine::F_do        )
    //.def("get",     &TF_engine::F_work      )
    //.def("set",     &TF_engine::F_stop      )
  ;
 }

void expose_IceRay_render_pixel_constant()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( pixel );

  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure  Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_pixel::GC_constant  Tf_constant;

  // TODO Tf_color const& (TF_base::*I_getColor )( )                 = &TF_base::F_color;
  // TODO bool            (TF_base::*I_setcolor )( Tf_color const& ) = &TF_base::F_color;

  boost::python::class_<Tf_constant, boost::python::bases<Tf__pure> >("RenderPixelConstant" )
    .def( boost::python::init<>() )
   // TODO .def( boost::python::init<GT_color>() )
   // TODO .def("color",     &TF_engine::F_color        )
   // TODO .def("color",     &TF_engine::F_color        )
  ;
 }
