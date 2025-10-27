#include "./memory.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {


GC_memory::T_scalar const& GC_memory::F_get( T_size const& P_index )
 {
  return M2_container[P_index];
 }

bool GC_memory::F_set(T_size const& P_index, T_scalar const& P_value )
 {
  M2_container[ P_index] = P_value;
  return true;
 }

bool GC_memory::F_set( T_size const& P_index, T_size const& P_size, T_scalar* P_value )
 {
  return false;
 }
bool GC_memory::F_resize( T_size const& P_size )
 {
  M2_container.resize( P_size );
  return true;
 }
 
bool GC_memory::F_apply( T_mapper const& P_mapper )
 {
  this->F_resize( P_mapper.F_end() );
  for( auto const& I_item : P_mapper.F_container() )
   {
    std::size_t total;
    T_scalar I_value;
    try
     {
      I_value = std::stod( I_item.first, &total );
     }
    catch(...)
     {
      continue;
     }
    if( total != I_item.first.size() )
     {
      continue;
     }
    this->F_set( I_item.second, I_value );
   }

  return true;
 }

GC_memory::T_data& GC_memory::F_container()
 {
  return M2_container;
 }

GC_memory::T_data const& GC_memory::F_container()const
 {
  return M2_container;
 }


        }
      }
    }
  }
