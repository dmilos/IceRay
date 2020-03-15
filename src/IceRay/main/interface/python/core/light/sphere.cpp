

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "../../../../../light/sphere.hpp"

typedef GS_DDMRM::S_IceRay::S_light::S_type::GT_size GTs_size;

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   GTs_spot;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;
typedef GS_DDMRM::S_IceRay::S_light::GC_sphere         GTs_sphere;


void expose_IceRay_light_Sphere()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );


  typedef  GTs_coord3D const& (GTs_sphere::*Tf_getCenter  )(void) const;
  typedef  bool (GTs_sphere::*Tf_setCenter  )(GTs_coord3D const&);
  typedef  GTs_scalar const& (GTs_sphere::*Tf_getRadius)(void) const;
  typedef  bool (GTs_sphere::*Tf_setRadius  )(GTs_scalar const&);

  typedef  GTs_spot const& (GTs_sphere::*Tf_getSpot )(void) const;
  typedef  bool (GTs_sphere::*Tf_setSpot )(GTs_spot const&);

  Tf_getCenter I_getCenter = &GTs_sphere::F_center;
  Tf_setCenter I_setCenter = &GTs_sphere::F_center;

  Tf_getRadius I_getRadius = &GTs_sphere::F_radius;
  Tf_setRadius I_setRadius = &GTs_sphere::F_radius;

  Tf_getSpot  I_getSpot = &GTs_sphere::F_spot;
  Tf_setSpot  I_setSpot = &GTs_sphere::F_spot;

  typedef  GTs_size const& (GTs_sphere::*Tf_getSize )(void) const;
  typedef  bool (GTs_sphere::*Tf_setSize  )(GTs_size const&);
  Tf_getSize I_getSample = &GTs_sphere::F_sample;
  Tf_setSize I_setSample = &GTs_sphere::F_sample;

  boost::python::class_<GTs_sphere, boost::python::bases<GTs__pure> >( "LightSphere" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_spot>() )
    .def( boost::python::init<GTs_spot,GTs_scalar >() )
    .def( boost::python::init<GTs_spot,GTs_scalar, GTs_size >() )
    .def( "spot",    I_getSpot, boost::python::return_value_policy<boost::python::copy_const_reference>()        )
    .def( "spot",    I_setSpot      )
    .def( "center",  I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "center",  I_setCenter )
    .def( "radius",  I_getRadius, boost::python::return_value_policy<boost::python::copy_const_reference>()  )
    .def( "radius",  I_setRadius )
    .def( "sample",  I_getSample, boost::python::return_value_policy<boost::python::copy_const_reference>() )
    .def( "sample",  I_setSample      )
  ;

 }
