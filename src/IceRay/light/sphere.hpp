#ifndef Dh_DDMM_IceRay_LIGHT_sphere_H_
 #define Dh_DDMM_IceRay_LIGHT_sphere_H_

 #include "./_pure.hpp"
 #include "./type/affine.hpp"
 #include "IceRay/utility/random.hpp"




 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC_sphere
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:

           GC_sphere( );
           GC_sphere( T_spot const& P_spot, T_scalar const& P_radius = 1, T_size const& P_sample = 1 );

         public:
           T_size  Fv_swarm( T_swarm &P_spot, T_coord const& P_point )const;

         public:  // property scalar  radius
           T_scalar const& F_radius()const{ return M2_radius; }
           bool            F_radius( T_scalar const& P_radius );
         protected:
           T_scalar        & F1_radius(){ return M2_radius; }
         private:
           T_scalar M2_radius;

         public:  // property coord  center
           T_coord    const& F_center()const{ return M2_spot.F_center(); }
           bool              F_center( T_coord const& P_center ){ M2_spot.F_center( P_center ); return true; }

         public:  // property coord  center
           T_spot    const& F_spot()const{ return M2_spot; }
           bool             F_spot( T_spot const& P_spot ){ M2_spot = P_spot; return true; }
         protected:
           T_spot        & F1_spot(){ return M2_spot; }
         private:
           T_spot M2_spot;

         public:  // property size sample
           T_size    const& F_sample()const{ return M2_sample; }
           bool             F_sample( T_size const& P_sample );
         protected:
           //T_size        & F1_sample(){ return M2_sample; }
         private:
           T_size M2_sample;

         private:
           typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_affine    T2_affine;

          private:
            mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_sobol2D       M2_randSobol2D;
            mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_standard2D    M2_randStandard2D;
            mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_VaLND         M2_randVaLND;

        };

      }
    }
  }



#endif
