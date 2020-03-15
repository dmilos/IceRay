#include   "./super.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera::S_flat;


GC_super::GC_super()
 : GC_super( {1,1}, {0,0}, {0,1} )
 {
}

GC_super::GC_super( T_coord2D const& P_eye, T_coord2D const& P_view )
:GC_super( P_eye, P_view, {0,1} )
 {
 }

GC_super::GC_super( T_coord2D const& P_eye, T_coord2D const& P_view, T_coord2D const& P_focus )
 {
  F_eye( P_eye );
  F_view(P_view );
  F_focus( P_focus );
 }

GC_super::~GC_super()
 {
 }

GC_super::T_size
GC_super::Fv_beam
 (
   T_beam         &  P_beam
  ,T_coord2D const&  P_uv
 )const
 {
  T_coord & I_origin = P_beam[0].M_origin;

  I_origin[0] = P_uv[0] * M2_eye2[0];
  I_origin[1] =           M2_focus[0];
  I_origin[2] = P_uv[1] * M2_eye2[1];

  T_coord & I_direction = P_beam[0].M_direction;

  I_direction[0] =  P_uv[0] * M2_view2[0] - I_origin[0];
  I_direction[1] =            M2_focus[1] - I_origin[1];
  I_direction[2] =  P_uv[1] * M2_view2[1] - I_origin[2];

  return 1;
 }

void
GC_super::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
 { // TODO check
  T_coord I_e0;
  I_e0[0] =  P_uv[0] * M2_view2[0];
  I_e0[1] =            M2_focus[0];
  I_e0[2] =  P_uv[1] * M2_view2[1];

  T_coord I_eY;
  I_eY[0] =  P_uv[0] * M2_eye2[0];
  I_eY[1] =            M2_focus[1];
  I_eY[2] =  P_uv[1] * M2_eye2[1];

  ::math::linear::vector::subtraction( I_eY, I_e0 );

  T_coord I_z;  ::math::linear::vector::load( I_z, 0, 0, 1 );
  T_coord I_eX; ::math::linear::vector::cross( I_eX, I_eY, I_z  ); ::math::linear::vector::length( I_eX, T_scalar(1) );
  T_coord I_eZ; ::math::linear::vector::cross( I_eZ, I_eY, I_eX ); ::math::linear::vector::length( I_eZ, T_scalar(1) );

  ::math::linear::vector::fill( P_affine.vector(), 0 );
  ::math::linear::matrix::system( P_affine.matrix(), I_eX, I_eY, I_eZ );
 }

bool   GC_super::F_eye( T_coord2D const& P_eye )
 {
  M2_eye1 = P_eye;
  ::math::linear::vector::scale( M2_eye2, 0.5, M2_eye1 );
  return true;
 }

bool   GC_super::F_view( T_coord2D const& P_view )
{
  M2_view1 = P_view;
  ::math::linear::vector::scale( M2_view2, 0.5, M2_view1 );
  return true;
}

bool   GC_super::F_focus( T_coord2D const& P_focus )
{
  M2_focus = P_focus;
  return true;
}
