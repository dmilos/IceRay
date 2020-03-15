#ifndef Dh_IceRay_material_illumination_lambert_hpp_
 #define Dh_IceRay_material_illumination_lambert_hpp_

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

         class GC_lambert
          //: public S_IceRay::S_material::S_illumination::S__base::GC_data
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                     T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar            T_coord;
             typedef  GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar           T_color;
             typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot              T_light;

             GC_lambert( T_color const& P_diffuse )
              :M2_diffuse( P_diffuse )
              {

              }
           public:
             bool F_process
              (
               T_color      &  P_result,
               T_color const&  P_light,
               T_coord const&  P_2light,
               T_coord const&  P_normal
               )
              {
               T_scalar I_scalar = ::math::linear::vector::dot( P_2light, P_normal );
               if( I_scalar < 0 )
                {
                 return false;
                }

               ::color::operation::multiply( P_result, M2_diffuse, P_light );

               P_result *= I_scalar;
               return true;
              }

           private:
             T_color const& M2_diffuse;
          };

        }
      }
    }
  }

#endif
