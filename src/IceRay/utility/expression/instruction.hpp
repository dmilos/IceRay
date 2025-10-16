#ifndef Dh_DDMRM_Iceray_utility_expression_instruction_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_instruction_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_expression::GC_instruction

#include "math/math.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "./memory.hpp"





 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_expression
        {

         class GC_instruction
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
             typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_memory T_memory;

             typedef T_scalar (*T_function0)( );
             typedef T_scalar (*T_function1)( T_scalar const& p1);
             typedef T_scalar (*T_function2)( T_scalar const& p1, T_scalar const& p2 );
             typedef T_scalar (*T_function3)( T_scalar const& p1, T_scalar const& p2, T_scalar const& p3);
             typedef T_scalar (*T_function4)( T_scalar const& p1, T_scalar const& p2, T_scalar const& p3, T_scalar const& p4);

             typedef void (*T_vector1)( T_scalar *  ) ;
             typedef void (*T_vector2)( T_scalar *, T_scalar * ) ;
             typedef void (*T_vector3)( T_scalar *, T_scalar *, T_scalar * );

             bool F_memory( T_memory & P_memory );
             void F_execute( )const;

             T_scalar   *M2_data;

             T_function0  M2_scalar0;
             T_function1  M2_scalar1;
             T_function2  M2_scalar2;
             T_function3  M2_scalar3;
             T_function4  M2_scalar4;

             T_vector1  M2_vector1;
             T_vector2  M2_vector2;
             T_vector3  M2_vector3;

             int M_type;
             std::array< T_size, 4 > M2_index;
             std::array< T_size, 4 > M2_pointer;
          };

        }
      }
    }
  }

#endif
