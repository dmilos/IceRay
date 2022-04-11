#include "./pin.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera;


S_transform::GC_pin::GC_pin()
 {
  F_origin( T_coord{ 0, 0, 0 } );
 }

S_transform::GC_pin::GC_pin( T__pure * P_child )
 : T__parent( P_child )
 {
  F_origin( T_coord{ 0, 0, 0 } );
 }

S_transform::GC_pin::GC_pin( T__pure * P_child, T_coord const& P_origin )
 : T__parent( P_child )
 {
  F_origin( P_origin );
 }

S_transform::GC_pin::~GC_pin()
 {
 }

S_transform::GC_pin::T_size
S_transform::GC_pin::Fv_beam( T_beam &P_beam, T_coord2D const& P_uv )const
 {
  F_child().Fv_beam( P_beam, P_uv );
  for( auto & I_ray : P_beam )
   {
    auto & I_origin = I_ray.M_origin;
    auto & I_direction = I_ray.M_direction;
    T_coord I_view;

    ::math::linear::vector::addition( I_view, I_origin, I_direction );

    I_origin = F_origin();

    ::math::linear::vector::subtraction( I_direction, I_view, I_origin );
   }

  return P_beam.size();
 }

void
S_transform::GC_pin::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
 {
  T_affine I_affine;

  F_child().Fv_system( I_affine, P_uv );

  T_coord I_direction; ::math::linear::vector::fill( I_direction, 0 );
  I_direction[1] = 1;
  T_coord I_position; ::math::linear::vector::fill( I_position, 0 );

  // TODO Ceheck/fix

  P_affine = I_affine;
  return;
 }

S_transform::GC_pin::T_coord const& S_transform::GC_pin::F_origin()const
 { 
  return M2_origin; 
 }
bool           S_transform::GC_pin::F_origin( T_coord const& P_origin )
 {
  M2_origin = P_origin;
  return true;
 }

S_transform::GC_pin::T_coord      & S_transform::GC_pin::F1_origin()
 {
  return M2_origin;
 }
