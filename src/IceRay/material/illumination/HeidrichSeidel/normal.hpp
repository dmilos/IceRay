#ifndef Dh_IceRay_material_illumination_HeidrichSeidel_normal_hpp_
 #define Dh_IceRay_material_illumination_HeidrichSeidel_normal_hpp_

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
         namespace S_HeidrichSeidel
          {

           class GC_normal
          //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_normal( T_coord const& P_groove )
                : M2_groove( P_groove )
                {
                }

             public:
               bool F_process
                (
                  T_coord      &  P_result
                 ,T_coord const&  P_normal
                )
                {
                 T_coord I_0;
                 ::math::linear::vector::cross( I_0, P_normal, M2_groove );
                 ::math::linear::vector::cross( P_result, I_0, P_normal );
                 ::math::linear::vector::length( P_result, T_scalar(1) );

                 return true;
                }

             private:
               T_coord const& M2_groove;
            };

          }
        }
      }
    }
  }

#endif
