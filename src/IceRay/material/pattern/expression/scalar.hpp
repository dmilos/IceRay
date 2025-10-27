#ifndef Dh_IceRay_material_pattern_expression_scalar_hpp_
 #define Dh_IceRay_material_pattern_expression_scalar_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::S_expression::GC_scalar

#include "../_pure.hpp"


#include "IceRay/utility/expression/compiler.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {
         namespace S_expression
          {

           class GC_scalar
            : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
            {
             public:
               typedef std::string  T_string;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;

               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_compiler  T_compiler;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_program   T_program;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_memory    T_memory;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_mapper    T_mapper;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_library    T_library;

               // f(x,y,z) - no n for normal or similar things
               explicit GC_scalar( std::string const& P_expression = "X*x" )
                {
                 M2_mapper.F_tie( "X", 1 ); M2_mapper.F_tie( "x", 1 );
                 M2_mapper.F_tie( "Y", 2 ); M2_mapper.F_tie( "y", 2 );
                 M2_mapper.F_tie( "Z", 3 ); M2_mapper.F_tie( "z", 3 );

                 T_compiler I_compiler( M2_library, M2_mapper );
                 I_compiler.F_compile( M2_program, P_expression );
                 if( false == I_compiler.F_result().F_valid() )
                  {
                   //
                  }
                 M2_memory.F_apply( M2_mapper );
                 M2_program.F_memory( M2_memory );
                 M2_result = I_compiler.F_result().M_position;
                }

             public:
               void  Fv_process( T_result &P_result, T_coord const& P_coord )const
                {
                 M2_memory.F_set( 0, P_coord[0] );
                 M2_memory.F_set( 1, P_coord[1] );
                 M2_memory.F_set( 2, P_coord[2] );
                 M2_program.F_execute();
                 P_result = M2_memory.F_get( M2_result );
                }

             private:
               T_size M2_result;
               T_string  M2_expression;
               T_program M2_program;
               mutable T_memory  M2_memory;
               T_mapper  M2_mapper;
               T_library  M2_library;
           };

          }
        }
      }
    }
  }

#endif
