#ifndef Dh_DDMRM_Iceray_material_compute_operation_color_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_color_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_addition
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_load
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_multiply
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_scale
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GT_subtraction


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
           namespace S_color
            {

             class GC_addition
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_color;

                 T_color   operator()( T_color const& P_left, T_color const& P_right )const
                  {
                   return P_left + P_right;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GC_addition
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
               > GT_addition;

             class GC_load
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_color;

                 T_color   operator()( T_scalar const& P_r, T_scalar const& P_g, T_scalar const& P_b )const
                  {
                   T_color Ir_result;
                   Ir_result.container( { P_r, P_g, P_b } );
                   return Ir_result;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_ternary
               <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GC_load
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
               > GT_load;

             class GC_multiply
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_color;

                 T_color   operator()( T_color const& P_left, T_color const& P_right )const
                  {
                    T_color Ir_result;
                   ::color::operation::multiply( Ir_result, P_left, P_right );

                   return Ir_result;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GC_multiply
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
               > GT_multiply;

             class GC_scale
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_color;
               public:
                 T_color   operator()( T_scalar const& P_scale, T_color const& P_right )const
                  {
                   return P_scale * P_right;
                  }
              };
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GC_scale
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
               > GT_scale;

             class GC_subtraction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_color;

                 T_color   operator()( T_color const& P_left, T_color const& P_right )const
                  {
                   return P_left - P_right;
                  }
              };
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                 GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_color::GC_subtraction
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
                ,GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar
               > GT_subtraction;

            }
          }
        }
      }
    }
  }

#endif

