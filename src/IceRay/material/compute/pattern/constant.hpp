#ifndef Dh_DDMRM_Iceray_material_compute_constant_HPP_
 #define Dh_DDMRM_Iceray_material_compute_constant_HPP_

//GS_DDMRM::S_IceRay::S_material::S_compute::S_pattern::GC_constant< type >

 #include "../instruction.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_constant
          {

           template< typename N_type >
            class GC__model
             : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
             {
              public:

                typedef N_type         T_type;
                typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                enum Ee_output{ En_outTYPE_Result = 0 };

              public:
                explicit GC__model
                 (
                   T_type  const& P_value  = T_type{}
                  ,T_size  const& P_result = 0
                 )
                 : M2_value( P_value )
                 {
                  this->F_output<T_type>( En_outTYPE_Result, P_result );
                 }

              public:
                bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                 {
                  M2_memoryTYPE->Fv_store( this->F_output<T_type>( En_outTYPE_Result ), M2_value );
                  return true;
                 }

              public:
                T_type    const& F_value()const{ return M2_value; }
                bool              F_value( T_type const& P_value ){ M2_value = P_value; return bool( true ); }
              protected:
                T_type        & F1_value(){ return M2_value; }
              private:
                T_type M2_value;

              private:
                  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_type>  T2_memoryTYPE;
              public:
                void    Fv_memory( T_memory * P_memory  )
                 {
                  F1_memory() = P_memory;
                  M2_memoryTYPE  = dynamic_cast<T2_memoryTYPE* >( P_memory->F_get<T_type>( ) );
                 }

              private:
                T2_memoryTYPE    *M2_memoryTYPE;
            };

           typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_size       > GT_size;
           typedef GC__model< GS_DDMRM::S_IceRay::S_type::GT_scalar     > GT_scalar;
           
           typedef GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  > GT_coord2D;
           typedef GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  > GT_coord3D;
           typedef GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D  > GT_coord4D;
           
           typedef GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D  > GT_cell2D, GT_size2D;
           typedef GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D  > GT_cell3D, GT_size3D;
           typedef GC__model< GS_DDMRM::S_IceRay::S_type::S_coord::GT_size4D  > GT_cell4D, GT_size4D;
           
           typedef GC__model< GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    > GT_color;

          }
        }
      }
    }
  }

#endif
