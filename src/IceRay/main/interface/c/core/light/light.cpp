
#include "./light.h"

#include "IceRay/light/light.hpp"


GS_DDMRM::S_IceRay::S_light::S_type::GC_spot c2cpp( IceRayC_TypeSpot )
 {
  GS_DDMRM::S_IceRay::S_light::S_type::GC_spot Ir_result;
  return Ir_result;
 }

void IceRayC_Light_Release( IceRayC_LightHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

IceRayC_LightHandle IceRayC_LightArea( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;
  auto Ir_result = new Tf_area{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_LightArea_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_spot( c2cpp( P_spot ) );
  return 0;
 }
int IceRayC_LightArea_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_sample( P_sample );
  return 0;
 }
int IceRayC_LightArea_Origin( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_origin )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic I_this->
  return 0;
 }
int IceRayC_LightArea_X( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_X )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic I_this->
  return 0;
 }
int IceRayC_LightArea_Y( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_Y )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_area Tf_area;

  auto I_this = dynamic_cast< Tf_area *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic  I_this->
  return 0;
 }

IceRayC_LightHandle IceRayC_LightBlocked0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_blocked Tf_blocked;
  auto Ir_result = new Tf_blocked{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_LightBlocked_Barrier( IceRayC_LightHandle P_this, IceRayC_GeometryHandle P_barrier  )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_blocked Tf_blocked;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf_geometry;
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect T_barrier;

  auto I_this = dynamic_cast< Tf_blocked *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_barrier( dynamic_cast< T_barrier *>( reinterpret_cast<Tf_geometry*> ( P_barrier ) ) );
  return 0;
 }

IceRayC_LightHandle IceRayC_LightChandelier0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier Tf_chandelier;
  auto Ir_result = new Tf_chandelier{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_LightChandelier_push( IceRayC_LightHandle P_this, IceRayC_LightHandle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_chandelier Tf_chandelier;

  auto I_this = dynamic_cast< Tf_chandelier *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_add( reinterpret_cast<Tf__pure*> ( P_child ) );
  return 0;
 }


IceRayC_LightHandle IceRayC_LightCircle0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;
  auto Ir_result = new Tf_circle{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_LightCircle_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_sample( P_sample );
  return 0;
 }
int IceRayC_LightCircle_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_spot( c2cpp( P_spot ) );
  return 0;
 }
int IceRayC_LightCircle_Origin( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_origin )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightCircle_X( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_X )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightCircle_Y( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_Y )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_circle Tf_circle;

  auto I_this = dynamic_cast< Tf_circle *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }

IceRayC_LightHandle IceRayC_LightClipped0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_clipped Tf_clipped;
  auto Ir_result = new Tf_clipped{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_LightClipped_Qarter( IceRayC_LightHandle P_this/*, TODO */ )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_clipped Tf_clipped;

  auto I_this = dynamic_cast< Tf_clipped *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }


IceRayC_LightHandle IceRayC_LightDisc0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;
  auto Ir_result = new Tf_disc{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_LightDisc_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_sample( P_sample );
  return 0;
 }
int IceRayC_LightDisc_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_spot( c2cpp( P_spot ) );
  return 0;
 }
int IceRayC_LightDisc_Origin( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_origin )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightDisc_X( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_X )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightDisc_Y( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_Y )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_disc Tf_disc;

  auto I_this = dynamic_cast< Tf_disc *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }

IceRayC_LightHandle IceRayC_LightLine0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;
  auto Ir_result = new Tf_line{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_LightLine_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_spot( c2cpp( P_spot ) );
  return 0;
 }
int IceRayC_LightLine_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_sample( P_sample );
  return 0;
 }
int IceRayC_LightLine_Start( IceRayC_LightHandle P_this/*, TODO */ )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightLine_End( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_end )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_line Tf_line;

  auto I_this = dynamic_cast< Tf_line *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }


IceRayC_LightHandle IceRayC_LightPoint0()
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;
  auto Ir_result = new Tf_point{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
IceRayC_LightHandle IceRayC_LightPoint1( IceRayC_TypeCoord3D center, IceRayC_TypeColorRGB c0, IceRayC_TypeColorRGB c1, IceRayC_TypeColorRGB c2 )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;
  auto Ir_result = new Tf_point{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_LightPoint_Spot( IceRayC_LightHandle P_this , IceRayC_TypeSpot P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;

  auto I_this = dynamic_cast< Tf_point *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_spot( c2cpp( P_spot ) );
  return 0;
 }
int IceRayC_LightPoint_Center( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_center )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_point Tf_point;

  auto I_this = dynamic_cast< Tf_point *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }


IceRayC_LightHandle IceRayC_LightReflector0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;
  auto Ir_result = new Tf_reflector{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_LightReflector_Center( IceRayC_LightHandle P_this/*, TODO */   )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightReflector_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_spot( c2cpp( P_spot ) );
  return 0;
 }
int IceRayC_LightReflector_Direction( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_direction )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightReflector_In( IceRayC_LightHandle P_this/*, reflector */ )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightReflector_Out( IceRayC_LightHandle P_this/*, TODO reflector */ )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_reflector Tf_reflector;

  auto I_this = dynamic_cast< Tf_reflector *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }

IceRayC_LightHandle IceRayC_LightSpline( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;
  auto Ir_result = new Tf_spline{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }

int IceRayC_LightSpline_Spot( IceRayC_LightHandle P_this, IceRayC_TypeSpot P_spot )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_spot( c2cpp( P_spot ) );
  return 0;
 }
int IceRayC_LightSpline_Sample( IceRayC_LightHandle P_this, IceRayC_TypeSize P_sample )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_sample( P_sample );
  return 0;
 }
int IceRayC_LightSpline_CP_0( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_0 )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightSpline_CP_1( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_1 )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightSpline_CP_2( IceRayC_LightHandle P_this, IceRayC_TypeCoord3D P_2 )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic
  return 0;
 }
int IceRayC_LightSpline_CP_3( IceRayC_LightHandle P_this/*, TODO */ )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_spline Tf_spline;

  auto I_this = dynamic_cast< Tf_spline *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  // TODO logic I_this->F_child( c2cpp( )
  return 0;
 }

IceRayC_LightHandle IceRayC_LightSun0( )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sun Tf_sun;
  auto Ir_result = new Tf_sun{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
IceRayC_LightHandle IceRayC_LightSun1( IceRayC_LightHandle *P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sun Tf_sun;
  auto Ir_result = new Tf_sun{};
  return reinterpret_cast< IceRayC_LightHandle >( dynamic_cast< Tf__pure *> ( Ir_result ) );
 }
int IceRayC_LightSun_Child ( IceRayC_LightHandle P_this, IceRayC_LightHandle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_light::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_light::GC_sun Tf_sun;

  auto I_this = dynamic_cast< Tf_sun *>( reinterpret_cast<Tf__pure*> ( P_this ) );
  if( nullptr == I_this )
   {
    return 1;
   }
  I_this->F_child( reinterpret_cast< Tf__pure* >( P_child ) );
  return 0;
 }
