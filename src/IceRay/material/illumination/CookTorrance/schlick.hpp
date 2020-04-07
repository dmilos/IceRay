#ifndef Dh_IceRay_material_illumination_CookTorrance_Schlick_hpp_
 #define Dh_IceRay_material_illumination_CookTorrance_Schlick_hpp_

 namespace S_IceRay
  {
   namespace S_material
    {
     namespace S_illumination
      {
       namespace S_CookTorrance
        {

         struct GC_schlick
          //: public S_IceRay::S_material::S_illumination::GC__pure
          {
           public:
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

           public:
             GC_schlick( )
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