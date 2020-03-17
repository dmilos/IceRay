

#include <boost/python.hpp>
#include "../../def_submodule.hpp"

#include "IceRay/light/suns.hpp"
#include "IceRay/light/sung.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_light::GC__pure          GTs__pure;


void expose_IceRay_light_SunGeneral()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef GS_DDMRM::S_IceRay::S_light::GC_sung            Tf_sunG;

  typedef  bool (Tf_sunG::*Tf_setChild  )( GTs__pure * );
  Tf_setChild I_setChild = &Tf_sunG::F_child;

  boost::python::class_< Tf_sunG, boost::python::bases<GTs__pure> >( "LightSunGeneral" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__pure *>() )
    .def( "child", I_setChild      )
   ;

 }

void expose_IceRay_light_SunSpot()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( light );

  typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot   Tf_spot;
  typedef GS_DDMRM::S_IceRay::S_light::GC_suns           Tf_suns;

  typedef  GTs_coord3D const& (Tf_suns::*Tf_getCoord  )(void) const;
  typedef  bool (Tf_suns::*Tf_setCoord  )(GTs_coord3D const&);

  Tf_getCoord I_getCenter = &Tf_suns::F_center;
  Tf_setCoord I_setCenter = &Tf_suns::F_center;

  typedef  Tf_spot const& (Tf_suns::*Tf_getSpot  )(void) const;
  Tf_getSpot I_getSpot = &Tf_suns::F_spot;
  typedef  bool (Tf_suns::*Tf_setSpot  )(Tf_spot const&);
  Tf_setSpot I_setSpot = &Tf_suns::F_spot;

  boost::python::class_< Tf_suns, boost::python::bases<GTs__pure> >( "LightSunSpot" )
      .def( boost::python::init<>() )
      .def( boost::python::init<Tf_spot const&>() )
      .def("spot",   I_getSpot, boost::python::return_value_policy<boost::python::copy_const_reference>() )
      .def("spot",   I_setSpot    )
      .def("center",      I_getCenter, boost::python::return_value_policy<boost::python::copy_const_reference>() )
      .def("center",      I_setCenter      )
      ;
 }
