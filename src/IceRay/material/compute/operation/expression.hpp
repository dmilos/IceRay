#ifndef Dh_DDMRM_Iceray_material_compute_operation_expression_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_expression_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_expression
#include "IceRay/utility/expression/expression.hpp"



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

           class GC_expression
            : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_string             T_string;

               typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_program   T_program;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_memory    T_memoryExpression;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_compiler  T_compiler;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_mapper    T_mapper;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_library   T_library;

               typedef std::map< T_size, T_size  >   T2_index2index;


               enum Ee_input{  En_inScalar_LeadertValue = 0  };
               enum Ee_output{ En_outScalar_LeaderValue = 1 };

             public:
               GC_expression
               (
                 T_size const& P_outLeader
                ,T_size const& P_inLeader
               )
               {
                this->F_output<T_scalar>( En_outScalar_LeaderValue, P_outLeader );

                this->F_input<T_scalar>( En_inScalar_LeadertValue, P_inLeader );
               }

             bool F_mapper( T_size const& P_index, T_string const& P_name )
              {
               M2_mapper.F_tie( P_name, P_index ); //!< For Compiler
               return true;
              }

             bool F_mapper( T_size const& P_target, T_size const& P_source )
              {
               M2_index2index[P_target] = P_source;
               return true;
              }

             bool F_expression( T_string const& P_expression )
              {
               T_compiler I_compiler( M2_library, M2_mapper );
               I_compiler.F_compile( M2_program, P_expression );

               if( false == I_compiler.F_result().F_valid() )
                {
                 return bool( false );
                }

               M2_memoryExpression.F_apply( M2_mapper );
               M2_program.F_memory( M2_memoryExpression );

               M2_expression = P_expression;

               return true;
              }

             public:
               bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                {
                 T_size const& I_input  = this->F_input<T_scalar>( En_inScalar_LeadertValue );
                 T_size const& I_output = this->F_output<T_scalar>( En_outScalar_LeaderValue );

                 for( T_size I_index=0; I_index < M2_mapper.F_container().size(); ++I_index )
                  {
                   T_size           I_location = I_input + I_index;
                   T_scalar  const& I_value = M2_memoryScalar->Fv_load( I_location );
                   M2_memoryExpression.F_set( I_index, I_value );
                  }

                 M2_program.F_execute();

                 for( auto const& I_item: M2_index2index )
                  {
                   T_size           I_location = I_output + I_item.first;
                   T_scalar  const& I_value = M2_memoryExpression.F_get( I_item.second );
 
                   M2_memoryScalar->Fv_store( I_location, I_value );
                  }

                 return true;
                }

             private:
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>      T2_memorySize;
               typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_scalar>    T2_memoryScalar;

             public:
               void    Fv_memory( T_memory * P_memory )
                {
                 F1_memory() = P_memory;
                 M2_memorySize   = P_memory->F_get<T_size>();
                 M2_memoryScalar = P_memory->F_get<T_scalar>();
                }

             private:
               T2_index2index M2_index2index;
               T_library  M2_library;
               T_mapper   M2_mapper;
               T_program  M2_program;
               T_string   M2_expression;

               mutable T_memoryExpression  M2_memoryExpression;

               T2_memorySize     *M2_memorySize;
               T2_memoryScalar   *M2_memoryScalar;
              };


          }
        }
      }
    }
  }

#endif
