#include <algorithm>

#include "./processor.hpp"


using namespace GS_DDMRM::S_IceRay::S_material::S_compute;


GC_processor::GC_processor()
 {
  M2_program.F_memory( &M2_memory );
 }

bool  GC_processor::Fv_execute( T_beam &P_next, T_pigment::T_intersect const& P_intersect, T_state const& P_state )const
 {

  for( auto const& I_instruction : F_program().F_papllet() )
   {
    if( false == I_instruction->Fv_execute( P_next, P_intersect, P_state ) )
     {
      break;
     }
   }

  return true;
 }

void GC_processor::F_instruction( T_size const& P_index, T_instruction * P_instruction )
 {
  F1_program().F_instruction( P_index, P_instruction );
 }

void GC_processor::F_insert( T_size const& P_index, T_instruction * P_instruction  )
 {
  F1_program().F_insert( P_index, P_instruction );
 }

void GC_processor::F_set( T_size const& P_index, T_instruction * P_instruction)
 {
  F1_program().F_set( P_index, P_instruction );
 }
 
void GC_processor::F_append( T_instruction * P_instruction )
 {
  F1_program().F_append( P_instruction );
 }
