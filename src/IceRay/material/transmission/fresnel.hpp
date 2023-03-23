#ifndef Dh_IceRay_material_illumination_fresnel_hpp_
 #define Dh_IceRay_material_illumination_fresnel_hpp_

// GS_DDMRM::S_IceRay::S_material::S_transmission::GC_fresnel

 #include "../../type/basic/scalar.hpp"
 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"

 namespace  GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_transmission
        {

         class GC_fresnel
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                     T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar            T_coord;

             GC_fresnel( T_scalar const& P_air, T_scalar const& P_watter )
              :M2_air( P_air )
              ,M2_watter( P_watter )
              {

              }
           public:
             bool F_reflectance
              (
               T_scalar     &  P_s,
               T_scalar     &  P_r,
               T_coord const&  P_reflected,
               T_coord const&  P_refracted,
               T_coord const&  P_normal
               )
              {
               T_scalar I_Z0 = 1;
               T_scalar I_Z1 = I_Z0 / M2_air;
               T_scalar I_Z2 = I_Z0 / M2_watter;

               T_scalar I_cosTi = fabs( ::math::linear::vector::dot( P_reflected, P_normal ) );
               T_scalar I_cosTt = fabs( ::math::linear::vector::dot( P_refracted, P_normal ) );

               P_s = ( I_Z2 * I_cosTi - I_Z1 * I_cosTt ) / (I_Z2 * I_cosTi + I_Z1 * I_cosTt); P_s *= P_s;
               P_r = ( I_Z2 * I_cosTt - I_Z1 * I_cosTi ) / (I_Z2 * I_cosTt + I_Z1 * I_cosTi); P_r *= P_r;

               return true;
              }

             bool F_process
              (
               T_scalar     &  P_reflectance,
               T_scalar     &  P_transmittance,
               T_coord const&  P_reflected,
               T_coord const&  P_refracted,
               T_coord const&  P_normal
               )
              {
               T_scalar I_Rs;
               T_scalar I_Rp;

               F_reflectance( I_Rs, I_Rp, P_reflected, P_refracted, P_normal );

               P_reflectance = (I_Rs + I_Rp )/ T_scalar( 2 );

               T_scalar I_Ts = T_scalar(1) - I_Rs;
               T_scalar I_Tp = T_scalar(1) - I_Rp;
               P_transmittance = (I_Ts + I_Tp )/ T_scalar( 2 );

               return true;
              }

             bool F_reflectance
              (
               T_scalar      &  P_reflectance,
               T_scalar const&  P_cosI,
               T_scalar const&  P_cosT
               )
              {
               auto I_n0 = M2_air    * P_cosI - M2_watter * P_cosT;
               auto I_n1 = M2_air    * P_cosI + M2_watter * P_cosT;
               auto I_p0 = M2_watter * P_cosI - M2_air    * P_cosT;
               auto I_p1 = M2_watter * P_cosI + M2_air    * P_cosT;

               P_reflectance = fabs(I_n0/I_n1 + I_p0/I_p1 )/T_scalar(2);

               return true;
              }

             bool F_transmittance
              (
               T_scalar      &  P_transmittance,
               T_scalar const&  P_cosI,
               T_scalar const&  P_cosT
              )
              {
               auto I_0 =  M2_air * P_cosI;
               auto I_n1 = M2_air    * P_cosI + M2_watter * P_cosT;
               auto I_p1 = M2_watter * P_cosI + M2_air    * P_cosT;

               P_transmittance = I_0/I_n1 + I_0/I_p1 ;

               return true;
              }

             bool F_processKajiya
              (
               T_scalar     &  P_reflectance,
               T_scalar     &  P_transmittance,
               T_coord const&  P_reflected,
               T_coord const&  P_refracted,
               T_coord const&  P_normal
               )
              {
               T_scalar I_thetaI = fabs( ::math::linear::vector::dot( P_normal, P_reflected ) );
               T_scalar I_thetaT = fabs( ::math::linear::vector::dot( P_normal, P_refracted ) );

               //F_reflectance(   P_reflectance,   I_thetaI, I_thetaT );
               //F_transmittance( P_transmittance, I_thetaI, I_thetaT );
               //auto I_summae = P_reflectance + P_transmittance;
               //return true;

               T_scalar I_R_a =  fabs( I_thetaI*I_thetaI - I_thetaT*I_thetaT );
               T_scalar I_R_2 =  ( M2_air*M2_air + M2_watter*M2_watter ) / ( M2_air * M2_watter );
               T_scalar I_R_b =  I_thetaI*I_thetaI + I_thetaT*I_thetaT  + I_R_2 * I_thetaI*I_thetaT;
               P_reflectance = I_R_a / I_R_b;

               T_scalar I_T_a = M2_air *I_thetaI * ( M2_air + M2_watter ) *( I_thetaI + I_thetaT );
               T_scalar I_T_b_1 = I_thetaI * I_thetaT * ( M2_air*M2_air + M2_watter*M2_watter );
               T_scalar I_T_b_2 = M2_air * M2_watter * ( I_thetaI*I_thetaI + I_thetaT*I_thetaT );
               P_transmittance = I_T_a / ( I_T_b_1 + I_T_b_2 );

               //I_summae = P_reflectance + P_transmittance;
               return true;
              }

           private:
             T_scalar const& M2_air;
             T_scalar const& M2_watter;
          };

        }
      }
    }
  }

#endif
