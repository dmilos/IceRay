
#include "../../def_submodule.hpp"

#include "IceRay/material/pattern/image.hpp"
#include "IceRay/material/pattern/onion.hpp"
#include "IceRay/material/pattern/level.hpp"
#include "IceRay/material/pattern/checker.hpp"
#include "IceRay/material/pattern/hexagon.hpp"
#include "IceRay/material/pattern/brick.hpp"
#include "IceRay/material/pattern/noise/noise.hpp"
#include "IceRay/material/pattern/uvw.hpp"
#include "IceRay/material/pattern/wave.hpp"
#include "IceRay/material/pattern/side/side.hpp"



typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;

typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size          GTs__size;
typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar        GTs__scalar;
typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color         GTs__color;
typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord         GTs__coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure              T_image;


void expose_IceRay_material_pattern__pure()
 {
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( pattern );

  boost::python::class_< GTs__size,    boost::noncopyable > ( "FunctionSize_Pure",    boost::python::no_init );
  boost::python::class_< GTs__scalar,  boost::noncopyable > ( "FunctionScalar_Pure",  boost::python::no_init );
  boost::python::class_< GTs__color,   boost::noncopyable > ( "FunctionColor_Pure",   boost::python::no_init );
  boost::python::class_< GTs__coord3D, boost::noncopyable > ( "FunctionCoord3D_Pure", boost::python::no_init );
 }


void expose_IceRay_library_function_function()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( pattern );

  expose_IceRay_material_pattern__pure();

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_image          GTs_image;
  boost::python::class_<GTs_image, boost::python::bases< GTs__color > > ( "FunctionColorImage" )
   .def( boost::python::init< T_image*>() )
  ;

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_uvw          GTs_uvw;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base          T_geometry;
  boost::python::class_<GTs_uvw, boost::python::bases< GTs__coord3D > > ( "FunctionCoord3DGeometryUVW" )
   .def( boost::python::init< T_geometry*>() )
  ;

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_onion          GTs_onion;
  boost::python::class_<GTs_onion, boost::python::bases< GTs__scalar > >( "FunctionScalarOnion" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_coord3D >() )
    ;

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_level          GTs_level;
  boost::python::class_<GTs_level, boost::python::bases< GTs__scalar > >( "FunctionScalarLevel" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_coord3D >() )
    ;

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_checker        GTs_checker;
  boost::python::class_<GTs_checker, boost::python::bases< GTs__size > >( "FunctionSizeChecker" )
    .def( boost::python::init<>() )
    ;

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_hexagon        GTs_hexagon;
  boost::python::class_<GTs_hexagon, boost::python::bases< GTs__size > >( "FunctionSizeHexagon" )
    .def( boost::python::init<>() )
  ;

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_brick          GTs_brick;
  boost::python::class_<GTs_brick, boost::python::bases< GTs__size > >( "FunctionSizeBrick" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size>() )
    ;

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_crackle        Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__scalar > > ( "FunctionScalarCrackle" )
    .def( boost::python::init<>() )
  ;}

  { typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_perlin         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__scalar > > ( "FunctionScalarNoisePerlin" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_scalar,GTs_scalar>() )
  ;}

  { typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_gold         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__scalar > > ( "FunctionScalarNoiseGold" )
    .def( boost::python::init<>() )
  ;}

  { typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_VDC         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__scalar > > ( "FunctionScalarNoiseVDC" )
    .def( boost::python::init<>() )
  ;}

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_value            Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__scalar > > ( "FunctionScalarNoiseValue" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_scalar,GTs_scalar>() )
  ;}

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_random         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__scalar > > ( "FunctionScalarNoiseRandom" )
    .def( boost::python::init<>() )
  ;}

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_cells         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__scalar > > ( "FunctionScalarNoiseCells" )
    .def( boost::python::init<>() )
  ;}

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_waveSin         GTs_waveSin;
  boost::python::class_<GTs_waveSin, boost::python::bases< GTs__scalar > > ( "FunctionScalarWaveSin" )
    .def( boost::python::init<>() )
  ;

  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_waveSaw         GTs_waveSaw;
  boost::python::class_<GTs_waveSaw, boost::python::bases< GTs__scalar > > ( "FunctionScalarWaveSaw" )
    .def( boost::python::init<>() )
  ;

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_cube         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__size > > ( "FunctionSizeSideCube" )
    .def( boost::python::init<>() )
  ;}

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_dodecahedron         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__size > > ( "FunctionSizeSideDodecahedron" )
    .def( boost::python::init<>() )
  ;}

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_icosahedron         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__size > > ( "FunctionSizeSideIcosahedron" )
    .def( boost::python::init<>() )
  ;}

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_octahedron         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__size > > ( "FunctionSizeSideOctahedron" )
    .def( boost::python::init<>() )
  ;}

  {typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_tetrahedron         Ts_pattern;
  boost::python::class_<Ts_pattern, boost::python::bases< GTs__size > > ( "FunctionSizeSideTetrahedron" )
    .def( boost::python::init<>() )
  ;}

 }
