#ifndef Dh_IceRay_material_illumination_HeidrichSeidel_phong_hpp_
 #define Dh_IceRay_material_illumination_HeidrichSeidel_phong_hpp_

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
         namespace S_HeidrichSeidel
          {

           class GC_phong
          //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_phong( T_color const& P_specular, T_color const& P_shininess, /* T_coord const& P_radius,*/ T_coord const& P_groove )
                : M2_specular( P_specular )
                , M2_shininess( P_shininess )
                //, M2_radius( P_radius )
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
                 T_color const&  P_energy,
                 T_coord const&  P_2light,
                 T_coord const&  P_normal,
                 T_coord const&  P_viewer
                 )
                 {
                  T_coord I_T;
                  ::math::linear::vector::project( I_T, M2_groove, P_normal );
                  ::math::linear::vector::length( I_T, T_scalar(1) );

                  T_scalar I_lt =  ::math::linear::vector::dot( P_2light, I_T );
                  T_scalar I_vt = -::math::linear::vector::dot( P_viewer, I_T );
                  T_scalar I_value = sqrt( T_scalar(1) - I_lt * I_lt ) * sqrt( T_scalar(1) - I_vt * I_vt )  - I_lt * I_vt;

                  if( I_value < 0 )
                   {
                    P_result.set( 0, T_scalar(0) );
                    P_result.set( 1, T_scalar(0) );
                    P_result.set( 2, T_scalar(0) );
                    return true;
                   }

                  P_result.set( 0, P_energy[0] * M2_specular[0] * pow( I_value, M2_shininess[0] ) );
                  P_result.set( 1, P_energy[1] * M2_specular[1] * pow( I_value, M2_shininess[1] ) );
                  P_result.set( 2, P_energy[2] * M2_specular[2] * pow( I_value, M2_shininess[2] ) );

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
