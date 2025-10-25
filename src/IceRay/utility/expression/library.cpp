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
#define MAKE_UNARY_FUNCTION(DP_longName,DP_stdName)                      \
   GC_library::T_scalar  DP_longName( GC_library::T_scalar const& arg0 ) \
    {                                                                    \
     return DP_stdName( arg0 );                                          \
    }
#define MAKE_BINARY_FUNCTION(DP_longName,DP_stdName)                    \
   GC_library::T_scalar  DP_longName( GC_library::T_scalar const& arg0, GC_library::T_scalar const& arg1 ) \
    {                                                                    \
     return DP_stdName( arg0, arg1 );                                    \
    }

MAKE_UNARY_FUNCTION(cosinus,cos)
MAKE_UNARY_FUNCTION(sinus,sin)
MAKE_UNARY_FUNCTION(tanges,tan)
MAKE_UNARY_FUNCTION(arccos,acos)
MAKE_UNARY_FUNCTION(arcsin,asin)
MAKE_UNARY_FUNCTION(arctan,atan)
MAKE_BINARY_FUNCTION(arctan2,atan2)
MAKE_UNARY_FUNCTION(hypcos , cosh )
MAKE_UNARY_FUNCTION(hypsin , sinh )
MAKE_UNARY_FUNCTION(hyptan , tanh )
MAKE_UNARY_FUNCTION(hypacos, acosh)
MAKE_UNARY_FUNCTION(hypasin, asinh)
MAKE_UNARY_FUNCTION(hypatan, atanh)

MAKE_UNARY_FUNCTION( exponential, exp )
MAKE_UNARY_FUNCTION( exponential2, exp2 )
MAKE_UNARY_FUNCTION( exponentialm1, expm1 )

MAKE_UNARY_FUNCTION( logarithm, log)
MAKE_UNARY_FUNCTION( logarithm2, log2 )
MAKE_UNARY_FUNCTION( logarithm10, log10 )
MAKE_UNARY_FUNCTION( logarithmb, logb )

MAKE_BINARY_FUNCTION(lib_pow,   pow  )
MAKE_UNARY_FUNCTION( lib_sqrt,  sqrt )
MAKE_UNARY_FUNCTION( lib_cbrt,  cbrt )
MAKE_BINARY_FUNCTION(lib_hypot, hypot)

MAKE_UNARY_FUNCTION(lib_ceil,  ceil  )
MAKE_UNARY_FUNCTION(lib_floor, floor )
MAKE_BINARY_FUNCTION(lib_fmod,  fmod  )
MAKE_UNARY_FUNCTION(lib_trunc, trunc )

MAKE_UNARY_FUNCTION(lib_abs, fabs )
 }

GC_library::GC_library(   )
 {
  M2_container["+"]   = T_instruction( &plus, 0, 0, 0 );
  M2_container["-"]   = T_instruction( &minus, 0, 0, 0 );
  M2_container["*"]   = T_instruction( &multiply, 0, 0, 0 );
  M2_container["/"]   = T_instruction( &division, 0, 0, 0 );
//M2_container["%"]   = T_instruction( &lib_fmod, 0, 0, 0 );

  M2_container[ "cos"  ] = T_instruction( &cosinus, 0, 0 );
  M2_container[ "sin"  ] = T_instruction( &sinus, 0, 0 );
  M2_container[ "tan"  ] = T_instruction( &tanges, 0, 0 );
  M2_container[ "acos" ] = T_instruction( &arccos, 0, 0 );
  M2_container[ "asin" ] = T_instruction( &arcsin, 0, 0 );
  M2_container[ "atan" ] = T_instruction( &arctan, 0, 0 );
  M2_container[ "atan2"] = T_instruction( &arctan2, 0, 0, 0 );

  M2_container["cosh" ] = T_instruction( &hypcos , 0, 0 );
  M2_container["sinh" ] = T_instruction( &hypsin , 0, 0 );
  M2_container["tanh" ] = T_instruction( &hyptan , 0, 0 );
  M2_container["acosh"] = T_instruction( &hypacos, 0, 0 );
  M2_container["asinh"] = T_instruction( &hypasin, 0, 0 );
  M2_container["atanh"] = T_instruction( &hypatan, 0, 0 );

  M2_container["exp"] = T_instruction( &exponential , 0, 0 );
  M2_container["exp2"] = T_instruction( &exponential2, 0, 0 );
  M2_container["expm1"] = T_instruction( &exponentialm1 , 0, 0 );
//M2_container["frexp"] = T_instruction( &sinus, 0, 0 );
//M2_container["ldexp"] = T_instruction( &sinus, 0, 0 );
  M2_container["log"]   = T_instruction( &logarithm , 0, 0 );
  M2_container["log2"]  = T_instruction( &logarithm2, 0, 0 );
  M2_container["log10"] = T_instruction( &logarithm10, 0, 0 );
  M2_container["logb"]  = T_instruction( &logarithmb, 0, 0 );
//M2_container["expm1"] = T_instruction( &sinus, 0, 0 );
//M2_container["ilogb"] = T_instruction( &sinus, 0, 0 );
//M2_container["log1p"] = T_instruction( &sinus, 0, 0 );
//M2_container["scalbn"] = T_instruction( &sinus, 0, 0 );
//M2_container["scalbln"] = T_instruction( &sinus, 0, 0 );

  M2_container["pow"]   = T_instruction( &lib_pow,   0, 0, 0 );
  M2_container["sqrt"]  = T_instruction( &lib_sqrt,  0, 0 );
  M2_container["cbrt"]  = T_instruction( &lib_cbrt,  0, 0 );
  M2_container["hypot"] = T_instruction( &lib_hypot, 0, 0, 0 );

  M2_container["ceil"]  = T_instruction( &lib_ceil,  0, 0 );
  M2_container["floor"] = T_instruction( &lib_floor, 0, 0 );
  M2_container["fmod"]  = T_instruction( &lib_fmod,  0, 0, 0 );
  M2_container["trunc"] = T_instruction( &lib_trunc, 0, 0 );
  M2_container["fabs"]  = T_instruction( &lib_abs, 0, 0 );

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
