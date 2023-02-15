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

           template
             <
               typename operation_name
              ,typename result_name
              ,typename input_name
             >
             class GC_unary
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef operation_name    T_operation;
                 typedef result_name       T_result;
                 typedef input_name        T_input;

                 //typedef GS_DDMRM::S_IceRay::S_type::GT_bool T_bool;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 //typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction   T_instruction;

                 enum Ee_output{ En_outTYPE_ResultValue = 0 };
                 enum Ee_input{  En_inTYPE_LeftValue    = 01 };

               public:
                 GC_unary
                  (
                    T_size const& P_outType_result = 0
                   ,T_size const& P_inType_left    = 1
                  )
                  {
                   this-> template F_output<T_result>(  En_outTYPE_ResultValue,  P_outType_result );

                   this-> template F_input<T_input>(    En_inTYPE_LeftValue,     P_inType_left    );
                  }

                 GC_unary
                  (
                    T_operation const& P_operation
                   ,T_size      const& P_outType_result = 0
                   ,T_size      const& P_inType_left    = 1
                  ): M2_operation( P_operation )
                  {
                   this->template F_output<T_result>( En_outTYPE_ResultValue,  P_outType_result );

                   this-> template F_input<T_input>(    En_inTYPE_LeftValue,     P_inType_left    );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_input const& I_left  = M2_memoryInput->Fv_load( this->template F_input<T_input>(En_inTYPE_LeftValue) );

                   T_result I_result = M2_operation( I_left );

                   M2_memoryResult->Fv_store( this->template F_output<T_result>(En_outTYPE_ResultValue), I_result );

                   return true;
                  }

               public:
                 T_operation const& F_operation()const{ return M2_operation; }
                 T_operation      & F_operation()     { return M2_operation; }
               private:
                 T_operation M2_operation;

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_result >  T2_memoryResult;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_input >   T2_memoryInput;
               public:
                 void    Fv_memory( T_memory * P_memory )
                  {
                   F1_memory() = P_memory;
                   M2_memoryResult  = F1_memory()->template F_get<T_result>();
                   M2_memoryInput   = F1_memory()->template F_get<T_input>() ;
                  }

               private:
                 T2_memoryResult    *M2_memoryResult;
                 T2_memoryInput     *M2_memoryInput;
              };

          }
        }
      }
    }
  }

#endif

