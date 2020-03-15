    #ifndef Dh_DDMRM_Iceray_utility_operation_HPP_
 #define Dh_DDMRM_Iceray_utility_operation_HPP_

//  GS_DDMRM::S_IceRay::S_utility::S_operation::GC_plus
//  GS_DDMRM::S_IceRay::S_utility::S_operation::GC_minus
//  GS_DDMRM::S_IceRay::S_utility::S_operation::GC_product
//  GS_DDMRM::S_IceRay::S_utility::S_operation::GC_division

 #include "IceRay/type/basic/basic.hpp"
 #include "IceRay/type/color.hpp"
 #include "IceRay/type/math/coord.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_operation
        {

         template < typename N_result, typename N_left, typename N_right >
          struct GC_plus
           {
            typedef N_result  T_result;
            typedef N_left    T_left;
            typedef N_right   T_right;

            T_result operator()( T_left const& P_left, T_right const& P_right )const
             {
              return T_result( P_left + P_right );
             }
           };

         template < typename N_result, typename N_left, typename N_right >
          struct GC_minus
           {
            typedef N_result  T_result;
            typedef N_left    T_left;
            typedef N_right   T_right;

            T_result operator()( T_left const& P_left, T_right const& P_right )const
             {
              return T_result( P_left - P_right );
             }
           };

         template < typename N_result, typename N_left, typename N_right >
          struct GC_multiplies
           {
            typedef N_result  T_result;
            typedef N_left    T_left;
            typedef N_right   T_right;

            T_result operator()( T_left const& P_left, T_right const& P_right )const
             {
              return T_result( P_left * P_right );
             }
           };

         template < typename N_result, typename N_left, typename N_right >
          struct GC_division
           {
            typedef N_result  T_result;
            typedef N_left    T_left;
            typedef N_right   T_right;

            T_result operator()( T_left const& P_left, T_right const& P_right )const
             {
              return T_result( P_left / P_right );
             }
           };

        }
      }
    }
  }

#endif
