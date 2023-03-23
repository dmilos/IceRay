#ifndef Dh_IceRay_material_illumination_TrowbridgeReitz_isotropic_hpp_
 #define Dh_IceRay_material_illumination_TrowbridgeReitz_isotropic_hpp_

//  GS_DDMRM::S_IceRay::S_material::S_illumination::S_TrowbridgeReitz::GC_isotropic

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
         namespace S_TrowbridgeReitz
          {

           class GC_isotropic  //!< Average irregularity representation of a rough surface for ray reflection
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
           
             public:
               GC_isotropic( T_color const&  P_specular, T_scalar const& P_roughness )
                : M2_specular( P_specular )
                , M2_roughness( P_roughness )
                {
                 static T_scalar Is_phi  = ::math::constants::PHI;
                 M2_X2 = M2_roughness*M2_roughness;
                 M2_c = Is_phi * M2_roughness * M2_roughness;
                }
           
             public:
               bool F_process
                (
                 T_color      &  P_result,
                 T_color const&  P_light,
                 T_coord const&  P_normal,
                 T_coord const&  P_half
                )
                {
                 T_scalar I_cos = ::math::linear::vector::dot( P_normal, P_half );
                 I_cos   *= I_cos;
                 T_scalar I_sin = sqrt( T_scalar(1) - I_cos );

                 I_sin   *= I_sin;

                 T_scalar I_b =  M2_X2 * I_cos + I_sin ;
                          I_b *= I_b;
                 T_scalar I_value = T_scalar(1) / I_b;

                 P_result.set( 0, P_light[0] * M2_specular[0] * I_value );
                 P_result.set( 1, P_light[1] * M2_specular[1] * I_value );
                 P_result.set( 2, P_light[2] * M2_specular[2] * I_value );
                 return true;
                }

             private:
               T_color  const& M2_specular;
               T_scalar const& M2_roughness; T_scalar M2_X2;
               T_scalar M2_c;
            };

          }
        }
      }
    }
  }

#endif
