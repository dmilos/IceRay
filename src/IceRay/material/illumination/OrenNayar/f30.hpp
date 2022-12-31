#ifndef Dh_IceRay_material_illumination_OrenNayar_f30_hpp_
 #define Dh_IceRay_material_illumination_OrenNayar_f30_hpp_

// GS_DDMRM::S_IceRay::S_material::S_illumination::S_OrenNayar::GC_f30

 #include "IceRay/type/basic/scalar.hpp"
 #include "IceRay/type/color.hpp"
 #include "IceRay/type/math/coord.hpp"


 namespace  GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_illumination
        {
         namespace S_OrenNayar
          {

           class GC_f30
          //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;



             public:
               GC_f30( T_color const& P_rho, T_color const& P_sigma )
                {
                 M2_a[0] = Fs_a( P_rho[0], P_sigma[0] ); M2_b[0] = Fs_b( P_rho[0], P_sigma[0] );
                 M2_a[1] = Fs_a( P_rho[1], P_sigma[1] ); M2_b[1] = Fs_b( P_rho[1], P_sigma[1] );
                 M2_a[2] = Fs_a( P_rho[2], P_sigma[2] ); M2_b[2] = Fs_b( P_rho[2], P_sigma[2] );
                }

             public:
               bool F_process
                (
                  T_color      &  P_result
                 ,T_color const&  P_energy
                 ,T_coord const&  P_normal
                 ,T_coord const&  P_2light
                 ,T_coord const&  P_2viewer
                )
                 { // Tested with success
                  T_scalar I_cos_thetaI = ::math::linear::vector::dot( P_normal, P_2light  );
                  T_scalar I_cos_thetaR = ::math::linear::vector::dot( P_normal, P_2viewer );

                  T_scalar I_thetaI = acos( I_cos_thetaI );
                  T_scalar I_thetaR = acos( I_cos_thetaR );

                  T_scalar I_alpha = std::max( I_thetaI, I_thetaR );
                  T_scalar I_beta  = std::min( I_thetaI, I_thetaR );

                  T_coord I_vp;        ::math::linear::vector::project( I_vp, P_2viewer, P_normal ); ::math::linear::vector::length( I_vp, T_scalar(1) );
                  T_coord I_lp;        ::math::linear::vector::project( I_lp, P_2light,  P_normal ); ::math::linear::vector::length( I_lp, T_scalar(1) );
                  T_scalar I_cos_phi = ::math::linear::vector::dot( I_lp, I_vp ); if( I_cos_phi < 0 ){ I_cos_phi = 0; }

                  T_scalar const& I_Ca = I_cos_thetaI;
                  T_scalar I_Cb = I_cos_thetaI * I_cos_phi * sin(I_alpha) * tan(I_beta);
                  P_result.set( 0, P_energy[0] * ( I_Ca * M2_a[0] + I_Cb * M2_b[0] ) );
                  P_result.set( 1, P_energy[1] * ( I_Ca * M2_a[1] + I_Cb * M2_b[1] ) );
                  P_result.set( 2, P_energy[2] * ( I_Ca * M2_a[2] + I_Cb * M2_b[2] ) );

                  return true;
                 }

             private:
               T_color M2_a;
               T_color M2_b;

             public:
              static T_scalar Fs_A( T_scalar const& P_sigma )
               {
                T_scalar Ir_result; 
                Ir_result = T_scalar(1) - T_scalar( 0.5 ) * P_sigma*P_sigma/( P_sigma*P_sigma + 0.33 );
                return Ir_result;
               }
              static T_scalar Fs_B( T_scalar const& P_sigma )
               {
                T_scalar Ir_result; 
                Ir_result = T_scalar(0.45) * P_sigma*P_sigma/( P_sigma*P_sigma + 0.09 );
                return Ir_result;
               }

              static T_scalar Fs_a( T_scalar const& P_rho, T_scalar const& P_sigma )
               {
                return Fs_A(P_sigma) * P_rho / ::math::constants::PHI;
               }
              static T_scalar Fs_b( T_scalar const& P_rho, T_scalar const& P_sigma )
               {
                 return Fs_B(P_sigma) * P_rho / ::math::constants::PHI;
               }
            };

          }
        }
      }
    }
  }

#endif
