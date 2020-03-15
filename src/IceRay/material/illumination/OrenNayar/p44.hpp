#ifndef Dh_IceRay_material_illumination_OrenNayar_4_4_hpp_
 #define Dh_IceRay_material_illumination_OrenNayar_4_4_hpp_

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
         namespace S_OrenNayar
          {

           class GC_p44
            //: public S_IceRay::S_material::S_illumination::S__base::GC_data
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_p44( T_color const& P_A, T_color const& P_B )
                : M2_A( P_A )
                , M2_B( P_B )
                {
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
                 { // Tested with succes
                  T_scalar I_nl = ::math::linear::vector::dot( P_normal, P_2light );
                  T_scalar I_nv = ::math::linear::vector::dot( P_normal, P_viewer );

                  T_scalar I_angleVN = acos( I_nv );
                  T_scalar I_angleLN = acos( I_nl );

                  T_scalar I_alpha = std::max( I_angleVN, I_angleLN );
                  T_scalar I_beta  = std::min( I_angleVN, I_angleLN );

                  T_coord I_vp; ::math::linear::vector::project( I_vp, P_viewer, P_normal ); ::math::linear::vector::length( I_vp, T_scalar(1) );
                  T_coord I_lp; ::math::linear::vector::project( I_lp, P_2light, P_normal ); ::math::linear::vector::length( I_lp, T_scalar(1) );

                  T_scalar I_cos_phi = ::math::linear::vector::dot( I_lp, I_vp );

                  if( I_cos_phi < 0 )
                   {
                    I_cos_phi = 0;
                   }

                  P_result.set( 0, P_light[0] * I_nl * ( M2_A[0] + M2_B[0] * I_cos_phi * sin(I_alpha) * tan(I_beta) ) );
                  P_result.set( 2, P_light[1] * I_nl * ( M2_A[1] + M2_B[1] * I_cos_phi * sin(I_alpha) * tan(I_beta) ) );
                  P_result.set( 1, P_light[2] * I_nl * ( M2_A[2] + M2_B[2] * I_cos_phi * sin(I_alpha) * tan(I_beta) ) );

                  return true;
                 }

             private:
               T_color const& M2_A;
               T_color const& M2_B;
             public:
              //static Fs_A( ... )
              //static Fs_B( ... )

            };
          }
        }
      }
    }
  }

#endif
