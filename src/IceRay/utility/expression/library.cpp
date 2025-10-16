#include "./library.hpp"

namespace GS_DDMRM
 {
  namespace S_IceRay
   {
    namespace S_utility
     {
      namespace S_expression
       {

namespace
 {
   GC_library::T_scalar  cosinus( GC_library::T_scalar const& arg1 )
    {
     return sin( arg1 );
    }
   GC_library::T_scalar  sinus( GC_library::T_scalar const& arg1 )
    {
     return sin( arg1 );
    }
   GC_library::T_scalar  plus( GC_library::T_scalar const& arg1, GC_library::T_scalar const& arg2 )
    {
     return arg1+arg2;
    }
 
 }

GC_library::GC_library(   )
 {
  M2_container["cos"] = T_instruction( &cosinus, 0, 0 );
  M2_container["sin"] = T_instruction( &sinus, 0, 0 );
  M2_container["+"]   = T_instruction( &plus, 0, 0, 0 );
 }


GC_library::T_container const& GC_library::F_container()const
 {
  return M2_container;
 }

        }
      }
    }
  }
