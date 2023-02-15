#ifndef Dh_DDMM_IceRay_light_transform_homography
 #define Dh_DDMM_IceRay_light_transform_homography

 // GS_DDMRM::S_IceRay::S_light::S_transform::GC_homography

 #include "../_parent.hpp"
 #include "IceRay/type/math/homography.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {
       namespace S_transform
        {

         class GC_homography
          : public GS_DDMRM::S_IceRay::S_light::GC__parent
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_light::GC__pure  T_pure;
             typedef GS_DDMRM::S_IceRay::S_type::S_homography::GT_homography    T_homography;

           public:
                      GC_homography( );
             explicit GC_homography( T_pure * P_child );
                      GC_homography( T_pure * P_child, T_homography const& P_2world );
                     ~GC_homography();

           public:
             T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

           public:
             T_homography   const& F_2world()const{ return M2_2world; }
             bool                  F_2world( T_homography const& P_2world );
           protected:
             T_homography        & F1_2world(){ return M2_2world; }
           private:
             T_homography M2_2world;

           public:
             T_homography   const& F_2local()const{ return M2_2local; }
             bool                  F_2local( T_homography const& P_2local );
           protected:
             T_homography        & F1_2local(){ return M2_2local; }
           private:
             T_homography  M2_2local;
          };

        }
       }
     }
   }

#endif
