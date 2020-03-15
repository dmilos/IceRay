#ifndef _DDMRM_IceRAY_camera_flat_perspective_HPP_
 #define _DDMRM_IceRAY_camera_flat_perspective_HPP_
 //  GS_DDMRM::S_IceRay::S_camera::S_flat::GC_perspective
  #include "../_pure.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_flat
         {

          class GC_perspective
           : public GS_DDMRM::S_IceRay::S_camera::GC__pure
           {
            public:
              GC_perspective();
              explicit GC_perspective( T_scalar const& P_aspect );
                       GC_perspective( T_scalar const& P_width, T_scalar const& P_height );

             ~GC_perspective( );

            public:
              T_size Fv_beam( T_beam &, T_coord2D const& P_uv )const;
            protected:
              void   Fv_system( T_affine &, T_coord2D const& P_uv )const;

            public:
              T_scalar    const& F_width()const{ return M2_width; }
              bool               F_width( T_scalar const& P_width );
            protected:
              T_scalar        & F1_width(){ return M2_width; }
            private:
              T_scalar M2_width;

            public:
              T_scalar    const& F_height()const{ return M2_height; }
              bool               F_height( T_scalar const& P_height );
            protected:
              T_scalar        & F1_height(){ return M2_height; }
            private:
              T_scalar M2_height;

            public:  // width : height = 1 : M2_aspect
              T_scalar  const& F_aspect()const{ return M2_aspect; }
              bool             F_aspect( T_scalar const& P_aspect );
            protected:
              T_scalar      & F1_aspect(){ return M2_aspect; }
            private:
              T_scalar M2_aspect;
           };

         }
       }
     }
   }

#endif

