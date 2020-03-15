#include "./transform.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera;


S_transform::GC_affine::GC_affine()
 {
  ::math::linear::affine::one( M2_2world );
  ::math::linear::affine::one( M2_2local );
 }
 
S_transform::GC_affine::GC_affine( T__pure * P_child )
 : S_transform::GC_affine::GC_affine()
 {
  this->F_child( P_child );
 }

S_transform::GC_affine::~GC_affine()
 {
 }

S_transform::GC_affine::T_size
S_transform::GC_affine::Fv_beam( T_beam &P_beam, T_coord2D const& P_uv )const
 {
  F_child().Fv_beam( P_beam, P_uv );

  for( auto & I_ray : P_beam )
   {
    auto & I_origin = I_ray.M_origin;
    auto & I_direction = I_ray.M_direction;

    ::math::linear::vector::addition( I_direction, I_origin );
    ::math::linear::affine::transform( I_origin, M2_2world );

    ::math::linear::affine::transform( I_direction, M2_2world );

    ::math::linear::vector::subtraction( I_direction,I_origin );
    ::math::linear::vector::length( I_direction, T_scalar( 1 ) );
   }

  return P_beam.size();
 }

void
S_transform::GC_affine::Fv_system( T_affine &P_affine, T_coord2D const& P_uv )const
 {
  T_affine I_affine;
  F_child().Fv_system( I_affine, P_uv );
  ::math::linear::affine::compose( P_affine, F_2world(), I_affine );
 }

bool
S_transform::GC_affine::F_2world( T_affine const& P_2world )
 {
  M2_2world = P_2world;
  ::math::linear::affine::invert( M2_2local, P_2world );
  M2_transponate = M2_2world.matrix();
  ::math::linear::matrix::transpose( M2_transponate, M2_2world.matrix() );
  return true;
 }

bool            S_transform::GC_affine::F_2local( T_affine const& P_2local )
 {
  ::math::linear::affine::invert( M2_2world, P_2local );
  return F_2world( M2_2world );
 }
