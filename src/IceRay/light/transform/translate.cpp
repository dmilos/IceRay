#include <cmath>
#include "math/constants.hpp"
#include "./translate.hpp"

using namespace GS_DDMRM::S_IceRay::S_light;


S_transform::GC_translate::GC_translate( )
 {
  ::math::linear::vector::fill( M2_move, 0 );
 }

S_transform::GC_translate::GC_translate
 (
   T__pure *P_child
  ,T_coord const& P_move
 )
 :GC__parent( P_child )
 ,M2_move( P_move )
 {
 }

S_transform::GC_translate::~GC_translate( )
 {
 }

S_transform::GC_translate::T_size
S_transform::GC_translate::Fv_swarm
 (
   T_swarm      & P_swarm
  ,T_coord const& P_point
 )const
 {
   T_coord I_point;

   ::math::linear::vector::subtraction( I_point, P_point, M2_move );
   T_size I_new = F_child().Fv_swarm( P_swarm, I_point );

   for( T_size I_index = P_swarm.F_size() - I_new; I_index < P_swarm.F_size(); ++I_index )
    {
     ::math::linear::vector::addition( P_swarm[ I_index ].F_center(), M2_move );
    }
   return I_new;
 }
