#ifndef Dh_IceRay_material_illumination_HeidrichSeidel_lp_hpp_
 #define Dh_IceRay_material_illumination_HeidrichSeidel_lp_hpp_

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
         namespace S_HeidrichSeidel
          {

           class GC_value
            //: public S_IceRay::S_material::S_illumination::S__base::GC_data
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             public:
               GC_value( T_color const& P_diffuse, /* T_coord const& P_radius,*/ T_coord const& P_groove )
                : M2_diffuse( P_diffuse )
                , M2_specular( P_specular )
                : M2_shininess( P_shininess )
                , M2_radius( 1 /* T_coord const& P_radius,*/ )
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
                 T_color const&  P_light,
                 T_coord const&  P_2light,
                 T_coord const&  P_normal,
                 T_coord const&  P_viewer
                 )
                 {


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
