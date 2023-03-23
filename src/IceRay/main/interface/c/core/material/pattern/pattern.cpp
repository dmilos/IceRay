#include "./pattern.h"
#include "./pattern.hpp"

#include "../../../type/color.hpp"
#include "../../../type/coord.hpp"
#include "../../../type/affine.hpp"
#include "../../../type/picture.hpp"

#include "IceRay/material/pattern/pattern.hpp"


IceRayC_Material_Pattern_Handle cpp2c( GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Material_Pattern_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure * c2cpp( IceRayC_Material_Pattern_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure*> ( P_that );
 }

int IceRayC_Material_Pattern_Release( IceRayC_Material_Pattern_Handle  P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure Tf__pure;
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }


IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Size0(           IceRayC_Type_Size              P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_size{P_value};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Scalar0(         IceRayC_Type_Scalar            P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_scalar{ P_value };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Color0(          IceRayC_Type_Color_RGB            *P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_color{ c2cpp( *P_value ) };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Coord_Scalar2D0( IceRayC_Type_Coord_Scalar2D   *P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_coord2D{ c2cpp( *P_value ) };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Coord_Scalar3D0( IceRayC_Type_Coord_Scalar3D   *P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_coord3D{ c2cpp( *P_value ) };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Coord_Scalar4D0( IceRayC_Type_Coord_Scalar4D   *P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_coord4D{ c2cpp( *P_value ) };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Coord_Size2D0(   IceRayC_Type_Coord_Size2D     *P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_size2D{ c2cpp( *P_value ) };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Coord_Size3D0(   IceRayC_Type_Coord_Size3D     *P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_size3D{ c2cpp( *P_value ) };
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Constant_Coord_Size4D0(   IceRayC_Type_Coord_Size4D     *P_value )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_constant::GT_size4D{ c2cpp( *P_value ) };
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Brick0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_brick{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Checker0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_checker{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Hexagon0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_hexagon{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Wave0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_waveSaw{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Onion0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_onion{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Level0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_level{};
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Image0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_image{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Image1( IceRayC_Type_Picture_Handle P_picture )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::GC_image{ c2cpp( P_picture ) };
  return cpp2c( Ir_result );
 }

int IceRayC_Material_Pattern_Image_Picture( IceRayC_Material_Pattern_Handle P_that, IceRayC_Type_Picture_Handle P_picture )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_image Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_that ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_picture( c2cpp( P_picture ) );
  return 1;
 }

IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Cells0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_cells{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Crackle0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_crackle{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Gold0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_gold{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Perlin0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_perlin{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Random0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_random{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Value0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_value{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Vdc0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_VDC{};
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Congruent1D0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_congruent1d{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Congruent2D0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_congruent2d{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Noise_Congruent3D0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_noise::GC_congruent3d{};
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Cube0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_cube{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Dodecahedron0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_dodecahedron{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Icosahedron0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_icosahedron{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Octahedron0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_octahedron{};
  return cpp2c( Ir_result );
 }
IceRayC_Material_Pattern_Handle IceRayC_Material_Pattern_Side_Tetrahedron0( )
 {
  auto Ir_result = new GS_DDMRM::S_IceRay::S_material::S_pattern::S_side::GC_tetrahedron{};
  return cpp2c( Ir_result );
 }

IceRayC_Material_Pattern_Handle  IceRayC_Material_Pattern_Gradient0( )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_gradient    Tf_this;
  auto Ir_result = new Tf_this{  };
  return cpp2c( Ir_result );
 }

int IceRayC_Material_Pattern_Gradient_Set( IceRayC_Material_Pattern_Handle P_this, IceRayC_Type_Scalar P_point,   IceRayC_Type_Color_RGB* P_color )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_gradient        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_set( P_point, c2cpp( *P_color ) );
  return 1;
 }
 
int                             IceRayC_Material_Pattern_Gradient_Bottom( IceRayC_Material_Pattern_Handle P_this, IceRayC_Type_Math_Coord_Scalar3D* P_bottom )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_gradient        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_bottom( c2cpp( *P_bottom ) );
  return 1;
 }
int                             IceRayC_Material_Pattern_Gradient_Top(    IceRayC_Material_Pattern_Handle P_this, IceRayC_Type_Math_Coord_Scalar3D* P_top    )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_gradient        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_top( c2cpp( *P_top ) );
  return 1;
 }

int                             IceRayC_Material_Pattern_Gradient_Clear(    IceRayC_Material_Pattern_Handle P_this )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC_gradient        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_clear();
  return 1;
 }
