#include "./default.hpp"

namespace GS_DDMRM{ namespace S_IceRay{ namespace S_type{ namespace S_picture {

void GF_lebesgue( GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure & P_image )
 {
  typedef  GS_DDMRM::S_IceRay::S_type::GT_scalar Tf_scalar;
  typedef  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_color Tf_color;
  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_coord I_coord;

  Tf_scalar I_width  = (Tf_scalar)P_image.F_size()[0];
  Tf_scalar I_height = (Tf_scalar)P_image.F_size()[1];

  for( I_coord[1]=0; I_coord[1] < I_height; ++I_coord[1] )
   for( I_coord[0]=0; I_coord[0] < I_width;  ++I_coord[0] )
    {
     std::array<Tf_scalar, 2> point2;
     point2[0] = I_coord[0] / Tf_scalar( I_width - 1 );
     point2[1] = I_coord[1] / Tf_scalar( I_height - 1 );

     auto value1 = ::math::function::lebesgueND( point2 );
     std::array<Tf_scalar, 3> point3;
     ::math::function::lebesgueND<Tf_scalar>( point3, value1 );

     Tf_color pixel = ::color::constant::black_t{};

     pixel[0] = std::uint8_t( 255 * point3[0] );
     pixel[1] = std::uint8_t( 255 * point3[1] );
     pixel[2] = std::uint8_t( 255 * point3[2] );

     P_image.Fv_pixel( I_coord, pixel );
    }
 }

void GF_checkboad( GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure & P_image )
 {
  typedef  GS_DDMRM::S_IceRay::S_type::GT_scalar Tf_scalar;
  typedef  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_color Tf_color;
  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_coord I_coord;

  Tf_scalar I_width  = (Tf_scalar)P_image.F_size()[0];
  Tf_scalar I_height = (Tf_scalar)P_image.F_size()[1];

  int I_size = int( I_width / 6 );

  for( I_coord[1]=0; I_coord[1] < I_height; ++I_coord[1] )
   for( I_coord[0]=0; I_coord[0] < I_width;  ++I_coord[0] )
    {
     Tf_color pixel = ::color::constant::black_t{};

     pixel[0] = std::uint8_t( 255 * ( I_coord[0]/Tf_scalar( I_width  - 1 ) ) );
     pixel[1] = 0* std::uint8_t( 255 * ( I_coord[1]/Tf_scalar( I_height - 1 ) ) );
     pixel[2] = std::uint8_t( 0 );
     if( I_coord[0] <  I_coord[1] )
      {
       pixel[0] = 0;
      }
     else
      {
       pixel[1] = 0;
      }
     auto sum = ( I_coord[0] / I_size ) + ( I_coord[1] / I_size );
     if( 0 != (sum % 2 ) ) 
      {
       pixel[0] = 255-pixel[0];
       pixel[1] = 255-pixel[1];
      }

     P_image.Fv_pixel( I_coord, pixel );
    }

 }

void GF_testsignal( GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure & P_image )
 {
  typedef  GS_DDMRM::S_IceRay::S_type::GT_scalar Tf_scalar;
  typedef  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_color Tf_color;
  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D    T_coord2D;


  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_coord I_coord;

  Tf_scalar I_width  = (Tf_scalar)P_image.F_size()[0];
  Tf_scalar I_height = (Tf_scalar)P_image.F_size()[1];
  typedef   color::hsl<Tf_scalar> hsl_t;
  typedef   color::rgb<Tf_scalar> rgb_t;
  typedef   color::gray<Tf_scalar> gray_t;

  auto rainbow_ribbon = []( Tf_scalar const& P_scalar )-> Tf_color
   {
    hsl_t c;
    c[0] = 360*P_scalar;
    c[1] = 100;
    c[2] = 50;
    return Tf_color( c );
   };

  auto gray_ribbon = []( Tf_scalar const& P_scalar )-> Tf_color
   {
    return Tf_color( gray_t( { P_scalar } ) );
   };

  auto rgb_ribbon = []( Tf_scalar const& P_scalar )-> rgb_t
   {
    if( P_scalar < Tf_scalar(1)/ Tf_scalar(6) ) return rgb_t( { 6*P_scalar-0,            0,            0 } );
    if( P_scalar < Tf_scalar(2)/ Tf_scalar(6) ) return rgb_t( {            0, 6*P_scalar-1,            0 } );
    if( P_scalar < Tf_scalar(3)/ Tf_scalar(6) ) return rgb_t( {            0,            0, 6*P_scalar-2 } );
    if( P_scalar < Tf_scalar(4)/ Tf_scalar(6) ) return rgb_t( {            0, 6*P_scalar-3, 6*P_scalar-3 } );
    if( P_scalar < Tf_scalar(5)/ Tf_scalar(6) ) return rgb_t( { 6*P_scalar-4,            0, 6*P_scalar-4 } );
    if( P_scalar < Tf_scalar(6)/ Tf_scalar(6) ) return rgb_t( { 6*P_scalar-5, 6*P_scalar-5,            0 });
    return color::rgb<Tf_scalar>( { 1, 1, 1 } );
   };

  auto ring = []( T_coord2D const& P_uv, T_coord2D const& P_center, T_coord2D const& P_radius )-> bool
   {
    T_coord2D I_point;
    ::math::linear::vector::subtraction( I_point, P_uv, P_center );
    auto I_distance = ::math::linear::vector::length( I_point );
    if( I_distance < P_radius[0] ) return false;
    if( P_radius[1] < I_distance ) return false;
    return true;
   };

  for( I_coord[1]=0; I_coord[1] < I_height; ++I_coord[1] )
   for( I_coord[0]=0; I_coord[0] < I_width;  ++I_coord[0] )
    {
     Tf_scalar I_u = (I_coord[0] - I_width/Tf_scalar(2) )/(I_height/Tf_scalar(2));
     Tf_scalar I_v = (I_coord[1] - I_height/Tf_scalar(2) )/(I_height/Tf_scalar(2));
     Tf_scalar I_x = (I_u + 1)/Tf_scalar(2);
     Tf_scalar I_y = (I_v + 1)/Tf_scalar(2);
     Tf_scalar I_angle = atan2( I_v, I_u ); if( I_angle < 0 ) I_angle += math::constants::PHI_two;
     Tf_scalar I_distance = sqrt( I_u*I_u + I_v*I_v );
     Tf_color pixel;

     hsl_t c;
     c[0] = 240* (( I_width-I_coord[0]-1)+I_coord[1])/( I_width+I_height -2 );
     c[1] = 100;
     c[2] = 100* (I_coord[0]+I_coord[1])/( I_width+I_height -2 );
     pixel = c;
     bool invert = bool( int(8*(I_u+1)) %2?true:false ) ^ bool( int(8* (I_v+1) ) %2?true:false );
     if( invert )
      {
       ::color::operation::invert( pixel, Tf_color{ c } );
      }

     if( fabs( I_u ) < Tf_scalar(1)/Tf_scalar( 64 ) ){ pixel = rgb_ribbon( I_y ); }
     if( fabs( I_u ) < Tf_scalar(1)/Tf_scalar(128 ) ){ pixel = rgb_ribbon( ::math::function::saw<Tf_scalar>( 6*I_y ) ); }
     if( fabs( I_v ) < Tf_scalar(1)/Tf_scalar( 64 ) ){ pixel = rgb_ribbon( I_x ); }
     if( fabs( I_v ) < Tf_scalar(1)/Tf_scalar(128 ) ){ pixel = rgb_ribbon( ::math::function::saw<Tf_scalar>( 6*I_x ) ); }

     if( fabs( I_u - I_v ) < Tf_scalar(1)/Tf_scalar( 64 ) )
      {
       auto I_value = ( (I_u+I_v) + 2)/Tf_scalar(4);
       pixel = rgb_ribbon( ((I_u+I_v) + 2)/Tf_scalar(4)  );
       if( fabs( I_u - I_v ) < Tf_scalar(1)/Tf_scalar( 128 ) )
        {
         pixel = rgb_ribbon( ::math::function::saw<Tf_scalar>( 12*I_value ) );
        }
      }

     if( fabs( I_x + I_y - 1) < Tf_scalar(1)/Tf_scalar( 128 ) )
      {
       auto I_value = ( I_x - I_y +1) /Tf_scalar( 2 );
       pixel = gray_ribbon( I_value );

       if( fabs( I_x + I_y - 1) < Tf_scalar(1)/Tf_scalar( 256 ) )
        {
         pixel = gray_ribbon( ::math::function::saw<Tf_scalar>( 12*I_value ) );
        }
       if( fabs( I_x + I_y - 1) < Tf_scalar(1)/Tf_scalar( 512 ) )
        {
         pixel = color::constant::white_t{};
        }
      }

     for( auto I_radius : { 1.0, 0.8, 0.75, 0.666666666, 0.5, 0.4, 0.3, 0.25, 0.2, 0.125, 0.1, 0.5 } )
      if( true == ring( {I_u, I_v}, {0,0}, { I_radius -Tf_scalar(1)/Tf_scalar(512), I_radius +Tf_scalar(1)/Tf_scalar(512) } ) )
       {
        pixel = color::constant::white_t{};
       }

     if( ( ( I_distance - 0.5 ) < Tf_scalar(1)/Tf_scalar(32) ) && ( 0.5 < I_distance  ) )
      {
       pixel = rgb_ribbon( ::math::function::saw<Tf_scalar>( 2 * I_angle/math::constants::PHI_two ) );
      }
     if( ( ( 0.5 - I_distance ) < Tf_scalar(1)/Tf_scalar(32) ) && ( I_distance < 0.5 ) )
      {
       pixel =  rgb_ribbon(  ::math::function::saw<Tf_scalar>( 10* I_angle/math::constants::PHI_two ) );
      }
     if( ( ( I_distance - 0.5 ) < Tf_scalar(1)/Tf_scalar(64) ) && ( 0.5 < I_distance  ) )
      {
       pixel =  rgb_ribbon(  ::math::function::saw<Tf_scalar>( 60* I_angle/math::constants::PHI_two ) );
      }
     if( fabs( 0.5 - I_distance ) < Tf_scalar(1)/Tf_scalar(512) )
      {
       pixel = color::constant::white_t{};
      }

     for( auto I_radius : { 0.5, 0.4, 0.3, 0.25, 0.2, 0.125, 0.1, 0.5 } )
      {
       if( true == ring( {I_u, I_v}, {-0.5,-0.5}, { I_radius -Tf_scalar(1)/Tf_scalar(512), I_radius +Tf_scalar(1)/Tf_scalar(512) } ) )
        {
         pixel = color::constant::black_t{};
        }
       if( true == ring( {I_u, I_v}, {+0.5,-0.5}, { I_radius -Tf_scalar(1)/Tf_scalar(512), I_radius +Tf_scalar(1)/Tf_scalar(512) } ) )
        {
         pixel = color::constant::red_t{};
        }
       if( true == ring( {I_u, I_v}, {-0.5,+0.5}, { I_radius -Tf_scalar(1)/Tf_scalar(512), I_radius +Tf_scalar(1)/Tf_scalar(512) } ) )
        {
         pixel = color::constant::green_t{};
        }
       if( true == ring( {I_u, I_v}, {+0.5,+0.5}, { I_radius -Tf_scalar(1)/Tf_scalar(512), I_radius +Tf_scalar(1)/Tf_scalar(512) } ) )
        {
         pixel = color::constant::blue_t{};
        }
      }  


     if( ( ( 1 - I_distance ) < Tf_scalar(1)/Tf_scalar(1*32) ) &&  ( I_distance < 1 ) )
      {
       //I_angle = ::math::function::wave<Tf_scalar>( 60*I_angle, 0, 2*math::constants::PHI );
         pixel =rainbow_ribbon( ::math::function::saw<Tf_scalar>(  60 * ( I_angle / math::constants::PHI_two ) ) );
       if( ( 1 - I_distance ) < Tf_scalar(1)/Tf_scalar(2*32) )
        {
         pixel =rainbow_ribbon( ::math::function::saw<Tf_scalar>(  12* ( I_angle / math::constants::PHI_two ) ) );
        }
       if( ( 1 - I_distance ) < Tf_scalar(1)/Tf_scalar(3*32) )
        {
         pixel =rainbow_ribbon( ::math::function::saw<Tf_scalar>(  1 * ( I_angle / math::constants::PHI_two ) ) );
        }
      }

     P_image.Fv_pixel( I_coord, pixel );
    }
 }

void GF_circle( GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure & P_image )
 {
  typedef  GS_DDMRM::S_IceRay::S_type::GT_scalar Tf_scalar;
  typedef  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_color Tf_color;
  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_coord I_coord;

  typedef   color::rgb<Tf_scalar> rgb_t;

  auto ribbon = []( Tf_scalar const& P_scalar )-> rgb_t
   {
    
    if( P_scalar < Tf_scalar(1)/ Tf_scalar(7) ) return rgb_t( { 7*P_scalar-0,            0,            0 } );
    if( P_scalar < Tf_scalar(2)/ Tf_scalar(7) ) return rgb_t( {            0, 7*P_scalar-1,            0 } );
    if( P_scalar < Tf_scalar(3)/ Tf_scalar(7) ) return rgb_t( {            0,            0, 7*P_scalar-2 } );
    if( P_scalar < Tf_scalar(4)/ Tf_scalar(7) ) return rgb_t( {            0, 7*P_scalar-3, 7*P_scalar-3 } );
    if( P_scalar < Tf_scalar(5)/ Tf_scalar(7) ) return rgb_t( { 7*P_scalar-4,            0, 7*P_scalar-4 } );
    if( P_scalar < Tf_scalar(6)/ Tf_scalar(7) ) return rgb_t( { 7*P_scalar-5, 7*P_scalar-5,            0 });
    if( P_scalar < Tf_scalar(7)/ Tf_scalar(7) ) return rgb_t( { 7*P_scalar-5, 7*P_scalar-5, 7*P_scalar-6 });
    return color::rgb<Tf_scalar>( { 1, 1, 1 } );
   };

  Tf_scalar I_width  = (Tf_scalar)P_image.F_size()[0];
  Tf_scalar I_height = (Tf_scalar)P_image.F_size()[1];

  for( I_coord[1]=0; I_coord[1] < I_height; ++I_coord[1] )
   for( I_coord[0]=0; I_coord[0] < I_width;  ++I_coord[0] )
    {
     Tf_scalar u = 2 * (I_coord[0] / Tf_scalar( I_width - 1 ) ) - 1;
     Tf_scalar v = 2 * (I_coord[1] / Tf_scalar( I_height - 1 ) ) - 1;

     Tf_scalar value = sqrt( u * u + v * v );

     auto C = ribbon( value );

     Tf_color pixel;
     pixel[0] = std::uint8_t( 255 * C[0] );
     pixel[1] = std::uint8_t( 255 * C[1] );
     pixel[2] = std::uint8_t( 255 * C[2] );

     P_image.Fv_pixel( I_coord, pixel );
    }
 }


void GF_default( GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure & P_image )
 {
  return GF_testsignal( P_image );
 }
}}}}
