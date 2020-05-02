#ifndef Dh_DDMRM_Iceray_material_compute_operation_unary_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_unary_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_unary< operation_name, result_name, input_name  >

 #include "../instruction.hpp"



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

            template< typename operation_name, typename result_name, typename input_name  >
             class GC_unary
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef result_name   T_result;
                 typedef input_name    T_input;

                 typedef GS_DDMRM::S_IceRay::S_type::GT_bool T_bool;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction   T_instruction;

                 enum Ee_output{ En_outTYPE_ResultValue = 1 };
                 enum Ee_input{  En_inTYPE_LeftValue    = 0 };

               public:
                 GC_unary
                 (
                   T_size const& P_outType_result = 0
                  ,T_size const& P_inType_left    = 0
                 )
                 {
                  this-> template F_output<T_result>(  En_outTYPE_ResultValue,  P_outType_result );

                  this-> template F_input<T_input>(    En_inTYPE_LeftValue,     P_inType_left  );
                 }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_input const& I_left  = M2_memory_Input->Fv_load( this->template F_input<T_input>(En_inTYPE_LeftValue) );
                   T_result I_result = operation_name()( I_left );
                   M2_memory_Result->Fv_store( this->template F_output<T_result>(En_outTYPE_ResultValue), I_result );

                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_result >  T2_memory_Result;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_input >   T2_memory_Input;
               public:
                 void    Fv_memory( T_memory * P_memory )
                  {
                   F1_memory() = P_memory;
                   M2_memory_Result  = dynamic_cast<T2_memory_Result* >( F1_memory()->template F_get<T_result>() );
                   M2_memory_Input   = dynamic_cast<T2_memory_Input* >(  F1_memory()->template F_get<T_input>()  );
                  }

               private:
                 T2_memory_Result    *M2_memory_Result;
                 T2_memory_Input     *M2_memory_Input;
              };

          }
        }
      }
    }
  }

#endif

