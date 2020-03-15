#ifndef Dh_IceRay_material_transmission_schlick_hpp_
 #define Dh_IceRay_material_transmission_schlick_hpp_

// GS_DDMRM::S_IceRay::S_material::S_transmission::GC_schlick


 #include "../../type/basic/scalar.hpp"
 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"

 namespace  GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_transmission
        {

         class GC_schlick
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                     T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar            T_coord;

             GC_schlick( T_scalar const& P_air, T_scalar const& P_watter )
              :M2_air( P_air )
              ,M2_watter( P_watter )
              {
              }
           public:
             bool F_process
              (
                T_scalar     &  P_result
               ,T_coord const&  P_incoming
               ,T_coord const&  P_normal
               )
              {
               T_scalar I_theta = fabs( ::math::linear::vector::dot( P_incoming,  P_normal ) );
               T_scalar I_r0 = ( M2_air - M2_watter )/ ( M2_air + M2_watter ); I_r0 *= I_r0;
               T_scalar I_r1  = T_scalar(1) - I_theta;
               I_r1 = I_r1 * I_r1 * I_r1 * I_r1 * I_r1;

               P_result = I_r0 + ( T_scalar(1) - I_r0 ) * I_r1;
               return true;
              }

           private:
             T_scalar const& M2_air;
             T_scalar const& M2_watter;
          };

        }
      }
    }
  }

#endif
