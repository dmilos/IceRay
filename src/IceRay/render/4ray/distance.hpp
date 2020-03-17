#ifndef Dh_DDMRM_Iceray_render_ray_distance_HPP_
 #define Dh_DDMRM_Iceray_render_ray_distance_HPP_

// GS_DDMRM::S_IceRay::S_render::S_ray::GC_distance

 #include "./_pure.hpp"
 #include "../../type/math/interval.hpp"
 #include "../../type/color.hpp"

 #include "../../geometry/_pure/intersect.hpp"
 #include "../../geometry/volumetric/vacuum.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_render
      {
       namespace S_ray
        {

         class GC_distance
          : public GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar                           T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_interval::GC__model<T_color,1>::T_typedef  T_gradient;

             typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar1D                       T_clip;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base                         T_geometry;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC_intersect                     T_state;
             //enum Ee_

             GC_distance();
             ~GC_distance();

             void Fv_trace( T_color & P_color, T_ray const& );

           public:
             T_clip const& F_clip()const{ return M2_clip; }
             void          F_clip( T_clip const& P_clip );
           private:
             T_clip M2_clip;

           public:
             T_gradient const& F_gradient()const{ return M2_gradient; }
             void              F_gradient( T_gradient const& P_gradient );
           private:
             T_gradient M2_gradient;

           private:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar  T2_scalar;

           public:
             void         F_geometry( T_geometry * P_geometry );
           protected:
             T_state *  F1_geometry( );
           private:
             T_state* M2_geometry;

           private:
             static T_state & Fs_geometry();
          };

       }
     }
   }
 }

#endif
