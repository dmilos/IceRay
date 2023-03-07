#ifndef Dh_DDMM_IceRay_LIGHT_line_HPP__nDIM_Ready
 #define Dh_DDMM_IceRay_LIGHT_line_HPP__nDIM_Ready


#include "./_pure.hpp"
#include "IceRay/utility/random.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_line
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
           GC_line();
           GC_line( T_spot const&  P_spot, T_coord const& P_end, T_size const& P_sample = 1 );
          ~GC_line();

          T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         public:  // property spot  spot
           T_spot    const& F_spot()const{ return M2_spot; }
           bool             F_spot( T_spot const& P_spot );
         protected:
           T_spot        & F1_spot(){ return M2_spot; }
         private:
           T_spot M2_spot;

         public:  // property coord  end
           T_coord    const& F_start()const{ return M2_spot.F_center(); }
           bool              F_start( T_coord const& P_start ){ return M2_spot.F_center( P_start ) ; }

         public:  // property coord  end
           T_coord    const& F_end()const{ return M2_end; }
           bool              F_end( T_coord const& P_end ){ M2_end = P_end; return bool( true ); }
         protected:
           T_coord        & F1_end(){ return M2_end; }
         private:
           T_coord M2_end;

         public:  // property size  sample
           T_size    const& F_sample()const{ return M2_sample; }
           bool             F_sample( T_size const& P_sample );
         protected:
           //T_size        & F1_sample(){ return M2_sample; }
         private:
           T_size M2_sample;

         private:
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_gold1D        M2_randGold1D;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol1D       M2_randSobol1D;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_vdc2          M2_randVDC;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard1D    M2_randStandard1D;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_table1D       M2_randTable1D;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_congruent1D   M2_congurent1D;
       };

      }
    }
  }


#endif

