#ifndef Dh_DDMRM_Iceray_render_image_block_HPP_
 #define Dh_DDMRM_Iceray_render_image_block_HPP_
 
// GS_DDMRM::S_IceRay::S_render::S_scanner::GC_block

 #include "./_pure.hpp"

 #include "../../type/math/interval.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_scanner
        {

         class GC_block
          : public GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                 T_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D      T_cell, T_cell2D;
             typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_size2D   T_range;

             typedef GS_DDMRM::S_IceRay::S_render::S_scanner::GC__pure T__pure;

             GC_block();
             GC_block( T_size const&,T_size const&,T_size const&,T_size const& );
             GC_block( T_cell2D const&, T_cell2D const&  );
             GC_block( T_range const& P_window, T_pixel * P_pixel = nullptr );

            ~GC_block();

           private:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size             T2_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_char    T2_color;

           protected:
             void F1v_render( T_picture & P_image );

           public:
             T_range const& F_window()const{ return M2_window; }
             T_report       F_window( T_range const& P_window );
             T_report       F_window( T_cell const& P_lo, T_cell const& P_ho );
           private:
             T_range M2_window;

          public:
            T_report       F_hot( T_cell2D const& P_hot );
          private:
            T_cell2D M2_hot;
          private:
            T_size M2_dot;
            T_size M2_asterisk;
            T_size M2_step;
          };

       }
     }
   }
 }

#endif
