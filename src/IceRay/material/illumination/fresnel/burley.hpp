#ifndef Dh_IceRay_material_illumination_fresnel_burley_hpp_
 #define Dh_IceRay_material_illumination_fresnel_burley_hpp_

// GS_DDMRM::S_IceRay::S_material::S_illumination::S_fresnel::GC_burley

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
         namespace S_fresnel
          {

           class GC_burley
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_burley( T_scalar const& P_roughness )
                : M2_roughness( P_roughness )
                {
                }

             public:
               static T_scalar F_FD90
                (
                  T_scalar const& P_roughness
                 ,T_scalar const& P_thetaD
                )
                {
                 return 0.5 + 2 * P_roughness * P_thetaD*P_thetaD;
                }

               T_scalar F_FD90
                (
                 T_scalar const&  P_cosNH
                )
                {
                 return F_FD90( M2_roughness, P_cosNH );
                }

               T_scalar F_process
                (
                  T_coord const&  P_normal
                 ,T_coord const&  P_2viewer
                 ,T_coord const&  P_2light
                 ,T_coord const&  P_half
                )
                {
                 auto I_thetaV = ::math::linear::vector::dot( P_normal, P_2viewer );
                 auto I_thetaL = ::math::linear::vector::dot( P_normal, P_2light  );
                 auto I_thetaD = ::math::linear::vector::dot( P_2light, P_half    );

                 auto I_FD90_1 = F_FD90( I_thetaD ) - T_scalar(1);
                 I_thetaV = T_scalar(1) - I_thetaV;  I_thetaV = I_thetaV*I_thetaV*I_thetaV*I_thetaV*I_thetaV;
                 I_thetaL = T_scalar(1) - I_thetaL;  I_thetaL = I_thetaL*I_thetaL*I_thetaL*I_thetaL*I_thetaL;

                 return ( T_scalar(1) + I_FD90_1 * I_thetaL )*( T_scalar(1) + I_FD90_1 * I_thetaV ) / math::constants::PHI;
                }
             private:
               T_scalar const& M2_roughness;
            };

          }
        }
      }
    }
  }

#endif
