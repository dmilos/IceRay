#ifndef Dh_DDMM_IceRay_light_transform_translate
 #define Dh_DDMM_IceRay_light_transform_translate

 // GS_DDMRM::S_IceRay::S_light::S_transform::GC_translate

 #include "../_parent.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {
       namespace S_transform
        {

         class GC_translate
          : public GS_DDMRM::S_IceRay::S_light::GC__parent
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_light::GC__pure  T_pure;

           public:
                      GC_translate( );
             explicit GC_translate( T_pure * P_child, T_coord const& P_2world = T_coord{0} );
                     ~GC_translate();

           public:
             T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

           public:
             T_coord    const& F_2local()const{ return M2_2local; }
             bool              F_2local( T_coord const& P_2local );
           protected:
             T_coord        & F1_2local(){ return M2_2local; }
           private:
             T_coord M2_2local;

           public:
             T_coord    const& F_2world()const{ return M2_2world; }
             bool              F_2world( T_coord const& P_2world );
           protected:
             T_coord        & F1_2world(){ return M2_2world; }
           private:
             T_coord M2_2world;
         };

         }
       }
     }
   }

#endif
