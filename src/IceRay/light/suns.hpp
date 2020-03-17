#ifndef Dh_DDMM_IceRay_light_suns_HPP_
 #define Dh_DDMM_IceRay_light_suns_HPP_

 #include "./_pure.hpp"




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_suns
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
           GC_suns( T_spot const& P_spot = T_spot() );

         public:
           T_size  Fv_swarm( T_swarm &P_swarm,  T_coord const& P_point )const;

         public:  // property spot  spot
             T_spot  const& F_spot()const{ return M2_spot; }
           bool             F_spot( T_spot const& P_spot ){ M2_spot = P_spot; return bool( true ); }
         protected:
        //T__pure        & F1_spot(){ return M2_spot; }
         private:
           T_spot M2_spot;

         public:
           T_coord  const& F_center()const{ return M2_spot.F_center(); }
           bool             F_center( T_coord const& P_center ){ M2_spot.F_center( P_center ); return bool( true ); }

        };

      }
    }
  }

#endif

