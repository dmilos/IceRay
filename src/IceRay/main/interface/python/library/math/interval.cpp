
#include "../../def_submodule.hpp"

#include "../../../../../type/math/coord.hpp"
#include "../../../../../type/math/interval.hpp"


#include <boost/python.hpp>

typedef  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D GTs_interval1D;
typedef  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar2D GTs_interval2D;
typedef  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar3D GTs_interval3D;
typedef  GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar4D GTs_interval4D;

typedef  GS_DDMRM::S_IceRay::S_type::S_interval::GT_size1D GTs_range1D;
typedef  GS_DDMRM::S_IceRay::S_type::S_interval::GT_size2D GTs_range2D;
typedef  GS_DDMRM::S_IceRay::S_type::S_interval::GT_size3D GTs_range3D;
typedef  GS_DDMRM::S_IceRay::S_type::S_interval::GT_size4D GTs_range4D;


typedef GS_DDMRM::S_IceRay::S_type::GT_size               GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D    GTs_cell2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D    GTs_cell3D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D    GTs_cell4D;

typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             GTs_scalar;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  GTs_coord2D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  GTs_coord3D;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D  GTs_coord4D;

void expose_math_type_interval()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( math   );

  typedef  GTs_coord3D const& (GTs_interval3D::*Tf_getLo3D )(void) const;
  Tf_getLo3D I_getLo3D = &GTs_interval3D::lo;

  //typedef  GTs_interval3D & (GTs_interval3D::*Tf_setLo3D   )(GTs_coord3D const&);
  //Tf_setLo3D I_setLo3D = &GTs_interval3D::lo;

  typedef  GTs_coord3D const& (GTs_interval3D::*Tf_getHi3D )(void) const;
  Tf_getHi3D I_getHi3D = &GTs_interval3D::hi;

  //typedef  GTs_interval3D & (GTs_interval3D::*Tf_setHi3D   )(GTs_coord3D const&);
  //Tf_setHi3D I_setHi3D = &GTs_interval3D::hi;

  boost::python::class_<GTs_interval3D>( "MathTypeInterval3D" )
   .def( boost::python::init<>() )
 //.def( boost::python::init<GTs_coord3D>() )
   .def( boost::python::init<GTs_coord3D,GTs_coord3D>() )
   .def( "lo", I_getLo3D, boost::python::return_value_policy<boost::python::copy_const_reference>() )
   //.def( "lo", I_setLo3D, boost::python::return_value_policy<boost::python::reference_existing_object>() )
   .def( "hi", I_getHi3D, boost::python::return_value_policy<boost::python::copy_const_reference>() )
   //.def( "hi", I_setHi3D, boost::python::return_value_policy<boost::python::reference_existing_object>() )
   //.def( "load",     &GTs_interval3D::F_load, boost::python::return_value_policy<boost::python::reference_existing_object>() )
   //.def( "inside",   &GTs_interval3D::F_in    )
   //.def( "outside",  &GTs_interval3D::F_out  )
   //.def( "correct",  &GTs_interval3D::F_correct, boost::python::return_value_policy<boost::python::reference_existing_object>() )

   //.def( "intersect",   )
   //.def( "extend",   )

   //.def( boost::python::self * GTs_scalar3D() )
   //.def( GTs_scalar3D() * boost::python::self  )
   //.def( boost::python::self / GTs_scalar3D() )
   //
   //.def( boost::python::self /= GTs_scalar3D() )
   //.def( boost::python::self *= GTs_scalar3D() )
   //
   //.def( boost::python::self += GTs_coord3D() )
   //.def( boost::python::self -= GTs_coord3D() )
  ;
  typedef  GTs_coord2D const& (GTs_interval2D::*Tf_getLo2D  )(void) const;
  Tf_getLo2D I_getLo2D = &GTs_interval2D::lo;

  //typedef  GTs_interval2D & (GTs_interval2D::*Tf_setLo2D   )(GTs_coord2D const&);
  //Tf_setLo2D I_setLo2D = &GTs_interval2D::lo;

  typedef  GTs_coord2D const& (GTs_interval2D::*Tf_getHi2D)(void) const;
  Tf_getHi2D I_getHi2D = &GTs_interval2D::hi;

  //typedef  GTs_interval2D & (GTs_interval2D::*Tf_setHi2D  )(GTs_coord2D const&);
  //Tf_setHi2D I_setHi2D = &GTs_interval2D::hi;

  boost::python::class_<GTs_interval2D>( "MathTypeInterval2D" )
   .def( boost::python::init<>() )
 //.def( boost::python::init<GTs_coord3D>() )
   .def( boost::python::init<GTs_coord2D,GTs_coord2D>() )
   .def( "lo",        I_getLo2D,                  boost::python::return_value_policy<boost::python::copy_const_reference>()      )
   //.def( "lo",        I_setLo2D,                  boost::python::return_value_policy<boost::python::reference_existing_object>() )
   .def( "hi",        I_getHi2D,                  boost::python::return_value_policy<boost::python::copy_const_reference>()      )
   //.def( "hi",        I_setHi2D,                  boost::python::return_value_policy<boost::python::reference_existing_object>() )
   //.def( "load",      &GTs_interval2D::F_load,    boost::python::return_value_policy<boost::python::reference_existing_object>() )
   //.def( "inside",    &GTs_interval2D::F_in        )
   //.def( "outside",   &GTs_interval2D::F_out       )
   //.def( "correct",   &GTs_interval2D::F_correct, boost::python::return_value_policy<boost::python::reference_existing_object>() )
   ;

  typedef  GTs_scalar const& (GTs_interval1D::*Tf_getLo1D  )(void) const;
  Tf_getLo1D I_getLo1D = &GTs_interval1D::lo;

  //typedef  GTs_interval1D & (GTs_interval1D::*Tf_setLo1D  )(GTs_scalar const&);
  //Tf_setLo1D I_setLo1D = &GTs_interval1D::lo;

  typedef  GTs_scalar const& (GTs_interval1D::*Tf_getHi1D )(void) const;
  Tf_getHi1D I_getHi1D = &GTs_interval1D::hi;

  //typedef  GTs_interval1D & (GTs_interval1D::*Tf_setHi1D )(GTs_scalar const&);
  //Tf_setHi1D I_setHi1D = &GTs_interval1D::hi;

  boost::python::class_<GTs_interval1D>( "MathTypeInterval1D" )
   .def( boost::python::init<>() )
 //.def( boost::python::init<GTs_scalar>() )
   .def( boost::python::init<GTs_scalar,GTs_scalar>() )
   .def( "lo", I_getLo1D,                      boost::python::return_value_policy<boost::python::copy_const_reference>()       )
   //.def( "lo", I_setLo1D,                      boost::python::return_value_policy<boost::python::reference_existing_object>()  )
   .def( "hi", I_getHi1D,                      boost::python::return_value_policy<boost::python::copy_const_reference>()       )
   //.def( "hi", I_setHi1D,                      boost::python::return_value_policy<boost::python::reference_existing_object>()  )
   //.def( "load",      &GTs_interval1D::F_load, boost::python::return_value_policy<boost::python::reference_existing_object>()  )
   //.def( "inside",    &GTs_interval1D::F_in   )
   //.def( "outside",   &GTs_interval1D::F_out  )
   //.def( "correct",   &GTs_interval1D::F_correct, boost::python::return_value_policy<boost::python::reference_existing_object>() )
   ;

  boost::python::class_<GTs_range1D>( "MathTypeRange1D" )
   .def( boost::python::init<>() )
 //.def( boost::python::init<GTs_scalar>() )
   .def( boost::python::init<GTs_size,GTs_size>() )
  ;
  boost::python::class_<GTs_range2D>( "MathTypeRange2D" )
   .def( boost::python::init<>() )
 //.def( boost::python::init<GTs_scalar>() )
   .def( boost::python::init<GTs_cell2D,GTs_cell2D>() )
    ;
  boost::python::class_<GTs_range3D>( "MathTypeRange3D" )
   .def( boost::python::init<>() )
 //.def( boost::python::init<GTs_scalar>() )
   .def( boost::python::init<GTs_cell3D,GTs_cell3D>() )
    ;
  boost::python::class_<GTs_range4D>( "MathTypeRange4D" )
   .def( boost::python::init<>() )
 //.def( boost::python::init<GTs_scalar>() )
   .def( boost::python::init<GTs_cell4D,GTs_cell4D>() )
   ;
 }
