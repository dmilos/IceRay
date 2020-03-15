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

          class GC_expression
           {  // form: var1=function(var1|const,var2|const, ); a=a+b+c; x = -x; ...
            public:
            typedef std::string  T_string;

            typedef T_scalar (*T_function0)( );
            typedef T_scalar (*T_function1)( T_scalar const& p1);
            typedef T_scalar (*T_function2)( T_scalar const& p1, T_scalar const& p2 );
            typedef T_scalar (*T_function3)( T_scalar const& p1, T_scalar const& p2, T_scalar const& p3);
            typedef T_scalar (*T_function4)( T_scalar const& p1, T_scalar const& p2, T_scalar const& p3, T_scalar const& p4);

            struct C_operation
             {
              T_size M_length;

              T_function0 M_pointer0;
              T_function1 M_pointer1;
              T_function2 M_pointer2;
              T_function3 M_pointer3;
              T_function4 M_pointer4;
             };

            typedef std::vector< C_operation > T_program;

            typedef std::map< T_string, T_scalar > T_memory;
            typedef std::map< T_string, T_scalar > T_memory;

            void F_set( T_size const& P_index, T_scalar const& P_value )
             {


             }

            void F_set( T_string const& P_name, T_scalar const& P_value )
             {


             }


            T_scalar F_execute()
             {


             }

            bool F_compile( T_string const& P_expression )
             {
              T_size I_index=0;
              T_size I_next=0;
              do
               {
                if( false == F2_getStatement( P_expression, I_next ) ) return false;
                F2_white( P_expression, I_next );
               }
              while( I_next < P_expression.size() );

              return true;
             }

            bool F2_getStatement( T_string const& P_expression, T_size & P_index )
             {
              T_size I_begin = P_index;

              if( false == F2_name( P_expression, P_index ) ){ P_index = I_begin; return false; }
              F2_white( P_expression, P_index );
              if( false == F2_character( P_expression, '=' ) ){ P_index = I_begin; return false; }

              if( false == F2_expression(P_expression, P_index ) ){ P_index = I_begin; return false; }

              if( false == F2_character( P_expression, ';' ) ){ P_index = I_begin; return false; }

              return true;
             }

            bool F2_assign( T_string const& P_expression, T_size & P_index )
             {
              return false;
             }

            bool F2_name( T_string const& P_expression, T_size & P_index )
             {
              return false;
             }

            bool F2_character( T_string const& P_expression, T_char const & P_char )
             {
              return false;
             }

            void F2_white( T_string const& P_expression, T_size & P_index )
             {

             }


           };


      }
    }
  }

#endif
