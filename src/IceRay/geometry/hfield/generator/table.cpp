#include <iostream>
#include <iomanip>

#include "./table.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;

S_hfield::S_generator::GC_table::GC_table( )
 {
  Fv_size( {11,11} );
 }

S_hfield::S_generator::GC_table::GC_table::GC_table( T_size2D const& P_size )
 {
  Fv_size( P_size );
 }

S_hfield::S_generator::GC_table::GC_table( T_field const& P_field )
 :T__pure( P_field.size(), P_field[0].size() )
 ,M2_field( P_field )
 {
 }

bool S_hfield::S_generator::GC_table::Fv_size( T_size2D    const& P_size )
 {
  T__pure::Fv_size( P_size );
  M2_field.resize( P_size[1] );

  for( T_size I_i =0; I_i < M2_field.size(); ++I_i )
   {
    auto& I_row = M2_field[ I_i ];
    I_row.resize( P_size[0] );
   }

  for( T_size I_y = 0; I_y < F_size()[1]; ++I_y )
   { //! default values
    for( T_size I_x = 0; I_x < F_size()[0]; ++I_x )
     {
      auto I_u = ::math::function::any_to_any<double>( I_x, 0, F_size()[0]-1, -3.14, +3.14 );
      auto I_v = ::math::function::any_to_any<double>( I_y, 0, F_size()[1]-1, -3.14, +3.14 );
      auto I_value = 0.5 * ( sin( sqrt( I_u*I_u + I_v*I_v ) ) + 1) /2;
      //auto I_value = 0.5 * ( sin( atan2( I_v, I_u ) ) + 1) /2;
      //auto I_value = 0.5;
      //auto I_value = I_v;

      F_set( I_y, I_x, I_value );
     }
   }

  return true;
 }

S_hfield::S_generator::GC_table::T_scalar S_hfield::S_generator::GC_table::Fv_value( T_size const& P_x, T_size const& P_y )const
 {
  if( M2_field.size() < P_y + 1)
   {
    return T_scalar(0);
   }

  if( M2_field[P_y].size()< P_x + 1 )
   {
    return T_scalar(0);
   }

  return M2_field[P_y][P_x];
 }

S_hfield::S_generator::GC_table::T_scalar S_hfield::S_generator::GC_table::Fv_value( T_size2D const& P_position )const
 {
  if( M2_field.size() < P_position[1] + 1)
   {
    return T_scalar(0);
   }

  if( M2_field[P_position[1]].size()< P_position[0] + 1 )
   {
    return T_scalar(0);
   }

  return M2_field[P_position[1]][P_position[0]];
 }

bool     S_hfield::S_generator::GC_table::F_set( T_size const& P_x, T_size const& P_y, T_scalar const& P_value )
 {
  if( M2_field.size() < P_y + 1)
   {
    return false;
   }
  auto& I_row = M2_field[ P_y ];
  if( I_row.size()< P_x + 1 )
   {
    return false;
   }

  I_row[ P_x ] = P_value;
  return true;
 }

bool     S_hfield::S_generator::GC_table::F_set( T_size2D const& P_coord, T_scalar const& P_value )
 {
  return F_set( P_coord[0], P_coord[1], P_value );
 }
