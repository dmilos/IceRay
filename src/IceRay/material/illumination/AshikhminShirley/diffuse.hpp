#ifndef Dh_IceRay_material_illumination_AshikhminShirley_diffuse_hpp_
 #define Dh_IceRay_material_illumination_AshikhminShirley_diffuse_hpp_

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
         namespace S_AshikhminShirley
          {

           class GC_diffuse
            { // An Anisotropic Phong BRDF Model, Michael Ashikhmin Peter Shirley, page 5, term 5
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_diffuse( T_color const& P_diffuse, T_color const& P_specular )
                : M2_diffuse ( P_diffuse   )
                , M2_specular( P_specular )
                {
                }

             public:
               bool F_process
                (
                   T_color      &  P_result
                  ,T_coord const&  P_normal
                  ,T_coord const&  P_2light   //!< k1
                  ,T_coord const&  P_2viewer  //!< k2
                )
                {
                 const T_scalar I_c0 = T_scalar(28)/( T_scalar(23) * math::constants::PHI );
                 T_scalar I_l = ::math::linear::vector::dot( P_normal, P_2light  );
                 T_scalar I_v = ::math::linear::vector::dot( P_normal, P_2viewer  );

                 I_l = T_scalar(1) -I_l/2;  I_l = I_l *I_l *I_l * I_l *I_l;
                 I_v = T_scalar(1) -I_v/2;  I_v = I_v *I_v *I_v * I_v *I_v;

                 T_scalar I_c1 = ( T_scalar(1) - I_l  )*( T_scalar(1) - I_v );

                 T_color I_invert; ::color::operation::invert( I_invert, M2_specular );
                 ::color::operation::multiply( P_result, M2_diffuse, I_invert );
                 P_result *= I_c0 * I_c1;
                 return true;
                }

             private:
               T_color const& M2_diffuse;
               T_color const& M2_specular;
            };

          }
        }
      }
    }
  }

#endif
