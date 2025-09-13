#include <map>
#include <string>
#include <cstddef>
#include <iostream>
#include <iomanip>

typedef std::map<std::string,std::string> InfoContainer;

InfoContainer & GetInfoContaier()
 {
  static InfoContainer Is_info;
  return Is_info;
 }

int InitInfo( )
 {
  auto & I_info = GetInfoContaier();

  I_info["size-size_t"] = std::to_string( sizeof( std::size_t ) );
  I_info["size-void*"] = std::to_string( sizeof( void* ) );
  I_info["size-float"] = std::to_string( sizeof( float ) );

  I_info["size-char"] = std::to_string( sizeof( char ) );
  I_info["size-long-double"] = std::to_string( sizeof( long double ) );
  I_info["size-double"] = std::to_string( sizeof( double ) );
  I_info["size-int"] = std::to_string( sizeof( int ) );
  I_info["size-long"] = std::to_string( sizeof( long ) );
  I_info["size-short"] = std::to_string( sizeof( short ) );

  I_info["__func__"] = __func__ ;
  I_info["__cplusplus"] = std::to_string(__cplusplus);
  I_info["__TIME__"] = __TIME__ ;
  I_info["__DATE__"] = __DATE__ ;
  I_info["__LINE__"] = std::to_string(__LINE__);
  I_info["__FILE__"] = __FILE__;

#if defined( _DEBUG  )
  I_info["_DEBUG"] =  std::to_string( _DEBUG );
#endif

#if defined( _MSC_VER  )
  I_info["OS"] = "Microsoft";
  I_info["compiler"] = "MSVC";
  I_info["_MSC_BUILD"] = std::to_string( _MSC_BUILD );
  I_info["_MSC_FULL_VER"] = std::to_string( _MSC_FULL_VER );

#if defined( _WIN32  )
  I_info["_WIN32"] = std::to_string( _WIN32 ) ;
#endif

#if defined( _WIN64  )
  I_info["_WIN64"] = std::to_string( _WIN64 ) ;
#endif
  I_info["_MSVC_LANG"] = std::to_string( _MSVC_LANG );
#endif

#if defined( __GNUC__  )
 // https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html#Common-Predefined-Macros
  I_info["OS"] = "gnu";
  I_info["__STRICT_ANSI__"] = "__STRICT_ANSI__";
  I_info["__GNUG__"] = "__GNUG__";
  I_info["__GNUC_MINOR__"] = "__GNUC_MINOR__";
  I_info["__GNUC_PATCHLEVEL__"] = "__GNUC_PATCHLEVEL__";

  I_info["__VERSION__"] = "__GNUC_PATCHLEVEL__";
  I_info["__OPTIMIZE__"] = "__GNUC_PATCHLEVEL__";
  I_info["__OPTIMIZE_SIZE__"] = "__GNUC_PATCHLEVEL__";
  I_info["__NO_INLINE__"] = "__GNUC_PATCHLEVEL__";
#endif
  return (int)I_info.size();
 }
