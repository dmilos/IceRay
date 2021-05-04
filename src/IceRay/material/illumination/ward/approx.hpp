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

           class GC_approx // http://radsite.lbl.gov/radiance/papers/sg92/page4.tif  page 268, 5b
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
                 ,T_scalar const&  P_alphaX     //!< 0 != P_alphaX[i] * P_alphaY[i]
                 ,T_scalar const&  P_alphaY     //!< 0 != P_alphaX[i] * P_alphaY[i]
                )
                : M2_specular( P_specular )
                , M2_alphaX( P_alphaX )
                , M2_alphaY( P_alphaY )
                , M2_direction( P_direction )
                {
                 M2_aX2 = M2_alphaX * M2_alphaX;
                 M2_aY2 = M2_alphaY * M2_alphaY;
                 M2_aXY = M2_alphaX * M2_alphaY;
                }

             public:
               bool F_process
                (
                 T_color      &  P_result,
                 T_color const&  P_energy,
                 T_coord const&  P_2light,
                 T_coord const&  P_normal,
                 T_coord const&  P_viewer,
                 T_coord const&  P_half
                )
                {
                 T_scalar I_ln =  ::math::linear::vector::dot( P_2light,  P_normal ); //if( I_ln < 0 ){ return false; }
                 T_scalar I_vn =  ::math::linear::vector::dot( P_viewer,  P_normal ); //if( I_vn < 0 ){ return false; }
                 T_scalar I_hn =  ::math::linear::vector::dot( P_half,    P_normal );

                 T_coord I_y;
                 ::math::linear::vector::cross( I_y, P_normal, M2_direction );
                 ::math::linear::vector::length( I_y, T_scalar(1) );

                 T_coord I_x;
                 ::math::linear::vector::cross( I_x, I_y, P_normal );
                 ::math::linear::vector::length( I_x, T_scalar(1) );

                 T_scalar I_hx = ::math::linear::vector::dot( P_half, I_x ) / M2_alphaX;
                 T_scalar I_hy = ::math::linear::vector::dot( P_half, I_y ) / M2_alphaY;

                 T_scalar I_den = sqrt( I_ln * I_vn ) * T_scalar(4) * ::math::constants::PHI * M2_aXY;
                 T_scalar I_nom = exp( T_scalar(-2)*( I_hx * I_hx + I_hy * I_hy ) / ( 1 + I_hn ) );

                 T_scalar I_final =  I_nom / I_den ;

                 P_result.set( 0, P_energy[0] * M2_specular[0] * I_final );
                 P_result.set( 1, P_energy[1] * M2_specular[1] * I_final );
                 P_result.set( 2, P_energy[2] * M2_specular[2] * I_final );

                 return true;
                }

             private:
               T_color const& M2_specular;
               T_scalar const& M2_alphaX;  T_scalar M2_aX2;
               T_scalar const& M2_alphaY;  T_scalar M2_aY2;
               T_scalar M2_aXY;
               T_coord const& M2_direction;
            };

          }
        }
      }
    }
  }

#endif
