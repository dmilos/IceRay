#ifndef Dh_DDMRM_Iceray_material_compute_clamp_HPP_
 #define Dh_DDMRM_Iceray_material_compute_clamp_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_ramp
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_saw
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_wave
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_sinkhole
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_clamp::GT_relu

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
         namespace S_operation
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

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
               <
                  GS_DDMRM::S_IceRay::S_utility::S_clamp::GC_sinkhole
                 ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                 ,GS_DDMRM::S_IceRay::S_type::GT_scalar
               > GT_sinkhole;

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
               <
                  GS_DDMRM::S_IceRay::S_utility::S_clamp::GC_relu
                 ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                 ,GS_DDMRM::S_IceRay::S_type::GT_scalar
               > GT_relu;

            }
          }
        }
      }
    }
  }

#endif
