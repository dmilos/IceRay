#ifndef Dh_IceRay_material_illumination_ward_approx_hpp_
 #define Dh_IceRay_material_illumination_ward_approx_hpp_

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

           class GC_approx // http://radsite.lbl.gov/radiance/papers/sg92/page4.gif  page 268, 5b
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple      T_ray;

             public:
               GC_approx
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

                 T_coord I_y;
                 ::math::linear::vector::cross( I_y, P_normal, M2_direction );
                 ::math::linear::vector::length( I_y, T_scalar(1) );

                 T_coord I_x;
                 ::math::linear::vector::cross( I_x, I_y, P_normal );
                 ::math::linear::vector::length( I_x, T_scalar(1) );

                 T_scalar I_hx = ::math::linear::vector::dot( P_half, I_x ); I_hx *= I_hx;
                 T_scalar I_hy = ::math::linear::vector::dot( P_half, I_y ); I_hy *= I_hy;

                 T_scalar I_c0 = sqrt( I_ln * I_vn ) * T_scalar(4) * Is_phi;
                 T_scalar I_e1 = T_scalar(-2)/( 1 + I_hn );

                 P_result.set( 0, P_light[0] * M2_specular[0] * ( T_scalar(1)/( I_c0 * M2_aXY[0] ) ) * exp( I_e1 * ( I_hx / M2_iAX2[0] + I_hy / M2_iAY2[0] ) ) );
                 P_result.set( 1, P_light[1] * M2_specular[1] * ( T_scalar(1)/( I_c0 * M2_aXY[1] ) ) * exp( I_e1 * ( I_hx / M2_iAX2[1] + I_hy / M2_iAY2[1] ) ) );
                 P_result.set( 2, P_light[2] * M2_specular[2] * ( T_scalar(1)/( I_c0 * M2_aXY[2] ) ) * exp( I_e1 * ( I_hx / M2_iAX2[2] + I_hy / M2_iAY2[2] ) ) );

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
