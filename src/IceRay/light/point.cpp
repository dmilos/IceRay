#include "./point.hpp"


using namespace GS_DDMRM::S_IceRay::S_light;


GC_point::GC_point( )
 :T__pure( T_interval(), 1 )
 {

 }

GC_point::GC_point( T_coord const& P_center )
 :T__pure( T_interval( P_center, P_center ), 1 )
 ,M2_spot( P_center )
 {

 }
 
GC_point::GC_point( T_coord const & P_center, T_color const& P_0, T_color const& P_1, T_color const& P_2 )
 :T__pure( T_interval(P_center,P_center), 1 )
 ,M2_spot( P_center, P_0, P_1, P_2 )
 {

 }

GC_point::GC_point( T_spot const& P_spot )
 :T__pure( T_interval( P_spot.F_center(), P_spot.F_center() ), 1 )
 ,M2_spot( P_spot )
 {

 }

GC_point::~GC_point()
 {
 }

GC_point::T_size
GC_point::Fv_swarm 
 (
   T_swarm      & P_swarm
  ,T_coord const& P_point
 )const
 {
  P_swarm.F_push( M2_spot );
  return 1;
 }

bool
GC_point::F_spot 
 (
   T_spot const& P_spot
 )
 {
  M2_spot = P_spot; 
  return bool( true ); 
 }
