#ifndef Dh_IceRay_material_illumination_burley_GTR_hpp_
 #define Dh_IceRay_material_illumination_burley_GTR_hpp_

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

           class GC_GTR //!< Burley's distribution
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_GTR( T_scalar const& P_roughness, T_scalar const& P_gamma )
                : M2_roughness( P_roughness )
                , M2_gamma( P_gamma )
                {
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
                  T_scalar I_sinH =  T_scalar(1)- I_cosH ;


                  T_scalar I_value = M2_roughness*M2_roughness* I_cosH + I_sinH;
                           I_value = pow( I_value, M2_gamma );
                           I_value = T_scalar(1) / I_value;

                  return I_value;
                 }

             private:
               T_scalar const& M2_roughness;
               T_scalar const& M2_gamma;
            };

          }
        }
      }
    }
  }

#endif
