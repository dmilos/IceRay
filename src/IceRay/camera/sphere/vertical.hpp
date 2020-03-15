#ifndef _DDMRM_IceRAY_camera_sphere_vertical_HPP_
 #define _DDMRM_IceRAY_camera_sphere_vertical_HPP_

 // GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_vertical

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

          class GC_vertical
           : public GS_DDMRM::S_IceRay::S_camera::GC__pure
           {
            public:
              GC_vertical();
              explicit GC_vertical( T_scalar const& P_theta, T_scalar const& P_phi, T_scalar const& P_radius = 1 );
             ~GC_vertical();

            public:
              T_size Fv_beam( T_beam &, T_coord2D const& P_uv )const;
            protected:
              void   Fv_system( T_affine &, T_coord2D const& P_uv )const;

            public:  // property scalar  theta
              T_scalar  const& F_theta()const{ return M2_theta; }
              bool             F_theta( T_scalar const& P_theta ){ M2_theta = P_theta; return bool( true ); }
            protected:
              T_scalar        & F1_theta(){ return M2_theta; }
            private:
              T_scalar M2_theta;

            public:  // property scalar  phi
              T_scalar    const& F_phi()const{ return M2_phi; }
              bool               F_phi( T_scalar const& P_phi ){ M2_phi = P_phi; return ( true ); }
            protected:
              T_scalar        & F1_phi(){ return M2_phi; }
            private:
              T_scalar M2_phi;

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

