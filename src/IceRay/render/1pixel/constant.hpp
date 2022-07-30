#ifndef Dh_DDMRM_Iceray_render_pixel_constant_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_constant_HPP_

// GS_DDMRM::S_IceRay::S_render::S_pixel::GC_constant

 #include "./_pure.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pixel
        {

         class GC_constant
          : public GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure
          {
           public:
             GC_constant()
              : GC_constant( T_color({0,0,0}) )
              {
              }

             GC_constant( T_color const& P_color )
              : M2_color( P_color )
              {
              }

             virtual ~GC_constant()
              {
              }

           public:
             void Fv_render( T_color & P_color, T_cell const& P_cell )
              {
               P_color.set( 0, 127 );
               P_color.set( 1, 127 );
               P_color.set( 2, 127 );
              }

           public:
             T_color const&         F_color()const
              {
               return M2_color; 
              }
           protected:
             bool   F_color( T_color const& P_color )
              { 
               M2_color = P_color; 
               return true; 
              }
           private:
             T_color  M2_color;
          };

       }
     }
   }
 }

#endif
