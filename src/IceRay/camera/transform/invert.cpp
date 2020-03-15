#include "./invert.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera;


S_transform::GC_invert::GC_invert()
 {
 }

S_transform::GC_invert::GC_invert( T__pure * P_child )
 : T__parent( P_child )
 {
 }

S_transform::GC_invert::~GC_invert()
 {
 }

S_transform::GC_invert::T_size
S_transform::GC_invert::Fv_beam( T_beam &P_beam, T_coord2D const& P_uv )const
 {
  F_child().Fv_beam( P_beam, P_uv );
  for( auto & I_ray : P_beam )
   {
    auto & I_origin = I_ray.M_origin;
    auto & I_direction = I_ray.M_direction;

    ::math::linear::vector::addition( I_origin, I_direction );

    ::math::linear::vector::negate( I_direction );
   }
  return P_beam.size();
 }

void
S_transform::GC_invert::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
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

