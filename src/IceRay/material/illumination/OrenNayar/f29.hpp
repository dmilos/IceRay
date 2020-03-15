#ifndef Dh_IceRay_material_illumination_OrenNayar_29_hpp_
 #define Dh_IceRay_material_illumination_OrenNayar_29_hpp_

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

           class GC_f29
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             private:
                typedef std::array< T_color, 4 > T_precalc;
             public:
               GC_f29( T_color const& P_rho, T_color const& P_sigma )
                {
                 static T_scalar Is_phi= ::math::constants::PHI;
                 M2_C1.set(0, P_rho[0]/Is_phi*( 1-0.5 * P_sigma[0]*P_sigma[0]/( P_sigma[0]*P_sigma[0] +0.33 ) ) );
                 M2_C1.set(1, P_rho[1]/Is_phi*( 1-0.5 * P_sigma[1]*P_sigma[1]/( P_sigma[1]*P_sigma[1] +0.33 ) ) );
                 M2_C1.set(2, P_rho[2]/Is_phi*( 1-0.5 * P_sigma[2]*P_sigma[2]/( P_sigma[2]*P_sigma[2] +0.33 ) ) );

                 M2_C2.set(0, P_rho[0]/Is_phi*(0.45  * P_sigma[0]*P_sigma[0]/( P_sigma[0]*P_sigma[0] +0.09 ) ) );
                 M2_C2.set(1, P_rho[1]/Is_phi*(0.45  * P_sigma[1]*P_sigma[1]/( P_sigma[1]*P_sigma[1] +0.09 ) ) );
                 M2_C2.set(2, P_rho[2]/Is_phi*(0.45  * P_sigma[2]*P_sigma[2]/( P_sigma[2]*P_sigma[2] +0.09 ) ) );

                 M2_C3.set( 0, P_rho[0]/Is_phi*( 0.125 * P_sigma[0]*P_sigma[0]/( P_sigma[0]*P_sigma[0] +0.09 ) ) * 16 * pow(Is_phi, -4 ) );
                 M2_C3.set( 1, P_rho[1]/Is_phi*( 0.125 * P_sigma[1]*P_sigma[1]/( P_sigma[1]*P_sigma[1] +0.09 ) ) * 16 * pow(Is_phi, -4 ) );
                 M2_C3.set( 2, P_rho[2]/Is_phi*( 0.125 * P_sigma[2]*P_sigma[2]/( P_sigma[2]*P_sigma[2] +0.09 ) ) * 16 * pow(Is_phi, -4 ) );

                 M2_C4.set(0, (P_rho[0]*P_rho[0] /Is_phi) *0.17*P_sigma[0]*P_sigma[0]/( P_sigma[0]*P_sigma[0] + 0.13 ) );
                 M2_C4.set(1, (P_rho[1]*P_rho[1] /Is_phi) *0.17*P_sigma[1]*P_sigma[1]/( P_sigma[1]*P_sigma[1] + 0.13 ) );
                 M2_C4.set(2, (P_rho[2]*P_rho[2] /Is_phi) *0.17*P_sigma[2]*P_sigma[2]/( P_sigma[2]*P_sigma[2] + 0.13 ) );
                }

             public:
               bool F_process
                (
                 T_color      &  P_result,
                 T_color const&  P_light,
                 T_coord const&  P_normal,
                 T_coord const&  P_2light,
                 T_coord const&  P_viewer
                 )
                 {
                  static T_scalar Is_phi= ::math::constants::PHI;
                  T_scalar I_nl = ::math::linear::vector::dot( P_normal, P_2light );
                  T_scalar I_nv = ::math::linear::vector::dot( P_normal, P_viewer );

                  T_scalar I_angleVN = acos(I_nv);
                  T_scalar I_angleLN = acos(I_nl);

                  T_scalar I_alpha = std::max( I_angleVN, I_angleLN );
                  T_scalar I_beta  = std::min( I_angleVN, I_angleLN );

                  T_coord I_vp; ::math::linear::vector::project( I_vp, P_viewer, P_normal ); ::math::linear::vector::length( I_vp, T_scalar(1) );
                  T_coord I_lp; ::math::linear::vector::project( I_lp, P_2light, P_normal ); ::math::linear::vector::length( I_lp, T_scalar(1) );

                  T_scalar I_cos_phi = ::math::linear::vector::dot( I_lp, I_vp );
                  T_scalar I_c2 = I_cos_phi * tan( I_beta );
                  if( 0 < I_cos_phi )
                   {
                    I_c2 *= sin( I_alpha );
                   }
                  else
                   {
                    I_c2 *= sin(I_alpha ) - pow( 2*I_beta/Is_phi, 3 );
                   }
                  T_scalar I_c3 = ( 1- fabs( I_cos_phi )) * tan( (I_alpha + I_beta)/2 ) * pow( I_alpha * I_beta, 2 ) ;

                  P_result.set( 0, P_light[0] * I_nl * ( M2_C1[0] + M2_C2[0] * I_c2 + M2_C3[0] *I_c3 ) );
                  P_result.set( 1, P_light[1] * I_nl * ( M2_C1[1] + M2_C2[1] * I_c2 + M2_C3[1] *I_c3 ) );
                  P_result.set( 2, P_light[2] * I_nl * ( M2_C1[2] + M2_C2[2] * I_c2 + M2_C3[2] *I_c3 ) );

                  T_scalar I_cL2 = I_nl * ( 1-  I_cos_phi * pow( 2*I_beta/Is_phi,2) );

                  P_result.set( 0, P_result[0] + P_light[0] * M2_C4[0] * I_cL2 );
                  P_result.set( 1, P_result[1] + P_light[1] * M2_C4[1] * I_cL2 );
                  P_result.set( 2, P_result[2] + P_light[2] * M2_C4[2] * I_cL2 );

                  return true;
                 }

             private:
               T_color M2_C1;
               T_color M2_C2;
               T_color M2_C3;
               T_color M2_C4;

               static void Fs_Cs( T_precalc &P_precalc, T_color const& P_rho, T_color const& P_sigma )
                {
                 static T_scalar Is_phi= ::math::constants::PHI;
                 auto & M2_C1 = P_precalc[0];
                 auto & M2_C2 = P_precalc[0];
                 auto & M2_C3 = P_precalc[0];
                 auto & M2_C4 = P_precalc[0];

                 M2_C1.set(0, P_rho[0]/Is_phi*( 1-0.5 * P_sigma[0]*P_sigma[0]/( P_sigma[0]*P_sigma[0] +0.33 ) ) );
                 M2_C1.set(1, P_rho[1]/Is_phi*( 1-0.5 * P_sigma[1]*P_sigma[1]/( P_sigma[1]*P_sigma[1] +0.33 ) ) );
                 M2_C1.set(2, P_rho[2]/Is_phi*( 1-0.5 * P_sigma[2]*P_sigma[2]/( P_sigma[2]*P_sigma[2] +0.33 ) ) );

                 M2_C2.set(0, P_rho[0]/Is_phi*(0.45  * P_sigma[0]*P_sigma[0]/( P_sigma[0]*P_sigma[0] +0.09 ) ) );
                 M2_C2.set(1, P_rho[1]/Is_phi*(0.45  * P_sigma[1]*P_sigma[1]/( P_sigma[1]*P_sigma[1] +0.09 ) ) );
                 M2_C2.set(2, P_rho[2]/Is_phi*(0.45  * P_sigma[2]*P_sigma[2]/( P_sigma[2]*P_sigma[2] +0.09 ) ) );

                 M2_C3.set( 0, P_rho[0]/Is_phi*( 0.125 * P_sigma[0]*P_sigma[0]/( P_sigma[0]*P_sigma[0] +0.09 ) ) * 16 * pow(Is_phi, -4 ) );
                 M2_C3.set( 1, P_rho[1]/Is_phi*( 0.125 * P_sigma[1]*P_sigma[1]/( P_sigma[1]*P_sigma[1] +0.09 ) ) * 16 * pow(Is_phi, -4 ) );
                 M2_C3.set( 2, P_rho[2]/Is_phi*( 0.125 * P_sigma[2]*P_sigma[2]/( P_sigma[2]*P_sigma[2] +0.09 ) ) * 16 * pow(Is_phi, -4 ) );

                 M2_C4.set(0, (P_rho[0]*P_rho[0] /Is_phi) *0.17*P_sigma[0]*P_sigma[0]/( P_sigma[0]*P_sigma[0] + 0.13 ) );
                 M2_C4.set(1, (P_rho[1]*P_rho[1] /Is_phi) *0.17*P_sigma[1]*P_sigma[1]/( P_sigma[1]*P_sigma[1] + 0.13 ) );
                 M2_C4.set(2, (P_rho[2]*P_rho[2] /Is_phi) *0.17*P_sigma[2]*P_sigma[2]/( P_sigma[2]*P_sigma[2] + 0.13 ) );
                }
            };
          }
        }
      }
    }
  }

#endif
