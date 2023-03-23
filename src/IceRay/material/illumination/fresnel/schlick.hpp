#ifndef Dh_IceRay_material_illumination_fresnel_schlick_hpp_
 #define Dh_IceRay_material_illumination_fresnel_schlick_hpp_

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
         namespace S_fresnel
          {

           class GC_schlick
            //: public S_IceRay::S_material::S_illumination::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_schlick(  )
                {
                }

             public:
               static T_scalar F_f0
                (
                  T_scalar P_IOR
                )
                {
                 return ( P_IOR - T_scalar(1) )/( P_IOR + T_scalar(1) );
                }

               static T_scalar F_process
                (
                  T_scalar P_F0
                 ,T_scalar P_cos
                )
                {
                 P_cos = T_scalar(1)-P_cos;
                 P_cos = P_cos*P_cos*P_cos*P_cos*P_cos;

                 return P_F0 + ( T_scalar(1) - P_F0 )* P_cos;
                }

               static T_scalar F_process
                (
                  T_scalar const& P_F0
                 ,T_coord const&  P_A //!< P_2light
                 ,T_coord const&  P_B //!< P_half
                )
                {
                 T_scalar I_cos = ::math::linear::vector::dot( P_A, P_B );

                 return F_process( P_F0, I_cos );
                }

            };

          }
        }
      }
    }
  }

#endif
