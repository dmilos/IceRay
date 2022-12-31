#ifndef Dh_IceRay_material_illumination_OrenNayar_Fujii_Proposed_hpp_
 #define Dh_IceRay_material_illumination_OrenNayar_Fujii_Proposed_hpp_

// GS_DDMRM::S_IceRay::S_material::S_illumination::S_OrenNayar::S_Fujii::GC_proposed

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
           namespace S_Fujii
            {

             class GC_proposed
            //: public S_IceRay::S_material::S_illumination::GC__pure
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

               public:
                 GC_proposed( T_color const& P_rho, T_color const& P_sigma )
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
                  {
                   T_scalar I_dotLV = ::math::linear::vector::dot( P_2viewer, P_2light );
                   T_scalar I_dotNL = ::math::linear::vector::dot( P_normal, P_2light );
                   T_scalar I_dotNV = ::math::linear::vector::dot( P_normal, P_2viewer );

                   T_scalar I_s = I_dotLV - I_dotNL * I_dotNV;

                   T_scalar I_t;
                   if( I_s < T_scalar(0) )
                    {
                     I_t = T_scalar(1);
                    }
                   else
                    {
                     I_t = std::max( I_dotNL, I_dotNV );
                    }

                   P_result.set( 0, P_energy[0] * I_dotNL * ( M2_a[0] + M2_b[0] * I_s/I_t ) );
                   P_result.set( 1, P_energy[1] * I_dotNL * ( M2_a[1] + M2_b[1] * I_s/I_t ) );
                   P_result.set( 2, P_energy[2] * I_dotNL * ( M2_a[2] + M2_b[2] * I_s/I_t ) );

                   return true;
                  }

               private:
                 T_color M2_a;
                 T_color M2_b;
               public:
                 static T_scalar Fs_A( T_scalar const& P_rho, T_scalar const& P_sigma )
                   {
                    T_scalar Ir_result;
                    T_scalar I_s2 = P_sigma * P_sigma;
                    Ir_result = 1 - 0.5*I_s2/( I_s2 + 0.33) + 0.17*P_sigma* I_s2/( I_s2 + 0.13);
                    return Ir_result/ ::math::constants::PHI;
                   }
                 static T_scalar Fs_B(T_scalar const& P_rho, T_scalar const& P_sigma )
                  {
                   T_scalar Ir_result;
                   T_scalar I_s2 = P_sigma * P_sigma;
                   Ir_result = ( 0.45) * I_s2 / ( I_s2 + 0.09 ) ;
                   return Ir_result/ ::math::constants::PHI;
                  }

                 static T_scalar Fs_a( T_scalar const& P_rho, T_scalar const& P_sigma )
                  {
                   return P_rho * Fs_A( P_rho, P_sigma );
                  }
                 static T_scalar Fs_b( T_scalar const& P_rho, T_scalar const& P_sigma )
                  {
                   return P_rho * Fs_B( P_rho, P_sigma );
                  }
              };

            }
          }
        }
      }
    }
  }

#endif
