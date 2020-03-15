

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/chandelier.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier          GTs_chandelier;


void expose_IceRay_light_Chandelier()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  boost::python::class_<GTs_chandelier, boost::python::bases<GTs__pure> >( "LightChandelier" )
    .def( boost::python::init<>() )
    .def( "add",   &GTs_chandelier::F_add  )
    .def( "size",  &GTs_chandelier::F_size, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
  ;

 }
