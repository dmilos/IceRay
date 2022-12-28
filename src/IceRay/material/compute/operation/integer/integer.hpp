#ifndef Dh_DDMRM_Iceray_material_compute_operation_integer_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_integer_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_integer::GT_addition
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_integer::GT_multiply
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_integer::GT_subtraction


#include "IceRay/material/compute/operation/unary.hpp"
#include "IceRay/material/compute/operation/binary.hpp"
#include "IceRay/material/compute/operation/ternary.hpp"

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
           namespace S_integer
            {

             class GC_addition
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;

                 T_scalar   operator()( T_scalar const& P_left, T_scalar const& P_right )const
                  {
                   return P_left + P_right;
                  }
              };
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
              <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_integer::GC_addition
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
              > GT_addition;

             class GC_multiply
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;

                 T_scalar   operator()( T_scalar const& P_left, T_scalar const& P_right )const
                  {
                   return P_left * P_right;
                  }
              };
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
              <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_integer::GC_multiply
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
              > GT_multiply;

             class GC_subtraction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;

                 T_scalar   operator()( T_scalar const& P_left, T_scalar const& P_right )const
                  {
                   return P_left - P_right;
                  }
              };
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
              <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_integer::GC_subtraction
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
              > GT_subtraction;

             class GC_divide
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;

                 T_scalar   operator()( T_scalar const& P_left, T_scalar const& P_right )const
                  {
                   return P_left / P_right;
                  }
              };
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
              <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_integer::GC_divide
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
              > GT_divide;

            }
          }
        }
      }
    }
  }

#endif

