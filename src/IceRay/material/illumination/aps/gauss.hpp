#ifndef Dh_IceRay_material_illumination_APS_gauss_hpp_
 #define Dh_IceRay_material_illumination_APS_gauss_hpp_

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
         namespace S_APS
          {

           class GC_gauss // (34)
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_simple      T_ray;

             public:
               GC_gauss
                (
                  T_scalar const&  P_C
                 ,T_scalar const&  P_sigmaX
                 ,T_scalar const&  P_sigmaY
                )
                : M2_C( P_C )
                , M2_sigmaX( P_sigmaX )
                , M2_sigmaY( P_sigmaY )
                {
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
                 // TODO
                 return true;
                }

             private:
               T_scalar const& M2_C;
               T_scalar const& M2_sigmaX;
               T_scalar const& M2_sigmaY;
            };

          }
        }
      }
    }
  }

#endif
