#ifndef Dh_DDMRM_Iceray_material_compute_operation_random_congruent2d_HPP_
 #define Dh_DDMRM_Iceray_material_compute_operation_random_congruent2d_HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::S_random::GC_congruent2d

#include "../../instruction.hpp"
#include "IceRay/utility/random.hpp"
#include "math/math.hpp"

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
           namespace S_random
            {

             class GC_congruent2d
              : public GS_DDMRM::S_IceRay::S_material::S_compute::GC_instruction
              {
               public:
                 typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
                 typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;
                 typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;

                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory   T_memory;

                 enum Ee_input
                  {
                    En_inSize_Count     = 1
                  };
                 enum Ee_output
                  {
                    En_inScalar_Leader = 0 //!< it is pointer scalar
                  };

               public:
                 GC_congruent2d
                  (
                    T_size const& P_inSize_Count     //= 1
                   ,T_size const& P_inScalar_Leader  //= 1
                  )
                  {
                   F_input<T_size>(  En_inSize_Count,   P_inSize_Count    );

                   F_output<T_coord2D>( En_inScalar_Leader,  P_inScalar_Leader );
                  }

               public:
                 bool    Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
                  {
                   T_size   const& I_count  = M2_memorySize->Fv_load( F_input<T_size  >( En_inSize_Count  ) );
                   T_size   const& I_leader = F_output<T_coord2D>( En_inScalar_Leader );
                   for( T_size I_index = 0; I_index < I_count; ++I_index )
                    {
                     M2_memoryCoord2D->Fv_store( I_leader + I_index, M2_generator.next() );
                    }
                   return true;
                  }

               private:
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_size>    T2_memorySize;
                 typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<T_coord2D>  T2_memoryCoord2D;

               public:
                 void    Fv_memory( T_memory * P_memory  )
                  {
                   F1_memory() = P_memory;
                   M2_memorySize   = P_memory->F_get<T_size>();
                   M2_memoryCoord2D = P_memory->F_get<T_coord2D>();
                  }
               private:
                 T2_memorySize     *M2_memorySize;
                 T2_memoryCoord2D   *M2_memoryCoord2D;
               private:
                 mutable GS_DDMRM::S_IceRay::S_utility::S_random::GT_congruent2D M2_generator;
              };

            }
          }
        }
      }
    }
  }

#endif
