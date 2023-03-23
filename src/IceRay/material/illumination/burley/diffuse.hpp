#ifndef Dh_IceRay_material_illumination_burley_diffuse_hpp_
 #define Dh_IceRay_material_illumination_burley_diffuse_hpp_

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
         namespace S_burley
          {

           class GC_diffuse
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_diffuse( T_color const& P_diffuse, T_scalar const& P_roughness )
                : M2_diffuse  ( P_diffuse  )
                , M2_roughness( P_roughness )
                {
                }

             public:
               bool F_process
                (
                 T_color      &  P_result,
                 T_color const&  P_light,
                 T_coord const&  P_normal,
                 T_coord const&  P_2viewer,
                 T_coord const&  P_2light,
                 T_coord const&  P_half
                 )
                 {
                  T_scalar I_thetaV = ::math::linear::vector::dot( P_normal, P_2viewer );
                  T_scalar I_thetaL = ::math::linear::vector::dot( P_normal, P_2light  );
                  T_scalar I_thetaD = ::math::linear::vector::dot( P_2light, P_half    );

                  T_scalar I_FD90 = 0.5 + 2 * M2_roughness * ( I_thetaD * I_thetaD );
                  T_scalar I_FD90_1 = I_FD90 - 1;

                  I_thetaL = T_scalar(1) - I_thetaL; I_thetaL = I_thetaL*I_thetaL*I_thetaL*I_thetaL*I_thetaL;
                  I_thetaV = T_scalar(1) - I_thetaV; I_thetaV = I_thetaV*I_thetaV*I_thetaV*I_thetaV*I_thetaV;

                  T_scalar I_value = ( 1 + I_FD90_1 * I_thetaL ) * ( 1 + I_FD90_1 * I_thetaV );
                           I_value /= ::math::constants::PHI;

                  P_result.set( 0, P_light[0] * M2_diffuse[0] * I_value );
                  P_result.set( 1, P_light[1] * M2_diffuse[1] * I_value );
                  P_result.set( 2, P_light[2] * M2_diffuse[2] * I_value );

                  return true;
                 }

             private:
               T_color  const& M2_diffuse;
               T_scalar const& M2_roughness;
            };

          }
        }
      }
    }
  }

#endif
