#ifndef Dh_IceRay_material_pattern_image_hpp_
 #define Dh_IceRay_material_pattern_image_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_image

#include "./_pure.hpp"

#include "../../type/basic/scalar.hpp"
#include "../../type/color.hpp"
#include "../../type/math/coord.hpp"
#include "../../type/picture/_pure.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_image
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color
          {// DONE. Alg for tile is separate thing. Use Cllipers.
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                  T_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure      T_image;

             GC_image( T_image * P_image = nullptr )
              : M2_image( P_image )
              {
              }

           public:
             void  Fv_process( T_result &P_result, T_coord const& P_coord )const
              {
               auto xF = ::math::function::saw( P_coord[0] );
               auto yF = ::math::function::saw( P_coord[1] );

               auto x = T_size( xF *M2_image->F_size()[0] );
               auto y = T_size( yF *M2_image->F_size()[1] );

               P_result = M2_image->Fv_data()[ y* M2_image->F_size()[0] + x ];
              }

           private:
             T_image *M2_image;
          };

        }
      }
    }
  }

#endif
