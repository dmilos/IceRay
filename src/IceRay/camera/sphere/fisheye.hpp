#ifndef _DDMRM_IceRAY_camera_sphere_fisheye_HPP_
 #define _DDMRM_IceRAY_camera_sphere_fisheye_HPP_

 // GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_fisheye

  #include <stddef.h>

  #include "../_pure.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_sphere
         {

          class GC_fisheye
           : public GS_DDMRM::S_IceRay::S_camera::GC__pure
           {
            public:
              GC_fisheye();
              explicit GC_fisheye( T_scalar const& P_theta, T_scalar const& P_phi, T_scalar const& P_radius = 1 );
             ~GC_fisheye();

            public:
              T_size Fv_beam( T_beam &, T_coord2D const& P_uv )const;
            protected:
              void   Fv_system( T_affine &, T_coord2D const& P_uv )const;

            public:  // property scalar  horizon
              T_scalar  const& F_horizont()const{ return M2_horizont; }
              bool             F_horizont( T_scalar const& P_horizont ){ M2_horizont = P_horizont; return bool( true ); }
            protected:
              T_scalar        & F1_horizont(){ return M2_horizont; }
            private:
              T_scalar M2_horizont;

            public:  // property scalar  vertical
              T_scalar    const& F_vertical()const{ return M2_vertical; }
              bool               F_vertical( T_scalar const& P_vertical ){ M2_vertical = P_vertical; return ( true ); }
            protected:
              T_scalar        & F1_vertical(){ return M2_vertical; }
            private:
              T_scalar M2_vertical;

            public:  // property scalar  radius
              T_scalar  const&   F_radius()const{ return M2_radius; }
              bool               F_radius( T_scalar const& P_radius ){ M2_radius = P_radius; return bool( true ); }
            protected:
              T_scalar        & F1_radius(){ return M2_radius; }
            private:
              T_scalar M2_radius;

          };

         }
       }
     }
   }

#endif

