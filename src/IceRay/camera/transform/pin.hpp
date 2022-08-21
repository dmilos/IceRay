#ifndef _DDMRM_IceRAY_camera_transform_pin_HPP_
 #define _DDMRM_IceRAY_camera_transform_pin_HPP_

  #include "../_parent.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {
        namespace S_transform
         {

          class GC_pin
           : public GS_DDMRM::S_IceRay::S_camera::GC__parent
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_camera::GC__pure T__pure;
              typedef GS_DDMRM::S_IceRay::S_camera::GC__parent T__parent;

            public:
                       GC_pin();
                       GC_pin( T__pure * P_child );
                       GC_pin( T__pure * P_child, T_coord const& P_origin );
              virtual ~GC_pin();

            public:
              T_size Fv_beam( T_beam &P_beam, T_coord2D const& P_uv )const;
            public:
              void   Fv_system( T_affine &P_matrix, T_coord2D const& P_uv )const;

            public:
              T_coord const& F_origin()const;
              bool           F_origin( T_coord const& P_origin );
            protected:
              T_coord      & F1_origin();
            private:
              T_coord M2_origin;
           };

         }
       }
     }
   }

#endif
