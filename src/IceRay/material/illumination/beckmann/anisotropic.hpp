#ifndef Dh_IceRay_material_illumination_beckmann_anisotropic_hpp_
 #define Dh_IceRay_material_illumination_beckmann_anisotropic_hpp_

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
         namespace S_beckmann
          {

           class GC_anisotropic
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_anisotropic( T_color const&  P_specular, T_scalar const& P_roughnessX, T_scalar const& P_roughnessY )
                : M2_specular( P_specular )
                , M2_roughnessX( P_roughnessX )
                , M2_roughnessY( P_roughnessY )
                {
                 static T_scalar Is_phi  = ::math::constants::PHI;
                 M2_X2 = M2_roughnessX*M2_roughnessX;
                 M2_Y2 = M2_roughnessY*M2_roughnessY;
                 M2_c = Is_phi * M2_roughnessX * M2_roughnessY;
                }

             public:
               bool F_process
                (
                 T_color      & P_result,
                 T_color const& P_light,
                 T_coord const& P_normal,
                 T_coord const& P_half
                )
                {
                 T_scalar I_cos = ::math::linear::vector::dot( P_normal, P_half );
                 T_scalar I_sin = sqrt( T_scalar(1) - I_cos * I_cos );
                 T_scalar I_tan = I_sin / I_cos;

                 I_cos   *= I_cos;
                 I_sin   *= I_sin;
                 I_tan   *= I_tan;

                 T_scalar I_x = - I_tan * ( I_cos/M2_X2 + I_sin/M2_Y2 );
                 T_scalar I_y =  M2_c * I_cos * I_cos;
                 T_scalar I_value = exp( I_x ) / I_y ;

                 P_result.set( 0, P_light[0] * M2_specular[0] * I_value );
                 P_result.set( 1, P_light[1] * M2_specular[1] * I_value );
                 P_result.set( 2, P_light[2] * M2_specular[2] * I_value );
                 return true;
                }

             private:
               T_color  const& M2_specular;
               T_scalar const& M2_roughnessX; T_scalar M2_X2;
               T_scalar const& M2_roughnessY; T_scalar M2_Y2;
               T_scalar M2_c;
            };

          }
        }
      }
    }
  }

#endif
