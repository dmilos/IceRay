#ifndef Dh_IceRay_material_illumination_ward_isotropic_hpp_
 #define Dh_IceRay_material_illumination_ward_isotropic_hpp_

 #include "../../../type/basic/scalar.hpp"
 #include "../../../type/color.hpp"
 #include "../../../type/math/coord.hpp"

 namespace  GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_illumination
        {
         namespace S_ward
          {

           class GC_isotropic       // http://radsite.lbl.gov/radiance/papers/sg92/page4.gif  page 268, 4
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple      T_ray;

             public:
               GC_isotropic( T_color const&  P_specular, T_color const&  P_alpha )
                : M2_specular( P_specular )
                , M2_alpha( P_alpha )
                {
                }

             public:
               bool F_process
                (
                 T_color      &  P_result,
                 T_color const&  P_light,
                 T_coord const&  P_2light,
                 T_coord const&  P_normal,
                 T_coord const&  P_viewer,
                 T_coord const&  P_half
                )
                {
                 static T_scalar Is_phi = ::math::constants::PHI;

                 T_scalar I_ln =  ::math::linear::vector::dot( P_2light,  P_normal );
                 T_scalar I_vn =  ::math::linear::vector::dot( P_viewer,  P_normal );
                 T_scalar I_hn =  ::math::linear::vector::dot( P_half,    P_normal );

                 T_scalar I_delta = acos( I_hn );

                 T_scalar I_c = sqrt( I_ln * I_vn ) * 4 * Is_phi ;
                 T_scalar I_e = tan( I_delta ); I_e *= - I_e;

                 P_result.set( 0, P_light[0] * M2_specular[0] * T_scalar(1) /( I_c * M2_alpha[0] * M2_alpha[0] ) * exp( I_e /( M2_alpha[0] * M2_alpha[0] ) ) );
                 P_result.set( 1, P_light[1] * M2_specular[1] * T_scalar(1) /( I_c * M2_alpha[1] * M2_alpha[1] ) * exp( I_e /( M2_alpha[1] * M2_alpha[1] ) ) );
                 P_result.set( 2, P_light[2] * M2_specular[2] * T_scalar(1) /( I_c * M2_alpha[2] * M2_alpha[2] ) * exp( I_e /( M2_alpha[2] * M2_alpha[2] ) ) );

                 return true;
                }

             private:
               T_color const& M2_specular;
               T_color const& M2_alpha;   //T_color M2_iA2;
            };

          }
        }
      }
    }
  }

#endif
