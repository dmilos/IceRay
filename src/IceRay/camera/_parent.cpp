#include   "./_parent.hpp"

#include "./flat/perspective.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera;

GC__parent::GC__parent()
: GC__parent( &Fs_child(), 1 )
 {
 }

GC__parent::GC__parent ( T__pure * P_child, T_size const& P_size )
 :GC__pure( P_size )
 ,M2_child ( &Fs_child() )
 {
  F_child( M2_child );
 }

GC__parent::~GC__parent ()
 {
  // do nothing
 }

GC__parent::T_size
GC__parent::Fv_beam( T_beam & P_beam, T_coord2D const& P_uv )const
 {
  return M2_child->Fv_beam( P_beam, P_uv );
 }

void
GC__parent::Fv_system( T_affine &P_matrix, T_coord2D const& P_uv )const
 {
  return M2_child->Fv_system( P_matrix, P_uv );
 }

bool
GC__parent::F_child( T__pure * P_child )
 {
  M2_child = P_child;
  if( nullptr == P_child )
   {
    M2_child = &Fs_child();
   }

  F1_size() = M2_child->F_size();
  return true;
 }

GC__parent::T__pure & GC__parent::Fs_child()
 {
  typedef GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective  T2_perspective;
  static T2_perspective Irs_perspective;
  return Irs_perspective;
 }

