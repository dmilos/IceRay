#ifndef Dh_IceRay_material_illumination_phong_hpp_
 #define Dh_IceRay_material_illumination_phong_hpp_

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

         class GC_phong //!< Illuminati for computer generated Picture, Bui Tuong Phong, formula (3)
          //: public S_IceRay::S_material::S_illumination::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

           public:
             GC_phong( T_color const& P_specular, T_color const& P_shininess )
              : M2_specular ( P_specular  )
              , M2_shininess( P_shininess )
              {
              }

           public:
             bool F_process
              (
               T_color      &  P_result,
               T_color const&  P_light,
               T_coord const&  P_reflected,
               T_coord const&  P_2light
               )
               {
                T_scalar I_scalar = ::math::linear::vector::dot( P_reflected, P_2light );

                if( I_scalar < 0 )
                 {
                  return false;
                 }

                P_result.set( 0, P_light[0] * M2_specular[0] * pow( I_scalar, M2_shininess[0] ) );
                P_result.set( 1, P_light[1] * M2_specular[1] * pow( I_scalar, M2_shininess[1] ) );
                P_result.set( 2, P_light[2] * M2_specular[2] * pow( I_scalar, M2_shininess[2] ) );

                return true;
               }

           private:
             T_color const& M2_specular;
             T_color const& M2_shininess;
          };

        }
      }
    }
  }

#endif
