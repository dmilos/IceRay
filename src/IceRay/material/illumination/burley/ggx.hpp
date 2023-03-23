#ifndef Dh_IceRay_material_illumination_burley_GGX_hpp_
 #define Dh_IceRay_material_illumination_burley_GGX_hpp_

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

           class GC_GGX //!< geometric
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_GGX( T_scalar const& P_roughness )
                : M2_roughness( P_roughness )
                {
                 M2_R = T_scalar(1) + M2_roughness;
                 M2_R = T_scalar(0.25) * M2_R * M2_R;
                }

             public:
               T_scalar F_process
                (
                 T_coord const&  P_normal,
                 T_coord const&  P_half
                 )
                 {
                  T_scalar I_cosH = ::math::linear::vector::dot( P_normal, P_half );
                           I_cosH *= I_cosH; 
                  T_scalar I_tanH = (T_scalar(1)-I_cosH)/I_cosH;

                  T_scalar Ir_result;
                  Ir_result = M2_R / ( I_cosH *( M2_R*M2_R + I_tanH ) );
                  Ir_result = Ir_result * Ir_result / ::math::constants::PHI;
                  return Ir_result;
                 }

             private:
               T_scalar  M2_R;
               T_scalar const& M2_roughness;
            };

          }
        }
      }
    }
  }

#endif
