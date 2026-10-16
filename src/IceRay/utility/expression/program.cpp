#include "./program.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

GC_program::GC_program()
 {
 }

GC_program::~GC_program()
 {
 }

void GC_program::F_clear( )
 {
  M2_container.clear();
 }

void GC_program::F_memory( T_memory& P_memory )
 {
  for( auto & I_instruction: M2_container )
   {
    I_instruction.F_memory( P_memory );
   }
 }

void GC_program::F_push( T_instruction const& P_instruction )
 {
  M2_container.push_back( P_instruction );
 }

void GC_program::F_execute( )const
 {
  for( auto const& I_instruction: M2_container )
   {
    I_instruction.F_execute();
   }
 }

GC_program::T_size GC_program::F_consumption()
 {
  T_size Ir_result = 0;
  for( auto const& I_instruction: M2_container )
   {
    Ir_result = std::max( Ir_result, I_instruction.F_consumption() );
   }
  return Ir_result+1;
 }

GC_program::T_container const& GC_program::F_container()const
 {
  return M2_container;
 }

        }
      }
    }
  }
