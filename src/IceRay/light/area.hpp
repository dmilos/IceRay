#ifndef Dh_DDMM_IceRay_LIGHT_area_H_
 #define Dh_DDMM_IceRay_LIGHT_area_H_

 #include "./_pure.hpp"
#include "IceRay/utility/random.hpp"




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_area
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:

           GC_area( );
           GC_area( T_spot const&  P_spot, T_coord const&  P_x, T_coord const&  P_y, T_size const& P_sample = 1 );

           T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

         public:  // property size  sample
           T_size    const& F_sample()const{ return M2_sample; }
           bool             F_sample( T_size const& P_sample );
         protected:
         //T_size         & F1_sample(){ return M2_sample; }
         private:
           T_size M2_sample;

         public:  // property spot  spot
           T_spot    const& F_spot()const{ return M2_spot; }
           bool             F_spot( T_spot const& P_spot );
         protected:
           T_spot        & F1_spot(){ return M2_spot; }
         private:
           T_spot M2_spot;

         public:  // property coord  origin
           T_coord   const& F_origin()const{ return M2_spot.F_center(); }
           bool             F_origin( T_coord const& P_position ){ return M2_spot.F_center( P_position ); }

         public:  // property coord  x
           T_coord    const& F_x()const{ return M2_x; }
           bool              F_x( T_coord const& P_x ){ M2_x = P_x; return bool( true ); }
         protected:
           T_coord        & F1_x(){ return M2_x; }
         private:
           T_coord M2_x;

         public:  // property coord  y
           T_coord    const& F_y()const{ return M2_y; }
           bool              F_y( T_coord const& P_y ){ M2_y = P_y; return bool( true ); }
         protected:
           T_coord        & F1_y(){ return M2_y; }
         private:
           T_coord M2_y;
         private: 
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol2D       M2_randSobol2D;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard2D    M2_randStandard2D;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_VaLND         M2_randVaLND;
           mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_congruent2D   M2_randCongruent2D;
       };

      }
    }
  }

#endif

