#ifndef Dh_IceRay_material_illumination_HeidrichSeidel_lp_hpp_
 #define Dh_IceRay_material_illumination_HeidrichSeidel_lp_hpp_

 #include "../../type/basic/scalar.hpp"
 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"


 namespace  GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_illumination
        {
         namespace S_HeidrichSeidel
          {

           class GC_lambert
            //: public S_IceRay::S_material::S_illumination::S__base::GC_data
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_lambert( T_color const& P_diffuse, /* T_coord const& P_radius,*/ T_coord const& P_groove )
                : M2_diffuse( P_diffuse )
                , M2_specular( P_specular )
                : M2_shininess( P_shininess )
                , M2_radius( 1 /* T_coord const& P_radius */ )
                , M2_groove( P_groove )
                {
                 M2_radius[0] = 1.0;
                 M2_radius[1] = 1.0;
                 M2_radius[2] = 1.0;
                }

             public:
               bool F_process
                (
                 T_color      &  P_result,
                 T_color const&  P_light,
                 T_coord const&  P_2light,
                 T_coord const&  P_normal,
                 T_coord const&  P_viewer
                 )
                 {
                  
                  T_coord I_T, I_0;
                  ::math::linear::vector::cross( I_0, P_normal, M2_groove );
                  ::math::linear::vector::cross( I_T, I_0, P_normal );
                  ::math::linear::vector::length( I_T, T_scalar(1) );

                  T_scalar I_lt = acos( -::math::linear::vector::dot( P_2light, I_T ) );
                  T_scalar I_vt = acos( +::math::linear::vector::dot( P_viewer, I_T ) );

                  T_scalar I_summae = I_vt + I_lt;

                  T_scalar I_cos0 = cos( M2_radius[0] * I_summae );
                  T_scalar I_cos1 = cos( M2_radius[1] * I_summae );
                  T_scalar I_cos2 = cos( M2_radius[2] * I_summae );

                  if( I_cos0 < 0 ){ P_result.F_set( 0, P_light[0] * M2_specular[0] * pow( -I_cos0, M2_shininess[0] ) ); }else{P_result.F_set( 0, 0 ); }
                  if( I_cos1 < 0 ){ P_result.F_set( 1, P_light[1] * M2_specular[1] * pow( -I_cos1, M2_shininess[1] ) ); }else{P_result.F_set( 1, 0 ); }
                  if( I_cos2 < 0 ){ P_result.F_set( 2, P_light[2] * M2_specular[2] * pow( -I_cos2, M2_shininess[2] ) ); }else{P_result.F_set( 2, 0 ); }

                  return true;
                 }

             private:
               T_color const& M2_specular;
               T_color const& M2_shininess;
               T_coord const& M2_groove;
               T_coord        M2_radius;
            };

          }
        }
      }
    }
  }

#endif
