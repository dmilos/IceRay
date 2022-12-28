#ifndef Dh_DDMRM_Iceray_material_compute_operation_coord2d_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_coord2d_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GT_addition
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GT_load
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GT_multiply
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GT_scale
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GT_subtraction
// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GT_unit


#include "IceRay/material/compute/operation/unary.hpp"
#include "IceRay/material/compute/operation/binary.hpp"

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
           namespace S_coord2d
            {

             class GC_addition
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord;

                 T_coord   operator()( T_coord const& P_left, T_coord const& P_right )const
                  {
                   T_coord Ir_result;
                   ::math::linear::vector::addition( Ir_result, P_left, P_right );
                   return Ir_result;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GC_addition
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
               > GT_addition;
 
             class GC_load
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord;

                 T_coord   operator()( T_scalar const& P_X, T_scalar const& P_Y )const
                  {
                   T_coord Ir_result;
                   ::math::linear::vector::load( Ir_result, P_X, P_Y );
                   return Ir_result;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GC_load
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                 ,GS_DDMRM::S_IceRay::S_type::GT_scalar
               > GT_load;

             class GC_multiply
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord;

                 T_coord   operator()( T_coord const& P_left, T_coord const& P_right )const
                  {
                   T_coord Ir_result;
                   ::math::linear::vector::multiply( Ir_result, P_left, P_right );
                   return Ir_result;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GC_multiply
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
               > GT_multiply;

             class GC_scale
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord;

                 T_coord   operator()( T_scalar const& P_scale, T_coord const& P_right )const
                  {
                   T_coord Ir_result;
                   ::math::linear::vector::scale( Ir_result, P_scale, P_right );
                   return Ir_result;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GC_scale
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::GT_scalar
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
               > GT_scale;

             class GC_subtraction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord;

                 T_coord   operator()( T_coord const& P_left, T_coord const& P_right )const
                  {
                   T_coord Ir_result;
                   ::math::linear::vector::subtraction( Ir_result, P_left, P_right );
                   return Ir_result;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary
               <
                  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GC_subtraction
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
               > GT_subtraction;

             class GC_unit
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D T_coord;

                 T_coord   operator()( T_coord const& P_model )const
                  {
                   T_coord Ir_result;
                   ::math::linear::vector::unit( Ir_result, P_model );
                   return Ir_result;
                  }
              };

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary
               <
                  GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_coord2d::GC_unit
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
                 ,GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D
               > GT_unit;

            }
          }
        }
      }
    }
  }

#endif
