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


           private:
             T_scalar const& M2_air;
             T_scalar const& M2_watter;
          };

        }
      }
    }
  }

#endif
