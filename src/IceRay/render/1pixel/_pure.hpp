#ifndef Dh_DDMRM_Iceray_render_pixel__pure_HPP_
 #define Dh_DDMRM_Iceray_render_pixel__pure_HPP_

 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"

 #include "../2pierce/_pure.hpp"
 #include "../2pierce/_base.hpp"
 #include "../2pierce/uv.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pixel
        {
         /*
          To have pure class
         */
         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_char      T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D    T_cell;

             typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure T_pierce;

             typedef GC__pure T__pure, T_this;

             GC__pure();
             virtual ~GC__pure();

           public:
             /*!
              @param P_cell &sin; [0,width-1]x[0,height-1]
             */
             virtual void Fv_render( T_color & P_color, T_cell const& P_cell )=0;

           public:
             void         F_pierce( T_pierce * P_pierce );
             T_pierce &   F_pierce( )
              {
               return *M2_pierce; 
              }
           private:
             T_pierce* M2_pierce;
             typedef GS_DDMRM::S_IceRay::S_render::S_pierce::GC_UV      T2_UV;
             static T2_UV M2s_pierce;

           public:
             T_cell const& F_resolution( )const{ return M2_resolution; };
             void          F_resolution( T_cell const& P_resolution );
           private:
             T_cell M2_resolution;

           protected:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T1_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T1_uv;
             void F1_2uv( T1_uv & P_uv, T_cell const& P_cell );

           protected:
             T1_uv const& F1_scale( )const{ return M2_scale; }
           private:
             T1_uv M2_scale;

          };

       }
     }
   }
 }

#endif
