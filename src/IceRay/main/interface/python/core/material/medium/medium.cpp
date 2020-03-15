#include "../../../def_submodule.hpp"
#include "IceRay/material/medium/quadratic.hpp"
#include "IceRay/material/medium/linear.hpp"
#include "IceRay/material/medium/exponential.hpp"
#include "IceRay/material/medium/constant.hpp"
#include "IceRay/material/medium/pattern.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;

typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure         GTs__pure;


void expose_IceRay_material_medium__pure()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( medium );

  boost::python::class_<GTs__pure, boost::noncopyable>( "MaterialMedium_pure", boost::python::no_init )
  ;
 }

void expose_IceRay_material_medium_constant()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( medium );

  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_constant      GTs_constant;


  typedef  bool                (GTs_constant::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_constant::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_constant::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_constant::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_constant::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_constant::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_constant, boost::python::bases< GTs__pure > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialMediumConstant" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_color, GTs_color>() )
  ;

  //boost::python::scope I_scope = I_this;
 }

void expose_IceRay_material_medium_linear()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( medium );

  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_linear        GTs_linear;

  typedef  bool                (GTs_linear::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_linear::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_linear::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_linear::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_linear::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_linear::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_linear, boost::python::bases< GTs__pure > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialMediumLinear")
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_color, GTs_scalar, GTs_scalar >() )
  ;

  //boost::python::scope I_scope = I_this;

 }

void expose_IceRay_material_medium_quadratic()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( medium );

  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_quadratic     GTs_quadratic;


  typedef  bool                (GTs_quadratic::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_quadratic::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_quadratic::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_quadratic::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_quadratic::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_quadratic::*Tf_getCoord3D  )( void ) const;


  typedef boost::python::class_<GTs_quadratic, boost::python::bases< GTs__pure > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialMediumQuadratic")
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_color, GTs_scalar, GTs_scalar, GTs_scalar >() )
  ;
  //boost::python::scope I_scope = I_this;
 }

void expose_IceRay_material_medium_exponential()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( medium );

  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_exponential   GTs_exponential;

  typedef  bool                (GTs_exponential::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_exponential::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_exponential::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_exponential::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_exponential::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_exponential::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_exponential, boost::python::bases< GTs__pure > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialMediumExponential" )
    .def( boost::python::init<>( ) )
    .def( boost::python::init< GTs_color, GTs_scalar >() )
  ;

  //boost::python::scope I_scope = I_this;
 }


void expose_IceRay_material_medium_pattern()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( medium );

  typedef GS_DDMRM::S_IceRay::S_material::S_medium::GC_pattern   GTs_pattern;

  typedef  bool                (GTs_pattern::*Tf_setScalar   )( GTs_scalar const& );
  typedef  GTs_scalar const&   (GTs_pattern::*Tf_getScalar   )( void ) const;
  typedef  bool                (GTs_pattern::*Tf_setColor    )( GTs_color const& );
  typedef  GTs_color const&    (GTs_pattern::*Tf_getColor    )( void ) const;
  typedef  bool                (GTs_pattern::*Tf_setCoord3D  )( GTs_coord3D const& );
  typedef  GTs_coord3D const&  (GTs_pattern::*Tf_getCoord3D  )( void ) const;

  typedef boost::python::class_<GTs_pattern, boost::python::bases< GTs__pure > > Tf_this;

  boost::python::object I_this = Tf_this( "MaterialMediumPattern" )
    .def( boost::python::init<>( ) )
  ;

  //boost::python::scope I_scope = I_this;
 }