#include "./projector.hpp"

#include "../../camera/flat/perspective.hpp"

 #include "../3sheaf/all.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_pierce;


GC_projector::GC_projector( void )
 :M2_camera( nullptr )
 ,M2_sheaf   ( nullptr  )
 {
  Fv_camera( M2_camera );
  Fv_sheaf( M2_sheaf );
 }

GC_projector::~GC_projector( void )
 {
 }

void GC_projector::Fv_camera( T_camera* P_camera )
 {
  M2_camera = P_camera;
  if( nullptr == M2_camera )
   {
    M2_camera = &Fs_camera();
   }
  M2_beam.resize( F1_camera()->F_size() );
 }

GC_projector::T_camera & GC_projector::Fs_camera()
 {
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective  T2_perspective;
  static T2_perspective Irs_camera;
  return Irs_camera;
 }

void GC_projector::F1v_render( T_color & P_color, T_coord const& P_coord )
 {
  static T_coord Is_one; ::math::linear::vector::fill( Is_one, 1 );

  T_coord I_coord;

  ::math::linear::vector::scale( I_coord, 2, P_coord );
  ::math::linear::vector::subtraction( I_coord , Is_one );
  I_coord[1] = -I_coord[1];

  F1_camera()->Fv_beam( M2_beam, I_coord );

  T_color I_color( ::color::constant::black_t{} );

  F_sheaf().Fv_do( I_color, M2_beam );

   P_color = I_color;
 }

void      GC_projector::Fv_sheaf( T_sheaf * P_sheaf )
 {
  M2_sheaf = P_sheaf;
  if( nullptr == M2_sheaf )
   {
    M2_sheaf = &Fs_sheaf();
   }
 }

GC_projector::T_sheaf & GC_projector::Fs_sheaf()
 {
  typedef GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_all Tf_all;
  static Tf_all Irs_all;
  return Irs_all;
 }