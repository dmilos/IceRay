#ifndef Dh_IceRay_material_pattern_noise_random_hpp_
 #define Dh_IceRay_material_pattern_noise_random_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_noise_random

#include "../_pure.hpp"

#include <iostream>
#include <iomanip>





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

           class GC_random
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_random()
                {
                }

               ~GC_random()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 P_result = rand()/ (T_scalar)RAND_MAX;
                }

            };

           }
        }
      }
    }
  }

#endif
