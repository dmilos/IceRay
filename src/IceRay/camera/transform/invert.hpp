#ifndef _DDMRM_IceRAY_camera_transform_invert_HPP_
 #define _DDMRM_IceRAY_camera_transform_invert_HPP_

  #include "../_parent.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_transform
         {

          class GC_invert
           : public GS_DDMRM::S_IceRay::S_camera::GC__parent
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_camera::GC__pure T__pure;
              typedef GS_DDMRM::S_IceRay::S_camera::GC__parent T__parent;

            public:
                       GC_invert();
                       GC_invert( T__pure * P_child );
              virtual ~GC_invert();

            public:
              T_size Fv_beam( T_beam &P_beam, T_coord2D const& P_uv )const;
            public:
              void   Fv_system( T_affine &P_matrix, T_coord2D const& P_uv )const;
           };

         }
       }
     }
   }

#endif
