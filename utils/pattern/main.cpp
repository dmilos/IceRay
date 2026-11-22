#include <iostream>
#include <iomanip>
#include <string>

#include "math/math.hpp"
#include "color/color.hpp"
#include <opencv2/opencv.hpp>

#include "IceRay/utility/mapping.hpp"

using namespace std;



int g_u = 800;
int g_v = 550;
int g_Z = 700;
int g_cameraX = 420;
int g_cameraY = 380;
int g_cameraZ = 673;
int g_swap   = 4;
void initUI()
{
  cv::namedWindow( "Command", cv::WINDOW_FREERATIO );
  ::cv::createTrackbar( "u", "Command", &g_u, 1000, NULL );
  ::cv::createTrackbar( "v", "Command", &g_v, 1000, NULL );
  ::cv::createTrackbar( "Z", "Command", &g_Z, 1000, NULL );
  ::cv::createTrackbar( "cX", "Command", &g_cameraX, 1000, NULL );
  ::cv::createTrackbar( "cY", "Command", &g_cameraY, 1000, NULL );
  ::cv::createTrackbar( "cZ", "Command", &g_cameraZ, 1000, NULL );
  ::cv::createTrackbar( "swap", "Command", &g_swap, 6, NULL );
 }

typedef ::math::geometry::projective::camera::mobile< double > camera_type;
typedef ::math::linear::vector::point< double ,2 > point2d_type;
typedef ::math::linear::vector::point< double, 3 > point3d_type;
typedef ::color::rgb<std::uint8_t>  color_type;

camera_type g_camera;

void init_common()
{
}

//  typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_spherical2cartesian   MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cylindric2cartesian   MapperType;

//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_identity              MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2cylindric   MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2spherical   MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cylindric2spherical   MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_spherical2cylindric   MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_euclid2max            MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_max2euclid            MapperType;

//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2tablecloth  MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2torus       MapperType;
typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_torus2cartesian       MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2woodX       MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2woodY       MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2woodZ       MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2fisheye     MapperType;
//typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2package     MapperType;


void set_point( cv::Mat& frame, camera_type const& camera, point3d_type const& P, color_type const& C )
 {
  auto pixel = g_camera.projectXY<int>( P );
  if( (pixel[0] < frame.cols)
    && (pixel[1] < frame.rows)
    && (0 < pixel[0])
    && (0 < pixel[1]) )
  {
    frame.at<cv::Vec3b>( pixel[1], pixel[0] )[0] = C[2];
    frame.at<cv::Vec3b>( pixel[1], pixel[0] )[1] = C[1];
    frame.at<cv::Vec3b>( pixel[1], pixel[0] )[2] = C[0];
  }
}
void set_line( cv::Mat& frame, camera_type const& camera, point3d_type const& start, point3d_type const& end, color_type const& C )
 {
  point3d_type P;
  for( double t=0; t< 1.0; t+=0.001 )
   {
    ::math::linear::vector::convex( P, t, start, end );
    set_point( frame, camera,  P,  C );
   }
}

void monitor( cv::Mat& frame )
{
  ::math::linear::affine::structure<double,3> to_world;

  double x = math::function::any_to_any<double>( g_cameraX, 0, 1000, -5, +5 ) ;
  double y = math::function::any_to_any<double>( g_cameraY, 0, 1000, -5, +5 ) ;
  double z = math::function::any_to_any<double>( g_cameraZ, 0, 1000, -5, +5 ) ;
  ::math::linear::affine::look_at<double>( to_world, {x,y,z}, {0,0,0}, {0,0,1} );

  g_camera.to_world( to_world );
  g_camera.optical().resolution( frame.cols, frame.rows );

  //point3d_type p3;
   MapperType::T_coord p3;
   MapperType mapper;

   auto limitU = math::function::any_to_any<double>( g_u, 0, 1000, -2.0, +2.0 );
   auto limitV = math::function::any_to_any<double>( g_v, 0, 1000, -2.0, +2.0 );

   color_type C;                    

   for( double v=-limitV; v< +limitV; v+= limitV*0.01 )
    for( double u=-limitU; u< +limitU; u+= limitU*0.01 )
    {
     p3[0] = u;
     p3[1] = v;
     p3[2] = math::function::any_to_any<double>( g_Z, 0, 1000, -2, +2 );

     switch( g_swap )
      {
       default: break;                             //!< 0, 1, 2
       case(1) : std::swap( p3[1], p3[2] ); break; //!< 0, 2, 1
       case(2) : std::swap( p3[0], p3[1] ); break; //!< 1, 0, 2
       case(3) : std::swap( p3[0], p3[1] ); std::swap( p3[1], p3[2] );break; //!< 1, 2, 0
       case(4) : std::swap( p3[0], p3[2] ); std::swap( p3[1], p3[2] );break; //!< 2, 0, 1
       case(5) : std::swap( p3[0], p3[2] ); break; //!< 2, 1, 0
      }

     C[0] = (std::uint8_t)math::function::any_to_any<double>( u, -limitU, limitU, 0, 255 );
     C[1] = (std::uint8_t)math::function::any_to_any<double>( v, -limitV, limitV, 0, 255 );
     C[2] = ( (int)C[0]+ (int)C[1] )/2;
     set_point(  frame, g_camera, mapper( p3 ), C );
     set_point(  frame, g_camera,   p3 ,  C );
    }

   set_line( frame, g_camera, { -0.25, 0.0, 0.0 }, { +1, 0, 0 }, color_type( { 255,   0,   0 } ) );
   set_line( frame, g_camera, {  0.0,-0.25, 0.0 }, {  0,+1, 0 }, color_type( {   0, 255,   0 } ) );
   set_line( frame, g_camera, {  0.0, 0.0,-0.25 }, {  0, 0,+1 }, color_type( {   0,   0, 255 } ) );
   set_line( frame, g_camera, {  0.0, 0.0, 0.0 }, { +1,+1,+1 }, color_type( { 255, 255, 255 } ) );

   set_line( frame, g_camera, { 1,1,-1 }, { 1,1,+1 }, color_type( { 255, 255,   0 } ) );
   set_line( frame, g_camera, { 1,1,1 }, { 1,0,1 }, color_type( { 255,   0, 255 } ) );
   set_line( frame, g_camera, { 1,1,1 }, { 0,1,1 }, color_type( {   0, 255, 255 } ) );
}

void invert_test()
 {
  typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_cartesian2torus       ForwardType;
  typedef GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_torus2cartesian       BackwardType;

  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar Tf_coord;

  Tf_coord I_p0,I_p1,I_p2;
  double delta ;

  ::math::linear::vector::load( I_p0, -2, 0, 0 ); 
  I_p1 = ForwardType()(I_p0);
  I_p2 = BackwardType()( I_p1 );  
  delta = ::math::linear::vector::distance( I_p0, I_p2 );

  ::math::linear::vector::load( I_p0, +2, 0, 0 ); 
  I_p1 = ForwardType()(I_p0);
  I_p2 = BackwardType()(I_p1);
  delta = ::math::linear::vector::distance( I_p0, I_p2 );

  ::math::linear::vector::load( I_p0, 0, -2, 0 ); 
  I_p1 = ForwardType()(I_p0);
  I_p2 = BackwardType()(I_p1);
  delta = ::math::linear::vector::distance( I_p0, I_p2 );

  ::math::linear::vector::load( I_p0, 0, +2, 0 ); 
  I_p1 = ForwardType()(I_p0);
  I_p2 = BackwardType()(I_p1);
  delta = ::math::linear::vector::distance( I_p0, I_p2 );

  double limitU =  3.0;
  double limitV =  3.0;
  double limitW =  3.0;

   for( double u=-1; u< +limitU; u+= limitU*0.01 )
    for( double v=-1; v< +limitV; v+= limitV*0.01 )
     for( double w=-1; w< +limitW; w+= limitW*0.01 )
      {
       ::math::linear::vector::load( I_p0, u, v, w );

       I_p1 = ForwardType()(I_p0);
       I_p2 = BackwardType()(I_p1);

       auto delta = ::math::linear::vector::distance( I_p0, I_p2 );
       if( 0.0001 < delta )
        {
         std::cout << delta << std::endl;
        }
      }

}

int main( int argc, char *argv[] )
 {
  invert_test();
  int frame_height = 600;
  int frame_width = 800;

  cv::Mat frame( frame_height, frame_width, CV_8UC3 );

  initUI();
  init_common();

  for( unsigned long counter = 0; true; ++counter )
  {
    cv::rectangle( frame, cv::Point2i( 0, 0 ), ::cv::Point2i( frame.cols, frame.rows ), ::cv::Scalar( 0, 0, 0 ), cv::FILLED );

    //monitor(frame);
    //init_common();
    monitor( frame );

    ::cv::line( frame, ::cv::Point2i( 0, frame.rows / 2 ), ::cv::Point2i( frame.cols, frame.rows / 2 ), ::cv::Scalar( 255, 255, 255 ), 1 );
    ::cv::line( frame, ::cv::Point2i( frame.cols / 2, 0 ), ::cv::Point2i( frame.cols / 2, frame.rows ), ::cv::Scalar( 255, 255, 255 ), 1 );

    cv::imshow( "Frame-frame", frame );
    char c = (char)cv::waitKey( 1 );
    if( c == 27 ) break;
    if( ' ' == c ) init_common();
   }

  return EXIT_SUCCESS;
}
