#ifndef Dh_DDMRM_Iceray_render_pixel__base_HPP_
 #define Dh_DDMRM_Iceray_render_pixel__base_HPP_
 // GS_DDMRM::S_IceRay::S_render::S_pixel::GC__base

 #include "./_pure.hpp"
 #include "../../type/math/coord.hpp"

 #include "./strategy/_pure.hpp"
 #include "./filter/_pure.hpp"
 #include "./strategy/center.hpp"
 #include "./filter/const.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pixel
        {

         class GC__base
          : public GS_DDMRM::S_IceRay::S_render::S_pixel::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_char      T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D    T_cell;

             typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC__pure T_strategy;
             typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC__pure T_filter;

             typedef GC__base T__base, T_this;

             GC__base();
             virtual ~GC__base();

           public:
             /*!
              @param P_cell &sin; [0,width-1]x[0,height-1]
             */
             virtual void Fv_render( T_color & P_color, T_cell const& P_cell );

           public:
             void           F_strategy( T_strategy * P_strategy );
             T_strategy &   F_strategy( ){ return *M2_strategy; }
           private:
             T_strategy* M2_strategy;
             typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_strategy::GC_center T2_center;
             static T2_center  M2s_center;

           public:
             void         F_filter( T_filter * P_filter );
           protected:
             T_filter &   F1_filter(){ return *M2_filter; }
           private:
             T_filter* M2_filter;
             typedef GS_DDMRM::S_IceRay::S_render::S_pixel::S_filter::GC_const T2_const;
             static T2_const M2s_const;

           protected:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T1_color;
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T1_size;
          };

       }
     }
   }
 }

#endif
