#include   "./_parent.hpp"

using namespace GS_DDMRM::S_IceRay::S_camera;

GC__parent::T2_perspective GC__parent::M2s_perspective;

GC__parent::GC__parent()
: GC__parent( &M2s_perspective, 1 )
 {
 }

GC__parent::GC__parent ( T__pure * P_child, T_size const& P_size )
 :GC__pure( P_size )
 ,M2_child ( nullptr )
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
  if( NULL == P_child )
   {
    M2_child = &M2s_perspective;
   }
  else
   {
    M2_child = P_child;
   }
  F1_size() = M2_child->F_size();
  return true;
 }

GC__parent::T__pure & GC__parent::Fs_perspective()
 {
  return M2s_perspective;
 }
