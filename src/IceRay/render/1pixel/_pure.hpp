#ifndef Dh_DDMRM_Iceray_render_pixel__pure_HPP_
 #define Dh_DDMRM_Iceray_render_pixel__pure_HPP_

 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pixel
        {

         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_char      T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_uv;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D    T_cell;

             typedef GC__pure T__pure, T_this;

             GC__pure();
             virtual ~GC__pure();

           public:
             /*!
              @param P_cell &sin; [0,width-1]x[0,height-1]
             */
             virtual void Fv_render( T_color & P_color, T_cell const& P_cell )=0;

           public:
             T_cell const& F_resolution( )const{ return M2_resolution; };
             void          F_resolution( T_cell const& P_resolution );
           private:
             T_cell M2_resolution;

           protected:
             void F1_2uv( T_uv & P_uv, T_cell const& P_cell );

           protected:
             T_uv const& F1_scale( )const{ return M2_scale; }
           private:
             T_uv M2_scale;

          };

       }
     }
   }
 }

#endif
