#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

#include "IceRay/main/interface/handcode/get_scene.hpp"

#include "IceRay/geometry/_pure/_base.hpp"

#include "IceRay/type/picture/memory.hpp"
#include "IceRay/render/engine.hpp"

#include "pnm/pnm.hpp"

#include "IceRay/camera/_pure.hpp"
#include "IceRay/object/wrap.hpp"

#include "IceRay/render/0scanner/block.hpp"
#include "IceRay/render/0scanner/parallel.hpp"
#include "IceRay/render/1pixel/_base.hpp"
#include "IceRay/render/1pixel/uv.hpp"
#include "IceRay/render/1pixel/strategy/grid.hpp"
#include "IceRay/render/1pixel/strategy/random.hpp"
#include "IceRay/render/2pierce/_base.hpp"
#include "IceRay/render/2pierce/uv.hpp"
#include "IceRay/render/4ray/classic2/algorithm.hpp"
#include "IceRay/render/4ray/distance.hpp"


typedef GS_DDMRM::S_IceRay::S_type::GT_size            GTs_size;
typedef GS_DDMRM::S_IceRay::S_type::GT_scalar          GTs_scalar;

typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base GTs_geometry;
typedef GS_DDMRM::S_IceRay::S_camera::GC__pure            GTs_camera;

int main( int argc, char *argv[] )
 {
  cout << "Zero time" << endl;

  extern void InitSystem( void );
  std::cout << "Init: System" << endl;
  InitSystem();
  GTs_scalar I_alpha = 0.02;
  GTs_scalar I_betha = 0.0666;

  if( 1 < argc )
   {
    I_alpha = atof( argv[1] );
   }

  if( 2 < argc )
   {
    I_betha = atof( argv[2] );
   }

  //1.
  //// parse file
  cout << "Init: Scene" << endl;

  using namespace GS_DDMRM::S_IceRay;

  S_camera::GC__pure    *I_camera = nullptr;
  GTs_geometry          *I_geometry = nullptr;

  GS_DDMRM::S_IceRay::S_handcode::get_scene( &I_camera, &I_geometry );

  S_render::S_ray::S_classic2::GC_algorithm             *I_algorithm = new S_render::S_ray::S_classic2::GC_algorithm();
  I_algorithm->F_object( dynamic_cast<S_object::GC_wrap*>( I_geometry ) );

  S_render::S_ray::GC__pure              *I_RayRender     = I_algorithm;

  /*{
   S_render::S_ray::GC_distance *I_distance = new S_render::S_ray::GC_distance;

   I_distance->F_geometry( I_geometry );
   I_RayRender     = I_distance;
  }*/


  /*{
   S_render::S_pierce::GC_UV *I_uv = new S_render::S_pierce::GC_UV();
   I_PierceRender = I_uv;
  }*/

  S_render::S_pierce::GC__pure *I_PierceRender = nullptr;
  {
   S_render::S_pierce::GC__base *I_pierce= new S_render::S_pierce::GC__base();

   I_pierce->Fv_camera( I_camera );
   I_pierce->Fv_ray( I_RayRender );
   I_PierceRender = I_pierce;
  }

  S_render::S_pixel::GC__pure *I_PixelRender  = nullptr;
  {

   S_render::S_pixel::GC__base * I__base = new S_render::S_pixel::GC__base();

   //I__base->F_strategy( new  S_render::S_pixel::S_strategy::GC_grid( 5 ) );

   I_PixelRender = I__base;

   //I_PixelRender  = new S_render::S_pixel::GC_UV();
  }

  S_type::S_picture::GC__pure  *I_image = new S_type::S_picture::GC_memory();
  {
   S_type::S_picture::GC__pure::T_coord I_size;
   I_size[0] =1200;
   I_size[1] =1200;
   I_image->Fv_size( I_size );
  }

  S_render::S_scanner::GC__pure  *I_ScannerRender = nullptr;
  /*{
   S_render::S_scanner::GC_parallel *I_parallel = new S_render::S_scanner::GC_parallel();
   I_parallel->F_threads( 10 );
   I_ScannerRender = I_parallel;
  }*/

  {
   S_render::S_scanner::GC_block *I_block = new S_render::S_scanner::GC_block();
   I_ScannerRender = I_block;
  }

  S_render::GC_engine I_engine;

  I_engine.F_scanner( I_ScannerRender  );
  I_engine.F_pixel  ( I_PixelRender  );
  I_engine.F_pierce ( I_PierceRender );

  cout << "Rendering ... "  << endl;

  clock_t I_time=clock();

  I_engine.F_do( *I_image );

  I_time = clock() - I_time;

  while( I_engine.F_work() );

  cout << "vreme: " << I_time/GTs_scalar(CLK_TCK) << endl;

  {
   std::ofstream of( "image.ppm", std::ios_base::binary );

   of << PNM::save( (const uint8_t *)(I_image->Fv_data()), I_image->F_size()[0], I_image->F_size()[1], PNM::P6 );
  }

  cout << "DONE! " << endl;

  extern void ShutDownSystem( void );
  ShutDownSystem();
  return 0;
 }
