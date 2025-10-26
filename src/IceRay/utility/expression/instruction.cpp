#include "./program.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

GC_instruction::GC_instruction()
 :M2_data( nullptr )
 ,M2_scalar0( nullptr )
 ,M2_scalar1( nullptr )
 ,M2_scalar2( nullptr )
 ,M2_scalar3( nullptr )
 ,M2_scalar4( nullptr )
 ,M2_vector1( nullptr )
 ,M2_vector2( nullptr )
 ,M2_vector3( nullptr )
 ,M2_vector4( nullptr )
 ,M2_vector5( nullptr )
 ,M_type(-1)
 ,M2_address{0,0,0,0,0}
 {
  
 }
 
GC_instruction::GC_instruction( T_function0 const& P_func0, T_address const& P_0 )
 :GC_instruction()
 {
  M_type = 0;
  M2_scalar0 = P_func0;
  M2_address[0] = P_0;
 }
 
GC_instruction::GC_instruction( T_function1 const& P_func1, T_address const& P_0, T_address const& P_1 )
 :GC_instruction()
 {
  M_type = 1;
  M2_scalar1 = P_func1;
  M2_address[0] = P_0; M2_address[1] = P_1;
 }
GC_instruction::GC_instruction( T_function2 const& P_func2, T_address const& P_0, T_address const& P_1, T_address const& P_2 )
 :GC_instruction()
 {
  M_type = 2;
  M2_scalar2 = P_func2;
  M2_address[0] = P_0; M2_address[1] = P_1; M2_address[2] = P_2;
 }
GC_instruction::GC_instruction( T_function3 const& P_func3, T_address const& P_0, T_address const& P_1, T_address const& P_2, T_address const& P_3 )
 :GC_instruction()
 {
  M_type = 3;
  M2_scalar3 = P_func3;
  M2_address[0] = P_0; M2_address[1] = P_1; M2_address[2] = P_2; M2_address[3] = P_3;
 }
GC_instruction::GC_instruction( T_function4 const& P_func4, T_address const& P_0, T_address const& P_1, T_address const& P_2, T_address const& P_3, T_address const& P_4 )
 :GC_instruction()
 {
  M_type = 4;
  M2_scalar4 = P_func4;
  M2_address[0] = P_0; M2_address[1] = P_1; M2_address[2] = P_2; M2_address[3] = P_3; M2_address[4] = P_4;
 }

bool GC_instruction::F_valid( )const
 {
  return -1 != M_type;
 }

bool GC_instruction::F_memory( T_memory & P_memory )
 {
  M2_data = P_memory.F_container().data();
  return true;
 }

bool GC_instruction::F_address( T_address const& P_0, T_address const& P_1, T_address const& P_2, T_address const& P_3, T_address const& P_4 )
 {
  M2_address[0] = P_0; 
  M2_address[1] = P_1; 
  M2_address[2] = P_2; 
  M2_address[3] = P_3; 
  M2_address[4] = P_4;

  return true;
 }
 
void GC_instruction::F_execute(  )const
 {
  auto & I_data = this->M2_data;

  switch( M_type )
   {
    case( 0 ): I_data[M2_address[0]] = (*M2_scalar0)();  break;
    case( 1 ): I_data[M2_address[0]] = (*M2_scalar1)(I_data[M2_address[1]]);  break;
    case( 2 ): I_data[M2_address[0]] = (*M2_scalar2)(I_data[M2_address[1]], I_data[M2_address[2]]);  break;
    case( 3 ): I_data[M2_address[0]] = (*M2_scalar3)(I_data[M2_address[1]], I_data[M2_address[2]], I_data[M2_address[3]]);  break;
    case( 4 ): I_data[M2_address[0]] = (*M2_scalar4)(I_data[M2_address[1]], I_data[M2_address[2]], I_data[M2_address[3]], I_data[M2_address[4]]);  break;
    case( 5 ): M2_vector1( I_data + M2_address[0] ); break;
    case( 6 ): M2_vector2( I_data + M2_address[0], I_data + M2_address[1] ); break;
    case( 7 ): M2_vector3( I_data + M2_address[0], I_data + M2_address[1], I_data + M2_address[2] ); break;
    case( 8 ): M2_vector4( I_data + M2_address[0], I_data + M2_address[1], I_data + M2_address[2], I_data + M2_address[3] ); break;
    case( 9 ): M2_vector5( I_data + M2_address[0], I_data + M2_address[1], I_data + M2_address[2], I_data + M2_address[3], I_data + M2_address[4] ); break;
    default: /*nothing*/;
   }
 }

GC_instruction::T_address GC_instruction::F_consumption()const
 {
  switch( M_type )
   {
    case( 0 ): return M2_address[0];
    case( 1 ): return std::max( M2_address[0], M2_address[1] );  break;
    case( 2 ): return std::max( M2_address[0], std::max( M2_address[1], M2_address[2] ) );
    //case( 3 ): return std::max( M2_address[0], M2_address[1], I_data[M2_address[2]], I_data[M2_address[3]]);  break;
    //case( 4 ): return std::max( M2_address[0], M2_address[1], I_data[M2_address[2]], I_data[M2_address[3]], I_data[M2_address[4]]);  break;
    //case( 5 ): M2_vector1( I_data + M2_address[0] ); break;
    //case( 6 ): M2_vector2( I_data + M2_address[0], I_data + M2_address[1] ); break;
    //case( 7 ): M2_vector3( I_data + M2_address[0], I_data + M2_address[1], I_data + M2_address[2] ); break;
    //case( 8 ): M2_vector4( I_data + M2_address[0], I_data + M2_address[1], I_data + M2_address[2], I_data + M2_address[3] ); break;
    //case( 9 ): M2_vector5( I_data + M2_address[0], I_data + M2_address[1], I_data + M2_address[2], I_data + M2_address[3], I_data + M2_address[4] ); break;
    default:return 0;
   }
 }


        }
      }
    }
  }
