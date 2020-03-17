#ifndef Dh_DDMRM_Iceray_render_pixel_UV_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_UV_HPP_

// GS_DDMRM::S_IceRay::S_render::S_pixel::GC_UV

 #include "./_pure.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pixel
        {

         // Just return color. Demo that pixel render might be something different than ray tracer
         class GC_UV
          : public GC__pure
          {
           public:
             GC_UV()
              {
              }

             virtual ~GC_UV()
              {
              }

           public:
             /*
              @param P_cell &sin; [0,width-1]x[0,height-1]
             */
             void Fv_render( T_color & P_color, T_cell const& P_cell )
              {
               P_color.set( 0, 0*255*(P_cell[0]/(T_scalar)F_resolution()[0]) );
               P_color.set( 1,   255*(P_cell[1]/(T_scalar)F_resolution()[1]) );
               P_color.set( 2,  127 );
              }

          };

       }
     }
   }
 }

#endif
