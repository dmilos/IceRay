#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/light/generator.hpp"

#include "IceRay/material/compute/light/spotUVW.hpp"
#include "IceRay/material/compute/light/spotCull.hpp"

#include "IceRay/material/compute/light/swarmA.hpp"
#include "IceRay/material/compute/light/swarmB.hpp"
#include "IceRay/material/compute/light/swarmC.hpp"

#include "IceRay/material/compute/instruction.hpp"

typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction         GTs_instruction;
typedef GS_DDMRM::S_IceRay::S_light::GC__pure    GTs__pure;


void expose_IceRay_material_light_generator()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( light );

typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_generator  GTs_generator;
  typedef boost::python::class_<GTs_generator, boost::python::bases< GTs_instruction  > > Tf_this;

  //typedef  GTs__pure * (GTs_generator::*Tf_getRadius)(void) const;
  typedef  bool (GTs_generator::*Tf_setLight )(GTs__pure *);

  Tf_setLight I_setLight = &GTs_generator::F_light;

  boost::python::object I_this = Tf_this( "MaterialLightGenerator" ) // TODO MaterialLightLightGenerator, MaterialLightLightGenerator0
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs__pure*, GTs_size>() )
    .def("light",  I_setLight )
  ;

  boost::python::scope I_scope = I_this;

  boost::python::enum_<GTs_generator::Ee_input>( "Input" )
    .export_values()
   ;

  boost::python::enum_<GTs_generator::Ee_output>( "Output" )
    .value( "result",     GTs_generator::En_outLight_Result )
    .export_values()
   ;

 }

void expose_IceRay_material_light_spotSwarm()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( light );

  {
    typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_swarmA     Ts_swarmA;
  
    typedef boost::python::class_<Ts_swarmA, boost::python::bases< GTs_instruction  > > Tf_this;
  
    boost::python::object I_this = Tf_this( "MaterialLightSpotSwarmA" )
      .def( boost::python::init<>() )
      .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size>() )
    ;
  }

  {
    typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_swarmB     Ts_swarmB;
  
    typedef boost::python::class_<Ts_swarmB, boost::python::bases< GTs_instruction  > > Tf_this;
  
    boost::python::object I_this = Tf_this( "MaterialLightSpotSwarmB" )
      .def( boost::python::init<>() )
      .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>() )
    ;
  }

  {
   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_swarmC     Ts_swarmC;
 
   typedef boost::python::class_<Ts_swarmC, boost::python::bases< GTs_instruction  > > Tf_this;
 
   boost::python::object I_this = Tf_this( "MaterialLightSpotSwarmC" )
     .def( boost::python::init<>() )
     .def( boost::python::init<GTs_size,GTs_size,GTs_size,GTs_size>() )
   ;
  }

 }

void expose_IceRay_material_light_spotUVW()
 {
//MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( light );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_spotUVW     GTs_spotUVW;

  typedef boost::python::class_<GTs_spotUVW, boost::python::bases< GTs_instruction  > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialLightSpotUVW" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size, GTs_size, GTs_size, GTs_size >() )
  ;

  boost::python::scope I_scope = I_this;

  //boost::python::enum_<GTs_swarm0::Ee_input>( "Input" )
  //  .value( "point",     GTs_swarm0::En_inCoord_Point  )
  //  .value( "normal",    GTs_swarm0::En_inCoord_Normal )
  //  .value( "start",     GTs_swarm0::En_inSize_SpotStart   )
  //  .value( "light",     GTs_swarm0::En_inLight_Start      )
  //  .value( "light",     GTs_swarm0::En_inLight_Count      )
  ////.value( "limit",     GTs_swarm0::En_inSize_SpotLimit   )
  //  .export_values()
  //;
 }

void expose_IceRay_material_light_spotCull()
{
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( light );

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_light::GC_spotCull  Ts_cull;
  typedef boost::python::class_<Ts_cull, boost::python::bases< GTs_instruction  > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialLightSpotCull" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size>() )
    ;

  boost::python::scope I_scope = I_this;

  //boost::python::enum_<GTs_generator::Ee_input>( "Input" )
  //  .export_values()
  //  ;
  //
  //boost::python::enum_<GTs_generator::Ee_output>( "Output" )
  //  .value( "result",     GTs_generator::En_outLight_Result )
  //  .export_values()
  //  ;
}
