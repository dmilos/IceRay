#ifndef Dh_IceRay_material_illumination_ward_real_hpp_
 #define Dh_IceRay_material_illumination_ward_real_hpp_

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

           class GC_real // http://radsite.lbl.gov/radiance/papers/sg92/page4.gif page 268, 5A
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple      T_ray;

             public:
               GC_real
                (
                  T_coord const&  P_direction  //!< unit vector
                 ,T_color const&  P_specular   //!< no limits
                 ,T_color const&  P_alphaX     //!< 0 != P_alphaX[i] * P_alphaY[i]
                 ,T_color const&  P_alphaY     //!< 0 != P_alphaX[i] * P_alphaY[i]
                )
                : M2_specular( P_specular )
                , M2_alphaX( P_alphaX )
                , M2_alphaY( P_alphaY )
                , M2_direction( P_direction )
                {
                 M2_iAX2[0] =  M2_alphaX[0]*M2_alphaX[0];  M2_iAY2[0] =  M2_alphaY[0]*M2_alphaY[0];
                 M2_iAX2[1] =  M2_alphaX[1]*M2_alphaX[1];  M2_iAY2[1] =  M2_alphaY[1]*M2_alphaY[1];
                 M2_iAX2[2] =  M2_alphaX[2]*M2_alphaX[2];  M2_iAY2[2] =  M2_alphaY[2]*M2_alphaY[2];

                 M2_aXY[0] =  M2_alphaX[0]*M2_alphaY[0];
                 M2_aXY[1] =  M2_alphaX[1]*M2_alphaY[1];
                 M2_aXY[2] =  M2_alphaX[2]*M2_alphaY[2];

                 M2_aXY[0] =  M2_specular[0] / M2_aXY[0];
                 M2_aXY[1] =  M2_specular[1] / M2_aXY[1];
                 M2_aXY[2] =  M2_specular[2] / M2_aXY[2];
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
                 static T_scalar Is_epsilon = 1e-12;
                 static T_scalar Is_one_small = T_scalar(1)-10*Is_epsilon;
                 static T_scalar Is_one_exact = T_scalar(1);
                 static T_scalar Is_one_big   = T_scalar(1)+Is_epsilon;

                 T_scalar I_ln =  ::math::linear::vector::dot( P_2light,  P_normal );
                 if( I_ln < 0 )
                  {
                   return false;
                  }
                 T_scalar I_vn =  ::math::linear::vector::dot( P_viewer,  P_normal );
                 if( I_vn < 0 )
                  {
                   return false;
                  }
                 T_scalar I_hn =  ::math::linear::vector::dot( P_half,    P_normal );

                 T_scalar I_delta = acos( I_hn ); // ::math::linear::vector::angle<true>( P_half, P_normal )

                 T_coord I_groove;
                 ::math::linear::vector::project( I_groove, M2_direction, P_normal );
                 ::math::linear::vector::length( I_groove, Is_one_small );

                 T_coord I_half;
                 ::math::linear::vector::project( I_half, P_half, P_normal );
                 ::math::linear::vector::length( I_half, Is_one_small );

                 T_scalar I_cos_phi = ::math::linear::vector::dot( I_groove, I_half );
                 T_scalar I_tan_delta = tan( I_delta );
                 T_scalar I_eX = I_tan_delta * I_cos_phi;  I_eX *= -I_eX;
                 T_scalar I_sin2_phi =  T_scalar(1) - I_cos_phi*I_cos_phi;
                 T_scalar I_eY = I_tan_delta;  I_eY *= -I_eY * I_sin2_phi;

                 T_scalar I_c0 = 4 * Is_phi * sqrt( I_ln * I_vn );

                 P_result.set( 0, P_light[0] * M2_aXY[0] * exp( I_eX/M2_iAX2[0] + I_eY/M2_iAY2[0] ) / I_c0 );
                 P_result.set( 1, P_light[1] * M2_aXY[1] * exp( I_eX/M2_iAX2[1] + I_eY/M2_iAY2[1] ) / I_c0 );
                 P_result.set( 2, P_light[2] * M2_aXY[2] * exp( I_eX/M2_iAX2[2] + I_eY/M2_iAY2[2] ) / I_c0 );

                 return true;
                }

             private:
               T_color const& M2_specular;
               T_color const& M2_alphaX;  T_color M2_iAX2;
               T_color const& M2_alphaY;  T_color M2_iAY2;
                                          T_color M2_aXY;
               T_coord const& M2_direction;
            };

          }
        }
      }
    }
  }

#endif

