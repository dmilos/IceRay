#ifndef Dh_IceRay_material_illumination_fresnel_term_hpp_
 #define Dh_IceRay_material_illumination_fresnel_term_hpp_

// GS_DDMRM::S_IceRay::S_material::S_illumination::S_fresnel::GC_term

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

           class GC_term
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_term(  )
                {
                }

             public:

               T_scalar F_process
                (
                  T_scalar const&  P_n
                 ,T_coord  const&  P_2viewer
                 ,T_coord  const&  P_half
                )
                {
                 auto I_cos = ::math::linear::vector::dot( P_2viewer, P_half );
                 auto I_g = P_n*P_n + I_cos*I_cos - T_scalar(1);
                 if( I_g < T_scalar(0) )
                  {
                   return T_scalar(1);
                  }
                 I_g = sqrt( I_g );

                 T_scalar I_a = 0.5;
                 T_scalar I_b = ( I_g - I_cos )/( I_g + I_cos); 
                          I_b *= I_b;
                 T_scalar I_c = ( I_cos*(I_g+I_cos) - T_scalar(1))/( I_cos*(I_g-I_cos) + T_scalar(1) ); 
                          I_c = 1 + I_c*I_c;

                 return I_a * I_b * I_c;
                }
            };

          }
        }
      }
    }
  }

#endif
