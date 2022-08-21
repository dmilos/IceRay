#ifndef Dh_IceRay_material_pattern_noise_gold_hpp_
 #define Dh_IceRay_material_pattern_noise_gold_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_noise_gold

#include "../_pure.hpp"

#include <iostream>
#include <iomanip>

#include "IceRay/utility/random.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {
         namespace S_noise
          {

           class GC_gold
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_gold()
                {
                }

               ~GC_gold()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 P_result = M2_randGold1D.next();
                }
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GC_gold1D        M2_randGold1D;
             };

          }
        }
      }
    }
  }

#endif
