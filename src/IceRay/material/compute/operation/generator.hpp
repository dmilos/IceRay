#ifndef Dh_DDMRM_Iceray_material_compute_operation_generator_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_generator_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_generator< operation_name, result_name >

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
             >
             class GC_generator
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef operation_name    T_operation;
                 typedef result_name       T_result;

                 typedef GS_DDMRM::S_IceRay::S_type::GT_bool T_bool;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction   T_instruction;

                 enum Ee_output{ En_outTYPE_ResultValue = 1 };
                 enum Ee_input{   };

               public:
                 GC_generator
                  (
                    T_size const& P_outType_result = 0
                  )
                  {
                   this-> template F_output<T_result>(  En_outTYPE_ResultValue,  P_outType_result );
                  }

                 GC_generator
                  (
                    T_operation const& P_operation
                   ,T_size      const& P_outType_result = 0
                  ) : M2_operation( P_operation )
                  {
                   this->template F_output<T_result>( En_outTYPE_ResultValue,  P_outType_result );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {

                   T_result I_result = M2_operation( );

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
               public:
                 void    Fv_memory( T_memory * P_memory )
                  {
                   F1_memory() = P_memory;
                   M2_memoryResult  = dynamic_cast<T2_memoryResult* >( F1_memory()->template F_get<T_result>() );
                  }

               private:
                 T2_memoryResult    *M2_memoryResult;
              };

          }
        }
      }
    }
  }

#endif

