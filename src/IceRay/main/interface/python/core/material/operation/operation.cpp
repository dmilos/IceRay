

#include "../../../def_submodule.hpp"

#include "IceRay/material/compute/instruction.hpp"

#include "IceRay/material/compute/operation/convert.hpp"
#include "IceRay/material/compute/operation/switch.hpp"
#include "IceRay/material/compute/operation/clamp.hpp"
#include "IceRay/material/compute/operation/mapping.hpp"
#include "IceRay/material/compute/operation/operator.hpp"

typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  GTs_coord2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;


typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction               GTs_instruction;


void expose_IceRay_material_compute_operation_switch()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( convert );

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GT_switchSize       GTs_switchSize;
  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GT_switchScalar     GTs_switchScalar;
  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GT_switchColor      GTs_switchColor;
  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GT_switchCoord3D    GTs_switchCoord3D;

  typedef boost::python::class_< GTs_switchSize, boost::python::bases< GTs_instruction > > ( "MaterialSwitchSize" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;

  typedef boost::python::class_< GTs_switchScalar, boost::python::bases< GTs_instruction > > ( "MaterialSwitchScalar" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;
  typedef boost::python::class_< GTs_switchColor, boost::python::bases< GTs_instruction > > ( "MaterialSwitchColor" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;
  typedef boost::python::class_< GTs_switchCoord3D, boost::python::bases< GTs_instruction > > ( "MaterialSwitchCoord3D" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;
 }

void expose_IceRay_material_compute_operation_scalar_clamp()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( convert );

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_clamp::GT_ramp    GTs_ramp;
  typedef boost::python::class_< GTs_ramp, boost::python::bases< GTs_instruction > > ( "MaterialScalarClipRamp" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_clamp::GT_saw    GTs_saw;
  typedef boost::python::class_< GTs_saw, boost::python::bases< GTs_instruction > > ( "MaterialScalarClipSaw" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_clamp::GT_wave    GTs_wave;
  typedef boost::python::class_< GTs_wave, boost::python::bases< GTs_instruction > > ( "MaterialScalarClipWave" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;
 }

void expose_IceRay_material_compute_operation_scalar_arithmetic()
 {
  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_size::GT_plus    GTs_Plus;
  typedef boost::python::class_< GTs_Plus, boost::python::bases< GTs_instruction > > ( "MaterialScalarArithmeticPlus" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_size::GT_minus    GTs_Minus;
  typedef boost::python::class_< GTs_Minus, boost::python::bases< GTs_instruction > > ( "MaterialScalarArithmeticMinus" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_size::GT_multiplies    GTs_Multiply;
  typedef boost::python::class_< GTs_Multiply, boost::python::bases< GTs_instruction > > ( "MaterialScalarArithmeticMultiply" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_size::GT_divides    GTs_Divide;
  typedef boost::python::class_< GTs_Divide, boost::python::bases< GTs_instruction > > ( "MaterialScalarArithmeticDivide" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;
 }


void expose_IceRay_material_compute_operation_color_arithmetic()
 {
  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_plus    GTs_Plus;
  typedef boost::python::class_< GTs_Plus, boost::python::bases< GTs_instruction > > ( "MaterialColorArithmeticPlus" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
  //TODO .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size>( ) )
  //TODO .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>( ) )
  //TODO .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>( ) )
  //TODO .def( boost::python::init< GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_minus    GTs_Minus;
  typedef boost::python::class_< GTs_Minus, boost::python::bases< GTs_instruction > > ( "MaterialColorArithmeticMinus" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_multiplies    GTs_multiplies;
  typedef boost::python::class_< GTs_multiplies, boost::python::bases< GTs_instruction > > ( "MaterialColorArithmeticMultiply" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_divides    GTs_divides;
  typedef boost::python::class_< GTs_divides, boost::python::bases< GTs_instruction > > ( "MaterialColorArithmeticDivide" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size,GTs_size>( ) )
    ;
 }

void expose_IceRay_material_compute_operation_mapping()
 {

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( convert );

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_identity    GTs_identity;
  typedef boost::python::class_< GTs_identity, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingIdentity" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2cylindric GTs_cartesian2cylindric;
  typedef boost::python::class_< GTs_cartesian2cylindric, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2Cylindric" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2spherical GTs_cartesian2spherical;
  typedef boost::python::class_< GTs_cartesian2spherical, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2Spherical" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cylindric2cartesian GTs_cylindric2cartesian;
  typedef boost::python::class_< GTs_cylindric2cartesian, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCylindric2Cartesian" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cylindric2spherical GTs_cylindric2spherical;
  typedef boost::python::class_< GTs_cylindric2spherical, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCylindric2Spherical" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_spherical2cartesian    GTs_spherical2cartesian;
  typedef boost::python::class_< GTs_spherical2cartesian, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingSpherical2Cartesian" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_spherical2cylindric GTs_spherical2cylindric;
  typedef boost::python::class_< GTs_spherical2cylindric, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingSpherical2Cylindric" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;


  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2package    GTs_cartesian2package;
  typedef boost::python::class_< GTs_cartesian2package, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2Package" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2torus    GTs_cartesian2torus;
  typedef boost::python::class_< GTs_cartesian2torus, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2Torus" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2tablecloth    GTs_cartesian2tablecloth;
  typedef boost::python::class_< GTs_cartesian2tablecloth, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2Tablecloth" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2woodX    GTs_cartesian2woodX;
  typedef boost::python::class_< GTs_cartesian2woodX, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2WoodX" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2woodY    GTs_cartesian2woodY;
  typedef boost::python::class_< GTs_cartesian2woodY, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2WoodY" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;
  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2woodZ    GTs_cartesian2woodZ;
  typedef boost::python::class_< GTs_cartesian2woodZ, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2WoodZ" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_euclid2max    GTs_euclid2max;
  typedef boost::python::class_< GTs_euclid2max, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingEuclid2Max" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_max2euclid    GTs_max2euclid;
  typedef boost::python::class_< GTs_max2euclid, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingMax2Euclid" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_mapping::GT_cartesian2fisheye    GTs_cartesian2fisheye;
  typedef boost::python::class_< GTs_cartesian2fisheye, boost::python::bases< GTs_instruction > > ( "MaterialCoord3DMappingCartesian2Fisheye" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

 }

void expose_IceRay_material_compute_operation_convert()
 {
// TODO CoordND conversions

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2size    GTs_bool2size;
  typedef boost::python::class_< GTs_bool2size, boost::python::bases< GTs_instruction > > ( "MaterialConvertBool2Size" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_bool2scalar  GTs_bool2scalar;
  typedef boost::python::class_< GTs_bool2scalar, boost::python::bases< GTs_instruction > > ( "MaterialConvertBool2Scalar" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2bool    GTs_size2bool  ;
  typedef boost::python::class_< GTs_size2bool, boost::python::bases< GTs_instruction > > ( "MaterialConvertSize2Bool" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_size2scalar  GTs_size2scalar;
  typedef boost::python::class_< GTs_size2scalar, boost::python::bases< GTs_instruction > > ( "MaterialConvertSize2Scalar" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
    ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2size  GTs_scalar2size;
  typedef boost::python::class_< GTs_scalar2size, boost::python::bases< GTs_instruction > > ( "MaterialConvertScalar2Size" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
  ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2bool  GTs_scalar2bool;
  typedef boost::python::class_< GTs_scalar2bool, boost::python::bases< GTs_instruction > > ( "MaterialConvertScalar2Bool" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
  ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_scalar2color GTs_scalar2color;
  typedef boost::python::class_< GTs_scalar2color, boost::python::bases< GTs_instruction > > ( "MaterialConvertScalar2Color" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
  ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2scalar GTs_color2scalar;
  typedef boost::python::class_< GTs_color2scalar, boost::python::bases< GTs_instruction > > ( "MaterialConvertColor2Scalar" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
  ;


  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_color2coord GTs_color2coord;
  typedef boost::python::class_< GTs_color2coord, boost::python::bases< GTs_instruction > > ( "MaterialConvertColor2Coord3D" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
  ;

  typedef  GS_DDMRM::S_IceRay::S_material::S_compute::S_convert::GT_coord2color GTs_coord2color;
  typedef boost::python::class_< GTs_coord2color, boost::python::bases< GTs_instruction > > ( "MaterialConvertCoord3D2Color" )
    .def( boost::python::init<>() )
    .def( boost::python::init< GTs_size,GTs_size>( ) )
  ;

 }

