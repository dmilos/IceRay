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
             explicit GC_translate( T_pure * P_child, T_coord const& P_move = T_coord{0} );
                     ~GC_translate();

           public:
             T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

           public:
             T_coord    const& F_move()const{ return M2_move; }
             bool              F_move( T_coord const& P_move ){ M2_move = P_move; return bool( true ); }
           protected:
             T_coord        & F1_move(){ return M2_move; }
           private:
             T_coord M2_move;
         };

        }
       }
     }
   }

#endif
