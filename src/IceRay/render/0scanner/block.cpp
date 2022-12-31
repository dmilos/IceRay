#include <iostream>
#include <iomanip>
#include <chrono>
#include "block.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_scanner;

GC_block::GC_block()
 : GC_block( { ::math::linear::vector::fill( T_cell{}, 0 ) , ::math::linear::vector::fill( T_cell{}, -1 ) }, nullptr)
 {
 }

GC_block::GC_block( T_size const& P_left, T_size const& P_top, T_size const& P_right, T_size const& P_bottom )
 : GC_block( { T_cell2D{P_left,P_top}, T_cell2D{P_right,P_bottom} }, nullptr )
 {
 }

GC_block::GC_block( T_cell2D const& P_lo, T_cell2D const& P_hi )
 : GC_block( { P_lo, P_hi }, nullptr )
 {
 }

GC_block::GC_block( T_range const& P_window, T_pixel * P_pixel )
 : T__pure( P_pixel )
 ,M2_window( ::math::linear::vector::fill( T_cell{}, 0 ) , ::math::linear::vector::fill( T_cell{}, -1 ) )
 {
  M2_hot[0] = M2_hot[1] = 1;
  M2_dot = 10;
  M2_asterisk = 100;
  M2_step = 10;
 }

GC_block::~GC_block()
 {
 }

GC_block::T_report
GC_block::F_window( T_range const& P_window )
 {
  if( F_work() ) return T_report( false );
  M2_window = P_window;
  ::math::geometry::interval::correct( M2_window );
  return T_report( true );
 }


GC_block::T_report      GC_block:: F_hot( T_cell2D const& P_hot )
 {
  M2_hot = P_hot;
  return T_report( true );
 }
 
void
GC_block::F1v_render( T_picture & P_picture )
 {
  if( nullptr == F_pixel() )
   {
    return;
   }

  T_pixel::T_cell I_cell;

  T2_size I_left  = std::min<T2_size>( std::max<T2_size>( 0, M2_window.lo()[0] ), P_picture.F_size()[0]-1 );
  T2_size I_right = std::min<T2_size>( P_picture.F_size()[0]-1, M2_window.hi()[0] );

  T2_size I_down  = std::min<T2_size>( std::max<T2_size>( 0, M2_window.lo()[1] ), P_picture.F_size()[1]-1 );
  T2_size I_up    = std::min<T2_size>( P_picture.F_size()[1]-1, M2_window.hi()[1] );

  T2_color I_color;
  auto image_start = std::chrono::steady_clock::now();
  auto block_start = std::chrono::steady_clock::now();
  std::cout << std::endl;

  for( I_cell[1] = I_down; I_cell[1] <= I_up;  )
   {

    {
     block_start = std::chrono::steady_clock::now();
     std::cout << I_cell[1] << " / " << I_up ;
    }

    T_size I_end = std::min<T_size>( I_cell[1] + M2_step, I_up+1 );

    for( /*I_cell[1]*/ ; I_cell[1] < I_end;  ++I_cell[1]  )
     {
      for( I_cell[0] = I_left; I_cell[0] <= I_right; ++I_cell[0] )
       {
        if( ( M2_hot[0] == I_cell[0] ) && ( M2_hot[1] == I_cell[1] ) )
         {
          I_cell = I_cell;
         }

        F1_pixel()->Fv_render( I_color, I_cell );
        P_picture.Fv_pixel(   I_cell, I_color );
        if( false == F_work() ) break;
        if( 0 == ( I_cell[1] % M2_step ) )
         {
          if( 0 == ( I_cell[0] %  M2_dot      ) ) { std::cout << "."; }
          if( 0 == ( I_cell[0] %  M2_asterisk ) ) { std::cout << "*"; }
         }
       }
     }

     {
      auto image_current = std::chrono::steady_clock::now();
      auto block_end     = std::chrono::steady_clock::now();

      auto image_delta = image_current - image_start;
      auto block_delta = block_end - block_start;

      std::cout << "[" << std::setw(8) << std::chrono::duration_cast< std::chrono::duration<double> >(block_delta).count() << " ]"; 
      std::cout << "[" << std::setw(8) << std::chrono::duration_cast< std::chrono::duration<double> >(image_delta).count() << " / "; 
      std::cout << std::setw(8) << std::chrono::duration_cast<std::chrono::duration<double> >(image_delta).count() * T_scalar( I_up - I_down)/T_scalar( I_cell[1] - I_down ) << " ]"; 

      block_start = std::chrono::steady_clock::now();
      std::cout << std::endl; 
     }

   }

  std::cout << std::endl;
 }
