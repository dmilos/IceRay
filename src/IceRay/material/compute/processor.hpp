#ifndef Dh_DDMRM_Iceray_material_compute_processor_HPP_
 #define Dh_DDMRM_Iceray_material_compute_processor_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::GC_processor

 #include "./instruction.hpp"
 #include "./program.hpp"
 #include "./memory.hpp"
 
 #include "./medium.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {

         class GC_processor
          : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
          {
           public:
             typedef   GS_DDMRM::S_IceRay::S_material::S_compute::GC_program   T_program;
             typedef   GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory    T_memory;

             typedef   GS_DDMRM::S_IceRay::S_material::S_compute::GT_medium     T_medium;

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction T_instruction;

                      GC_processor();
             virtual ~GC_processor(){}

           public:
             virtual bool     Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const;

           public:
             void F_instruction( T_size const& P_index, T_instruction * P_instruction );
             void F_insert(      T_size const& P_index, T_instruction * P_instruction  );
             void F_set(         T_size const& P_index, T_instruction * P_instruction);
             void F_append( T_instruction * P_instruction );

           public:
             T_program const&  F_program()const{ return M2_program; }
           protected:
             T_program      &  F1_program(){ return M2_program; }
           private:
             mutable T_program   M2_program; //!< dumb_ptr;

           public:
             T_memory      &  F_memory()     { return M2_memory; }
             T_memory const&  F_memory()const{ return M2_memory; }
           private:
             mutable T_memory   M2_memory;

           public:
             T_medium      &  F_medium()     { return M2_medium; }
             T_medium const&  F_medium()const{ return M2_medium; }
           private:
             mutable T_medium   M2_medium;
          };

        }
      }
    }
  }

#endif
