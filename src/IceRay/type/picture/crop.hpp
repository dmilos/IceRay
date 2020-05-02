#ifndef Dh_DDMM_IceRay_type_picture_crop_HPP_
 #define Dh_DDMM_IceRay_type_picture_crop_HPP_

 //GS_DDMRM::S_IceRay::S_type::S_picture::GF_crop( )

 #include "../math/interval.hpp"
 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_type
      {
       namespace S_picture
        {

         bool GF_crop
          (
            GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure        & P_this
           ,GS_DDMRM::S_IceRay::S_type::S_interval::GT_size2D const& P_window
          )
          {
           GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_coord I_coord;
           GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_color I_color;
           P_this.Fv_size( { P_window[1][0] - P_window[0][0] , P_window[1][1] - P_window[0][1] } );
           for( I_coord[1]= P_window[0][1]; I_coord[1] < P_window[1][1]; ++ I_coord[1] )
            for( I_coord[0]= P_window[0][0]; I_coord[0] < P_window[1][0]; ++ I_coord[0] )
             {
              P_this.Fv_pixel( I_color, I_coord );
              P_this.Fv_pixel( { I_coord[0] - P_window[0][0], I_coord[1] - P_window[0][1] }, I_color );
             }

           return true;
          }

         bool GF_crop
          (
            GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure        & P_target
           ,GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure   const& P_source
           ,GS_DDMRM::S_IceRay::S_type::S_interval::GT_size2D const& P_window
          )
          {
           GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_coord I_coord;
           GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure::T_color I_color;
           P_target.Fv_size( { P_window[1][0] - P_window[0][0] , P_window[1][1] - P_window[0][1] } );
           for( I_coord[1]= P_window[0][1]; I_coord[1] < P_window[1][1]; ++ I_coord[1] )
            for( I_coord[0]= P_window[0][0]; I_coord[0] < P_window[1][0]; ++ I_coord[0] )
             {
              P_source.Fv_pixel( I_color, I_coord );
              P_target.Fv_pixel( { I_coord[0] - P_window[0][0], I_coord[1] - P_window[0][1] }, I_color );
             }

           return true;
          }

        }
      }
    }
  }

#endif
