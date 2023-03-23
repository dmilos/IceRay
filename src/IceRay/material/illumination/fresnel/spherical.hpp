#ifndef Dh_IceRay_material_illumination_fresnel_spherical_hpp_
 #define Dh_IceRay_material_illumination_fresnel_spherical_hpp_

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

           class GC_spherical
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_spherical(  )
                {
                }

             public:
               T_scalar F_process
                (
                  T_scalar P_color
                 ,T_scalar P_cos
                )
                {
                 T_scalar I_power = ( ( -5.55473 * P_cos ) - 6.98316 ) * P_cos;

                 return P_color + ( 1-P_color) * pow( T_scalar(2), I_power );
                }

               T_scalar F_process
                (
                  T_scalar P_color
                 ,T_coord const&  P_2light
                 ,T_coord const&  P_half
                )
                {
                 T_scalar I_cos = ::math::linear::vector::dot( P_2light, P_half );
                 return F_process( P_color, I_cos );
                }

            };

          }
        }
      }
    }
  }

#endif
