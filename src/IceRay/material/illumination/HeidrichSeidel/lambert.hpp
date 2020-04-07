#ifndef Dh_IceRay_material_illumination_HeidrichSeidel_lambert_hpp_
 #define Dh_IceRay_material_illumination_HeidrichSeidel_lambert_hpp_

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

           class GC_lambert
          //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_lambert( T_color const& P_diffuse, /* T_coord const& P_radius,*/ T_coord const& P_groove )
                : M2_diffuse( P_diffuse )
                , M2_groove( P_groove )
                {
                }

             public:
               bool F_process
                (
                 T_color      &  P_result,
                 T_color const&  P_light,
                 T_coord const&  P_2light,
                 T_coord const&  P_normal
                 )
                 {


                  T_coord I_T;
                  ::math::linear::vector::project( I_T, M2_groove, P_normal );
                  ::math::linear::vector::length( I_T, T_scalar(1) );

                  //T_scalar I_ln = ::math::linear::vector::dot( P_2light, P_normal );

                  //T_coord I_P;
                  //::math::linear::vector::project( I_P, P_2light, I_T );
                  //::math::linear::vector::length( I_P, T_scalar(1) );
                  //
                  //T_scalar I_lp = ::math::linear::vector::dot( P_2light, I_P );
                  ////T_scalar I_value = I_lp;

                  T_scalar I_lt = ::math::linear::vector::dot( P_2light, I_T );
                  T_scalar I_value = sqrt( 1 - I_lt * I_lt );

                  //I_value *= I_ln * pow( I_value, 1 );

                  P_result.set( 0, I_value * M2_diffuse[0] * P_light[0] );
                  P_result.set( 1, I_value * M2_diffuse[1] * P_light[1] );
                  P_result.set( 2, I_value * M2_diffuse[2] * P_light[2] );

                  return true;
                 }

             private:
               T_color const& M2_diffuse;
               T_coord const& M2_groove;
            };

          }
        }
      }
    }
  }

#endif
