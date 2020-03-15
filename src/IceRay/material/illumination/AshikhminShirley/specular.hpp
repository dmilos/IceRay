#ifndef Dh_IceRay_material_illumination_AshikhminShirley_specular_hpp_
 #define Dh_IceRay_material_illumination_AshikhminShirley_specular_hpp_

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
         namespace S_AshikhminShirley
          {

           class GC_specular
            {  //https://www.cs.utah.edu/~shirley/papers/jgtbrdf.pdf
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

             GC_specular( T_color const& P_specular, T_scalar const& P_nu, T_scalar const& P_nv )
              : M2_specular( P_specular )
              , M2_nu( P_nu )
              , M2_nv( P_nv )
              {
              }

           public:
             bool F_process
              (
                 T_color      &  P_result
                ,T_coord const&  P_normal
                ,T_coord const&  P_2light  //!< k1
                ,T_coord const&  P_viewer //!< k2
                ,T_coord const&  P_half
                ,T_coord const&  P_u
                ,T_coord const&  P_v
               )
               {
                T_coord const& I_k = P_viewer;

                T_scalar I_hu = ::math::linear::vector::dot( P_half, P_u  );
                T_scalar I_hv = ::math::linear::vector::dot( P_half, P_v  );
                T_scalar I_hn = ::math::linear::vector::dot( P_half, P_normal  );

                T_scalar I_hk = ::math::linear::vector::dot( P_half, I_k  );

                T_scalar I_nL = ::math::linear::vector::dot( P_normal, P_2light  );
                T_scalar I_nV = ::math::linear::vector::dot( P_normal, P_viewer  );

                T_scalar I_power  = (M2_nu * ( I_hu * I_hu) + M2_nv * ( I_hv * I_hv ) )/( T_scalar(1) - (I_hn * I_hn ) );

                T_scalar I_c0 = sqrt( (T_scalar(1)+M2_nu)*(T_scalar(1)+M2_nv) )/( T_scalar(8) * T_scalar(math::constants::PHI) );
                T_scalar I_c1 = pow( I_hn, I_power );
                T_scalar I_c2 = I_hk * std::max<T_scalar>( I_nL, I_nV );
                T_scalar I_F  = T_scalar(1)- I_hk*I_hk*I_hk*I_hk*I_hk;

                T_color I_invert; ::color::operation::invert( I_invert, M2_specular );

                P_result = (I_c0* I_c1 / I_c2) * ( M2_specular + I_invert * I_F);

                return true;
               }

           private:
             T_color const& M2_specular;
             T_scalar const& M2_nu;
             T_scalar const& M2_nv;

             //static T_scalar M2s_c0  = T_scalar(1)/( T_scalar(8)*math::constants::PHI );

            };

          }
        }
      }
    }
  }

#endif
