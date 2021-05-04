#ifndef Dh_IceRay_material_illumination_OrenNayar_Ouwerkerk_hpp_
 #define Dh_IceRay_material_illumination_OrenNayar_Ouwerkerk_hpp_

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

           class GC_ouwerkerk
          //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_ouwerkerk( T_color const& P_rho, T_color const& P_sigma )
                {
                 static T_scalar Is_phi= ::math::constants::PHI;

                 M2_a[0] = Fs_a( P_rho[0], P_sigma[0] ); M2_b[0] = Fs_b( P_rho[0], P_sigma[0] );
                 M2_a[1] = Fs_a( P_rho[1], P_sigma[1] ); M2_b[1] = Fs_b( P_rho[1], P_sigma[1] );
                 M2_a[2] = Fs_a( P_rho[2], P_sigma[2] ); M2_b[2] = Fs_b( P_rho[2], P_sigma[2] );
                }

             public:
               bool F_process
                (
                 T_color      &  P_result,
                 T_color const&  P_energy,
                 T_coord const&  P_2light,
                 T_coord const&  P_normal,
                 T_coord const&  P_2viewer
                 )
                 {
                  T_scalar I_L = ::math::linear::vector::dot( P_normal, P_2light  ); if( I_L < 0 ) I_L = 0; // if( 1 < I_L ) I_L = 1;
                  T_scalar I_V = ::math::linear::vector::dot( P_normal, P_2viewer ); if( I_V < 0 ) I_V = 0; // if( 1 < I_V ) I_V = 1;

                  T_coord I_Pl; ::math::linear::vector::project( I_Pl, P_2light,  P_normal ); ::math::linear::vector::length( I_Pl, T_scalar(1) );
                  T_coord I_Pv; ::math::linear::vector::project( I_Pv, P_2viewer, P_normal ); ::math::linear::vector::length( I_Pv, T_scalar(1) );
                  T_scalar I_P = ::math::linear::vector::dot( I_Pl, I_Pv ); if( I_P < 0 ) I_P = 0; //if( 1 < I_P ) I_P = 1;

                  T_scalar I_Q = sqrt( ( 1- I_L*I_L  ) * ( 1- I_V*I_V ) ) / std::max( I_L, I_V );

                  P_result.set( 0, P_energy[0] * I_L * ( M2_a[0] + M2_b[0] * I_P * I_Q ) );
                  P_result.set( 1, P_energy[1] * I_L * ( M2_a[1] + M2_b[1] * I_P * I_Q ) );
                  P_result.set( 2, P_energy[2] * I_L * ( M2_a[2] + M2_b[2] * I_P * I_Q ) );

                  return true;
                 }

             private:
               T_color M2_a;
               T_color M2_b;

             public:
              static T_scalar Fs_A( T_scalar const& P_rho, T_scalar const& P_sigma )
                {
                 T_scalar Ir_result; 
                 Ir_result = T_scalar(1) -  P_sigma*P_sigma/( P_sigma*P_sigma + 0.33 ) / T_scalar( 2 );
                 return Ir_result;
                }
              static T_scalar Fs_B( T_scalar const& P_rho, T_scalar const& P_sigma )
               {
                T_scalar Ir_result; 
                Ir_result = T_scalar(0.45) * P_sigma*P_sigma/( P_sigma*P_sigma + 0.09 );
                return Ir_result;
               }

              static T_scalar Fs_a( T_scalar const& P_rho, T_scalar const& P_sigma )
               {
                return ( P_rho / ::math::constants::PHI ) * Fs_A( P_rho, P_sigma );
               }
              static T_scalar Fs_b( T_scalar const& P_rho, T_scalar const& P_sigma )
               {
                return ( P_rho / ::math::constants::PHI ) * Fs_B( P_rho, P_sigma );
               }

            };
          }
        }
      }
    }
  }

#endif
