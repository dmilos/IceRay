#include "../../../def_submodule.hpp"

#include "IceRay/material/pattern/_pure.hpp"

#include "IceRay/material/compute/pattern/constant.hpp"
#include "IceRay/material/compute/pattern/function.hpp"
#include "IceRay/material/compute/instruction.hpp"

typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  GTs_coord2D;
typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    GTs_color;
typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction         GTs_instruction;


void expose_IceRay_material_compute_pattern_constant()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( pattern );

typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_size      GTs_constSize;
  typedef boost::python::class_< GTs_constSize, boost::python::bases< GTs_instruction > > ( "MaterialPatternSizeConstant" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_size,GTs_size >( ) )
  ;

typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_scalar    GTs_constScalar;
  typedef boost::python::class_< GTs_constScalar, boost::python::bases< GTs_instruction > > ( "MaterialPatternScalarConstant" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_scalar,GTs_size >( ) )
  ;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_color     GTs_constColor;
  typedef boost::python::class_< GTs_constColor, boost::python::bases< GTs_instruction > > ( "MaterialPatternColorConstant" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_color,GTs_size >( ) )
  ;

  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_constant::GT_coord3D   GTs_constCoord3D;
  typedef boost::python::class_< GTs_constCoord3D, boost::python::bases< GTs_instruction > > ( "MaterialPatternCoord3DConstant" )
    .def( boost::python::init<>() )
    .def( boost::python::init<GTs_coord3D,GTs_size >( ) )
  ;
  
// TODO typedef GS_DDMRM::S_IceRay::S_material::S_compute::GT_constCoord2D   GTs_constCoord2D;
// TODO typedef GS_DDMRM::S_IceRay::S_material::S_compute::GT_constCoord4D   GTs_constCoord4D;
// TODO typedef GS_DDMRM::S_IceRay::S_material::S_compute::GT_constCell2D    GTs_constCell2D;
// TODO typedef GS_DDMRM::S_IceRay::S_material::S_compute::GT_constCell3D    GTs_constCell3D;
// TODO typedef GS_DDMRM::S_IceRay::S_material::S_compute::GT_constCell4D    GTs_constCell4D;

 }



void expose_IceRay_material_compute_pattern_function()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( core );
  MAKE_SUBMODULE( material );
  MAKE_SUBMODULE( pattern );

  {
   typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size                     Tf_pattern;
   boost::python::class_< Tf_pattern, boost::noncopyable >( "MaterialPatternSize_Pure", boost::python::no_init );

   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_size    TF_function;
   boost::python::class_< TF_function, boost::python::bases< GTs_instruction > >( "MaterialPatternFunctionSize" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Tf_pattern*,GTs_size,GTs_size>( ) )
   ;
  }

  {
   typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar                     Tf_pattern;
   boost::python::class_< Tf_pattern, boost::noncopyable >( "MaterialPatternScalar_Pure", boost::python::no_init );

   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_scalar    TF_function;
   boost::python::class_< TF_function, boost::python::bases< GTs_instruction > >( "MaterialPatternFunctionScalar" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Tf_pattern*,GTs_size,GTs_size>( ) )
   ;
  }

  {
   typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color                     Tf_pattern;
   boost::python::class_< Tf_pattern, boost::noncopyable >( "MaterialPatternColor_Pure", boost::python::no_init );

   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_color    TF_function;
   boost::python::class_< TF_function, boost::python::bases< GTs_instruction > >( "MaterialPatternFunctionColor" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Tf_pattern*,GTs_size,GTs_size>( ) )
   ;
  }

  {
   typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord3D                     Tf_pattern;
   boost::python::class_< Tf_pattern, boost::noncopyable >( "MaterialPatternCoord3D_Pure", boost::python::no_init );

   typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::S_function::GT_coord3D TF_function;
   boost::python::class_< TF_function, boost::python::bases< GTs_instruction > >( "MaterialPatternFunctionCoord3D" )
    .def( boost::python::init<>() )
    .def( boost::python::init<Tf_pattern*,GTs_size,GTs_size>( ) )
    ;
  }


 }
