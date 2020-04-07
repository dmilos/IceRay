#include "./pattern.h"

#include "IceRay/material/pattern/pattern.hpp"


void IceRayC_Material_Pattern_Release( IceRayC_Material_Pattern_SizeHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  auto I_this = reinterpret_cast<Tf__pure*> ( P_this );
  delete I_this;
 }

void IceRayC_Material_Pattern_Size_Release( IceRayC_Material_Pattern_SizeHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;
  auto I_this = reinterpret_cast<Tf_size*> ( P_this );
  delete I_this;
 }

IceRayC_Material_Pattern_SizeHandle IceRayC_Material_Pattern_Brick0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;

  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_brick{};
  return reinterpret_cast<IceRayC_Material_Pattern_SizeHandle>( dynamic_cast< Tf_size *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_SizeHandle IceRayC_Material_Pattern_Checker0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_checker{};
  return reinterpret_cast<IceRayC_Material_Pattern_SizeHandle>( dynamic_cast< Tf_size *> ( Ir_result ) );
 }
IceRayC_Material_Pattern_SizeHandle IceRayC_Material_Pattern_Hexagon0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_hexagon{};
  return reinterpret_cast<IceRayC_Material_Pattern_SizeHandle>( dynamic_cast< Tf_size *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_SizeHandle IceRayC_Material_Pattern_Side_Cube0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_cube{};
  return reinterpret_cast<IceRayC_Material_Pattern_SizeHandle>( dynamic_cast< Tf_size *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_SizeHandle IceRayC_Material_Pattern_Side_Dodecahedron0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_dodecahedron{};
  return reinterpret_cast<IceRayC_Material_Pattern_SizeHandle>( dynamic_cast< Tf_size *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_SizeHandle IceRayC_Material_Pattern_Side_Icosahedron0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_icosahedron{};
  return reinterpret_cast<IceRayC_Material_Pattern_SizeHandle>( dynamic_cast< Tf_size *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_SizeHandle IceRayC_Material_Pattern_Side_Octahedron0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_octahedron{};
  return reinterpret_cast<IceRayC_Material_Pattern_SizeHandle>( dynamic_cast< Tf_size *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_SizeHandle IceRayC_Material_Pattern_Side_Tetrahedron0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size Tf_size;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_tetrahedron{};
  return reinterpret_cast<IceRayC_Material_Pattern_SizeHandle>( dynamic_cast< Tf_size *> ( Ir_result ) );
 }


IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Level0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_level{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Onion0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_onion{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Noise_Cells( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_cells{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Noise_Crackle( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_crackle{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Noise_Perlin( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_perlin{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Noise_Value( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_value{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }


IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Noise_Gold( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_gold{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Noise_Random( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_random{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Noise_VDC( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_VDC{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Scalar_Expression( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf_scalar;
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_expression::GC_scalar{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_scalar *> ( Ir_result ) );
 }

// TODO wave.hpp

// COLOR
void IceRayC_Material_Pattern_ColorRelease( IceRayC_Material_Pattern_ColorHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color Tf_color;
  auto I_this = reinterpret_cast<Tf_color*> ( P_this );
  delete I_this;
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Color_Image0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color  Tf_color;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_image   Tf_image;
  auto Ir_result = new Tf_image{};
  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_color *> ( Ir_result ) );
 }

IceRayC_Material_Pattern_ScalarHandle IceRayC_Material_Pattern_Color_Image1( IceRayC_Type_Picture_Handle P_picture )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color  Tf_color;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure       Tf_picture;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_image   Tf_image;

  auto Ir_result = new Tf_image{ reinterpret_cast< Tf_picture* >( P_picture )};

  return reinterpret_cast<IceRayC_Material_Pattern_ScalarHandle>( dynamic_cast< Tf_color *> ( Ir_result ) );
 }

int IceRayC_Material_Pattern_Color_Image_Picture( IceRayC_Material_Pattern_ScalarHandle P_this, IceRayC_Type_Picture_Handle P_picture )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure   Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color  Tf_color;
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure       Tf_picture;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_image   Tf_image;

  auto I_picture = reinterpret_cast< Tf_picture* >( P_picture );
  auto I_this = dynamic_cast<Tf_image*>( reinterpret_cast< Tf_color* >( P_this ) );

  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_image( I_picture );
  return 0;
 }

void IceRayC_Material_PatternCoord2DRelease( IceRayC_Material_Pattern_Coord2DHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord2D Tf_coord2D;
  auto I_this = reinterpret_cast<Tf_coord2D*> ( P_this );
  delete I_this;
 }

// TODO Coord2d

void IceRayC_Material_PatternCoord3DRelease( IceRayC_Material_Pattern_Coord3DHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord3D Tf_coord3D;
  auto I_this = reinterpret_cast<Tf_coord3D*> ( P_this );
  delete I_this;
 }
// TODO Coord3d

void IceRayC_Material_PatternCoord4DRelease( IceRayC_Material_Pattern_Coord4DHandle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GT__coord4D Tf_coord4D;
  auto I_this = reinterpret_cast<Tf_coord4D*> ( P_this );
  delete I_this;
 }

// TODO Coord4d
