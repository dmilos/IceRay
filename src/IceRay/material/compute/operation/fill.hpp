#ifndef Dh_DDMRM_Iceray_material_compute_operation_fill_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_fill_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_fill< result_name, size >

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
               typename value_name
             >
             class GC_fill/*  GC_fillGenerator */
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef value_name       T_value;

                 typedef GS_DDMRM::S_IceRay::S_type::GT_bool T_bool;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction   T_instruction;

                 enum Ee_output{ En_outTYPE_ResultValue = 1 };
                 enum Ee_input{  };

               public:
                 GC_fill
                  (
                    T_size  const& P_outLeader
                   ,T_value const& P_value
                   ,T_size  const& P_size
                  )
                  {
                   M2_size  = P_size;
                   M2_value = P_value;
                   this->template F_output<T_value>( En_outTYPE_ResultValue, P_outLeader );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_size const& I_leader = this->template F_output<T_value>( En_outTYPE_ResultValue );

                   for( T_size I_index=0; I_index< F_size(); ++I_index )
                    {
                     M2_memoryResult->Fv_store( I_leader + I_index, F_value() );
                    }
                   return true;
                  }

               public:
                 T_size const& F_size()const{ return M2_size; }
                 T_size      & F_size()     { return M2_size; }
               private:
                 T_size M2_size;
                 
               public:
                 T_value const& F_value()const{ return M2_value; }
                 T_value      & F_value()     { return M2_value; }
               private:
                 T_value M2_value;

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_value >  T2_memoryResult;
               public:
                 void    Fv_memory( T_memory * P_memory )
                  {
                   F1_memory() = P_memory;
                   M2_memoryResult  = dynamic_cast<T2_memoryResult* >( F1_memory()->template F_get<T_value>() );
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

