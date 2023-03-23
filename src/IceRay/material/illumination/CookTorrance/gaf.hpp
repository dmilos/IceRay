#ifndef Dh_IceRay_material_illumination_CookTorrance_GAF_hpp_
 #define Dh_IceRay_material_illumination_CookTorrance_GAF_hpp_

// GS_DDMRM::S_IceRay::S_material::S_illumination::S_CookTorrance::GC_GAF

 namespace  GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_illumination
        {
         namespace S_CookTorrance
          {

         class GC_GAF
          //: public S_IceRay::S_material::S_illumination::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

           public:
             GC_GAF( )
              {
              }

           public:
             T_scalar F_process
              (
               T_scalar const&  P_nh,
               T_scalar const&  P_nv,
               T_scalar const&  P_vh,
               T_scalar const&  P_nl
              )
              {
               T_scalar I_1 = 1;
               T_scalar I_2 = T_scalar(2) * P_nh * P_nv / P_vh;
               T_scalar I_3 = T_scalar(2) * P_nh * P_nl / P_vh;
               return std::min<T_scalar>( I_1, std::min<T_scalar>( I_2, I_3 ) );
              }

             T_scalar F_process
              (
               T_coord const&  P_2light,
               T_coord const&  P_normal,
               T_coord const&  P_2viewer,
               T_coord const&  P_half
              )
              {
               T_scalar I_nh =  ::math::linear::vector::dot( P_normal, P_half    );
               T_scalar I_nv =  ::math::linear::vector::dot( P_normal, P_2viewer );
               T_scalar I_vh =  ::math::linear::vector::dot( P_2viewer, P_half   );
               T_scalar I_nl =  ::math::linear::vector::dot( P_normal, P_2light  );

               return F_process( I_nh, I_nv, I_vh, I_nl );
              }
          };

          }
        }
      }
    }
  }

#endif
