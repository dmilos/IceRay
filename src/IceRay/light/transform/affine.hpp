#ifndef Dh_DDMM_IceRay_light_transform_affine
 #define Dh_DDMM_IceRay_light_transform_affine

 // GS_DDMRM::S_IceRay::S_light::S_transform::GC_affine

 #include "../_parent.hpp"
 #include "IceRay/type/math/affine.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {
       namespace S_transform
        {

         class GC_affine
          : public GS_DDMRM::S_IceRay::S_light::GC__parent
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_light::GC__pure  T_pure;
             typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_affine    T_affine;

           public:
                      GC_affine( );
             explicit GC_affine( T_pure * P_child );
                      GC_affine( T_pure * P_child, T_affine const& P_affine );
                     ~GC_affine();

           public:
             T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

           public:
             T_affine   const& F_2world()const{ return M2_2world; }
             bool              F_2world( T_affine const& P_2world );
           protected:
             T_affine        & F1_2world(){ return M2_2world; }
           private:
             T_affine M2_2world;

           public:
             T_affine   const& F_2local()const{ return M2_2local; }
             bool              F_2local( T_affine const& P_2local);
           protected:
             T_affine        & F1_2local(){ return M2_2local; }
           private:
             T_affine M2_2local;

          };

        }
       }
     }
   }

#endif
