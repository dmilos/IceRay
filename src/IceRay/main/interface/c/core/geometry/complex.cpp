#include <iostream>
#include <iomanip>

#include "./geometry.h"
#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "../../type/affine.hpp"

#include "IceRay/geometry/complex/complex.hpp"
#include "./geometry.hpp"


IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;
  auto Ir_result = new Tf_intersect{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Intersect1( IceRayC_Geometry_Handle P_left, IceRayC_Geometry_Handle P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;
  auto Ir_result = new Tf_intersect{};
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Complex_Intersect_Left0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_left )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_left( c2cpp( P_left ) );
 }

int IceRayC_Geometry_Complex_Intersect_Left1( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_left, int location )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside::T_location    Tf_location;
  return I_this->F_left( c2cpp( P_left ), Tf_location( location ) );
 }

int IceRayC_Geometry_Complex_Intersect_Right0( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_right )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_right( c2cpp( P_right ) );
 }

int IceRayC_Geometry_Complex_Intersect_Right1( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_right, int location )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::S_CSG::GC_intersect Tf_intersect;

  auto I_this = dynamic_cast< Tf_intersect *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside::T_location    Tf_location;
  return I_this->F_right( c2cpp( P_right ), Tf_location( location ) );
 }

IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Enclose0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_enclose Tf_enclose;
  auto Ir_result = new Tf_enclose{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_Handle IceRayC_Geometry_Complex_Enclose1( IceRayC_Geometry_Handle P_child, IceRayC_Geometry_Handle P_hull )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_enclose Tf_enclose;
  auto Ir_result = new Tf_enclose{ c2cpp( P_child ), c2cpp( P_hull ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Geometry_Complex_Enclose_Child( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_enclose Tf_enclose;

  auto I_this = dynamic_cast< Tf_enclose *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_child( c2cpp( P_child ) );
 }

int IceRayC_Geometry_Complex_Enclose_Hull(  IceRayC_Geometry_Handle P_this, IceRayC_Geometry_Handle P_hull  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_complex::GC_enclose Tf_enclose;

  auto I_this = dynamic_cast< Tf_enclose *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside::T_location    Tf_location;
  return I_this->F_hull( c2cpp( P_hull ) );
 }


