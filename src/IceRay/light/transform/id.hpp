#ifndef Dh_DDMM_IceRay_light_transform_id
 #define Dh_DDMM_IceRay_light_transform_id

 // GS_DDMRM::S_IceRay::S_light::S_transform::GC_identity

 #include "../_parent.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {
       namespace S_transform
        {

         class GC_identity
          : public GS_DDMRM::S_IceRay::S_light::GC__parent
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_light::GC__pure  T_pure;

           public:
                      GC_identity( );
             explicit GC_identity( T_pure * P_child );
                     ~GC_identity();

           public:
             T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

          };

        }
       }
     }
   }

#endif
