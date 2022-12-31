#include <algorithm>

#include "./program.hpp"


using namespace GS_DDMRM::S_IceRay::S_material::S_compute;


GC_program::GC_program()
 {
 }

GC_program::~GC_program()
 {
 }

void GC_program::F_instruction( T_size const& P_index, T_instruction * P_instruction )
 {
  M2_papllet.resize( std::max<T_size>( M2_papllet.size(), P_index +1 ), nullptr );
  M2_papllet[P_index] = P_instruction;
  M2_papllet[P_index]->Fv_memory( this->F_memory() );

  for( T_size I_component = static_cast<T_size>( T_memory::T_component::En__begin );
              I_component < static_cast<T_size>( T_memory::T_component::En__end );
            ++I_component
   )
   {
     M2_memory->F_size
      (
        T_memory::T_component( I_component ) ,
        std::max<T_size>
         (
            M2_memory->F_size( T_memory::T_component( I_component ) )
           ,M2_papllet[P_index]->F_size( T_memory::T_component( I_component ) )
         )
      );
   }

 }

void GC_program::F_insert( T_size const& P_index, T_instruction * P_instruction  )
 {
  // TODO
 }

void GC_program::F_append( T_instruction * P_instruction )
 {
  F_instruction( M2_papllet.size(), P_instruction );
 }
void GC_program::F_set( T_size const& P_index, T_instruction * P_instruction )
 {
  F_instruction( P_index, P_instruction );
 }


