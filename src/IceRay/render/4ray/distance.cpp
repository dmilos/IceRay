#include <limits>

#include "./distance.hpp"
 #include "../../geometry/volumetric/vacuum.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_ray;





GC_distance::GC_distance()
 :M2_geometry( &GC_distance::Fs_geometry() )
 {
  M2_clip.lo() =  1;
  M2_clip.hi() =  2;
  M2_gradient.lo() = ::color::constant::white_t{};
  M2_gradient.hi() = ::color::constant::black_t{};
 }

GC_distance::~GC_distance()
 {

 }

void
GC_distance::Fv_trace( T_color & P_color, T_ray const& P_ray )
 {
  T2_scalar I_distance = std::numeric_limits<T2_scalar>::max();

  T_geometry::T_state I_state;
  F1_geometry()->Fv_reset( I_state );
  if( false == F1_geometry()->Fv_intersect( I_distance, I_state, P_ray ) )
   {
    P_color    = M2_gradient.hi();
    return;
   }

  I_distance = (I_distance - M2_clip.lo() ) / ( M2_clip.hi() - M2_clip.lo() );
  P_color = ( 1- I_distance)* M2_gradient.lo() + I_distance * M2_gradient.hi();
 }

void
GC_distance::F_clip( T_clip const& P_clip )
 {
  M2_clip = P_clip;
 }

void
GC_distance::F_gradient( T_gradient const& P_color )
 {
  M2_gradient = P_color;
 }

void         GC_distance::F_geometry( T_geometry * P_geometry )
 {
   M2_geometry = dynamic_cast<T_state*>( P_geometry ); 
 }

GC_distance::T_state*
GC_distance::F1_geometry( )
 {
  return M2_geometry;
 }

GC_distance::T_state & GC_distance::Fs_geometry()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::GC_vacuum Tf_vacuum;
  static Tf_vacuum Is_vacuum;
  return Is_vacuum;
 }
