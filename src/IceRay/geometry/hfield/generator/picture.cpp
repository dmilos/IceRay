#include "./picture.hpp"

using namespace GS_DDMRM::S_IceRay::S_geometry;


S_hfield::S_generator::GC_image::GC_image( )
 {
 }
S_hfield::S_generator::GC_image::GC_image( T_picture const& P_picture )
 {
  F_picture( P_picture );
 }

S_hfield::S_generator::GC_image::T_bool S_hfield::S_generator::GC_image::F_picture( T_picture const& P_picture )
 {
  T_table::Fv_size( P_picture.F_size() );
  T_picture::T_color I_color;
  for( T_size I_y =0; I_y < F_size()[1]; ++I_y )
   {
    for( T_size I_x =0; I_x < F_size()[0]; ++I_x )
     {
      P_picture.Fv_pixel( I_color, { I_x, I_y } );
      T_table::F_set( I_x, F_size()[1]-I_y-1, ::color::gray<double>( I_color )[0] );
     }
   }
  return true;
 }

S_hfield::S_generator::GC_image::T_bool S_hfield::S_generator::GC_image::Fv_size( T_size2D    const& P_size )
 {
  if( P_size[0] != F_size()[0] )
   {
    return false;
   }
  if( P_size[1] != F_size()[1] )
   {
    return false;
   }

  return true;
 }
