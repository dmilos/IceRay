#include "./geometry.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object;

GC_geometry::GC_geometry()
 : GC_geometry( &Fs_vacuum() )
 {

 }
GC_geometry::GC_geometry( T_geometry * P_child )
 {
  F_child( P_child );
 }


bool GC_geometry::Fv_intersect( T_scalar &P_lambda, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_ray const& P_ray )const
 {
  // TODO return M2_intersect-Fv_intersect( P_lambda, P_ray, /*intersect*/ );
  return false;
 }

void GC_geometry::Fv_height( T_scalar &P_height, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
  // TODO
  P_height = 0;
 }

void GC_geometry::Fv_normal( T_coord  &P_normal, T_scalar const& P_00, T_scalar const& P_10, T_scalar const& P_01, T_scalar const& P_11, T_scalar const& P_x, T_scalar const& P_y )const
 {
 //TODO return M2_intersect-Fv_normal( lambda, P_ray, /*intersect*/ );
  ::math::linear::vector::fill( P_normal, 0 );
 }

bool GC_geometry::F_child( T_geometry * P_geometry )
 {
  M2_intersect = dynamic_cast< T_intersect*  >( P_geometry ); if( nullptr == M2_intersect ){ F_child( & Fs_vacuum() ); return false; }
  M2_normal    = dynamic_cast< T_normal   *  >( P_geometry ); if( nullptr == M2_normal    ){ F_child( & Fs_vacuum() ); return false; }
  return true;
 }

GC_geometry::T_vacuum & GC_geometry::Fs_vacuum()
 {
  static T_vacuum Is_vacuum;
  return Is_vacuum;
 }
