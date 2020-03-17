#ifndef Dh_DDMRM_Iceray_render_pierce__pure_HPP_
 #define Dh_DDMRM_Iceray_render_pierce__pure_HPP_

 //GS_DDMRM::S_IceRay::S_render::S_pierce::GC__pure

 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"

 #include "./_pure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_pierce
        {

         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar               T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar      T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D      T_resolution;

             typedef GC__pure T__pure, T_this;

          public:
                      GC__pure();
             virtual ~GC__pure();

          public:
             /*
              @param P_coord &sin; [-1,1]x[-1,1]
             */
                     void F_render( T_color & P_color, T_coord const& P_coord );
           protected:
             /*
              @param P_coord &sin; [-1,1]x[-1,1]
             */
             virtual void F1v_render( T_color & P_color, T_coord const& P_coord )=0;

           public:
             T_resolution const& F_resolution( )const{ return M2_resolution; };
             void                F_resolution( T_resolution const& P_resolution );
           private:
             T_resolution M2_resolution;

           protected:
             T_coord const& F1_scale( )const{ return M2_scale; }
           private:
             T_coord M2_scale;
          };

       }
     }
   }
 }

#endif
