#include "./mapper.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

bool GC_mapper::F_tie( T_string const& P_name, T_size const& P_index )
 {
  M2_container[P_name] = P_index;
  M2_reverse[P_index] = P_name;
  return true;
 }
bool GC_mapper::F_untie( T_string const& P_name, T_size const& P_index )
 {
  {
   auto I_iterator = M2_container.find( P_name );

   if( I_iterator == M2_container.end()) 
    {
     M2_container.erase (I_iterator);
    }     
  }
  {
   auto I_iterator = M2_reverse.find( P_index );

   if( I_iterator == M2_reverse.end()) 
    {
     M2_reverse.erase ( I_iterator );
    }     
  }
  
  return true;
 }

GC_mapper::T_container const& GC_mapper::F_container()const
 {
  return M2_container;
 }
GC_mapper::T_reverse const& GC_mapper::F_reverse()const
 {
  return M2_reverse;
 }








        }
      }
    }
  }
