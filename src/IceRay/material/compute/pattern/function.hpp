#ifndef Dh_DDMRM_Iceray_material_compute_pattern_function_HPP_
 #define Dh_DDMRM_Iceray_material_compute_pattern_function_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::GC_function<type>

 #include "../../pattern/_pure.hpp"

 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_pattern
          {

           template< typename type_type >
             class GC_function
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef type_type T_type;


                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 typedef GS_DDMRM::S_IceRay::S_material::S_pattern::GC__pure<T_type> T_pattern;

                 enum Ee_input{ En_inCoord_Point   = 0};
                 enum Ee_output{ En_outType_ResultValue = 0 };

               public:
                 explicit GC_function
                  (
                    T_pattern * P_pattern               = nullptr
                   ,T_size const& P_inCoord_Point       = 0
                   ,T_size const& P_outTYPE_ResultValue = 0
                  )
                 :M2_pattern( P_pattern )
                  {
                   this->F_input<T_coord>( En_inCoord_Point,       P_inCoord_Point );
                   this->F_output<T_type>( En_outType_ResultValue, P_outTYPE_ResultValue );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_coord const& I_point= M2_memoryCoord->Fv_load( this->F_input<T_coord>( En_inCoord_Point ) );
                   T_type I_result;

                   M2_pattern->Fv_process( I_result, I_point );

                   M2_memoryTYPE->Fv_store( this->F_output<T_type>(En_outType_ResultValue), I_result );
                   return true;
                  }

               private:
                 T_pattern *M2_pattern;

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord>   T2_memoryCoord;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_type >   T2_memoryTYPE;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memoryCoord  = dynamic_cast<T2_memoryCoord* >( P_memory->F_get<T_coord>() );
                   M2_memoryTYPE   = dynamic_cast<T2_memoryTYPE* >( P_memory->F_get<T_type>() );
                  }

               private:
                 T2_memoryCoord    *M2_memoryCoord;
                 T2_memoryTYPE     *M2_memoryTYPE;

             };

             typedef GC_function< GS_DDMRM::S_IceRay::S_type::GT_size >            GT_functionSize;
             typedef GC_function< GS_DDMRM::S_IceRay::S_type::GT_scalar >          GT_functionScalar;
             typedef GC_function< GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar > GT_functionColor;
             typedef GC_function< GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar > GT_functionCoord3D;

          }
        }
      }
    }
  }

#endif
