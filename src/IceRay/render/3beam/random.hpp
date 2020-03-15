#ifndef Dh_DDMRM_Iceray_render_beam_random_HPP_
 #define Dh_DDMRM_Iceray_render_beam_random_HPP_

 #include "_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_beam
        {

         class GC_random
          : public GC__pure
          {
           public:

             GC_random();
             virtual ~GC_random();

             virtual void Fv_do( T_color & P_color, T_beam const& );

          };

       }
     }
   }
 }

#endif
