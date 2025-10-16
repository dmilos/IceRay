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
  return false;
 }

bool GC_memory::F_set( T_size const& P_index, T_size const& P_size, T_scalar* P_value )
 {
  return false;
 }
bool GC_memory::F_resize( T_size const& P_size )
{
    return false;
}

GC_memory::T_container& GC_memory::F_container()
 {
  return M2_container;
 }

GC_memory::T_container const& GC_memory::F_container()const
 {
  return M2_container;
 }


        }
      }
    }
  }
