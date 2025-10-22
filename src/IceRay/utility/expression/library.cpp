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
   GC_library::T_scalar  minus( GC_library::T_scalar const& arg1, GC_library::T_scalar const& arg2 )
    {
     return arg1-arg2;
    }
   GC_library::T_scalar  multiply( GC_library::T_scalar const& arg1, GC_library::T_scalar const& arg2 )
    {
     return arg1*arg2;
    }
   GC_library::T_scalar  division( GC_library::T_scalar const& arg1, GC_library::T_scalar const& arg2 )
    {
     return arg1/arg2;
    }

 }

GC_library::GC_library(   )
 {
  M2_container["cos"] = T_instruction( &cosinus, 0, 0 );
  M2_container["sin"] = T_instruction( &sinus, 0, 0 );
  M2_container["+"]   = T_instruction( &plus, 0, 0, 0 );
  M2_container["-"]   = T_instruction( &minus, 0, 0, 0 );
  M2_container["*"]   = T_instruction( &multiply, 0, 0, 0 );
  M2_container["/"]   = T_instruction( &division, 0, 0, 0 );
  //M2_container["×"]   = T_instruction( &cross, 0, 0, 0 );
  //M2_container["."]   = T_instruction( &dot, 0, 0, 0 );

 }

GC_library::T_instruction const& GC_library::F_get( T_string const& P_name )const
 {
  static T_instruction Is_default;
  auto I_iterator = M2_container.find( P_name );
  if( I_iterator == M2_container.end() )
   {
    return Is_default;
   }

  return I_iterator->second;
 }

GC_library::T_container const& GC_library::F_container()const
 {
  return M2_container;
 }

        }
      }
    }
  }
