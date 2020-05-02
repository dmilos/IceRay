#ifndef Dh_DDMRM_Iceray_material_compute_operation_switch_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_switch_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_switch<type>

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
           namespace S_switch
            {

             template< typename type_name >
              class GC__model
               : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
               {
                public:
                  typedef type_name    T_type;

                  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                  enum Ee_input{  En_inSize_Value = 0, En_inTYPE_StartCandidate = 2 };
                  enum Ee_output{ En_outTYPE_ResultValue = 1 };

                public:
                  GC__model
                  (
                    T_size const& P_outResult           = 0
                   ,T_size const& P_inValue             = 1 // !< index in candidate list. Do not care for length
                   ,T_size const& P_inCandidateStart    = 2
                  )
                  {
                   this->F_output<T_type>( En_outTYPE_ResultValue,  P_outResult );

                   this->F_input<T_size>(  En_inSize_Value,           P_inValue          );
                   this->F_input<T_type>( En_inTYPE_StartCandidate,   P_inCandidateStart );
                  }

                public:
                  bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                   {
                    T_size const& I_index  = M2_memorySize->Fv_load( this->F_input<T_size>(En_inSize_Value) );
                    T_type const& I_result = M2_memoryTYPE->Fv_load( this->F_input<T_type>(En_inTYPE_StartCandidate) + I_index );

                    M2_memoryTYPE->Fv_store( this->F_output<T_type>(En_outTYPE_ResultValue), I_result );
                    return true;
                   }

                private:
                  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>    T2_memorySize;
                  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base< T_type >  T2_memoryTYPE;

                public:
                  void    Fv_memory( T_memory * P_memory )
                   {
                    F1_memory() = P_memory;
                    M2_memorySize  = dynamic_cast<T2_memorySize* >( P_memory->template F_get<T_size>() );
                    M2_memoryTYPE  = dynamic_cast<T2_memoryTYPE* >( P_memory->template F_get<T_type>() );
                   }

                private:
                  T2_memorySize     *M2_memorySize;
                  T2_memoryTYPE     *M2_memoryTYPE;
               };

            typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GC__model< GS_DDMRM::S_IceRay::S_type::GT_size              > GT_size;
            typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar            > GT_scalar;
            typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GC__model< GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar   > GT_color;
            typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D > GT_coord2D;
            typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D > GT_coord3D;

          //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D > GT_Cell2D;
          //typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_switch::GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D > GT_Cell3D;

            }
          }
        }
      }
    }
  }

#endif

