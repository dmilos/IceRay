#ifndef Dh_IceRay_material_pattern_noise_VDC_hpp_
 #define Dh_IceRay_material_pattern_noise_VDC_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_noise_VDC

#include "../_pure.hpp"

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

           class GC_VDC
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_material::S_pattern::S_type::GT_coord3D T_coord;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;


               GC_VDC()
                {
                }

               ~GC_VDC()
                {
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 P_result = M2_randVDC.next();
                }
              mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_vdc2          M2_randVDC;
            };

          }
        }
      }
    }
  }

#endif
