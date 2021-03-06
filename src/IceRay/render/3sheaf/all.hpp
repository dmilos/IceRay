#ifndef Dh_DDMRM_Iceray_render_sheaf_all_HPP_
 #define Dh_DDMRM_Iceray_render_sheaf_all_HPP_

// GS_DDMRM::S_IceRay::S_render::S_sheaf::GC_all

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_sheaf
        {

         class GC_all
          : public GC__pure
          {
           public:

             GC_all();
             virtual ~GC_all();

             virtual void Fv_do( T_color & P_color, T_beam const& );

          };

       }
     }
   }
 }

#endif
