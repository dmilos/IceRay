#ifndef _DDMRM_IceRAY_camera_flat_super_HPP_
 #define _DDMRM_IceRAY_camera_flat_super_HPP_
 //  GS_DDMRM::S_IceRay::S_camera::S_flat::GC_super
  #include "../_pure.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_flat
         {

          class GC_super
           : public GS_DDMRM::S_IceRay::S_camera::GC__pure
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D    T_coord2D;

              GC_super( );
              GC_super( T_coord2D const& P_eye, T_coord2D const& P_view );
              GC_super( T_coord2D const& P_eye, T_coord2D const& P_view, T_coord2D const& P_focus );

             ~GC_super( );

            public:
              T_size Fv_beam( T_beam &, T_coord2D const& P_uv )const;
            protected:
              void   Fv_system( T_affine &, T_coord2D const& P_uv )const;

            public:
              T_coord2D    const& F_eye()const{ return M2_eye1; }
              bool                F_eye( T_coord2D const& P_eye );
            protected:
              T_coord2D        & F1_eye(){ return M2_eye1; }
            private:
              T_coord2D M2_eye1, M2_eye2;

            public:  // eye :
              T_coord2D  const& F_view()const{ return M2_view1; }
              bool              F_view( T_coord2D const& P_view );
            protected:
              T_coord2D      & F1_view(){ return M2_view1; }
            private:
              T_coord2D M2_view1, M2_view2;

            public:  // focus :
              T_coord2D  const& F_focus()const{ return M2_focus; }
              bool              F_focus( T_coord2D const& P_focus );
            protected:
              T_coord2D      & F1_focus(){ return M2_focus; }
            private:
              T_coord2D M2_focus;
          };

         }
       }
     }
   }

#endif

