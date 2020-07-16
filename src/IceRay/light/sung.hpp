#ifndef Dh_DDMM_IceRay_light_sung_HPP_
 #define Dh_DDMM_IceRay_light_sung_HPP_

 #include "./_pure.hpp"




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_sung
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:

           GC_sung( );
           GC_sung( T__pure *P_child );

         public:
           T_size  Fv_swarm( T_swarm &P_swarm,  T_coord const& P_point )const;

         public:  // property child  child
           T__pure    const& F_child()const{ return *M2_child; }
           bool             F_child( T__pure * P_child );
         protected:
        //T__pure        & F1_child(){ return M2_child; }
         private:
           T__pure * M2_child;

         private:
          static T__pure & Fs_point();
        };

      }
    }
  }

#endif

