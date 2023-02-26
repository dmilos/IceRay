#ifndef Dh_DDMM_IceRay_light_spline_H_
 #define Dh_DDMM_IceRay_light_spline_H_

#include "./_pure.hpp"
#include "IceRay/utility/random.hpp"




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_spline
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
           GC_spline( );
           GC_spline( T_spot const& P_spot, T_coord const P_cp[3], T_size const& P_sample = 1 );
          ~GC_spline();

         public:
          T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         public:  // property spot  spot
           T_spot    const& F_spot()const{ return M2_spot; }
           bool             F_spot( T_spot const& P_spot );
         protected:
           T_spot        & F1_spot(){ return M2_spot; }
         private:
           T_spot M2_spot;

         public:
           T_coord const& F_cp( T_size const& P_index )const;
           bool           F_cp( T_size const& P_index, T_coord const& P_value );

         public:  // property size sample
           T_size    const& F_sample()const{ return M2_sample; }
           bool             F_sample( T_size const& P_sample );
         protected:
           //T_size        & F1_sample(){ return M2_sample; }
         private:
           T_size M2_sample;

         private:
           std::array<T_coord,4>  M2_cp;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_gold1D        M2_randGold1D;
         //mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol1D       M2_randSobol1D;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_vdc2          M2_randVDC;
         //mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard1D    M2_randStandard1D;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_congruent1D   M2_randCongruent1D;
        };

      }
    }
  }

#endif
