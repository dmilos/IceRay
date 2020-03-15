#ifndef Dh_DDMM_IceRay_light_sun_HPP_
 #define Dh_DDMM_IceRay_light_sun_HPP_

 #include "./_pure.hpp"




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_sun
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:

           GC_sun( );
           GC_sun( T__pure *P_light );

         public:
           T_size  Fv_swarm( T_swarm &P_swarm,  T_coord const& P_point )const;

         public:  // property child  child
           //T__pure    const& F_child()const{ return M2_child; }
           bool             F_child( T__pure * P_child ){ M2_child = P_child; return bool( true ); }
         protected:
        //T__pure        & F1_child(){ return M2_child; }
         private:
           T__pure * M2_child;

         //public:
         //   bool           F_from( T_coord const& P_from ){ M2_spot.F_center(P_from); return true; }
         //   T_coord const& F_from( )const { return M2_spot.F_center(); }

         private:
          
          static T__pure* Fs_point();
        };

      }
    }
  }

#endif

