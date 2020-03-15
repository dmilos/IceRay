#include "../../def_submodule.hpp"

#include <boost/python.hpp>


#include "IceRay/render/0scanner/block.hpp"
#include "IceRay/render/0scanner/parallel.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D    GTs_cell2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  GTs_coord2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


void expose_IceRay_render_scanner__pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( core );

  MAKE_SUBMODULE( render  );
  MAKE_SUBMODULE( scanner );

  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  Tf__pure;

  boost::python::class_<Tf__pure, boost::noncopyable>( "RenderScanner_pure", boost::python::no_init );
 }

void expose_IceRay_render_scanner_Block()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( core );

  MAKE_SUBMODULE( render  );
  MAKE_SUBMODULE( scanner );

  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  TF__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block  TF_block;

    typedef TF_block::T_range  TF_range;


    typedef TF_block::T_report (TF_block::*T_setRange )( TF_range const& );
    T_setRange I_setRange = &TF_block::F_range;

    typedef TF_block::T_report (TF_block::*T_setHot )( GTs_cell2D const& );
    T_setHot I_setHot = &TF_block::F_hot;

  boost::python::class_<TF_block, boost::python::bases<TF__pure> >( "RenderScannerBlock" )
      .def( boost::python::init<>() )
      .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size >() )
      .def( boost::python::init<GTs_cell2D,GTs_cell2D >() )
      .def("range",     I_setRange )
      .def("hot",       I_setHot )
  //.def("top",       &TF_engine::F_range )
  //  .def("bottom",    &TF_engine::F_range )
  //  .def("left",      &TF_engine::F_range )
  //  .def("right",     &TF_engine::F_range )
  //  .def("range",     &TF_engine::F_range )
  ;

 }

void expose_IceRay_render_scanner_Parallel()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( core );

  MAKE_SUBMODULE( render  );
  MAKE_SUBMODULE( scanner );

  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure  TF__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC_parallel TF_parallel;

  boost::python::class_<TF_parallel, boost::python::bases<TF__pure> >( "RenderScannerParallel" )
      .def( boost::python::init<>() )
      //.def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size >() )
      //.def( boost::python::init<GTs_cell2D,GTs_cell2D >() )
     //.def("threads",       &TF_engine::F_range )
  //  .def("top",       &TF_engine::F_range )
  //  .def("bottom",    &TF_engine::F_range )
  //  .def("left",      &TF_engine::F_range )
  //  .def("right",     &TF_engine::F_range )
  //  .def("range",     &TF_engine::F_range )
  //  .def("range",     &TF_engine::F_range )
  ;

 }

