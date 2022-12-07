#include "./default.hpp"

namespace GS_DDMRM{ namespace S_IceRay{ namespace S_type{ namespace S_picture {

void GF_default( GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure & P_image )
 {
  GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_coord I_coord;
  double I_width  = P_image.F_size()[0];
  double I_height = P_image.F_size()[1];

  for( I_coord[1]=0; I_coord[1] < I_height; ++I_coord[1] )
   for( I_coord[0]=0; I_coord[0] < I_width;  ++I_coord[0] )
    {
     auto I_r = I_coord[0]/I_width;
     auto I_g = I_coord[1]/I_height;
     auto I_b = 0.25;
     if( I_coord[0]== I_coord[1] )
      {
       I_r = I_g = I_b = I_coord[1]/I_height;
      }
     auto I_color = GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_color{ (unsigned char)(255*I_r), (unsigned char)(255*I_g), (unsigned char)(255*I_b) };
     P_image.Fv_pixel( I_coord, I_color );
    }
 }

}}}}
