#ifndef Dh_IceRay_material_illumination_OrenNayar_YasuhiroFujii_hpp_
 #define Dh_IceRay_material_illumination_OrenNayar_YasuhiroFujii_hpp_

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
         namespace S_OrenNayar
          {

           class GC_YasuhiroFujii
            //: public S_IceRay::S_material::S_illumination::S__base::GC_data
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_YasuhiroFujii( T_color const& P_A, T_color const& P_B )
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
                 {
                  T_scalar I_dotLV = ::math::linear::vector::dot( P_normal, P_2light );
                  T_scalar I_dotNL = ::math::linear::vector::dot( P_normal, P_2light );
                  T_scalar I_dotNV = ::math::linear::vector::dot( P_normal, P_viewer );

                  T_scalar I_s = I_dotLV - I_dotNL * I_dotNV;

                  T_scalar I_t;
                  if( I_s < 0 )
                   {
                    I_t = 1;
                   }
                  else
                   {
                    I_t = std::max( I_dotNL, I_dotNV );
                   }

                  P_result.set( 0, P_light[0] * I_dotNL * ( M2_A[0] + M2_B[0] * I_s/I_t ) );
                  P_result.set( 2, P_light[1] * I_dotNL * ( M2_A[1] + M2_B[1] * I_s/I_t ) );
                  P_result.set( 1, P_light[2] * I_dotNL * ( M2_A[2] + M2_B[2] * I_s/I_t ) );

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
