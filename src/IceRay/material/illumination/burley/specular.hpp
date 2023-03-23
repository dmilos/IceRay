#ifndef Dh_IceRay_material_illumination_burley_specular_hpp_
 #define Dh_IceRay_material_illumination_burley_specular_hpp_

 #include "IceRay/type/basic/scalar.hpp"
 #include "IceRay/type/color.hpp"
 #include "IceRay/type/math/coord.hpp"

#include "../fresnel/fresnel.hpp"
#include "./gtr.hpp"
#include "./ggx.hpp"



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

           class GC_specular
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_specular
                (
                  T_color  const& P_specular
                 ,T_scalar const& P_roughness //!< ( 0, ... ,0.3 )
                 ,T_scalar const& P_gamma     //!< ( 0, ... ,5.0 )
                 ,T_scalar const& P_F0        //!< ( 0, ..., 0.3 )
                )
                : M2_specular  ( P_specular  )
                , M2_distribution( P_roughness, P_gamma )
                , M2_fresnel( P_F0 )
                , M2_geometric( P_roughness )
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
                 T_scalar I_thetaL = ::math::linear::vector::dot( P_normal, P_2viewer );
                 T_scalar I_thetaV = ::math::linear::vector::dot( P_normal, P_2light  );

                 T_scalar I_D = M2_distribution.F_process( P_normal, P_half );
                 T_scalar I_F = M2_fresnel.F_process( P_normal, P_2viewer, P_2light, P_half );
                 T_scalar I_G = M2_geometric.F_process( P_normal, P_half );
                 T_scalar I_deniminator =  4 * I_thetaL * I_thetaV;

                 T_scalar I_value = I_D * I_F * I_G / I_deniminator;

                 P_result.set( 0, P_light[0] * M2_specular[0] * I_value );
                 P_result.set( 1, P_light[1] * M2_specular[1] * I_value );
                 P_result.set( 2, P_light[2] * M2_specular[2] * I_value );

                 return true;
                }

             private:
               T_color const&  M2_specular;

               GS_DDMRM::S_IceRay::S_material::S_illumination::S_burley::GC_GTR       M2_distribution;
               GS_DDMRM::S_IceRay::S_material::S_illumination::S_fresnel::GC_burley   M2_fresnel;
               GS_DDMRM::S_IceRay::S_material::S_illumination::S_burley::GC_GGX       M2_geometric;
            };

          }
        }
      }
    }
  }

#endif


