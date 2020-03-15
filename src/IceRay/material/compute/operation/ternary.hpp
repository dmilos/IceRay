#ifndef Dh_DDMRM_Iceray_material_compute_operation_ternary_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_ternary_HPP_



 #include "../instruction.hpp"
#include <functional>


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
              ,typename result_type_name
              ,typename   left_type_name
              ,typename  middle_type_name
              ,typename  right_type_name
             >
            class GC_ternary
             : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
             {
              public:
                typedef result_type_name   T_typeResult;
                typedef   left_type_name   T_typeLeft;
                typedef middle_type_name   T_typeMiddle;
                typedef  right_type_name   T_typeRight;

                typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                enum Ee_input{  En_inTYPE_LeftValue   = 0
                                En_inTYPE_MiddleValue = 1
                                En_inTYPE_RightValue  = 2 };
                enum Ee_output{ En_outTYPE_ResultValue= 3 };

              public:
                GC_ternary
                (
                  T_size const& P_inType_left    = 0
                 ,T_size const& P_inType_right   = 1
                 ,T_size const& P_inType_middle  = 2
                 ,T_size const& P_outType_result = 3
                )
                {
                 F_input<T_typeLeft>(   En_inTYPE_LeftValue,   P_inType_left   );
                 F_input<T_typeMiddle>( En_inTYPE_MiddleValue, P_inType_middle );
                 F_input<T_typeRight>(  En_inTYPE_RightValue,  P_inType_right  );

                 F_output<T_typeRight>( En_outTYPE_ResultValue,  P_outType_result );
                }

              public:
                bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                 {
                  T_typeLeft   const& I_left   = M2_memoryLeft->Fv_load(  this->template F_input<T_typeLeft>(En_inTYPE_LeftValue)   );
                  T_typeMiddle const& I_middle = M2_memoryRight->Fv_load( this->template F_input<T_typeMiddle>(En_inTYPE_MiddleValue) );
                  T_typeRight  const& I_right  = M2_memoryRight->Fv_load( this->template F_input<T_typeRight>(En_inTYPE_RightValue) );
                  T_typeResult I_result = operation_name()( I_left, I_middle, I_right );
                  M2_memoryResult->Fv_store( this->template F_output<T_typeResult>()[ En_outTYPE_ResultValue ], I_result );

                  return true;
                 }

              private:
                typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_typeResult >  T2_memoryResult;
                typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_typeLeft   >  T2_memoryLeft  ;
                typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_typeMiddle >  T2_memoryMiddle  ;
                typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_typeRight  >  T2_memoryRight ;
              public:
                void    Fv_memory( T_memory * P_memory )
                 {
                  F1_memory() = P_memory;
                  M2_memoryResult  = dynamic_cast<T2_memoryResult* >( F1_memory()->template F_get<T_typeResult >() );
                  M2_memoryMiddle  = dynamic_cast<T2_memoryMiddle* >( F1_memory()->template F_get<T_typeMiddle >() );
                  M2_memoryLeft    = dynamic_cast<T2_memoryLeft  * >( F1_memory()->template F_get<T_typeLeft   >() );
                  M2_memoryRight   = dynamic_cast<T2_memoryRight * >( F1_memory()->template F_get<T_typeRight  >() );
                 }

              private:
                T2_memoryResult    *M2_memoryResult;
                T2_memoryLeft      *M2_memoryLeft;
                T2_memoryMiddle    *M2_memoryMiddle;
                T2_memoryRight     *M2_memoryRight;
             };

          }
        }
      }
    }
  }

#endif

