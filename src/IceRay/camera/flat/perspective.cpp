#include   "./perspective.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera::S_flat;


GC_perspective::GC_perspective()
 : GC_perspective( 1, 1 )
 {

 }

GC_perspective::GC_perspective( T_scalar const& P_aspect )
 :GC_perspective( P_aspect, 1 )
 {
 }

GC_perspective::GC_perspective(  T_scalar const& P_width, T_scalar const& P_height )
 {
  M2_width = P_width;
  M2_height = P_height;
  M2_aspect = M2_width / M2_height;
 }

GC_perspective::~GC_perspective()
 {

 }

GC_perspective::T_size
GC_perspective::Fv_beam
 (
   T_beam         &  P_beam
  ,T_coord2D const&  P_uv
 )const
 {
  T_coord & I_origin = P_beam[0].M_origin;

  ::math::linear::vector::fill( I_origin, 0 );

  T_coord & I_direction = P_beam[0].M_direction;

  I_direction[0] =  P_uv[0] * M2_width;
  I_direction[1] =        1;
  I_direction[2] =  P_uv[1] * M2_height;

  return 1;
 }

void
GC_perspective::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
 {
  T_coord I_eY;
  I_eY[0] =  P_uv[0] * M2_width;
  I_eY[1] =        1;
  I_eY[2] =  P_uv[1] * M2_height;

  T_coord I_z;  ::math::linear::vector::load( I_z, 0, 0, 1 );
  T_coord I_eX; ::math::linear::vector::cross( I_eX, I_eY, I_z  ); ::math::linear::vector::length( I_eX, T_scalar(1) );
  T_coord I_eZ; ::math::linear::vector::cross( I_eZ, I_eY, I_eX ); ::math::linear::vector::length( I_eZ, T_scalar(1) );

  ::math::linear::vector::fill( P_affine.vector(), 0 );
  ::math::linear::matrix::system( P_affine.matrix(), I_eX, I_eY, I_eZ );
 }


bool               GC_perspective::F_width( T_scalar const& P_width )
 {
  M2_width  = P_width;
  M2_aspect = P_width/ M2_height;
  return true;
 }

bool               GC_perspective::F_height( T_scalar const& P_height )
 {
  M2_height = P_height;
  M2_aspect = M2_width/ M2_height;

  return true;
 }

bool  GC_perspective::F_aspect( T_scalar const& P_aspect )
 {
  M2_aspect = P_aspect;
  M2_height = M2_aspect * M2_width;
  return bool( true );
 }
