#ifndef Dh_DDMRM_Iceray_material_compute_operation_binary_definition_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_binary_definition_HPP_



#include "./binary.hpp"


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

           template < typename acumulator_name >
           class    A2R
           {
           public:
             typedef typename acumulator_name::result_type result_type;
             typedef typename acumulator_name::left_type left_type;
             typedef typename acumulator_name::right_type right_type;

             result_type operator()( left_type const& left, right_type const& right )
             {
               result_type result;
               acumulator_name{}( result, left, right );
               return result;
             }
           };



#define ICeRay_compute_operation_TYPEDEF_BINARY_COMPLETE( DP_name, DP_operation, DP_resultType, DP_leftType, DP_rightType ) \
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_binary< DP_operation, DP_resultType, DP_leftType, DP_rightType > DP_name


#define ICeRay_compute_operation_TYPEDEF_BINARY_IceRay( DP_name, DP_operation, DP_resultType, DP_leftType, DP_rightType ) \
  ICeRay_compute_operation_TYPEDEF_BINARY_COMPLETE \
   ( \
     DP_name, DP_operation<GS_DDMRM::S_IceRay::S_type::DP_resultType, GS_DDMRM::S_IceRay::S_type::DP_leftType, GS_DDMRM::S_IceRay::S_type::DP_rightType  > \
         ,GS_DDMRM::S_IceRay::S_type::DP_resultType                      \
         ,GS_DDMRM::S_IceRay::S_type::DP_leftType                        \
         ,GS_DDMRM::S_IceRay::S_type::DP_rightType                       \
     )


#define ICeRay_compute_operation_TYPEDEF_BINARY_std( DP_name, DP_operation, DP_resultType, DP_leftType, DP_rightType ) \
  ICeRay_compute_operation_TYPEDEF_BINARY_COMPLETE \
   ( \
     DP_name, DP_operation<GS_DDMRM::S_IceRay::S_type::DP_resultType  > \
         ,GS_DDMRM::S_IceRay::S_type::DP_resultType                      \
         ,GS_DDMRM::S_IceRay::S_type::DP_leftType                        \
         ,GS_DDMRM::S_IceRay::S_type::DP_rightType                       \
     )

           namespace S_size
            {
             ICeRay_compute_operation_TYPEDEF_BINARY_std( GT_plus,       std::plus      , GT_size, GT_size, GT_size );
             ICeRay_compute_operation_TYPEDEF_BINARY_std( GT_minus,      std::minus     , GT_size, GT_size, GT_size );
             ICeRay_compute_operation_TYPEDEF_BINARY_std( GT_multiplies, std::multiplies, GT_size, GT_size, GT_size );
             ICeRay_compute_operation_TYPEDEF_BINARY_std( GT_divides,    std::divides   , GT_size, GT_size, GT_size );
            }

           namespace S_scalar
            {
             ICeRay_compute_operation_TYPEDEF_BINARY_std( GT_plus,        std::plus      , GT_scalar, GT_scalar, GT_scalar );
             ICeRay_compute_operation_TYPEDEF_BINARY_std( GT_minus,       std::minus     , GT_scalar, GT_scalar, GT_scalar );
             ICeRay_compute_operation_TYPEDEF_BINARY_std( GT_multiplies,  std::multiplies, GT_scalar, GT_scalar, GT_scalar );
             ICeRay_compute_operation_TYPEDEF_BINARY_std( GT_divides,     std::divides   , GT_scalar, GT_scalar, GT_scalar );
            }

           namespace S_color
            {

#define ICeRay_compute_operation_TYPEDEF_BINARY_color( DP_name, DP_operation, DP_type ) \
  ICeRay_compute_operation_TYPEDEF_BINARY_COMPLETE \
   ( \
     DP_name, A2R< ::color::operation::DP_operation<GS_DDMRM::S_IceRay::S_type::S_color::DP_type::category_type> > \
         ,GS_DDMRM::S_IceRay::S_type::S_color::DP_type                      \
         ,GS_DDMRM::S_IceRay::S_type::S_color::DP_type                      \
         ,GS_DDMRM::S_IceRay::S_type::S_color::DP_type                      \
     )


             ICeRay_compute_operation_TYPEDEF_BINARY_color(    GT_plus,        _internal::addition,       GT_scalar );
             ICeRay_compute_operation_TYPEDEF_BINARY_color(    GT_minus,       _internal::subtract,       GT_scalar );
             //ICeRay_compute_operation_TYPEDEF_BINARY_color(  GT_scale,       _internal::scale,          GT_scalar );
             ICeRay_compute_operation_TYPEDEF_BINARY_color(    GT_multiplies,  _internal::multiply,       GT_scalar );
             ICeRay_compute_operation_TYPEDEF_BINARY_color(    GT_divides,     _internal::divide,         GT_scalar );
            }

           namespace S_coord2
            {
             //ICeRay_compute_operation_TYPEDEF_BINARY( GT_plus,        S_coord::GT_scalar2D, std::plus,       );
             //ICeRay_compute_operation_TYPEDEF_BINARY( GT_minus,       S_coord::GT_scalar2D, std::minus,      );
             //ICeRay_compute_operation_TYPEDEF_BINARY( GT_multiplies,  S_coord::GT_scalar2D, std::multiplies, );
             //ICeRay_compute_operation_TYPEDEF_BINARY( GT_divides,     S_coord::GT_scalar2D, std::divides,    );
            }

           namespace S_coord3
            {
             //ICeRay_compute_operation_TYPEDEF_BINARY_COMPLETE( GT_plus,      plus        , S_coord::GT_scalar3D, S_coord::GT_scalar3D, S_coord::GT_scalar3D );
             //ICeRay_compute_operation_TYPEDEF_BINARY_COMPLETE( GT_minus,     minus       , S_coord::GT_scalar3D, S_coord::GT_scalar3D, S_coord::GT_scalar3D );
             //ICeRay_compute_operation_TYPEDEF_BINARY_COMPLETE( GT_multiplies,multiplies  , S_coord::GT_scalar3D, S_coord::GT_scalar3D, S_coord::GT_scalar3D );
             //ICeRay_compute_operation_TYPEDEF_BINARY_COMPLETE( GT_divides,   divides     , S_coord::GT_scalar3D, S_coord::GT_scalar3D, S_coord::GT_scalar3D );
            }

           namespace S_coord4
            {
             //typedef GC_binary< GTs_coord4D, std::plus<       GTs_coord4D >, GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::En_coord4D >  GT_plus;
             //typedef GC_binary< GTs_coord4D, std::minus<      GTs_coord4D >, GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::En_coord4D >  GT_minus;
             //typedef GC_binary< GTs_coord4D, std::multiplies< GTs_coord4D >, GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::En_coord4D >  GT_multiplies;
             //typedef GC_binary< GTs_coord4D, std::divides<    GTs_coord4D >, GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::En_coord4D >  GT_divides;
            }

          }
        }
      }
    }
  }

#endif

