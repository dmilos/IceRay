#ifndef _DDMRM_IceRAY_camera_sphere_package_HPP_
 #define _DDMRM_IceRAY_camera_sphere_package_HPP_

 // GS_DDMRM::S_IceRay::S_camera::S_sphere::GC_package

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

          class GC_package
           : public GS_DDMRM::S_IceRay::S_camera::GC__pure
           {
            public:
              GC_package();
              explicit GC_package( T_scalar const& P_hfov, T_scalar const& P_vfov );
             ~GC_package();

            public:
              T_size Fv_beam( T_beam &, T_coord2D const& P_uv )const;
            protected:
              void   Fv_system( T_affine &, T_coord2D const& P_uv )const;

            public:  // property scalar  horizontal field of view
              T_scalar  const& F_horizontal()const{ return M2_horizontal; }
              bool             F_horizontal( T_scalar const& P_horizontal ){ M2_horizontal = P_horizontal; return bool( true ); }
            protected:
              T_scalar        & F1_horizontal(){ return M2_horizontal; }
            private:
              T_scalar M2_horizontal;

            public:  // property scalar  vertical field of view
              T_scalar    const& F_vertical()const{ return M2_vertical; }
              bool               F_vertical( T_scalar const& P_vertical ){ M2_vertical = P_vertical; return ( true ); }
            protected:
              T_scalar        & F1_vertical(){ return M2_vertical; }
            private:
              T_scalar M2_vertical;

           };

         }
       }
     }
   }

#endif

