#ifndef Dh_DDMRM_Iceray_utility_expression_compiler_HPP_
 #define Dh_DDMRM_Iceray_utility_expression_compiler_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_expression::GC_compiler

#include <map>
#include <set>
#include "math/math.hpp"

#include "IceRay/type/basic/scalar.hpp"
#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/basic/string.hpp"

#include "./program.hpp"
#include "./mapper.hpp"
#include "./library.hpp"
#include "./address.hpp"




namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

        class GC_compiler
         {
          public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
            typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
            typedef GS_DDMRM::S_IceRay::S_type::GT_string T_string;
            
            typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_program   T_program;
            typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_mapper    T_mapper;
            typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_library   T_library;
            typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_address   T_address;

          public:
            GC_compiler( T_library const& P_library, T_mapper  & P_mapper );

          public:
            T_address const& F_result( )const;
          private:
            T_address M2_result;
          public:
            bool F_compile( T_program & P_program, T_string const& P_expression );
          private:
            T_library  const& M2_library;
            T_mapper        & M2_mapper;
            T_program      * M2_program;    //!< temproal common;
            T_string  const* M2_expression; //!< temproal common;

            T_address F2_expression( T_size const& P_begin, T_size const& P_end );
            T_address F2_constant( T_size const& P_begin, T_size const& P_end );
            T_address F2_variable( T_size const& P_begin, T_size const& P_end );
            T_address F2_binary( std::set<T_string> const& P_set, T_size const& P_begin, T_size const& P_end );
            T_address F2_function(T_size const& P_begin, T_size const& P_end);

            void F2_trimspace( T_size & P_begin, T_size & P_end ) const;
        };

       }
     }
   }
 }

#endif
