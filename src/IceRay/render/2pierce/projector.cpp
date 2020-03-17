#include "./projector.hpp"


using namespace GS_DDMRM::S_IceRay::S_render::S_pierce;


GC_projector::T2_perspective GC_projector::M2s_camera;
//GC_projector::T1_base        GC_projector::M2s_base;

GC_projector::GC_projector( void )
 :M2_camera( &M2s_camera )
 ,M2_ray   ( nullptr  )
 {
 }

GC_projector::~GC_projector( void )
 {
 }

void GC_projector::Fv_camera( T_camera* P_camera )
 {
  M2_camera = ( nullptr == P_camera ? &M2s_camera : P_camera );
 }

void GC_projector::F1v_render( T_color & P_color, T_coord const& P_coord )
 {
  static T_coord Is_one; ::math::linear::vector::fill( Is_one, 1 );

  T_coord I_coord;

  ::math::linear::vector::scale( I_coord, 2, P_coord );
  ::math::linear::vector::subtraction( I_coord , Is_one );
  I_coord[1] = -I_coord[1];

  M2_beam.resize( F1_camera()->F_size() );
  F1_camera()->Fv_beam( M2_beam, I_coord );

  T_color I_summae( ::color::constant::black_t{} );
  for( auto & I_ray : M2_beam )
   {
    T_color I_color;

    ::math::linear::vector::length( I_ray.M_direction, T_scalar(1) );

    F1v_ray()->Fv_trace( I_color, I_ray );

    // DEBUG I_color.set( 0, 1*(I_ray.M_direction[0]/2+0.5) );
    // DEBUG I_color.set( 1, 1*(I_ray.M_direction[1]/2+0.5) );
    // DEBUG I_color.set( 2, 1*(I_ray.M_direction[2]/2+0.5) );

    I_summae += I_color;
   }

   P_color = I_summae / M2_beam.size();
 }
