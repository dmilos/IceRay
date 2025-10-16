#include "./program.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

bool GC_instruction::F_memory( T_memory & P_memory )
 {
  M2_data = P_memory.F_container().data();
  return true;
 }

void GC_instruction::F_execute(  )const
 {
  auto & I_data = this->M2_data;

  switch( M_type )
   {
    case( 0 ): I_data[M2_index[0]] = (*M2_scalar0)();  break;
    case( 1 ): I_data[M2_index[0]] = (*M2_scalar1)(I_data[M2_index[1]]);  break;
    case( 2 ): I_data[M2_index[0]] = (*M2_scalar2)(I_data[M2_index[1]], I_data[M2_index[2]]);  break;
    case( 3 ): I_data[M2_index[0]] = (*M2_scalar3)(I_data[M2_index[1]], I_data[M2_index[2]], I_data[M2_index[3]]);  break;
    case( 4 ): I_data[M2_index[0]] = (*M2_scalar4)(I_data[M2_index[1]], I_data[M2_index[2]], I_data[M2_index[3]], I_data[M2_index[4]]);  break;
    case( 5 ): M2_vector1( I_data + M2_index[0] ); break;
    case( 6 ): M2_vector2( I_data + M2_index[0], I_data + M2_index[1]); break;
    case( 7 ): M2_vector3( I_data + M2_index[0], I_data + M2_index[1], I_data + M2_index[2]); break;
    //case( 8 ): M2_vector4( I_data + M2_index[0], I_data + M2_index[1], I_data + M2_index[2], I_data + M2_index[3]) break;
   }
 }



        }
      }
    }
  }
