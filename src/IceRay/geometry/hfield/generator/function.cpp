#include "./function.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;

S_hfield::S_generator::GC_function::GC_function( )
 : GC_function( Fs_one(), 2, 2 )
 {
 }

S_hfield::S_generator::GC_function::GC_function( T_function const& P_function, T_size const& P_x, T_size const& P_y )
 :T__pure( P_x, P_y )
 ,M2_function (P_function )
 {
 }

S_hfield::S_generator::GC_function::T_scalar S_hfield::S_generator::GC_function::Fv_value( T_size const& P_y, T_size const& P_x )const
 {
  return M2_function( P_y/(T_scalar)(F_size()[0]-1), P_x/(T_scalar)(F_size()[1]-1) );
 }

S_hfield::S_generator::GC_function::T_scalar S_hfield::S_generator::GC_function::Fv_value( T_coord const& P_position )const
 {
  return M2_function( P_position[0]/(F_size()[0]-1), P_position[0]/(T_scalar)(F_size()[1]-1) ) ;
 }

S_hfield::S_generator::GC_function::T_function
S_hfield::S_generator::GC_function::Fs_one()
 {
  return []( T_scalar const&x, T_scalar const&y){ return sin( (x+y) / 10)/2 + 1; };
 }

