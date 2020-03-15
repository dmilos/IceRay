#ifndef _DDMRM_IceRAY_camera_cylinder_horizontal_HPP_
 #define _DDMRM_IceRAY_camera_cylinder_horizontal_HPP_

  #include <stddef.h>

  #include "../_pure.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_cylinder
         {

          class GC_horizontal
           : public GS_DDMRM::S_IceRay::S_camera::GC__pure
           {
            public:
              GC_horizontal();
              GC_horizontal( T_scalar const& P_width, T_scalar const& P_theta, T_scalar const& P_radius = 1 );
             ~GC_horizontal();

            public:
              T_size Fv_beam( T_beam &, T_coord2D const& P_uv )const;
            protected:
              void   Fv_system( T_affine &, T_coord2D const& P_uv )const;

            public:  // property scalar  height
              T_scalar    const& F_width()const{ return M2_width; }
              bool               F_width( T_scalar const& P_width ){ M2_width = P_width; return ( true ); }
            protected:
              T_scalar        & F1_width(){ return M2_width; }
            private:
              T_scalar M2_width;

            public:  // property scalar  theta
              T_scalar  const&   F_theta()const{ return M2_theta; }
              bool               F_theta( T_scalar const& P_theta ){ M2_theta = P_theta; return bool( true ); }
            protected:
              T_scalar        & F1_theta(){ return M2_theta; }
            private:
              T_scalar M2_theta;

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

