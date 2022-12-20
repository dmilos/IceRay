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

  for( I_coord[1]=0; I_coord[1] < I_height; ++I_coord[1] )
   for( I_coord[0]=0; I_coord[0] < I_width;  ++I_coord[0] )
    {
     Tf_scalar I_u = (I_coord[0] - I_width/Tf_scalar(2) )/(I_height/Tf_scalar(2));
     Tf_scalar I_v = (I_coord[1] - I_height/Tf_scalar(2) )/(I_height/Tf_scalar(2));
     hsl_t c;
     c[0] = 240* (( I_width-I_coord[0]-1)+I_coord[1])/( I_width+I_height -2 );
     c[1] = 100;
     c[2] = 100* (I_coord[0]+I_coord[1])/( I_width+I_height -2 );
     if( I_coord[0] == I_width/2 ) c = color::constant::lime_t{};
     if( I_coord[1] == I_width/2 ) c = color::constant::red_t{};
     if( I_coord[0] == I_coord[1] ) c = color::constant::white_t{};
     if( (I_width - I_coord[0] - 1) == I_coord[1] ) c = color::constant::black_t{};

     bool invert = bool( ( I_coord[0]/17)%2 ) ^ bool( ( I_coord[1]/17)%2 );
     Tf_color pixel { c };
     if( invert )
      {
       ::color::operation::invert( pixel, Tf_color{ c } );
      }

     if( fabs( sqrt(I_u*I_u + I_v*I_v ) - 1 ) < Tf_scalar(1)/I_width )
      {
       pixel = color::constant::black_t{};
      }
     if( fabs( sqrt(I_u*I_u + I_v*I_v ) - 0.5 ) < Tf_scalar(1)/I_width )
      {
       pixel = color::constant::white_t{};
      }

     P_image.Fv_pixel( I_coord, pixel );
    }
 }

}}}}
