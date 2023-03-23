#ifndef Dh_IceRay_material_illumination_CookTorrance_specular_hpp_
 #define Dh_IceRay_material_illumination_CookTorrance_specular_hpp_

// S_IceRay::S_material::S_illumination::S_CookTorrance::GC_specular

#include "../beckmann/isotropic.hpp"
#include "./gaf.hpp"
#include "../fresnel/fresnel.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_illumination
        {
         namespace S_CookTorrance
          {

           struct GC_specular
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_specular( T_color const&  P_specular, T_color const& P_roughness, T_scalar const& P_ior )
                :M2_ior( P_ior )
                ,M2_distribution( P_specular, P_roughness )
                {
                }

               bool F_process
                (
                 T_color       &  P_result,
                 T_color  const&  P_light,
                 T_coord  const&  P_normal,
                 T_coord  const&  P_2viewer,
                 T_coord  const&  P_2light,
                 T_coord  const&  P_half
                )
                {
                 auto I_nv = ::math::linear::vector::dot( P_normal, P_2viewer );
                 auto I_nl = ::math::linear::vector::dot( P_normal, P_2light );

                 T_scalar I_F = 1; // TODO enable one day M2_fresnel.F_process( M2_ior, P_2viever, P_half );
                 T_color  I_D;  M2_distribution.F_process( I_D, P_light, P_normal, P_half );
                 T_scalar I_G = M2_geometric.F_process( P_2light, P_normal, P_2viewer, P_half );
                 T_scalar I_denominator = I_nl * I_nv * ::math::constants::PHI;

                 P_result =  I_D * I_F * I_G / I_denominator;
                 // DEBUG P_result = color::gray<T_scalar>( { 1.0/I_denominator } );
                 // DEBUG P_result = color::gray<T_scalar>( { I_G } );
                 // DEBUG P_result = color::gray<T_scalar>( { I_F } );
                 // DEBUG P_result = I_D;

                 P_result *=  I_nl;
                 return true;
                }

              private:
                T_scalar const& M2_ior;
                GS_DDMRM::S_IceRay::S_material::S_illumination::S_beckmann::GC_isotropic     M2_distribution;
                GS_DDMRM::S_IceRay::S_material::S_illumination::S_fresnel::GC_schlick        M2_fresnel;
                GS_DDMRM::S_IceRay::S_material::S_illumination::S_CookTorrance::GC_GAF       M2_geometric;
            };

          }
        }
      }
    }
  }

#endif
