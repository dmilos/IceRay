#ifndef Dh_IceRay_material_illumination_CookTorranceFresnel_hpp_
 #define Dh_IceRay_material_illumination_CookTorranceFresnel_hpp_

 namespace S_IceRay
  {
   namespace S_material
    {
     namespace S_illumination
      {
       namespace S_CookTorranceFresnel
        {

         struct GC_data
          : public S_IceRay::S_material::S_illumination::S__base::GC_data
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

           public:
             GC_data( )
              {
              }

           public:
             bool F_process
              (
               T_color      &  P_result,
               T_color const&  P_light,
               T_coord const&  P_reflected,
               T_coord const&  P_viewer
               )
               {
                // TODO
                return true;
               }
           public:
              T_color M_lambda;
          };

        }
      }
    }
  }

#endif