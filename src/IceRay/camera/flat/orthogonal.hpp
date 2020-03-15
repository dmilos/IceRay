#ifndef _DDMRM_IceRAY_camera_orthogonal_HPP_
 #define _DDMRM_IceRAY_camera_orthogonal_HPP_
 // GS_DDMRM::S_IceRay::S_camera::S_flat::GC_orthogonal
 
  #include "../_pure.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_flat
         {

          class GC_orthogonal
           : public GS_DDMRM::S_IceRay::S_camera::GC__pure
           {
            public:
                       GC_orthogonal();
              explicit GC_orthogonal( T_scalar const& P_aspect );
                       GC_orthogonal( T_scalar const& P_width, T_scalar const& P_height );

             ~GC_orthogonal();

            public:
              T_size Fv_beam( T_beam &, T_coord2D const& P_uv )const;
            protected:
              void   Fv_system( T_affine &, T_coord2D const& P_uv )const;

            public:
              T_scalar    const& F_width()const{ return M2_width1; }
              bool               F_width( T_scalar const& P_width );
            protected:
              T_scalar        & F1_width(){ return M2_width1; }
            private:
              T_scalar M2_width1,M2_width2;

            public:
              T_scalar    const& F_height()const{ return M2_height1; }
              bool               F_height( T_scalar const& P_height );
            protected:
              T_scalar        & F1_height(){ return M2_height1; }
            private:
              T_scalar M2_height1, M2_height2;

            public:  //  width : height = 1 : M2_aspect
              T_scalar    const& F_aspect()const{ return M2_aspect; }
              bool               F_aspect( T_scalar const& P_aspect );
            protected:
              T_scalar        & F1_aspect(){ return M2_aspect; }
            private:
              T_scalar M2_aspect;
           };

         }
       }
     }
   }

#endif

