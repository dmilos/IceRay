
#include "./light.h"

#include "../geometry/geometry.hpp"

#include "IceRay/light/light.hpp"
#include "../../type/coord.hpp"
#include "../../type/color.hpp"


GS_DDMRM::S_IceRay::S_light::S_type::GC_spot c2cpp( IceRayC_TypeSpot P_that )
 {
  GS_DDMRM::S_IceRay::S_light::S_type::GC_spot Ir_result;
  Ir_result.F_center( c2cpp( P_that.m_coord ) );
  Ir_result.F_0( c2cpp( P_that.m_c0 ) );
  Ir_result.F_1( c2cpp( P_that.m_c1 ) );
  Ir_result.F_2( c2cpp( P_that.m_c2 ) );

  return Ir_result;
 }
IceRayC_TypeSpot cpp2c(  GS_DDMRM::S_IceRay::S_light::S_type::GC_spot P_this )
 {
  IceRayC_TypeSpot Ir_result;
  Ir_result.m_coord = cpp2c( P_this.F_center() );
  Ir_result.m_c0    = cpp2c( P_this.F_0() );
  Ir_result.m_c1    = cpp2c( P_this.F_1() );
  Ir_result.m_c2    = cpp2c( P_this.F_2() );

  return Ir_result;
 }

IceRayC_Light_Handle cpp2c( GS_DDMRM::S_IceRay::S_light::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Light_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_light::GC__pure * c2cpp( IceRayC_Light_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_light::GC__pure*> ( P_that );
 }

void IceRayC_Light_Release( IceRayC_Light_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
 }

IceRayC_Light_Handle IceRayC_Light_Area0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;
  auto Ir_result = new Tf_area{};
  return cpp2c( Ir_result );
 }

int IceRayC_Light_Area_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }
int IceRayC_Light_Area_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sample( P_sample );
  return 1;
 }
int IceRayC_Light_Area_Origin( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D *P_origin )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_origin( c2cpp( *P_origin ) );
  return 1;
 }
int IceRayC_Light_Area_X( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_X )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_x( c2cpp( *P_X ) );
  return 1;
 }
int IceRayC_Light_Area_Y( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D *P_Y )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_x( c2cpp( *P_Y ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Obstruct0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_obstruct Tf_this;
  auto Ir_result = new Tf_this{};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Obstruct_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_obstruct Tf_this;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf_geometry;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect T_barrier;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }
int IceRayC_Light_Obstruct_Barrier( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_barrier  )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_obstruct Tf_this;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf_geometry;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect T_barrier;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_barrier( dynamic_cast< T_barrier *>( c2cpp( P_barrier ) ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Chandelier0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier Tf_chandelier;
  auto Ir_result = new Tf_chandelier{};
  return cpp2c( Ir_result );
 }

int IceRayC_Light_Chandelier_Push( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier Tf_chandelier;

  auto I_this = dynamic_cast< Tf_chandelier *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_add( c2cpp( P_child ) );
  return 1;
 }


IceRayC_Light_Handle IceRayC_Light_Circle0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;
  auto Ir_result = new Tf_circle{};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Circle_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sample( P_sample );
  return 1;
 }
int IceRayC_Light_Circle_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }
int IceRayC_Light_Circle_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( *P_center) ) ;
  return 1;
 }
int IceRayC_Light_Circle_X( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_X )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_x( c2cpp( *P_X ) ) ;
  return 1;
 }
int IceRayC_Light_Circle_Y( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_Y )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_x( c2cpp( *P_Y ) ) ;
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Clipped0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_clipped Tf_clipped;
  auto Ir_result = new Tf_clipped{};
  return cpp2c( Ir_result );
 }

int IceRayC_Light_Clipped_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_clipped Tf_clipped;

  auto I_this = dynamic_cast< Tf_clipped *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }

int IceRayC_Light_Clipped_Shell( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_shell )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_clipped Tf_clipped;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  Tf_geometry;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside Tf_inside;

  auto I_this = dynamic_cast< Tf_clipped *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_shell( dynamic_cast< Tf_inside *>( c2cpp ( P_shell ) ) );
  return 1;
 }


IceRayC_Light_Handle IceRayC_Light_Confine0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_confine Tf_confine;
  auto Ir_result = new Tf_confine{};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Confine_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_confine Tf_confine;

  auto I_this = dynamic_cast< Tf_confine *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp ( P_child ) );
  return 1;
 }
int IceRayC_Light_Confine_Hull( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_shell )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_confine Tf_confine;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  Tf_geometry;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside Tf_inside;

  auto I_this = dynamic_cast< Tf_confine *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hull( dynamic_cast<Tf_inside*>( c2cpp ( P_shell ) ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Disc0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Disc_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sample( P_sample );
  return 1;
 }
int IceRayC_Light_Disc_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }
int IceRayC_Light_Disc_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( *P_center ) );
  return 1;
 }
int IceRayC_Light_Disc_X( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_X )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_x( c2cpp( *P_X ) );
  return 1;
 }
int IceRayC_Light_Disc_Y( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_Y )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_y( c2cpp( *P_Y ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Line0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;
  auto Ir_result = new Tf_line{};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Line_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sample( P_sample );
  return 1;
 }
int IceRayC_Light_Line_Spot( IceRayC_Light_Handle P_this,  IceRayC_TypeSpot* P_spot )
  {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }
int IceRayC_Light_Line_Start( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_start )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_start( c2cpp( *P_start ) );
  return 1;
 }
int IceRayC_Light_Line_End( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_end )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_end( c2cpp( *P_end ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Point0()
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;
  auto Ir_result = new Tf_point{};
  return cpp2c( Ir_result );
 }
IceRayC_Light_Handle IceRayC_Light_Point1( IceRayC_TypeCoordScalar3D* center, IceRayC_TypeColorRGB* c0, IceRayC_TypeColorRGB* c1, IceRayC_TypeColorRGB* c2 )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;
  auto Ir_result = new Tf_point{};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Point_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;

  auto I_this = dynamic_cast< Tf_point *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }

int IceRayC_Light_Point_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;

  auto I_this = dynamic_cast< Tf_point *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( *P_center ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Reflector0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;
  auto Ir_result = new Tf_reflector{};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Reflector_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( *P_center ) );
  return 1;
 }
int IceRayC_Light_Reflector_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }
int IceRayC_Light_Reflector_Direction( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_direction )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( *P_direction ) );
  return 1;
 }
int IceRayC_Light_Reflector_Inner( IceRayC_Light_Handle P_this, IceRayC_TypeScalar P_innner )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_inner( P_innner );
  return 1;
 }
int IceRayC_Light_Reflector_Outter( IceRayC_Light_Handle P_this, IceRayC_TypeScalar P_outter )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_outter( P_outter );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Sphere0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;
  auto Ir_result = new Tf_sphere{};
  return cpp2c( Ir_result );
 }
IceRayC_Light_Handle IceRayC_Light_Sphere1( IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;
  auto Ir_result = new Tf_sphere{ c2cpp( *P_spot ) };
  return cpp2c( Ir_result );
 }
IceRayC_Light_Handle IceRayC_Light_Sphere2( IceRayC_TypeSpot* P_spot, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;
  auto Ir_result = new Tf_sphere{ c2cpp( *P_spot ), P_radius };
  return cpp2c( Ir_result );
 }
IceRayC_Light_Handle IceRayC_Light_Sphere3( IceRayC_TypeSpot* P_spot, IceRayC_TypeScalar P_radius, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;
  auto Ir_result = new Tf_sphere{ c2cpp( *P_spot ), P_radius, P_sample };
  return cpp2c( Ir_result );
 }
int IceRayC_Light_Sphere_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sample( P_sample );
  return 1;
 }
int IceRayC_Light_Sphere_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }
int IceRayC_Light_Sphere_Radius( IceRayC_Light_Handle P_this, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_radius( P_radius );
  return 1;
 }


IceRayC_Light_Handle IceRayC_Light_Spline0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;
  auto Ir_result = new Tf_spline{};
  return cpp2c ( Ir_result );
 }
int IceRayC_Light_Spline_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }
int IceRayC_Light_Spline_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_sample( P_sample );
  return 1;
 }
int IceRayC_Light_Spline_CP( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample, IceRayC_TypeCoordScalar3D* P_0 )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_cp( 0, c2cpp( *P_0 ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_SunS0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_suns Tf_suns;
  auto Ir_result = new Tf_suns{};
  return cpp2c( Ir_result );
 }
IceRayC_Light_Handle IceRayC_Light_SunS1( IceRayC_TypeSpot* P_spot )
{
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_suns Tf_suns;
  auto Ir_result = new Tf_suns{ c2cpp( *P_spot )};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_SunS_Spot ( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_suns Tf_suns;

  auto I_this = dynamic_cast< Tf_suns *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_spot( c2cpp( *P_spot ) );
  return 1;
 }

int IceRayC_Light_SunS_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_suns Tf_suns;

  auto I_this = dynamic_cast< Tf_suns *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_center( c2cpp( *P_center ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_SunG0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sung Tf_sun;
  auto Ir_result = new Tf_sun{};
  return cpp2c( Ir_result );
 }
IceRayC_Light_Handle IceRayC_Light_SunG1( IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sung Tf_sun;
  auto Ir_result = new Tf_sun{};
  return cpp2c( Ir_result );
 }
int IceRayC_Light_SunG_Child ( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sung Tf_sun;

  auto I_this = dynamic_cast< Tf_sun *>( c2cpp ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }


#include "./transform.cpp"