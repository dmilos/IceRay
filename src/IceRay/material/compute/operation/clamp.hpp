#ifndef Dh_DDMRM_Iceray_material_compute_clamp_HPP_
 #define Dh_DDMRM_Iceray_material_compute_clamp_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_clamp::GT_ramp
// GS_DDMRM::S_IceRay::S_material::S_compute::S_clamp::GT_saw
// GS_DDMRM::S_IceRay::S_material::S_compute::S_clamp::GT_wave


#include "IceRay/material/compute/operation/unary.hpp"
#include "IceRay/utility/clamp.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_clamp
          {

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_clamp::GC_ramp
               ,GS_DDMRM::S_IceRay::S_type::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::GT_scalar
             > GT_ramp;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_clamp::GC_saw
               ,GS_DDMRM::S_IceRay::S_type::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::GT_scalar
             > GT_saw;

           typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
             <
                GS_DDMRM::S_IceRay::S_utility::S_clamp::GC_wave
               ,GS_DDMRM::S_IceRay::S_type::GT_scalar
               ,GS_DDMRM::S_IceRay::S_type::GT_scalar
             > GT_wave;

         }
        }
      }
    }
  }

#endif
