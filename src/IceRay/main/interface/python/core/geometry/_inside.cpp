
#include "../../def_submodule.hpp"

#include "../../../../../geometry/_pure/inside.hpp"

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base    GTs__base;
typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside   GTs_inside;


void expose_IceRay_geometry__inside()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( geometry );

  boost::python::object I_inside = boost::python::class_< GTs_inside, boost::noncopyable, boost::python::bases<GTs__base> >( "Geometry_Inside", boost::python::no_init )
   ;

  boost::python::scope I_scope = I_inside;

  boost::python::enum_<GTs_inside::T_location>( "where" )
         .value( "nowhere",     GTs_inside::En_nowhere     )
         .value( "inside",      GTs_inside::En_in          )
         .value( "outside",     GTs_inside::En_out         )
         .value( "symmetric",   GTs_inside::En_symmetric    )
         .value( "surface",     GTs_inside::En_surface     )
         .value( "closure",     GTs_inside::En_closure     )
         .value( "complement",  GTs_inside::En_complement  )
         .value( "everywhere",  GTs_inside::En_everywhere  )
         .export_values()
        ;

 }
