#include "../get_scene.hpp"
#include "IceRay/main/make/make.hpp"
#include "IceRay/object/wrap.hpp"
#include "IceRay/geometry/rtss/object.hpp"


    using GS_DDMRM::S_IceRay::S_utility::make_coord3;
    using GS_DDMRM::S_IceRay::S_utility::make_color;

    using GS_DDMRM::S_IceRay::S_utility::make_light_point;
    using GS_DDMRM::S_IceRay::S_utility::make_light_spot;
    using GS_DDMRM::S_IceRay::S_utility::make_light_chandelier;

    using GS_DDMRM::S_IceRay::S_utility::make_sphere;
    using GS_DDMRM::S_IceRay::S_utility::make_box;

    using GS_DDMRM::S_IceRay::S_utility::make_ambient;
    using GS_DDMRM::S_IceRay::S_utility::make_lambert;

    using GS_DDMRM::S_IceRay::S_utility::make_camera_lookAt;
    using GS_DDMRM::S_IceRay::S_utility::make_camera_perspective;



void GS_DDMRM::S_IceRay::S_handcode::get_scene( GTs_camera **P_camera, GTs_geometry **P_geometry  )
 {
  GS_DDMRM::S_IceRay::S_utility::GTs_light *I_light;

  {
    GS_DDMRM::S_IceRay::S_utility::GTs_chandelier::T_container I_container;
   I_container.emplace_back( make_light_point( make_light_spot( make_coord3(  0, 0 , 6 ), make_color( 1, 1, 1),  make_color( 1, 1, 1 ), make_color( 1, 1, 1 ) ) ) );
   I_light = make_light_chandelier( I_container );
  }


  *P_camera = make_camera_lookAt
             (
                make_camera_perspective( )
               ,make_coord3( 2, -5, 5 )
               ,make_coord3( 0, 0, 0 )
              , make_coord3( 0, 0, 1 )
             );



  GS_DDMRM::S_IceRay::S_object::GC_wrap   *I_wrap    = new S_object::GC_wrap();
  {
   auto *I_list = new S_geometry::S_RTSS::GC_object();

   {
    S_object::GC_wrap   *I_child1 = new S_object::GC_wrap();
    I_child1->F_geometry(  make_sphere( make_coord3(  0, 0, 1 ), 1 ) );
    I_child1->F_pigment( make_ambient( I_child1, make_color( 0, 0.1, 0 ) ) );
    I_child1->F_pigment( make_lambert( I_child1, I_light, make_color( 0.2, 0.7, 0.5 ) ) );
    I_list->F_push( I_child1 );
   }

   {
    S_object::GC_wrap   *I_child1 = new S_object::GC_wrap();
    I_child1->F_geometry( make_box( make_coord3( -5.5, -5.5,  -0.1 ), make_coord3( 5.5,  5.5,  0  ) ) );
    I_child1->F_pigment( make_ambient( I_child1, make_color( 0.02, 0.01, 0 ) ) );
    I_child1->F_pigment( make_lambert( I_child1, I_light, make_color( 0.5, 0.5, 0.5 ) ) );

    I_list->F_push( I_child1 );
   }

    I_wrap->F_geometry(  I_list );
  }

  *P_geometry = I_wrap;
 }

    //make_camera_focus( make_camera_perspective( ), 1, 0, 1, 0 )
   //I_camera =  make_camera_invert( make_camera_cylinder( ::math::constants::PHI, 5 ) );
   //I_camera =  make_camera_perspective();

    //I_container.emplace_back( make_light_sun( make_light_spot( make_coord3( 0, 0, 20 ) ) ) );

    //I_container.emplace_back( make_light_point( make_light_spot( make_coord3(  6,  6, 6 ), make_color( 0.25,  0.25,  0.25 ),  make_color( 0.5, 0.5, 0.5 ), make_color( 0.5, 0.5, 0.5 ) ) ) );
    //I_container.emplace_back( make_light_point( make_light_spot( make_coord3(  8,  8, 8 ), make_color( 0.25,  0.25,  0.25 ),  make_color( 0.5, 0.5, 0.5 ), make_color( 0.5, 0.5, 0.5 ) ) ) );
    //I_container.emplace_back( make_light_point( make_light_spot( make_coord3( -8, -8, 8 ), make_color( 0.25,  0.25,  0.25 ),  make_color( 0.5, 0.5, 0.5 ), make_color( 0.5, 0.5, 0.5 ) ) ) );
    //I_container.emplace_back( make_light_point( make_light_spot( make_coord3(  8, -8, 8 ), make_color( 0.25,  0.25,  0.25 ),  make_color( 0.5, 0.5, 0.5 ), make_color( 0.5, 0.5, 0.5 ) ) ) );
    //I_container.emplace_back( make_light_point( make_light_spot( make_coord3( -8,  8, 8 ), make_color( 0.25,  0.25,  0.25 ),  make_color( 0.5, 0.5, 0.5 ), make_color( 0.5, 0.5, 0.5 ) ) ) );

    //I_container.emplace_back( make_light_line( make_light_spot( make_coord3( -1, -1, 2 ), make_color( 0.25, 0.25, 0.25 ) ),  make_coord3( -1,  1, 2 ) ) );
    //I_container.emplace_back( make_light_line( make_light_spot( make_coord3(  1, -1, 2 ), make_color( 0.25, 0.25, 0.25 ) ),  make_coord3(  1,  1, 2 ) ) );

    //I_container.emplace_back( make_light_circle( make_light_spot( make_coord3( 0,  0, 2 ) ),  make_coord3( 1,  0, 0 ), make_coord3( 0,  1, 0 ) ) );
   // { I_light = make_light_circle( make_light_spot( make_coord3( 0,  0, 2 ) ),  make_coord3( 0.1,  0, 0 ), make_coord3( 0,  0.1, 0 ) ); }
   // { I_light = make_light_area( make_light_spot( make_coord3( -1,  -1, 2 ) ),  make_coord3( 2,  0, 0 ), make_coord3( 0,  2, 0 ) ); }
   // { I_light = make_light_reflector( make_light_spot( make_coord3( 2,  2, 2 ) ),  make_coord3( 0,  2, - 1 ), 0, .7 ); }
   // { I_light = make_light_sun( make_light_spot( make_coord3( 0, 2, 2 ) ) ); }
   // { I_light = make_light_line( make_light_spot( make_coord3( -1,  0, 2 ) ),  make_coord3( 1,  0, 2 ) ); }
   // { I_light = make_light_spline( make_light_spot( make_coord3( -1,  -1, 1 ) ),  make_coord3( 1, -1, 1 ),  make_coord3( -1, 1, 1 ),  make_coord3( 1, 1, 1 ) ); }

    //{
    //GTs_light     *I_sub = make_light_point( make_light_spot( make_coord3( 0, 0, 16 ), make_color( 0.25, 0.25, 0.25 ) ) );
    // GTs_geometry  *I_geometry= make_box( make_coord3( -1, -1, -1 ), make_coord3( 1, 1, 1 ) );
    //
    // I_container.emplace_back( make_light_blocked( I_sub, I_geometry ) );
    //}

