#ifndef Dh_DDMRM_Iceray_material_compute_program_HPP_
 #define Dh_DDMRM_Iceray_material_compute_program_HPP_

 #include "../../type/basic/size.hpp"
 #include "../../type/color.hpp"
 #include "../../type/ray/state.hpp"

 #include "./instruction.hpp"
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

         class GC_program
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                  T_size;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar       T_color;
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory T_memory;
             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GT_medium T_medium;

             typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction T_instruction;

             typedef std::vector< T_instruction *> T_papllet;

             typedef T_instruction::T_ray    T_ray;
             typedef T_instruction::T_beam   T_beam;

                      GC_program(){}
             virtual ~GC_program(){}

           public:
            T_size Fv_size( T_memory::T_component const& P_component )const;

           public:
             void F_instruction( T_size const& P_index, T_instruction * P_instruction );
             void F_insert(      T_size const& P_index, T_instruction * P_instruction  );
             void F_set(         T_size const& P_index, T_instruction * P_instruction );
             void F_append( T_instruction * P_instruction );

           public:
             T_papllet const& F_papllet( )const{ return M2_papllet; }
           private:
             T_papllet  M2_papllet;

           public:
             void             F_memory( T_memory * P_memory )
              {
               M2_memory = P_memory;
              }
             T_memory *       F_memory( )
              {
               return M2_memory; 
              }
           private:
             T_memory   *M2_memory; //!< dumb_ptr;

           public:
             void             F_medium( T_medium * P_medium )
              {
               M2_medium = P_medium;
              }
             T_medium *       F_medium( )
              {
               return M2_medium; 
              }
           private:
             T_medium   *M2_medium; //!< dumb_ptr;


          };

        }
      }
    }
  }

#endif
