
#include "./light.h"

#include "IceRay/light/light.hpp"
#include "../../type/coord.hpp"


GS_DDMRM::S_IceRay::S_light::S_type::GC_spot c2cpp( IceRayC_TypeSpot )
 {
  GS_DDMRM::S_IceRay::S_light::S_type::GC_spot Ir_result;
  return Ir_result;
 }

void IceRayC_Light_Release( IceRayC_Light_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_Light_Handle IceRayC_Light_Area0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;
  auto Ir_result = new Tf_area{};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_Light_Area_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_x( c2cpp( *P_Y ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Blocked0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_blocked Tf_blocked;
  auto Ir_result = new Tf_blocked{};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_Light_Blocked_Barrier( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_barrier  )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_blocked Tf_blocked;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf_geometry;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect T_barrier;

  auto I_this = dynamic_cast< Tf_blocked *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_barrier( dynamic_cast< T_barrier *>( reinterpret_cast<Tf_geometry*> ( P_barrier ) ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Chandelier0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier Tf_chandelier;
  auto Ir_result = new Tf_chandelier{};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_Light_Chandelier_Push( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier Tf_chandelier;

  auto I_this = dynamic_cast< Tf_chandelier *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_add( reinterpret_cast<Tf__pure*> ( P_child ) );
  return 1;
 }


IceRayC_Light_Handle IceRayC_Light_Circle0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;
  auto Ir_result = new Tf_circle{};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_Circle_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_Light_Clipped_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_clipped Tf_clipped;

  auto I_this = dynamic_cast< Tf_clipped *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( reinterpret_cast<Tf__pure*> ( P_child ) );
  return 1;
 }

int IceRayC_Light_Clipped_Shell( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_shell )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_clipped Tf_clipped;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  Tf_geometry;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside Tf_inside;

  auto I_this = dynamic_cast< Tf_clipped *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_shell( dynamic_cast< Tf_inside *>( reinterpret_cast<Tf_geometry*> ( P_shell ) ) );
  return 1;
 }


IceRayC_Light_Handle IceRayC_Light_Confine0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_confine Tf_confine;
  auto Ir_result = new Tf_confine{};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_Confine_Child( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_confine Tf_confine;

  auto I_this = dynamic_cast< Tf_confine *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( reinterpret_cast<Tf__pure*> ( P_child ) );
  return 1;
 }
int IceRayC_Light_Confine_Hull( IceRayC_Light_Handle P_this, IceRayC_Geometry_Handle P_shell )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_confine Tf_confine;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base  Tf_geometry;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_inside Tf_inside;

  auto I_this = dynamic_cast< Tf_confine *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_hull( dynamic_cast< Tf_inside *>( reinterpret_cast<Tf_geometry*> ( P_shell ) ) );
  return 1;
 }

IceRayC_Light_Handle IceRayC_Light_Disc0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_Disc_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_Line_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_line *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_line *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_line *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
IceRayC_Light_Handle IceRayC_Light_Point1( IceRayC_TypeCoordScalar3D* center, IceRayC_TypeColorRGB* c0, IceRayC_TypeColorRGB* c1, IceRayC_TypeColorRGB* c2 )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;
  auto Ir_result = new Tf_point{};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_Point_Spot( IceRayC_Light_Handle P_this , IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;

  auto I_this = dynamic_cast< Tf_point *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_point *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_Reflector_Center( IceRayC_Light_Handle P_this, IceRayC_TypeCoordScalar3D* P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
IceRayC_Light_Handle IceRayC_Light_Sphere1( IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;
  auto Ir_result = new Tf_sphere{ c2cpp( *P_spot ) };
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
IceRayC_Light_Handle IceRayC_Light_Sphere2( IceRayC_TypeSpot* P_spot, IceRayC_TypeScalar P_radius )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;
  auto Ir_result = new Tf_sphere{ c2cpp( *P_spot ), P_radius };
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
IceRayC_Light_Handle IceRayC_Light_Sphere3( IceRayC_TypeSpot* P_spot, IceRayC_TypeScalar P_radius, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;
  auto Ir_result = new Tf_sphere{ c2cpp( *P_spot ), P_radius, P_sample };
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_Sphere_Sample( IceRayC_Light_Handle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sphere Tf_sphere;

  auto I_this = dynamic_cast< Tf_sphere *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_sphere *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_sphere *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_Spline_Spot( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
IceRayC_Light_Handle IceRayC_Light_SunS1( IceRayC_TypeSpot* P_spot )
{
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_suns Tf_suns;
  auto Ir_result = new Tf_suns{ c2cpp( *P_spot )};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_SunS_Spot ( IceRayC_Light_Handle P_this, IceRayC_TypeSpot* P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_suns Tf_suns;

  auto I_this = dynamic_cast< Tf_suns *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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

  auto I_this = dynamic_cast< Tf_suns *>( reinterpret_cast<Tf__pure*> ( P_this ) );
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
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
IceRayC_Light_Handle IceRayC_Light_SunG1( IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sung Tf_sun;
  auto Ir_result = new Tf_sun{};
  return reinterpret_cast< IceRayC_Light_Handle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_Light_SunG_Child ( IceRayC_Light_Handle P_this, IceRayC_Light_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sung Tf_sun;

  auto I_this = dynamic_cast< Tf_sun *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( reinterpret_cast< Tf__pure* >( P_child ) );
  return 1;
 }
