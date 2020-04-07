#ifndef Dh_IceRay_material_illumination_ambinet_hpp_
 #define Dh_IceRay_material_illumination_ambinet_hpp_

#include "../../type/color.hpp"

 namespace  GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_illumination
        {

         class GC_ambient
          //: public S_IceRay::S_material::S_illumination::GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;

           public:
             GC_ambient( T_color const&  P_color )
              : M2_color ( P_color )
              {
              }

           public:
             bool F_process( T_color & P_result )
              {
               P_result = M2_color;
               return true;
              }

           private:
             T_color const& M2_color;
          };

        }
      }
    }
  }

#endif
