#ifndef _DDMRM_IceRAY_camera_transfrom_affine_HPP_
 #define _DDMRM_IceRAY_camera_transfrom_affine_HPP_

  #include "./_parent.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_transform
         {

          class GC_affine
           : public GS_DDMRM::S_IceRay::S_camera::GC__parent
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_camera::GC__pure T__pure;
              typedef GS_DDMRM::S_IceRay::S_camera::GC__parent T__parent;

                       GC_affine();
                       GC_affine( T__pure * P_child );
              virtual ~GC_affine();

            public:
              T_size Fv_beam( T_beam &P_beam, T_coord2D const& P_uv )const;
            public:
              void   Fv_system( T_affine &P_matrix, T_coord2D const& P_uv )const;

            public:
              T_affine const& F_2world()const{ return M2_2world; }
              bool            F_2world( T_affine const& );
            protected:
              T_affine      & F1_2world(){ return M2_2world; }
            private:
              T_affine M2_2world;

            public:
              T_affine const& F_2local()const{ return M2_2local; }
              bool            F_2local( T_affine const& );
            protected:
              T_affine & F1_2local(){ return M2_2local; }
            private:
              T_affine  M2_2local;
            private:
               T_matrix3D M2_transponate;
           };

         }
       }
     }
   }

#endif

