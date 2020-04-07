#ifndef Dh_DDMRM_Iceray_render_pierce_UV_HPP_
 #define Dh_DDMRM_Iceray_render_pierce_UV_HPP_

// GS_DDMRM::S_IceRay::S_render::S_pierce::GC_UV

 #include "./_pure.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pierce
        {

         class GC_UV
          : public GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure
          {
           public:
             GC_UV()
              {
              }

             virtual ~GC_UV()
              {
              }

           protected:
             /*
              @param P_coord &sin; [0,1]x[0,1]
             */
             void F1v_render( T_color & P_color, T_coord const& P_coord )
              {
               P_color.set( 0, P_coord[0] );
               P_color.set( 1, P_coord[1] );
               P_color.set( 2, 0 );
              }

          };

       }
     }
   }
 }

#endif
