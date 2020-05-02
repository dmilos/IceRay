#include <iostream>
#include <iomanip>
#include "./parallel.hpp"
#include "./parallel.hpp"

#include "IceRay/render/1pixel/uv.hpp"

using namespace GS_DDMRM::S_IceRay::S_render::S_scanner;


GC_parallel::GC_parallel()
 {
  M2_range[0][0] = 0;  M2_range[1][0] = 0;
  M2_range[0][1] = 0;  M2_range[1][1] = 0;
  F_threads( 1 );
 }

GC_parallel::~GC_parallel()
 {
 }

GC_parallel::T_report
GC_parallel::Fv_pixel( T_pixel * P_pixel )
 {
  for( auto & I_job: M2_render )
   {
    I_job.M_scanner.Fv_pixel( P_pixel  );
   }
   return true;
 }

GC_parallel::T_report
GC_parallel::F_pixel( T_size const& P_index, T_pixel * P_pixel )
 {
   M2_render[ P_index ].M_scanner.Fv_pixel( P_pixel );
   return true;
 }


GC_parallel::T_report
GC_parallel::F_range( T_range const& P_range )
 {
  if( F_work() ) return T_report( false );

  M2_range = P_range;

  if( 0 == M2_render.size() )
   {
    return true;
   }

  T_size I_step   = (P_range.hi()[1]-P_range.lo()[1]+1)/M2_render.size();
  T_size I_extra  = (P_range.hi()[1]-P_range.lo()[1]+1)%M2_render.size();
  T_size I_bottom = P_range.lo()[1];

  for( auto & I_job : M2_render )
   {
    T_range I_range = P_range;
    T_range::point_type I_coord;

    I_coord = I_range.lo( );
    I_coord[1] = I_bottom;
    I_range.lo() = I_coord ;

    I_coord = I_range.hi();
    I_bottom  += I_step;
    if( 0 != I_extra )
     {
      ++I_bottom;
      --I_extra;
     }
    I_coord[1] = I_bottom;
    I_range.hi() =  I_coord;

    I_job.M_scanner.F_window( I_range );
   }

  return T_report( true );
 }

void GC_parallel::Fv_stop()
 {
  for( auto & I_job: M2_render )
   {
    I_job.M_scanner.Fv_stop();
   }

  for( auto & I_job: M2_render )
   {
    I_job.M_thread->join();
   }

  for( auto & I_job: M2_render )
   {
    I_job.M_thread = std::shared_ptr<std::thread>( new std::thread() );
   }


  F1_work() = false;
 }

GC_parallel::T_report
GC_parallel::F_threads( T_size const& P_count )
 {
  M2_render.resize( P_count, C_job{ T_scanner( &GC_parallel::F2s_pixel() ), nullptr } );

  F_range( M2_range );
  return true;
 }

void
GC_parallel::F1v_render( T_picture & P_picture )
 {
  for( auto & I_job : M2_render )
   {
    T_scanner & I_block = I_job.M_scanner;

    I_job.M_thread = std::shared_ptr<std::thread>( new std::thread( [&I_block, &P_picture]( ) -> void{ I_block.Fv_render( P_picture ); } ) );
   }

  for( auto & I_job: M2_render )
   {
    I_job.M_thread->join();
   }

  for( auto & I_job: M2_render )
   {
    I_job.M_thread = std::shared_ptr<std::thread>( new std::thread() );
   }

 }

GC_parallel::T_pixel & GC_parallel::F2s_pixel()
 {
  static  GS_DDMRM::S_IceRay::S_render::S_pixel::GC_UV Is_pixel;
  return Is_pixel;
 }

