
#include "../../def_submodule.hpp"

#include "IceRay/render/3sheaf/sheaf.hpp"


void expose_IceRay_render_sheaf__pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( sheaf  );

  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure Tf__pure;

  boost::python::class_<Tf__pure, boost::noncopyable>( "RenderSheaf_pure", boost::python::no_init );
 }

void expose_IceRay_render_sheaf_ALL()
{
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( render );
  MAKE_SUBMODULE( sheaf  );

  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_all Tf_all;

  typedef GS_DDMRM::S_IceRay::S_render::S_ray::GC__pure Tf_ray;

  void (Tf_all::*I_setRay  )( Tf_ray   * ) = &Tf_all::Fv_ray;

  boost::python::class_<Tf_all, boost::python::bases<Tf__pure> >( "RenderSheafAll" )
    .def( boost::python::init<>() )
    .def("ray",  I_setRay  )
 ;

}