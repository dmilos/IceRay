#ifndef Dh_DDMRM_Iceray_render_pixel_strategy_center_HPP_
 #define Dh_DDMRM_Iceray_render_pixel_strategy_center_HPP_

 
 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pixel
        {
         namespace S_strategy
          {
           class GC_center
           :public GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure
            {
             public:

             public:
               T_size Fv_make()
                {
                 F1_sieve().resize( 1 );

                 F1_sieve()[0][0] = 0.0;
                 F1_sieve()[0][1] = 0.0;

                 //F1_sieve()[1][0] = 0.5;
                 //F1_sieve()[1][1] = 0.5;
                 //
                 //F1_sieve()[2][0] = 1.0;
                 //F1_sieve()[2][1] = 1.0;

                 return F1_sieve().size();
                }

            };

          }
        }
      }
    }
  }

#endif
