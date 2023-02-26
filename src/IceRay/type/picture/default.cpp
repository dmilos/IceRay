#include "./default.hpp"

namespace GS_DDMRM{ namespace S_IceRay{ namespace S_type{ namespace S_picture {

void GF_default( GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure & P_image )
 {
  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_coord I_coord;
  double I_width  = P_image.F_size()[0];
  double I_height = P_image.F_size()[1];
  typedef   color::hsl<double> hsl_t;
  typedef  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_color Tf_color;
  typedef  GS_DDMRM::S_IceRay::S_type::GT_scalar Tf_scalar;

  auto rainbow_ribbon = []( Tf_scalar const& P_scalar )-> Tf_color
   {
    color::hsl<double> c;
    c[0] = 360*P_scalar;
    c[1] = 100;
    c[2] = 50;
    return Tf_color( c );
   };

  auto gray_ribbon = []( Tf_scalar const& P_scalar )-> Tf_color
   {
    return Tf_color( ::color::gray<Tf_scalar>( { P_scalar } ) );
   };

  auto rgb_ribbon = []( Tf_scalar const& P_scalar )-> color::rgb<Tf_scalar>
   {
    if( P_scalar < Tf_scalar(1)/ Tf_scalar(6) ) return color::rgb<Tf_scalar>( { 6*P_scalar-0,            0,            0 } );
    if( P_scalar < Tf_scalar(2)/ Tf_scalar(6) ) return color::rgb<Tf_scalar>( {            0, 6*P_scalar-1,            0 } );
    if( P_scalar < Tf_scalar(3)/ Tf_scalar(6) ) return color::rgb<Tf_scalar>( {            0,            0, 6*P_scalar-2 } );
    if( P_scalar < Tf_scalar(4)/ Tf_scalar(6) ) return color::rgb<Tf_scalar>( {            0, 6*P_scalar-3, 6*P_scalar-3 } );
    if( P_scalar < Tf_scalar(5)/ Tf_scalar(6) ) return color::rgb<Tf_scalar>( { 6*P_scalar-4,            0, 6*P_scalar-4 } );
    if( P_scalar < Tf_scalar(6)/ Tf_scalar(6) ) return color::rgb<Tf_scalar>( { 6*P_scalar-5, 6*P_scalar-5,            0 });
    return color::rgb<Tf_scalar>( { 1, 1, 1 } );
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

}}}}
