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
             typedef int   T_address;
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
             typedef void (*T_vector4)( T_scalar *, T_scalar *, T_scalar *, T_scalar * );
             typedef void (*T_vector5)( T_scalar *, T_scalar *, T_scalar *, T_scalar *, T_scalar * );


           public:
             GC_instruction( );
             GC_instruction( T_function0 const& P_func0, T_address const& P_0 );
             GC_instruction( T_function1 const& P_func1, T_address const& P_0, T_address const& P_1 );
             GC_instruction( T_function2 const& P_func2, T_address const& P_0, T_address const& P_1, T_address const& P_2 );
             GC_instruction( T_function3 const& P_func3, T_address const& P_0, T_address const& P_1, T_address const& P_2, T_address const& P_3 );
             GC_instruction( T_function4 const& P_func4, T_address const& P_0, T_address const& P_1, T_address const& P_2, T_address const& P_3, T_address const& P_4 );

             bool F_memory( T_memory & P_memory );
             bool F_address( T_address const& P_0, T_address const& P_1 =-1, T_address const& P_2=-1, T_address const& P_3=-1, T_address const& P_4=-1 );
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
             T_vector4  M2_vector4;
             T_vector5  M2_vector5;

             int M_type;
             std::array< T_address, 5 > M2_address;
          };

        }
      }
    }
  }

#endif
